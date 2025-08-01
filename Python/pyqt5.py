import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QWidget, QVBoxLayout, QHBoxLayout, QGridLayout, QPushButton, QCheckBox, QRadioButton, QButtonGroup
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPixmap


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My GUI")
        self.setGeometry(500, 300, 500, 500)
        self.initUI()

        label = QLabel(self)
        label.setGeometry(0, 0, 100, 100)

        pixmap = QPixmap("Guts.jpeg")
        label.setPixmap(pixmap)
        label.setScaledContents(True)

        label.setGeometry(self.width() - label.width(), self.height() - label.height(), label.width(), label.height())

    def initUI(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        self.button = QPushButton("Click me", self)
        self.button.setGeometry(150, 100, 200, 100)
        self.button.setStyleSheet("font-size: 30px;")
        self.button.clicked.connect(self.on_click)

        self.label = QLabel("Hello", self)
        self.label.setGeometry(150, 300, 200, 100)
        self.label.setStyleSheet("font-size: 50px;")

        self.checkbox = QCheckBox("Do you like food?", self)
        self.checkbox.setStyleSheet("font-size: 30px;"
                                    "font-family: arial;")
        self.checkbox.setGeometry(10, 0, 500, 100)
        self.checkbox.stateChanged.connect(self.checkbox_changed)

        self.radio1 = QRadioButton("Visa", self)
        self.radio2 = QRadioButton("Mastercard", self)
        self.radio3 = QRadioButton("Gift Card", self)

    def on_click(self):
        print("Button clicked")
        self.button.setText("Clicked")
        self.label.setText("Label text")

    def checkbox_changed(self, state):
        if state == Qt.Checked:
            print("You like food")
        else:
            print("You don't like food")

def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
