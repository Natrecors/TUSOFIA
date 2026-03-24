# 1. Клас Person
class Person:
    def __init__(self, name, family, age, nationality):
        self.name = name
        self.family = family
        self.age = age
        self.nationality = nationality
    def print(self):
        print(f"Name: {self.name}, Family: {self.family}, Age: {self.age}, Nationality: {self.nationality}")

person1 = Person("Ivan", "Ivanov", 30, "Bulgarian")
person2 = Person("Maria", "Petrova", 25, "Bulgarian")
person1.print()
person2.print()


# 2. Клас Student
class Student(Person):
    def __init__(self, name, family, age, nationality, university, yearofstudy):
        super().__init__(name, family, age, nationality)
        self.university = university
        self.yearofstudy = yearofstudy
        
    def print(self):
        super().print()
        print(f"University: {self.university}, Year of Study: {self.yearofstudy}")

student1 = Student("Georgi", "Dimitrov", 20, "Bulgarian", "TU-Sofia", 2015)
student1.print()

# 3. Клас Lecturer
class Lecturer(Person):
    def __init__(self, name, family, age, nationality, university, experience):
        super().__init__(name, family, age, nationality)
        self.university = university
        self.experience = experience
        
    def print(self):
        super().print()
        print(f"University: {self.university}, Experience: {self.experience} years")

lecturer1 = Lecturer("Dragan", "Kolev", 45, "Bulgarian", "TU-Sofia", 20) 
lecturer1.print()