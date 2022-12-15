import QtQuick 2.9
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QDTControlSystem 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sender")


GridLayout {
    width: parent.width/2
    height: parent.height/2
    anchors.centerIn: parent
    columns: 1
    Rectangle {
        anchors {fill: parent; margins: 50}
        color: "transparent"
        Column{
            anchors.fill: parent
            spacing: 15

            Row {
                x: -50
                spacing: 2
                Label {
                    x:0
                    y: 0
                    text: "IP:  "
                }
                TextEdit {
                    id: txtIP
                    x: 50
                    y: 0
                    horizontalAlignment:  Text.AlignHCenter
                    text: "224.1.1.6"
                }
            }
            Row{
                x: -50
                spacing: 2
                Label {
                    x:0
                    y: 0
                    text: "Port:  "
                }
                TextEdit {
                    id: txtPort
                    x: 50
                    y: 0
                    horizontalAlignment:  Text.AlignHCenter
                    text: "10669"
                }
             }
            Row {
                x: -50
                spacing: 10
                Label {
                    x:0
                    y: 0
                    text: "Path File:"
                }
                TextField {
                    id: txtFile
                    width: 200
                    horizontalAlignment:  Text.AlignHCenter
                    text: "please chose file !"
                }

                Button {
                    property bool isCheck_: true
                    x: 300
                    id: button2
                    text: "Chose file"
                    enabled: {
                        if(QDTControlSystem.simulator_.isEndFileToQML) return true
                        else
                        {
                            if(button1.isCheck_) setStateButton()
                            else QDTControlSystem.simulator_.isStopToQML
                         }
                    }
                    onClicked: {
                        fileDialog.open()
                        button2.isCheck_ = false
                    }
                }
            }
            Row {
                x: -50
                spacing: 20
                Label {
                    x:0
                    y: 0
                    text: "Data type:"
                }
                ExclusiveGroup { id: group2 }
                RadioButton {
                    property bool varBtn7_: false
                    id: button7
                    enabled:
                    {
                        if(QDTControlSystem.simulator_.isStopToQML) return true
                        else
                        {
                            if(button1.isCheck_)
                                return true
                            else
                                return QDTControlSystem.simulator_.isEndFileToQML
                        }
                    }
                    text: "CRL"
                    exclusiveGroup: group2
                    onClicked:
                    {
                        button7.varBtn7_ = true
                        button8.varBtn8_ = false
                        QDTControlSystem.simulator_.dataProcessor.typeOfData = TypeChecker.CRL
                    }
                }
                RadioButton {
                    property bool varBtn8_: false
                    id: button8
                    enabled:
                    {
                        if(QDTControlSystem.simulator_.isStopToQML) return true
                        else
                        {
                            if(button1.isCheck_)
                                return true
                            else
                                return QDTControlSystem.simulator_.isEndFileToQML
                        }
                    }
                    text: "KLV"
                    exclusiveGroup: group2
                    onClicked:
                    {
                        button8.varBtn8_ = true
                        button7.varBtn7_ = false
                         QDTControlSystem.simulator_.dataProcessor.typeOfData = TypeChecker.KLV
                    }
                }
            }
            Row {
                x: -50
                spacing: 20
                Label {
                    x:0
                    y:0
                    text: "Communication:"
                }
                ExclusiveGroup { id: group1 }
                RadioButton {
                    property bool varBtn5_: false
                    id: button5
                    enabled:
                    {
                        if( QDTControlSystem.simulator_.isStopToQML) return true
                        else
                        {
                            if(button1.isCheck_)
                                return true
                            else
                                return QDTControlSystem.simulator_.isEndFileToQML
                        }
                    }
                    text: "Broadcast"
                    exclusiveGroup: group1
                    onClicked:
                    {
                        button5.varBtn5_ = true
                        button6.varBtn6_ = false
                        QDTControlSystem.simulator_.communicator.typeOfCommu = TypeChecker.Broadcast
                    }
                }
                RadioButton {
                    property bool varBtn6_: false
                    id: button6
                    enabled:
                    {
                        if(QDTControlSystem.simulator_.isStopToQML) return true
                        else
                        {
                            if(button1.isCheck_)
                                return true
                            else
                                return QDTControlSystem.simulator_.isEndFileToQML
                        }
                    }
                    text: "Multicast"
                    exclusiveGroup: group1
                    onClicked:
                    {
                        button6.varBtn6_ = true
                        button5.varBtn5_ = false
                        QDTControlSystem.simulator_.communicator.typeOfCommu = TypeChecker.Multicast
                    }
                }
            }
            Row{
                x: 50
                width: 60
                height: 45
                spacing: 20
                Button {
                    property bool isCheck_: true
                    id: button1
                    text: "Simulate"
                    enabled:
                    {
                        if(QDTControlSystem.simulator_.isStopToQML) return true
                        else
                        {
                            if(button1.isCheck_ && !button2.isCheck_) return true
                            else if(button1.isCheck_ && button2.isCheck_) return false
                            else if(QDTControlSystem.simulator_.isStopToQML) return !button3.enabled
                            else if(button3.enabled && QDTControlSystem.simulator_.isStopToQML) return true
                            else return QDTControlSystem.simulator_.isEndFileToQML
                        }
                    }
                    onClicked: {
                       QDTControlSystem.simulator_.isStopToQML = false
                       QDTControlSystem.simulator_.isEndFileToQML = false
                       QDTControlSystem.simulator_.connectFunc()
                       button1.isCheck_ = false
                    }
                }
                Button {
                    property bool isCheck_: true
                    id: button3
                    text: "Stop"
                    enabled:
                    {
                        if(button1.isCheck_) return false
                        else return !button1.enabled
                    }
                    onClicked: {
                        if(button3.isCheck_)
                        {
                            button3.isCheck_ = false
                        }
                        else
                        {
                            button3.isCheck_ = true
                        }
                        QDTControlSystem.simulator_.isStopToQML = true
                    }
                }
            }
            FileDialog{
                id: fileDialog
                selectMultiple: false
                selectFolder: false
                nameFilters: "*.bin"
                onAccepted:{
                    selectMultiple ? console.log(this.fileUrls):txtFile.text = this.fileUrl
                    QDTControlSystem.simulator_.dataDecoder.pathOfFileToQML = txtFile.text.substring(7)
                    QDTControlSystem.simulator_.communicator.ipToQML = txtIP.text
                    QDTControlSystem.simulator_.communicator.portToQML = parseInt(txtPort.text)
                }

            }
        }
    }

  }
function setStateButton()
{
    var stateBroadcastBtn_ = button5.varBtn5_
    var stateMulticastBtn_ = button6.varBtn6_
    var stateCrlBtn_ = button7.varBtn7_
    var stateKlvBtn_ = button8.varBtn8_
    if(button2.isCheck_)
    {
        if(stateBroadcastBtn_ || stateMulticastBtn_)
        {
            if(stateCrlBtn_ || stateKlvBtn_)
            {
                return true
            }
            else
            {
                return false
            }
        }
        else if(stateCrlBtn_ || stateKlvBtn_)
        {
            if(stateBroadcastBtn_ || stateMulticastBtn_)
            {
                return true
            }
            else
            {
                return false
            }
        }
        else
        {
            return false
        }
    }
    else
        return true
}
}

