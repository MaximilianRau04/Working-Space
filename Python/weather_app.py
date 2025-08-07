import sys
from urllib.error import HTTPError

import requests
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QLineEdit, QVBoxLayout, QMessageBox
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt

class WeatherApp(QWidget):
    def __init__(self):
        super().__init__()
        self.city_label = QLabel("Enter city name", self)
        self.city_input = QLineEdit(self)
        self.get_weather_button = QPushButton("Get Weather", self)
        self.temperature_label = QLabel(self)
        self.emoji_label = QLabel(self)
        self.description_label = QLabel(self)
        self.font = QFont("Noto Color Emoji", 24)
        self.initUI()

    def initUI(self):
        self.setWindowTitle("Weather App")
        self.emoji_label.setFont(self.font)
        self.setFixedSize(400, 500)

        vbox = QVBoxLayout()
        vbox.addWidget(self.city_label, alignment=Qt.AlignCenter)
        vbox.addWidget(self.city_input, alignment=Qt.AlignCenter)
        vbox.addWidget(self.get_weather_button, alignment=Qt.AlignCenter)
        vbox.addWidget(self.temperature_label, alignment=Qt.AlignCenter)
        vbox.addWidget(self.emoji_label, alignment=Qt.AlignCenter)
        vbox.addWidget(self.description_label, alignment=Qt.AlignCenter)

        self.setLayout(vbox)

        self.city_label.setObjectName("city_label")
        self.city_input.setObjectName("city_input")
        self.get_weather_button.setObjectName("get_weather_button")
        self.temperature_label.setObjectName("temperature_label")
        self.emoji_label.setObjectName("emoji_label")
        self.description_label.setObjectName("description_label")

        self.city_input.setStyleSheet("width: 300px;")

        self.setStyleSheet("""
            QLabel, QPushButton {
                font-family: calibri;
            }
            QLabel#city_label {
                font-size: 40px;   
                font-style: italic;
            }
            QLineEdit#city_input {
                font-size: 30px;
            }
            QPushButton#get_weather_button {
                font-size: 30px;
                font-weight: bold;
            }
            QLabel#temperature_label {
                font-size: 75px;
                font-weight: bold;
            } 
            QLabel#emoji_label {
                font-size: 60px;
                font-family: Segoe UI emoji;
            }
            QLabel#description_label {
                font-size: 50px;
            }       
        """)

        self.get_weather_button.clicked.connect(self.get_weather)

    def get_weather(self):

        api_key = "6340128d4b749c583e2fb18893d4a932"
        city = self.city_input.text()
        url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}"

        try:
            response = requests.get(url)
            response.raise_for_status()
            data = response.json()

            if data["cod"] == 200:
                self.display_weather(data)

        except requests.exceptions.HTTPError as e:
            match response.status_code:
                case 400:
                    self.display_error("Bad request: \nplease check your input")
                case 401:
                    self.display_error("Unauthorized: \nInvalid api key")
                case 403:
                    self.display_error("Forbidden: \nAccess denied")
                case 404:
                    self.display_error("Not Found: \nCity not found")
                case 500:
                    self.display_error("Internal Server error: \nplease try again later")
                case 502:
                    self.display_error("Bad Gateway: \ninvalid response from server")
                case 503:
                    self.display_error("Service unavailable: \nServer is down currently")
                case 504:
                    self.display_error("Gateway Timeout: \nNo response from the server")
                case _:
                    self.display_error(f"HTTP error occured: \n{e}")

        except requests.exceptions.ConnectionError:
            print("Connection error\nCheck your internet connection")

        except requests.exceptions.Timeout:
            print("Timeout error\nThe request timed out")

        except requests.exceptions.TooManyRedirects:
            print("Too many Redirects\nCheck the URL")

        except requests.exceptions.RequestException as e:
            print(f"Request Error: {e}")

    def display_error(self, message):
        self.temperature_label.setStyleSheet("font-size: 30px")
        self.temperature_label.setText(message)
        self.emoji_label.clear()
        self.description_label.clear()

    def display_weather(self, data):
        self.temperature_label.setStyleSheet("font-size: 75px")
        temperature_k = data["main"]["temp"]
        temperature_c = temperature_k - 273.15
        weather_id = data["weather"][0]["id"]
        weather_description = data["weather"][0]["description"]

        self.temperature_label.setText(f"{temperature_c:.1f}°C")
        self.emoji_label.setText(self.get_weather_emoji(weather_id))
        self.description_label.setText(weather_description)

    @staticmethod
    def get_weather_emoji(weather_id):
        if 200 <= weather_id < 232:
            return "⛈️"
        elif 300 <= weather_id < 350:
            return "🌦"
        elif 500 <= weather_id < 531:
            return "🌧️"
        elif 600 <= weather_id < 622:
            return "❄️"
        elif 701 <= weather_id < 741:
            return "🌫️"
        elif weather_id == 762:
            return "🌋"
        elif weather_id == 771:
            return "💨"
        elif weather_id == 781:
            return "🌪"
        elif weather_id == 800:
            return "☀️"
        elif 801 <= weather_id < 804:
            return "☁️"
        else:
            return "❓"


if __name__ == "__main__":
    app = QApplication(sys.argv)
    weather_app = WeatherApp()
    weather_app.show()
    sys.exit(app.exec_())