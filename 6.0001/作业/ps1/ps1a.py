# #-*- coding:utf-8 -*-

annual_salary = int(input("Enter your annual salary: "))
portion_saved = float(input("Enter the percent of your salary to save, as a decimal: "))
total_cost = int(input("Enter the cost of your dream home: "))

portion_down_payment = 0.25
r = 0.04
month_salary = annual_salary / 12

down_payment = portion_down_payment * total_cost
months = 0
current_savings = 0

while current_savings < down_payment:
    current_savings += current_savings * r / 12 + month_salary * portion_saved
    months += 1

print("Number of months: ", months)


