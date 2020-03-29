import QtQuick 2.12
import QtQuick.Window 2.12

import an.OpenGLItem 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    OpenGLItem {
        id: openGLItem
        visible: true
        anchors.fill: parent
    }


}

