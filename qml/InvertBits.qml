import QtQuick 2.0

Image {
    source: "../img/invertBits.png"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            appCore.invertBits()
        }
    }
    Connections {
        target: appCore

        onChangeBit: {
            _data.model.setProperty(index,"display",bit);
        }
        onChangeNum: {
            _data.numText = number;
        }
    }
}
