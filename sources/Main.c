#include "../headers/FolhaPagamento.h"
#include <stdio.h>

void test(float expectedResult, float actualResult, char* messageTest) {
	if (expectedResult == actualResult) {
		printf("PASSED: %s - Actual value: %f, expected value: %f\n\r", messageTest, actualResult, expectedResult);
	}else{
		printf("FAILED: %s - Actual value: %f, expected value: %f\n\r", messageTest, actualResult, expectedResult);
	}
}

void failedToCreateEmployee(char* nameEmployee) {
	printf("Failed to create employee %s\n\r", nameEmployee);
}

int main(){	
	float currentValue;
	char* nameEmployee;
	
	nameEmployee = "Joao";
	if (!addPJ(nameEmployee, 50, 100, 0, 0))
		failedToCreateEmployee(nameEmployee);
	currentValue = calculeEmployeeByName(nameEmployee);
	test(5000, currentValue, "Test salary of Joao");

	nameEmployee = "Marcela";
	if (!addCLT(nameEmployee, 3000, 10, 200))
		failedToCreateEmployee(nameEmployee);
	currentValue = calculeEmployeeByName(nameEmployee);
	test(5000, currentValue, "Test salary of Marcela");

	nameEmployee = "Joaquim";
	if (!addPJ(nameEmployee, 30, 180, 12, 200))
		failedToCreateEmployee(nameEmployee);
	currentValue = calculeEmployeeByName(nameEmployee);
	test(7800, currentValue, "Test salary of Joaquim");

	currentValue = calculeEmployeeByName("Employees don't registered");
	test(0, currentValue, "Test salary of Employees don't registered");

	currentValue = calculeMonth();
	test(17800, currentValue, "Test salary month");

	freeEmployees();

	return 0;
}
