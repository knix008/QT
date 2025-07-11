/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import Constants

Rectangle {
    id: root
    width: 320
    height: 480
    color: Constants.backgroundColor

    Text {
        id: textLabel
        text: qsTr("Welcome to IntelliVix")
        anchors.centerIn: parent
    }

    BorderImage {
        id: borderImage
        x: 110
        y: 79
        width: 100
        height: 100
        source: "../../../../../Users/shkwon/Desktop/intellivix_logo.jpg"
    }

    Rectangle {
        id: rectangle
        x: 60
        y: 294
        width: 200
        height: 77
        color: "#ffffff"
    }

    BorderImage {
        id: borderImage1
        x: 19
        y: 22
        width: 286
        height: 442
        source: "imports/MCUDefaultStyle/images/checkbox.png"
    }
}
