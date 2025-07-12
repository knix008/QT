#ifndef POPUP_H
#define POPUP_H

#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

class PopupWindow : public QDialog {
public:
    PopupWindow(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("팝업 윈도우");
        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel("이것은 팝업 윈도우입니다.", this);
        layout->addWidget(label);
        QPushButton *closeButton = new QPushButton("닫기", this);
        layout->addWidget(closeButton);
        connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
        setLayout(layout);
        resize(250, 100);
    }
};

#endif // POPUP_H
