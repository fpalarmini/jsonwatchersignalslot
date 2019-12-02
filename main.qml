import QtQuick 2.9
import QtQuick.Window 2.2
import fernando.quick 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    JSWatcher
    {
        id: jsonWatcher
    }

    Connections
    {
        target: jsonWatcher

        onStatusChanged: image.visible = true

    }

    Image {
        id: image
        x: 128
        y: 133
        width: 100
        height: 100
        source: "check.png"
        visible: jsonWatcher.statusTest
        fillMode: Image.PreserveAspectFit
    }
}
