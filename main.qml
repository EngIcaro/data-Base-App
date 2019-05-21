import QtQuick 2.12
import QtQuick.Controls 2.12


ApplicationWindow {
    id: window
        visible: true
        width: 1420
        height: 780
        title: qsTr("Stack")
        FontLoader { id: fixedFont; name: "Roboto" }
        StackView {
            id: stackView
            initialItem: homeComponent
            anchors.fill: parent

            Component{
                id: loginComponent
                Login{}
            }

            Component{
                id: homeComponent
                Home{}
            }
        }

}
