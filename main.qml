import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Window {
    visible: true
    width: 800
    height: 600

    Material.theme: Material.Light
    Material.accent: Material.Purple

    Connections {
        target: MyClass

        // signal newData()
        onNewData: {
            labelInfo.text = value;
        }

        /*
        onChangedClock: {
            labelTime.text =    MyClass.clock;
        }
        */
    }

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Item {
            id: pageOne

            Rectangle {
                anchors.fill: parent
                color: "#323232"

                Text {
                    id: labelInfo
                    width: parent.width
                    height: parent.height/2
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: parent.width*0.2
                    style: Text.Sunken
                    color: "#D3D3D3"
                    text: "00"
                }

                Slider {
                    id: slider
                    anchors.bottom: parent.bottom
                    anchors.margins: 20
                    width: parent.width
                    height: 50
                    from: 1
                    value: 10
                    to: 100

                    onValueChanged: {
                        // Call function newValuePot() in MyClass
                        MyClass.newValuePot(slider.value);
                    }
                }

            }

        }

        Item {
            id: pageTwo

            Rectangle {
                anchors.fill: parent
                color: "#323232"

                Text {
                    id: labelTime
                    width: parent.width
                    height: parent.height/2
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: parent.width*0.16
                    style: Text.Sunken
                    color: "#D3D3D3"
                    text: MyClass.clock
                }


                Button {
                    id: buttonAction
                    width: parent.width/4
                    height: parent.height/10
                    anchors.top: labelTime.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    highlighted: true
                    Material.accent: Material.Orange
                    text: "START"

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            if (buttonAction.text === "START") {
                                buttonAction.text = "STOP";
                                MyClass.startTimer();
                            } else {
                                buttonAction.text = "START";
                                MyClass.stopTimer();
                            }
                        }
                    }
                }

            }
        }

    }

    PageIndicator {
        id: indicator
        count: view.count
        currentIndex: view.currentIndex
        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter               
    }


}
