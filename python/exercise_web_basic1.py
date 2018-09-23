#!/usr/bin/env
import sys
import datetime
import re
import math
import os


"""
Exercises based on the follow website:
   https://www.w3resource.com/python-exercises/

this exercite is the 'Basic (Part-I)'
   https://www.w3resource.com/python-exercises/python-basic-exercises.php
"""
class Exercise:
    def ex2(self):
        print(sys.version)

    def ex3(self):
        print("Current time:")
        print(datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

    def ex4_circle_area(self):
        radius = float(input("Input the radius of circle: "))
        area = math.pi * (radius **2)
        print("The area of circle is:", area)

    def ex5_revert_name(self):
        full_name = str(input("Type you first and last name: "))
        reverse_name = ""
        for character in reversed(full_name): reverse_name += character

        print(reverse_name)

    def ex6_generate_from_comma(self):
        number_separated_by_comma = str(input("Type a list of numbers separated with comma: "))
        number_separated_by_comma = re.split(r',\s*', number_separated_by_comma)
        print(number_separated_by_comma, type(number_separated_by_comma))
        number_tuple = tuple(number_separated_by_comma)
        print(number_tuple, type(number_tuple))
        for i in range(len(number_separated_by_comma)):
            print(i, number_separated_by_comma[i], number_tuple[i])

    def ex7_file_extension(self):
        file_path = input("Input the file name with extension: ")
        file_name, file_extension = os.path.splitext(file_path)
        print(file_name, file_extension)

    def ex8(self):
        color_list = ["Red","Green","White" ,"Black"]
        print("First element:", color_list[0])
        print("Last element:", color_list[-1])

    def ex10(self):
        number = input("Type a integer number: ")
        print(int(number) + int(number + number) + int(number + number + number))

    def _generated_method(self):
        object_attributes = dir(self)
        regexp_compiler = re.compile(r'^ex(\d+)')

        number_name_exercises = ((int(number), str(name)) for number, name in
            map(lambda att: (regexp_compiler.search(att).group(1), att),
                filter(lambda att: regexp_compiler.match(att), object_attributes)))
        print(number_name_exercises)
        return number_name_exercises

    def _execute_method(self, method_name):
        execute = "self." + method_name + "()"
        print("executing:", execute)
        exec(execute)

    def execute_all(self):
        for method in self._generated_method():
            self._execute_method(method[1])

    def execute_first(self):
        pass

    def execute_last(self):
        max_number_name_method = max(self._generated_method(), key=lambda item: item[0])
        print(max_number_name_method)

        self._execute_method(max_number_name_method[1])

exercise = Exercise()
exercise.execute_last()
