#include <stdio.h>
#include <string.h>

// Structure to store Employee Information
struct Employee {
    int id;
    char name[100];
    char job_title[100];
    char department[100];
};

// Structure to store Salary Information
struct Salary {
    float basic_salary;
    float overtime_hours;
    float allowances;
};

// Structure to store Tax Information
struct Tax {
    float tax_rate;
    float other_taxes;
};

// Function to input Employee Information
void inputEmployeeInfo(struct Employee *emp) {
    printf("Enter Employee ID: ");
    scanf("%d", &(emp->id));

    printf("Enter Employee Name: ");
    getchar();
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0';

    printf("Enter Employee Job Title: ");
    fgets(emp->job_title, sizeof(emp->job_title), stdin);
    emp->job_title[strcspn(emp->job_title, "\n")] = '\0';

    printf("Enter Employee Department: ");
    fgets(emp->department, sizeof(emp->department), stdin);
    emp->department[strcspn(emp->department, "\n")] = '\0';
}

// Function to input Salary Information
void inputSalaryInfo(struct Salary *sal) {
    printf("Enter Basic Salary: ");
    scanf("%f", &(sal->basic_salary));

    printf("Enter Overtime Hours: ");
    scanf("%f", &(sal->overtime_hours));

    printf("Enter Allowances: ");
    scanf("%f", &(sal->allowances));
}

// Function to input Tax Information
void inputTaxInfo(struct Tax *tax) {
    printf("Enter Tax Rate (in percentage): ");
    scanf("%f", &(tax->tax_rate));

    printf("Enter Other Taxes: ");
    scanf("%f", &(tax->other_taxes));
}

// Function to calculate Net Salary after Tax
float calculateNetSalary(struct Salary sal, struct Tax tax, float overtime_rate) {
    float gross_salary = sal.basic_salary + (sal.overtime_hours * overtime_rate) + sal.allowances;
    float tax_amount = (gross_salary * tax.tax_rate) / 100.0 + tax.other_taxes;
    return gross_salary - tax_amount;
}

int main() {
    // Define constants
    const float OVERTIME_RATE = 1.5;

    // Declare and initialize variables
    struct Employee emp;
    struct Salary sal;
    struct Tax tax;
    float net_salary;

    // Input Employee Information
    printf("===== Enter Employee Information =====\n");
    inputEmployeeInfo(&emp);

    // Input Salary Information
    printf("\n===== Enter Salary Information =====\n");
    inputSalaryInfo(&sal);

    // Input Tax Information
    printf("\n===== Enter Tax Information =====\n");
    inputTaxInfo(&tax);

    // Calculate Net Salary after Tax
    net_salary = calculateNetSalary(sal, tax, OVERTIME_RATE);

    // Display the Employee Payroll
    printf("\n===== Employee Payroll =====\n");
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Job Title: %s\n", emp.job_title);
    printf("Department: %s\n", emp.department);
    printf("Basic Salary: %.2f\n", sal.basic_salary);
    printf("Overtime Hours: %.2f\n", sal.overtime_hours);
    printf("Allowances: %.2f\n", sal.allowances);
    printf("Tax Rate: %.2f%%\n", tax.tax_rate);
    printf("Other Taxes: %.2f\n", tax.other_taxes);
    printf("Net Salary after Tax: %.2f\n", net_salary);

    return 0;
}