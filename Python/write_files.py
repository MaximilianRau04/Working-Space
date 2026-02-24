
import os
import json
import csv

employee = {"name": "Spongebob",
             "age": 30,
             "job": "Cook"}

employees = [["Name", "Age", "Job"],
            ["Spongebob", 30, "Cook"],
            ["Patrick", 25, "Doctor"],
            ["Bart", 20, "Engineer"],
            ["Lisa", 25, "Teacher"]]

json_path = "resources/output.json"
csv_path = "resources/output.csv"

try:
    with open(file=json_path, mode="w") as f:
        json.dump(employee, f, indent=4)
        print("JSON written successfully.")
    with open(file=csv_path, mode="w") as f:
        writer = csv.writer(f)
        for row in employees:
            writer.writerow(row)
        print("CSV written successfully.")
except Exception as e:
    print(f"An error occurred: {e}")

if os.path.exists(json_path):
    print(f"The location {json_path} exists")

    if os.path.isfile(json_path):
        print(f"The location {json_path} is a file")
    elif os.path.isdir(json_path):
        print(f"The location {json_path} is a directory")

else:
    print(f"The location {json_path} does not exist")

