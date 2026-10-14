package lab.lab2.zad1;

public class Main {
    public static void main(String[] args) {

        Book book1 = new Book("Под игото", "Иван Вазов", 1894);
        Book book2 = new Book("1984", "Джордж Оруел", 1949);
        
        book1.printInfo();
        book2.printInfo();
    }
}