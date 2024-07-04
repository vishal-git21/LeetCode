
class Employee {
    private double salary;

    public Employee(double salary) {
        this.salary = salary;
    }

    public void work() {
        System.out.println("Employee is performing regular tasks.");
    }

    public double getSalary() {
        return salary;
    }
}

class HRManager extends Employee {
    public HRManager(double salary) {
        super(salary);
    }

    @Override
    public void work() {
        System.out.println("HR Manager is managing human resources.");
    }

    public void addEmployee() {
        System.out.println("HR Manager is adding a new employee.");
    }
}

public class EmployeeDemo {
    public static void main(String[] args) {
        Employee employee = new Employee(50000);
        System.out.println("Employee's Salary: $" + employee.getSalary());
        employee.work();
        System.out.println();
        HRManager hrManager = new HRManager(70000);
        System.out.println("HR Manager's Salary: $" + hrManager.getSalary());
        hrManager.work();
        hrManager.addEmployee();
    }
}