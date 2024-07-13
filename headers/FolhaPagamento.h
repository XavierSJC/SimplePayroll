#pragma once

typedef enum EnumEmployee {
	CLT,
	PJ
} EmployeeType;

typedef struct Employee {
	char* name;
	int signedContracts;
	float commisionByContract;
} TypeEmployee;

typedef struct EmployeeCLT {
	TypeEmployee employee;
	float salary;
}TypeEmployeeCLT;

typedef struct EmployeePJ {
	TypeEmployee employee;
	float valueByHour;
	float hoursWorked;

}TypeEmployeePJ;

typedef struct ListEmployees {
	void* employee;
	EmployeeType typeEmployee;
	struct ListEmployees* nextEmployee;
} TypeListEmployee;

void addEmployeeToList(void* employee, EmployeeType type);
void addCLT(char* name, float salary, int signedContracts, float commisionByContract);
void addPJ(char* name, float valueByHour, float hoursWorked, int signedContracts, float commisionByContract);
float calculeEmployeeCLT(TypeEmployeeCLT* employee);
float calculeEmployeePJ(TypeEmployeePJ* employee);
float calculeEmployeeByName(char* name);
float calculeEmployee(TypeListEmployee* node);
float calculeMonth();
float calculeTypeEmployee(TypeEmployee* employee);
TypeEmployee createEmployee(char* name, int signedContracts, float commisionByContract);
char* getEmployeerName(TypeListEmployee* node);