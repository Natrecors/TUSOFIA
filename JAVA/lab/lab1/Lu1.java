package lab.lab1;
import java.util.Scanner;

public class Lu1 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Въведете брой студенти (n): ");
        int n = Integer.parseInt(scanner.nextLine());

        String[] facultyNumbers = new String[n];
        int[] grades = new int[n];

        readResults(facultyNumbers, grades);
        
        System.out.println("\n Въведени резултати");
        printResults(facultyNumbers, grades);
        
        System.out.println("\n Статистика");
        
        int failedCount = countFailedStudents(grades);
        System.out.println("Брой скъсани студенти: " + failedCount);
        if (failedCount > 0) {
            printFailedStudents(facultyNumbers, grades);
        }
        

        if (n > 0) {
            double averageGrade = calculateAverageGrade(grades);
            System.out.printf("Среден успех на групата: %.2f\n", averageGrade);
        }
        
        if (n > 0) {
            printTopStudents(facultyNumbers, grades);
        }
        
        scanner.close();
    }

    public static void readResults(String[] facultyNumbers, int[] grades) {
        System.out.println("Въведете Ф№ и оценка за всеки студент:");
        for (int i = 0; i < facultyNumbers.length; i++) {
            String[] input = scanner.nextLine().split(" ");
            facultyNumbers[i] = input[0];
            grades[i] = Integer.parseInt(input[1]);
        }
    }

    public static void printResults(String[] facultyNumbers, int[] grades) {
        for (int i = 0; i < facultyNumbers.length; i++) {
            System.out.println("Ф№: " + facultyNumbers[i] + ", оценка: " + grades[i]);
        }
    }

    public static int countFailedStudents(int[] grades) {
        int count = 0;
        for (int i = 0; i < grades.length; i++) {
            if (grades[i] == 2) {
                count++;
            }
        }
        return count;
    }

    public static void printFailedStudents(String[] facultyNumbers, int[] grades) {
        System.out.println("Факултетни номера на скъсаните студенти:");
        for (int i = 0; i < grades.length; i++) {
            if (grades[i] == 2) {
                System.out.println(facultyNumbers[i]);
            }
        }
    }

    public static double calculateAverageGrade(int[] grades) {
        double sum = 0;
        for (int i = 0; i < grades.length; i++) {
            sum += grades[i];
        }
        return sum / grades.length;
    }
    public static void printTopStudents(String[] facultyNumbers, int[] grades) {
        int maxGrade = grades[0]; 
        for (int i = 1; i < grades.length; i++) {
            if (grades[i] > maxGrade) {
                maxGrade = grades[i];
            }
        }
        
        System.out.println("Най-висока оценка: " + maxGrade);
        System.out.print("Студенти с най-висока оценка: ");
        
        
        String separator = ""; 
        for (int i = 0; i < grades.length; i++) {
            if (grades[i] == maxGrade) {
                System.out.print(separator + facultyNumbers[i]);
                separator = ", ";
            }
        }
        System.out.println(); 
    }
}