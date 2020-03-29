import QtQuick 2.0

Rectangle{
    id: _rectangle
    width: parent.width / 5
    height: parent.height / 5
    color: "lightblue"
    radius: 15
    border.width: 2

    TextInput{
        id: _input
        anchors.centerIn: _rectangle
        text: _data.numText
        font.pixelSize: Math.min(_rectangle.width, _rectangle.height) / 2

        onAccepted: {
            appCore.newNum(_input.text)
        }
        Connections {
            target: appCore

            onChangeBit: {
                _data.model.setProperty(index,"display",bit);
            }
        }
    }
}
