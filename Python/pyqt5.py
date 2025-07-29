import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QWidget, QVBoxLayout, QHBoxLayout, QGridLayout
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
        label.setGeometry(0, 0, 250, 250)

        pixmap = QPixmap("Guts.jpeg")
        label.setPixmap(pixmap)
        label.setScaledContents(True)

        label.setGeometry(self.width() - label.width(), self.height() - label.height(), label.width(), label.height())

    def initUI(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        label1 = QLabel("#1",self)
        label2 = QLabel("#2",self)
        label3 = QLabel("#3",self)
        label4 = QLabel("#4",self)
        label5 = QLabel("#5",self)

        label1.setStyleSheet("background-color:red;")
        label2.setStyleSheet("background-color:blue;")
        label3.setStyleSheet("background-color:green;")
        label4.setStyleSheet("background-color:yellow;")
        label5.setStyleSheet("background-color:purple;")

        grid = QGridLayout()

        grid.addWidget(label1, 0, 0)
        grid.addWidget(label2, 0, 1)
        grid.addWidget(label3, 1, 0)
        grid.addWidget(label4, 1, 1)
        grid.addWidget(label5, 2, 0)

        central_widget.setLayout(grid)

        # label = QLabel("Hello", self)
        # label.setFont(QFont("Arial", 40))
        # label.setGeometry(0, 0, 500, 100)
        # label.setStyleSheet("color: black;"
        #                    "background-color: lightblue;"
        #                    "font-weight: bold;"
        #                    "font-style: italic;"
        #                    "font-decoration: underline;")

        # label.setAlignment(Qt.AlignCenter)


def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
