class Employee {
    private String name;
    private double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() { 
        return name; 
    }
    public void setName(String name) {
        this.name = name; 
    }

    public double getSalary() {
        return salary; 
    }
    public void setSalary(double salary) {
        this.salary = salary; 
    }

    public void printInfo() {
        System.out.println("Име: " + name + ", Заплата: " + salary);
    }
}

class Programmer extends Employee {
    private String programmingLanguage;

    public Programmer(String name, double salary, String programmingLanguage) {
        super(name, salary);
        this.programmingLanguage = programmingLanguage;
    }

    public String getProgrammingLanguage() {
        return programmingLanguage; 
    }
    public void setProgrammingLanguage(String programmingLanguage) {
        this.programmingLanguage = programmingLanguage; 
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Език за програмиране: " + programmingLanguage);
    }

    public void writeCode() {
        System.out.println(getName() + " пише код на " + programmingLanguage + ".");
    }
}

public class Mainzad4 {
    public static void main(String[] args) {
        Employee emp = new Employee("Димитър", 1500);
        Programmer p1 = new Programmer("Иван", 3500, "Java");
        Programmer p2 = new Programmer("Петър", 4200, "C#");

        System.out.println(" Служител");
        emp.printInfo();

        System.out.println("\n Програмист 1");
        p1.printInfo();
        p1.writeCode();

        System.out.println("\n Програмист 2");
        p2.printInfo();
        p2.writeCode();
    }
}