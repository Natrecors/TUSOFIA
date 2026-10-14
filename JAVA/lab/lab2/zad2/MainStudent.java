package lab.lab2.zad2;

class Student {
    String facultyNumber;
    String name;
    double averageGrade;

    public Student(String facultyNumber, String name, double averageGrade) {
        this.facultyNumber = facultyNumber;
        this.name = name;
        this.averageGrade = averageGrade;
    }

    public String getFacultyNumber() {
        return facultyNumber;
    }

    public void setFacultyNumber(String facultyNumber) {
        this.facultyNumber = facultyNumber;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getAverageGrade() {
        return averageGrade;
    }

    public void setAverageGrade(double averageGrade) {
        this.averageGrade = averageGrade;
    }

    public void printInfo() {
        System.out.println("Фак. номер: " + facultyNumber + ", Име: " + name + ", Успех: " + averageGrade);
    }

    public boolean hasScholarship() {
        return averageGrade >= 5.50;
    }
}

public class MainStudent {
    public static void main(String[] args) {
        Student s1 = new Student("121223", "Иван Иванов", 5.60);
        Student s2 = new Student("121224", "Мария Петрова", 5.20);
        Student s3 = new Student("121225", "Георги Димитров", 6.00);

        Student[] students = {s1, s2, s3};

        for (Student s : students) {
            s.printInfo();
            System.out.println("Получава стипендия: " + s.hasScholarship());
            System.out.println();
        }
    }
}