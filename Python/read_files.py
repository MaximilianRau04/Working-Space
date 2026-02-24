
import json
import csv

file_path = "resources/output.csv"

try:
    with open(file_path, "r") as file:
        content = csv.reader(file)
        for line in content:
            print(line)
except FileNotFoundError:
    print(f"The file {file_path} does not exist.")
except PermissionError:
    print(f"You do not have permission to read the file {file_path}.")