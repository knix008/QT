#include "videoplayer.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Video Player");

    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    videoWidget->setFixedSize(360, 640);
    mediaPlayer->setVideoOutput(videoWidget);

    playPauseButton = new QPushButton("Play", this);
    stopButton = new QPushButton("Stop", this);

    positionSlider = new QSlider(Qt::Horizontal, this);
    positionSlider->setRange(0, 0);

    timeLabel = new QLabel("00:00 / 00:00", this);
    timeLabel->setAlignment(Qt::AlignCenter);

    videoList = new QListWidget(this);

    QHBoxLayout *controlLayout = new QHBoxLayout();
    controlLayout->addWidget(playPauseButton);
    controlLayout->addWidget(stopButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(videoWidget);
    mainLayout->addWidget(positionSlider);
    mainLayout->addWidget(timeLabel);
    mainLayout->addLayout(controlLayout);
    mainLayout->addWidget(videoList);

    setLayout(mainLayout);

    adjustSize();
    setFixedSize(size());

    connect(playPauseButton, &QPushButton::clicked, this, &VideoPlayer::playPauseClicked);
    connect(stopButton, &QPushButton::clicked, this, &VideoPlayer::stopClicked);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoPlayer::positionChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &VideoPlayer::durationChanged);
    connect(positionSlider, &QSlider::sliderMoved, this, &VideoPlayer::sliderMoved);
    connect(videoList, &QListWidget::itemClicked, this, &VideoPlayer::videoItemClicked);
    connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, &VideoPlayer::playerStateChanged);
    connect(mediaPlayer, &QMediaPlayer::errorOccurred, this, &VideoPlayer::handleError);

    loadVideos();
}

VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::loadVideos()
{
    QDir videoDir("videos");

    if (!videoDir.exists()) {
        videoList->addItem("Videos directory not found!");
        return;
    }

    QStringList filters;
    filters << "*.mp4" << "*.avi" << "*.mkv" << "*.mov" << "*.wmv" << "*.flv" << "*.webm";
    videoDir.setNameFilters(filters);

    videoFiles = videoDir.entryInfoList(QDir::Files);

    if (videoFiles.isEmpty()) {
        videoList->addItem("No video files found in videos directory");
        return;
    }

    for (const QFileInfo &fileInfo : videoFiles) {
        videoList->addItem(fileInfo.fileName());
    }
}

void VideoPlayer::playPauseClicked()
{
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
    } else {
        mediaPlayer->play();
    }
}

void VideoPlayer::stopClicked()
{
    mediaPlayer->stop();
}

void VideoPlayer::positionChanged(qint64 position)
{
    if (!positionSlider->isSliderDown()) {
        positionSlider->setValue(position);
    }

    QString timeStr = formatTime(position) + " / " + formatTime(mediaPlayer->duration());
    timeLabel->setText(timeStr);
}

void VideoPlayer::durationChanged(qint64 duration)
{
    positionSlider->setRange(0, duration);
}

void VideoPlayer::sliderMoved(int position)
{
    mediaPlayer->setPosition(position);
}

void VideoPlayer::videoItemClicked(QListWidgetItem *item)
{
    int index = videoList->row(item);

    if (index >= 0 && index < videoFiles.size()) {
        QString filePath = videoFiles.at(index).absoluteFilePath();
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        mediaPlayer->play();
    }
}

void VideoPlayer::playerStateChanged(QMediaPlayer::PlaybackState state)
{
    if (state == QMediaPlayer::PlayingState) {
        playPauseButton->setText("Pause");
    } else {
        playPauseButton->setText("Play");
    }
}

QString VideoPlayer::formatTime(qint64 milliseconds)
{
    qint64 seconds = milliseconds / 1000;
    qint64 minutes = seconds / 60;
    seconds = seconds % 60;

    return QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

void VideoPlayer::handleError(QMediaPlayer::Error error, const QString &errorString)
{
    qDebug() << "Media Player Error:" << error << errorString;
}
