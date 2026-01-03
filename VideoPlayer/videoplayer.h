#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileInfoList>

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();

private slots:
    void playPauseClicked();
    void stopClicked();
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void sliderMoved(int position);
    void videoItemClicked(QListWidgetItem *item);
    void playerStateChanged(QMediaPlayer::PlaybackState state);
    void handleError(QMediaPlayer::Error error, const QString &errorString);

private:
    void loadVideos();
    QString formatTime(qint64 milliseconds);

    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QPushButton *playPauseButton;
    QPushButton *stopButton;
    QSlider *positionSlider;
    QLabel *timeLabel;
    QListWidget *videoList;

    QFileInfoList videoFiles;
};

#endif // VIDEOPLAYER_H
