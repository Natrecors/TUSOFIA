class Employee:
    def __init__(self, name, age, salary):
        self.name = name
        self.age = age
        self.salary = salary

    def get_employee_info(self):
        return f"Име: {self.name}, Възраст: {self.age}, Заплата: {self.salary}"

class Manager(Employee):
    def __init__(self, name, age, salary, department):
        super().__init__(name, age, salary)
        self.department = department

    def get_employee_info(self):
        base_info = super().get_employee_info()
        return f"{base_info}, Отдел: {self.department}"

class SalesPerson(Employee):
    def __init__(self, name, age, salary, sales_target):
        super().__init__(name, age, salary)
        self.sales_target = sales_target

    def get_employee_info(self):
        base_info = super().get_employee_info()
        return f"{base_info}, Цел за продажби: {self.sales_target}"



def add_employee(employees, name, age, salary):
    new_emp = Employee(name, age, salary)
    employees.append(new_emp)

def add_manager(employees, name, age, salary, department):
    new_manager = Manager(name, age, salary, department)
    employees.append(new_manager)

def add_salesperson(employees, name, age, salary, sales_target):
    new_sales = SalesPerson(name, age, salary, sales_target)
    employees.append(new_sales)
def print_employee_info(employees, employee_type=None):
    print("\nИнформация за всички работници:\n")
    for emp in employees:
        print(emp.get_employee_info())

def check_manager_age(employees):
    print("\nИма поне един мениджър с възраст над 50 години:\n")
    found = False
    for emp in employees:
        if isinstance(emp, Manager) and emp.age > 50:
            print(emp.get_employee_info())
            found = True
    if not found:
        print("Няма открити мениджъри над 50 години.")

def check_salesperson_sales(employees):
    print("\nИма поне един продавач с продажби над 100 000 лева:\n")
    found = False
    for emp in employees:
        if isinstance(emp, SalesPerson) and emp.sales_target > 100000:
            print(emp.get_employee_info())
            found = True
    if not found:
        print("Няма открити продавачи с такава цел.")


def main():
    employees_list = []
    
    try:
        count = int(input("Въведете броя на работниците: "))
    except ValueError:
        print("Моля въведете цяло число.")
        return

    for i in range(count):
        print(f"\n--- Въвеждане на данни за работник {i+1} ---")
        
        
        while True:
            etype = input("Въведете типа на работника (employee, manager, salesperson): ").strip().lower()
            if etype in ["employee", "manager", "salesperson"]:
                break 
            else:
                print("ГРЕШКА: Невалиден тип! Моля напишете точно: employee, manager или salesperson")
        # -----------------------------------

        name = input("Въведете името на работника: ")
        
       
        while True:
            try:
                age = int(input("Въведете възрастта на работника: "))
                break
            except ValueError:
                print("Моля въведете цяло число за възраст.")

       
        while True:
            try:
                salary = float(input("Въведете заплатата на работника: "))
                break
            except ValueError:
                print("Моля въведете число за заплата.")

        if etype == "manager":
            dept = input("Въведете отдела на мениджъра: ")
            add_manager(employees_list, name, age, salary, dept)
            
        elif etype == "salesperson":
            while True:
                try:
                    raw_target = input("Въведете целта за продажби на продавача: ")
                    raw_target = raw_target.replace(",", ".")
                    target = float(raw_target)
                    break 
                except ValueError:
                    print("Грешка! Моля въведете валидно число.")
            
            add_salesperson(employees_list, name, age, salary, target)
            
        else:
            
            add_employee(employees_list, name, age, salary)

    print_employee_info(employees_list)
    check_manager_age(employees_list)
    check_salesperson_sales(employees_list)

if __name__ == "__main__":
    main()
