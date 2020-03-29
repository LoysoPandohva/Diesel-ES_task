import QtQuick 2.12

ListView {
    id: _bitsList
    model: _data.model

    orientation: ListView.Horizontal

    delegate: Item {
        id: _item
        width: _bitsList.width / 8
        height: _bitsList.height / 8

        Bit {
            id: _bit
            anchors.fill: _item
            anchors.margins: 3

            displayText: display

            MouseArea {
                anchors.fill: _bit
                onClicked: {
                    appCore.newBit(index)
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
    }
}
