class Vehicle {
    private String brand;
    private int year;

    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }

    public String getBrand(){ 
        return brand; 
    }
    public void setBrand(String brand){
        this.brand = brand; 
    }

    public int getYear(){
        return year; 
    }
    public void setYear(int year){
        this.year = year; 
    }

    public void printInfo() {
        System.out.println("Марка: " + brand + ", Година: " + year);
    }
}

class Car extends Vehicle {
    private int doors;

    public Car(String brand, int year, int doors) {
        super(brand, year);
        this.doors = doors;
    }

    public int getDoors() { 
        return doors; 
    }
    public void setDoors(int doors) {
        this.doors = doors; 
    }


    @Override
    public void printInfo() {
        super.printInfo(); 
        System.out.println("Брой врати: " + doors);
    }
}

public class MainVehicle {
    public static void main(String[] args) {
        Vehicle v = new Vehicle("Nissan", 2015);
        Car c1 = new Car("Toyota", 2018, 4);
        Car c2 = new Car("BMW", 2024, 4);

        System.out.println("Превозно средство");
        v.printInfo();
        
        System.out.println("\n Кола 1");
        c1.printInfo();
        
        System.out.println("\n Кола 2");
        c2.printInfo();
    }
}