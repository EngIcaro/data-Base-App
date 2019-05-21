import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Item {
    id: topLogin
     width: parent.width
     height: parent.height
     Rectangle{
         anchors.fill: parent
         color: "#041B3B"

         Rectangle{
             id: recCenter
             anchors.centerIn: parent
             height: parent.height*0.8
             width: parent.width*0.35
             color: "#D9D9D9"

             Rectangle{
                 id: recIconBase
                 anchors.horizontalCenter: parent.horizontalCenter
                 anchors.bottom: columnTop.top
                 height: parent.height*0.3
                 width: parent.width
                 color: "transparent"
                 Image {
                     id: dateBasePng
                     anchors.horizontalCenter: parent.horizontalCenter
                     anchors.verticalCenter: parent.verticalCenter
                     source: "Icon/baseBlack.png"

                 }
             }
             Column{
                 id: columnTop
                 anchors.centerIn: parent
                 spacing: parent.height*0.01
                // width: parent.width*0.5
                 TextField{
                     id: fieldName
                     width: recCenter.width*0.7
                     placeholderText: "User Name"
                     horizontalAlignment: TextInput.AlignHCenter
                     font.family: "Roboto"
                     font.pixelSize: 20
                     font.bold: true
                 }

                 TextField{
                     id: fieldSenha
                     width: recCenter.width*0.7
                     placeholderText: "Password"
                     horizontalAlignment: TextInput.AlignHCenter
                     font.family: "Roboto"
                     font.pixelSize: 20
                     font.bold: true
                     echoMode: TextInput.Password
                     //bottomInset: true

                 }
                 Rectangle{
                     id: recTextLink
                     anchors.horizontalCenter: columnTop.horizontalCenter
                     height: fieldSenha.height*0.4
                     width: fieldSenha.width
                     color: "Transparent"
                     Label {
                         id: textForgot
                         text: qsTr("Forgot your Password?")
                         color: Material.accent
                         font.family: "Roboto"
                         anchors.horizontalCenter: parent.horizontalCenter
                         anchors.verticalCenter: parent.verticalCenter
                         font.pixelSize: parent.height*0.6

                     }
                 }
                 Button{
                    id: buttonLogin
                    width: recCenter.width*0.7
                    contentItem: Label{
                        text: "Login"
                        font.family: "Roboto"
                        font.pixelSize: 20
                        color: "#D9D9D9"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Material.background: Material.accent

                 }
                 Button{
                    id: buttonCreatAc
                    width: recCenter.width*0.7
                    contentItem: Label{
                        text: "Creat Account"
                        font.family: "Roboto"
                        font.pixelSize: 20
                        color: "#D9D9D9"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Material.background: Material.accent

                 }
             }


             /*
             Rectangle{
                 id: recIconBase
                 anchors.horizontalCenter: parent.horizontalCenter
                 height: parent.height*0.3
                 width: parent.width
                 color: "transparent"
                 Image {
                     id: dateBasePng
                     anchors.horizontalCenter: parent.horizontalCenter
                     anchors.verticalCenter: parent.verticalCenter
                     source: "Icon/baseBlack.png"

                 }
             }
             Rectangle{
                 id: recFieldRec
                 anchors.horizontalCenter: parent.horizontalCenter
                 anchors.top: recIconBase.bottom
                 width: parent.width
                 height: parent.height*0.7
                 color: "transparent"

                 TextField{
                     id: fieldName
                     anchors.horizontalCenter: parent.horizontalCenter
                     anchors.top: parent.top
                     anchors.topMargin: parent.height*0.1
                     width: parent.width*0.7
                     placeholderText: "User Name"
                     horizontalAlignment: TextInput.AlignHCenter
                     font.family: "Roboto"
                     font.pixelSize: 20
                     font.bold: true
                 }
                 TextField{
                     id: fieldSenha
                     anchors.horizontalCenter: parent.horizontalCenter
                     anchors.top: fieldName.bottom
                     anchors.topMargin: parent.height*0.08
                     width: parent.width*0.7
                     placeholderText: "Password"
                     horizontalAlignment: TextInput.AlignHCenter
                     font.family: "Roboto"
                     font.pixelSize: 20
                     font.bold: true
                     //bottomInset: true
                 }
                 Rectangle{
                     id: recTextLink
                     anchors.horizontalCenter: parent.horizontalCenter
                     anchors.top: fieldSenha.bottom
                     anchors.topMargin: parent.height*0.03
                     height: fieldSenha.height*0.4
                     width: fieldSenha.width
                     color: "Transparent"
                     Label {
                         id: textForgot
                         text: qsTr("Forgot your Password?")
                         color: Material.accent
                         anchors.centerIn: parent
                         font.family: "Roboto"
                         font.pixelSize: 15

                     }
                 }
                 Button{
                    id: buttonLogin
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: recTextLink.bottom
                    width: parent.width*0.7
                    contentItem: Label{
                        text: "Login"
                        font.family: "Roboto"
                        font.pixelSize: 20
                        color: "#D9D9D9"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Material.background: Material.accent

                 }
                 Button{
                    id: buttonCreatAc
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: buttonLogin.bottom
                    width: parent.width*0.7
                    contentItem: Label{
                        text: "Creat Account"
                        font.family: "Roboto"
                        font.pixelSize: 20
                        color: "#D9D9D9"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Material.background: Material.accent

                 }
             }*/
         }
     }
}
