import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    property var largura: [0.1, 0.3, 0.2, 0.2, 0.2]
    function changeColorRec(rec){
        if(rec === "rec1"){
            rec1.color = "#042B3B"
            rec2.color = rec3.color = rec4.color = "transparent"
        }
        else if(rec === "rec2"){
            rec2.color = "#042B3B"
            rec1.color = rec3.color = rec4.color = "transparent"
        }
        else if(rec === "rec3"){
            rec1.color = rec2.color = rec4.color = "transparent"
            rec3.color = "#042B3B"
        }
        else{
            rec1.color = rec2.color = rec3.color = "transparent"
            //rec4.color = "#929292"
            rec4.color = "#042B3B"
        }
    }


    Rectangle{
        id: recHome
        color: "#D9D9D9"
        anchors.fill: parent
        Rectangle{
            id: recFunctions
            anchors.top: parent.top; anchors.left: parent.left
            height: parent.height
            width: parent.width*0.15
            color: "#041B3B"
            gradient: Gradient{
                //orientation: Gradient.Horizontal
                GradientStop {position: 0.0; color: "#041B3B"}
                GradientStop {position: 1.0; color: "#03146c"}
            }
            Rectangle{
                id: recAdm
                height: parent.height*0.2; width: parent.width
                color: "transparent"
                anchors.top: parent.top
                Image {
                    id: imageMan
                    anchors.centerIn: parent
                    source: "Icon/man.png"
                }
                Label{
                    anchors.top: imageMan.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                   //anchors.topMargin: parent.height*0.1
                    text: qsTr("Administrador")
                    font.family: "Roboto"
                    color: "#D9D9D9"
                }
            }
            Rectangle{
                anchors.top: recAdm.bottom;anchors.topMargin: parent.height*0.05 ;anchors.bottom: parent.bottom
                width: parent.width
                color: "transparent"
                Column{
                    anchors.left: parent.left
                    Button{
                       Component.onCompleted: {
                           changeColorRec("rec1")
                       }
                       width: recFunctions.width
                       height: recFunctions.height*0.1
                       contentItem: Label{
                           text: "Banco"
                           font.family: "Roboto"
                           font.pixelSize: 20
                           color: "#D9D9D9"
                           verticalAlignment: Text.AlignVCenter
                           horizontalAlignment: Text.AlignHCenter
                       }
                       background: Rectangle{
                           id: rec1
                           color: "transparent"
                           Image {
                               anchors.left: parent.left
                               anchors.leftMargin: parent.width*0.06
                               anchors.verticalCenter: parent.verticalCenter
                               source: "Icon/base.png"
                           }
                       }
                       onClicked: {
                           changeColorRec("rec1")
                       }
                    }
                    Button{
                       width: recFunctions.width
                       height: recFunctions.height*0.1
                       contentItem: Label{
                           text: "Histórico"
                           font.family: "Roboto"
                           font.pixelSize: 20
                           color: "#D9D9D9"
                           verticalAlignment: Text.AlignVCenter
                           horizontalAlignment: Text.AlignHCenter
                       }
                       background: Rectangle{
                           id: rec2
                           color: "transparent"
                           Image {
                               anchors.left: parent.left
                               anchors.verticalCenter: parent.verticalCenter
                               source: "Icon/book.png"
                               height: parent.height*0.5
                               width: parent.width*0.15
                               anchors.leftMargin: parent.width*0.05

                         }
                       }
                       onClicked: {
                           changeColorRec("rec2")
                       }
                    }
                    Button{
                       width: recFunctions.width
                       height: recFunctions.height*0.1
                       contentItem: Label{
                           text: "Gráficos"
                           font.family: "Roboto"
                           font.pixelSize: 20
                           color: "#D9D9D9"
                           verticalAlignment: Text.AlignVCenter
                           horizontalAlignment: Text.AlignHCenter
                       }
                       background: Rectangle{
                           id: rec3
                           color: "transparent"
                           Image {
                               anchors.left: parent.left
                               anchors.leftMargin: parent.width*0.05 ;anchors.verticalCenter: parent.verticalCenter
                               height: parent.height*0.5; width: parent.width*0.15
                               source: "Icon/chart.png"
                           }
                       }
                       onClicked: {
                        changeColorRec("rec3")
                       }
                    }
                    Button{

                       width: recFunctions.width
                       height: recFunctions.height*0.1
                       contentItem: Label{
                           text: " Configurações"
                           font.family: "Roboto"
                           font.pixelSize: 20
                           color: "#D9D9D9"
                           verticalAlignment: Text.AlignVCenter
                           horizontalAlignment: Text.AlignHCenter
                       }
                       background: Rectangle{
                           id: rec4
                           color: "transparent"
//                           Image {
//                               anchors.left: parent.left
//                               source: "Icon/man.png"
//                           }
                           Image {
                               anchors.left: parent.left
                               anchors.leftMargin: parent.width*0.02 ;anchors.verticalCenter: parent.verticalCenter
                               height: parent.height*0.5; width: parent.width*0.15
                               source: "Icon/gear.png"
                           }
                       }
                       onClicked: {
                           changeColorRec("rec4")
                       }
                    }
                }
            }

        }
        Rectangle{
            id: recAttribute
            anchors.left: recFunctions.right; anchors.top: parent.top
            width: parent.width*0.85
            height: parent.height*0.1
            color: "#041B3B"
            TabBar{
                id: bat
                anchors.fill: parent
                background: Rectangle{
                    color:"transparent"
                    height: parent.height
                }

                TabButton{
                    text: qsTr("Mudar Tabela")
                    height: bat.height
//                    background: Rectangle{
//                        height: recAttribute.height
//                        color: "transparent"
//                    }

                }
                TabButton{
                    text: qsTr("Adicionar Produto")

                }
                TabButton{
                    text: qsTr("Remover Produto")

                }
            }

        }
        Rectangle{
            clip: true
            id: recMid
            anchors.left: recFunctions.right; anchors.top: recAttribute.bottom
            height: parent.height*0.9; width: parent.width*0.85
            color: "transparent"
            ListView {
                    id: tableProduct
                    anchors.fill: parent
                    contentWidth: headerItem.width
                    flickableDirection: Flickable.HorizontalAndVerticalFlick
                    header: Row {
                        spacing: 1
                        Repeater {
                            id: repeater
                            model: ["id", "nome", "valor", "tipo", "item"]
                            Label {
                                text: modelData
                                font.bold: true
                                font.pixelSize: 20
                                padding: 10
                                background: Rectangle { id: recLabel; color: "silver" }
                                width: recMid.width*largura[index]
                            }
                        }
                    }

                    model: sqlModel
                    delegate: Column {
                        id: delegate
                        property int row: index
                        spacing: 5
                        Row {
                            spacing: 1
                            ItemDelegate{
                                width: recMid.width*0.1
                                text: idProduto
                                onClicked: {
                                    console.log("ai pai")
                                    baseController.novoProduto("Executivo de porco","30.50","1", "executivos")
                                   // baseController.removerProduto(modelName.text, modelTipo.text)
                                    sqlModel.refresh()
                                    //baseController.removerProduto(modelData.name, modelData.tipo)
                                }
                            }
                            ItemDelegate{
                                id: modelName
                                width: recMid.width*0.3
                                text: nome
                            }
                            ItemDelegate{
                                width: recMid.width*0.2
                                text: valor

                            }
                            ItemDelegate{
                                id: modelTipo
                                width: recMid.width*0.2
                                text: tipo
                            }
                            ItemDelegate{
                                width: recMid.width*0.2
                                text: item

                            }
                        }
                        Rectangle {
                            color: "silver"
                            width: parent.width
                            height: 1
                        }
                    }

                    ScrollIndicator.horizontal: ScrollIndicator { }
                    ScrollIndicator.vertical: ScrollIndicator { }
                }
        }
    }
}
