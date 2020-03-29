import QtQuick 2.12

Rectangle {
    id: _bitRectangle

    radius: 10
    border.width: 1

    property string displayText: ""
    color: displayText === "0" ? "#f55" : "#5f5"

    Text {
        anchors.centerIn: _bitRectangle
        text: _bitRectangle.displayText
        font.pixelSize: Math.min(_bitRectangle.width, _bitRectangle.height) / 2
    }
}
