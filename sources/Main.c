#include "../headers/FolhaPagamento.h"
#include <stdio.h>

void test(float expectedResult, float actualResult, char* messageTest) {
	if (expectedResult == actualResult) {
		printf("PASSED: %s - Actual value: %f, expeted value: %f\n\r", messageTest, actualResult, expectedResult);
	}else{
		printf("FAILED: %s - Actual value: %f, expeted value: %f\n\r", messageTest, actualResult, expectedResult);
	}
}


int main(){	
	float currentValue;
	
	addPJ("Joao", 50, 100, 0, 0);
	currentValue = calculeEmployeeByName("Joao");
	test(5000, currentValue, "Test salary of Joao");

	addCLT("Marcela", 3000, 10, 200);
	currentValue = calculeEmployeeByName("Marcela");
	test(5000, currentValue, "Test salary of Marcela");

	addPJ("Joaquim", 30, 180, 12, 200);
	currentValue = calculeEmployeeByName("Joaquim");
	test(7800, currentValue, "Test salary of Joaquim");

	currentValue = calculeEmployeeByName("Employees don't registered");
	test(0, currentValue, "Test salary of Employees don't registered");

	currentValue = calculeMonth();
	test(17800, currentValue, "Test salary month");

	return 0;
}
