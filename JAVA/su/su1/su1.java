package su1;
import java.util.Scanner;

// 1
class Student {
    String name;
    int age;
    double grade;

    public void printInfo() {
        System.out.println("Студент: " + name + ", Възраст: " + age + ", Оценка: " + grade);
    }
}
// 4
class NumberAnalyzer {
    public int findMax(int[] numbers) {
        int max = numbers[0];
        for (int num : numbers) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
}
// 5
class Calculator {
    public int calculate(int a, int b) {
        return a + b;
    }

    public double calculate(double a, double b) {
        return a + b;
    }

    public int calculate(int a, int b, int c) {
        return a + b + c;
    }
}

public class su1 {

    // 2
    public static int findSum(int[] numbers) {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Student student1 = new Student();
        System.out.print("Въведете име на първия студент: ");
        student1.name = scanner.nextLine();
        System.out.print("Въведете възраст: ");
        student1.age = scanner.nextInt();
        System.out.print("Въведете оценка: ");
        student1.grade = scanner.nextDouble();
        scanner.nextLine(); 

        Student student2 = new Student();
        System.out.print("Въведете име на втория студент: ");
        student2.name = scanner.nextLine();
        System.out.print("Въведете възраст: ");
        student2.age = scanner.nextInt();
        System.out.print("Въведете оценка: ");
        student2.grade = scanner.nextDouble();

        student1.printInfo();
        student2.printInfo();


        int[] numbers = new int[10];
        System.out.println("Въведете 10 цели числа:");
        for (int i = 0; i < 10; i++) {
            System.out.print("Число " + (i + 1) + ": ");
            numbers[i] = scanner.nextInt();
        }
        int sum = findSum(numbers);
        System.out.println("Сумата на 10-те елемента е: " + sum);

        int[] numbers8 = new int[8];
        System.out.println("Въведете 8 цели числа:");
        for (int i = 0; i < 8; i++) {
            System.out.print("Число " + (i + 1) + ": ");
            numbers8[i] = scanner.nextInt();
        }
        
        NumberAnalyzer analyzer = new NumberAnalyzer();
        int max = analyzer.findMax(numbers8);
        System.out.println("Най-голямото число в масива е: " + max);


        Calculator calc = new Calculator();
        
        System.out.print("Въведете две цели числа за събиране: ");
        int int1 = scanner.nextInt();
        int int2 = scanner.nextInt();
        
        System.out.print("Въведете две реални (десетични) числа за събиране: ");
        double double1 = scanner.nextDouble();
        double double2 = scanner.nextDouble();
        
        System.out.print("Въведете три цели числа за събиране: ");
        int int3 = scanner.nextInt();
        int int4 = scanner.nextInt();
        int int5 = scanner.nextInt();

        System.out.println("Сума на 2 цели числа: " + calc.calculate(int1, int2));
        System.out.println("Сума на 2 реални числа: " + calc.calculate(double1, double2));
        System.out.println("Сума на 3 цели числа: " + calc.calculate(int3, int4, int5));

        scanner.close();
    }
}