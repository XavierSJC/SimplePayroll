#include "../headers/FolhaPagamento.h"
#include <stdlib.h>
#include <string.h>

TypeListEmployee* employees;

void addEmployeeToList(void* employee, EmployeeType type) {
	if (employees == NULL) {
		employees = malloc(sizeof(TypeListEmployee));
		employees->employee = employee;
		employees->typeEmployee = type;
		employees->nextEmployee = NULL;
		return;
	}

	TypeListEmployee* node = employees;
	while (node->nextEmployee != NULL) {
		node = node->nextEmployee;
	}
	
	node->nextEmployee = malloc(sizeof(TypeListEmployee));
	node->nextEmployee->employee = employee;
	node->nextEmployee->typeEmployee = type;
	node->nextEmployee->nextEmployee = NULL;
}

void addCLT(char* name, float salary, int signedContracts, float commisionByContract) {
	TypeEmployeeCLT* newEmployee = malloc(sizeof(TypeEmployeeCLT));
	newEmployee->employee = createEmployee(name, signedContracts, commisionByContract);
	newEmployee->salary = salary;

	addEmployeeToList(newEmployee, CLT);
}

void addPJ(char* name, float valueByHour, float hoursWorked, int signedContracts, float commisionByContract){
	TypeEmployeePJ* newEmployee = malloc(sizeof(TypeEmployeePJ));
	newEmployee->employee = createEmployee(name, signedContracts, commisionByContract);
	newEmployee->valueByHour = valueByHour;
	newEmployee->hoursWorked = hoursWorked;

	addEmployeeToList(newEmployee, PJ);
}

float calculeEmployeeCLT(TypeEmployeeCLT* employee)
{
	float sum = 0;
	sum += employee->salary;
	sum += calculeTypeEmployee(&employee->employee);

	return sum;
}

float calculeEmployeePJ(TypeEmployeePJ* employee)
{
	float sum = 0;
	sum += employee->hoursWorked * employee->valueByHour;
	sum += calculeTypeEmployee(&employee->employee);

	return sum;
}

float calculeEmployeeByName(char* name)
{
	TypeListEmployee* node = employees;
	
	while (node != NULL && strcmp(getEmployeerName(node), name) != 0) {
		node = node->nextEmployee;
	}

	if(node == NULL)
		return 0.0f;

	return calculeEmployee(node);
}

float calculeEmployee(TypeListEmployee* node)
{
	if (node == NULL)
		return 0.f;

	if (node->typeEmployee == CLT) {
		TypeEmployeeCLT* emp = (TypeEmployeeCLT*)node->employee;
		return calculeEmployeeCLT(emp);
	}

	if (node->typeEmployee == PJ) {
		TypeEmployeePJ* emp = (TypeEmployeePJ*)node->employee;
		return calculeEmployeePJ(emp);
	}
}

char* getEmployeerName(TypeListEmployee* node)
{
	if (node == NULL) {
		return NULL;
	}

	if (node->typeEmployee == CLT) {
		TypeEmployeeCLT* emp = (TypeEmployeeCLT*)node->employee;
		return emp->employee.name;
	}

	if (node->typeEmployee == PJ) {
		TypeEmployeePJ* emp = (TypeEmployeePJ*)node->employee;
		return emp->employee.name;
	}

	return NULL;
}

float calculeTypeEmployee(TypeEmployee* employee)
{
	return employee->commisionByContract * employee->signedContracts;
}

TypeEmployee createEmployee(char* name, int signedContracts, float commisionByContract)
{
	TypeEmployee* employee = malloc(sizeof(TypeEmployee));
	employee->name = name;
	employee->signedContracts = signedContracts;
	employee->commisionByContract = commisionByContract;
	return *employee;
}

float calculeMonth()
{
	TypeListEmployee* node = employees;
	float sum = 0;
	while (node != NULL) {
		sum += calculeEmployee(node);
		node = node->nextEmployee;
	}

	return sum;
}
