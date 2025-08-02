import sys
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QLabel, QWidget, QVBoxLayout,
    QHBoxLayout, QGridLayout, QPushButton, QCheckBox,
    QRadioButton, QButtonGroup, QLineEdit
)
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My GUI")
        self.resize(600, 500)

        self.initUI()

    def initUI(self):
        # Main-Widget and Layout
        central_widget = QWidget()
        main_layout = QVBoxLayout()
        central_widget.setLayout(main_layout)
        self.setCentralWidget(central_widget)

        # Image
        self.image_label = QLabel()
        pixmap = QPixmap("Guts.jpeg")
        self.image_label.setPixmap(pixmap.scaled(100, 100, Qt.KeepAspectRatio, Qt.SmoothTransformation))
        self.image_label.setAlignment(Qt.AlignRight)
        main_layout.addWidget(self.image_label)

        # Buttons in one row
        button_layout = QHBoxLayout()
        self.button1 = QPushButton("#1")
        self.button2 = QPushButton("#2")
        self.button3 = QPushButton("#3")
        button_layout.addWidget(self.button1)
        button_layout.addWidget(self.button2)
        button_layout.addWidget(self.button3)
        main_layout.addLayout(button_layout)

        self.button1.setObjectName("button1")
        self.button2.setObjectName("button2")
        self.button3.setObjectName("button3")

        self.setStyleSheet("""
             QPushButton {
                 font-size: 20px;
                 font-family: arial;
                 padding: 10px 50px;
                 margin: 10px;
                 border: 2px solid;
                 border-radius: 10px;
             }
             QPushButton#button1 {
                background-color: #D93834
             }
             QPushButton#button2 {
                background-color: #62A667
             }
             QPushButton#button3 {
                background-color: #8FCAE7
             }
             QPushButton#button1:hover {
                background-color: #BC2E2C
             }
             QPushButton#button2:hover  {
                background-color: #408745
             }
             QPushButton#button3:hover  {
                background-color: #1981BA
             }         
        """)

        # Click Button + Label
        click_layout = QVBoxLayout()
        self.button = QPushButton("Click me")
        self.button.clicked.connect(self.on_click)

        self.label = QLabel("Hello")
        self.label.setStyleSheet("font-size: 20px;")
        self.label.setAlignment(Qt.AlignCenter)

        click_layout.addWidget(self.button, alignment=Qt.AlignCenter)
        click_layout.addWidget(self.label, alignment=Qt.AlignCenter)
        main_layout.addLayout(click_layout)

        # Checkbox
        self.checkbox = QCheckBox("Do you like food?")
        self.checkbox.setStyleSheet("font-size: 16px;")
        self.checkbox.stateChanged.connect(self.checkbox_changed)
        main_layout.addWidget(self.checkbox)

        # Radio Buttons in Grid
        radio_layout = QGridLayout()
        self.radio1 = QRadioButton("Visa")
        self.radio2 = QRadioButton("Mastercard")
        self.radio3 = QRadioButton("Gift Card")
        self.radio4 = QRadioButton("In-Store")
        self.radio5 = QRadioButton("Online")

        radios = [self.radio1, self.radio2, self.radio3, self.radio4, self.radio5]
        for i, rb in enumerate(radios):
            radio_layout.addWidget(rb, i // 2, i % 2)

        self.button_group1 = QButtonGroup(self)
        self.button_group2 = QButtonGroup(self)
        self.button_group1.addButton(self.radio1)
        self.button_group1.addButton(self.radio2)
        self.button_group1.addButton(self.radio3)
        self.button_group2.addButton(self.radio4)
        self.button_group2.addButton(self.radio5)

        for rb in radios:
            rb.toggled.connect(self.radio_button_changed)

        main_layout.addLayout(radio_layout)

        # text field + submit
        input_layout = QHBoxLayout()
        self.line_edit = QLineEdit()
        self.line_edit.setPlaceholderText("Enter your name")
        self.line_edit.setStyleSheet("font-size: 16px;")
        self.Line_button = QPushButton("Submit")
        self.Line_button.setStyleSheet("font-size: 16px;")
        self.Line_button.clicked.connect(self.submit)

        input_layout.addWidget(self.line_edit)
        input_layout.addWidget(self.Line_button)
        main_layout.addLayout(input_layout)

    # methods
    def radio_button_changed(self):
        radio_button = self.sender()
        if radio_button.isChecked():
            print(f"{radio_button.text()} is selected")

    def on_click(self):
        print("Button clicked")
        self.button.setText("Clicked")
        self.label.setText("Goodbye")

    def checkbox_changed(self, state):
        print("You like food" if state == Qt.Checked else "You don't like food")

    def submit(self):
        text = self.line_edit.text()
        print(f"Hello {text}")


def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
