# -*- coding:utf-8 -*-

def isPay(pay_down, current_savings, r, month_salary, portion_saved, semi_annual_raise):
    months = 0
    while current_savings < pay_down - 100:
        current_savings += current_savings * r / 12 + month_salary * portion_saved
        months += 1
        if months != 1 and months % 6 == 1:
            month_salary *= (1 + semi_annual_raise)
    return months


annual_salary = int(input("Enter the starting salary: "))
total_cost = 1000000
semi_annual_raise = .07
portion_down_payment = 0.25
r = 0.04
month_salary = annual_salary / 12
months = 36
pay_down = total_cost * portion_down_payment 

left, right = 0, 10000
count = 0

while left < right:
    mid = left + ((right - left) // 2)
    count += 1
    if isPay(pay_down, 0, r, month_salary, float(mid)/10000, semi_annual_raise) > months:
        left = int(mid) + 1
    else:
        right = int(mid)

if isPay(pay_down, 0, r, month_salary, float(left)/10000, semi_annual_raise) > months:
    print("It is not possible to pay the down payment in three years")
else:
    print("Best savings rate:", float(left)/10000)
    print("Steps in bisection search:", count)

