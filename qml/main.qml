import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Diesel Easy Solutions")

    Rectangle{
        id: _root
        anchors.fill: parent

        Item {
            id: _data
            property string numText: "00"
            BitsModel{
                id: _bitsM
            }
            property var model: _bitsM
        }

        BitsView {
            id: _bitsView
            width: _root.width / 2
            height: _root.height / 2
            anchors.centerIn: _root
        }

        InvertBits {
            width: Math.min(_root.width, _root.height) / 16
            height: Math.min(_root.width, _root.height) / 16
            anchors.left: _bitsView.right
            anchors.top: _bitsView.top
            anchors.leftMargin: 10
        }

        Num {
            id: _num
            anchors.centerIn: _root
        }

        AddFileAmount {
            width: _root.width / 8
            height: _root.height / 8
            anchors.top: _num.bottom
            anchors.horizontalCenter: _num.horizontalCenter
            anchors.topMargin: 40
        }
    }
}
