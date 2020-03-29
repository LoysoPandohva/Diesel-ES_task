import QtQuick 2.0

Rectangle {

    radius: 10
    border.width: 1

    color: "#ddf"

    Text {
        anchors.centerIn: parent
        text: "Add file\namount"
        font.pixelSize: Math.min(parent.width, parent.height) / 3
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            appCore.addFileAmount()
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
