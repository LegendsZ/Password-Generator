#include <iostream>
#pragma once

class PasswordGenerator {

#define DEFAULT_PASSWORD_MIN 5
#define DEFAULT_PASSWORD_MAX 15

#define DEFAULT_PASSWORD_GEN_MIN 32
#define DEFAULT_PASSWORD_GEN_MAX 126

private:

	int passwordLength;
	char* password;

	int passwordLengthMin = DEFAULT_PASSWORD_MIN;
	int passwordLengthMax = DEFAULT_PASSWORD_MAX;

	int passwordGenMin = DEFAULT_PASSWORD_GEN_MIN;
	int passwordGenMax = DEFAULT_PASSWORD_GEN_MAX;

public:

	PasswordGenerator() {
		randomizeSeed();
		passwordLength = randomizeInt(passwordLengthMin, passwordLengthMax);
		randomizePassword();
	}

	PasswordGenerator(int lengthMinG, int lengthMaxG, int genMinG, int genMaxG) :
		passwordLengthMin(lengthMinG != NULL ? lengthMinG : passwordLengthMin), passwordLengthMax(lengthMaxG != NULL ? lengthMaxG : passwordLengthMax), passwordGenMin(genMinG != NULL ? genMinG : passwordGenMin), passwordGenMax(genMaxG != NULL ? genMaxG : passwordGenMax) 
	{
		randomizeSeed();
		passwordLength = randomizeInt(passwordLengthMin, passwordLengthMax);
		randomizePassword();
	}

	int randomizeInt(int minG, int maxG) {
		return rand() % (maxG - minG + 1) + minG;
	}

	bool randomizePassword() {
		password = new char(passwordLength);
		for (int i = 0; i < passwordLength; i++) {
			int asciival = rand() % (passwordGenMax - passwordGenMin + 1) + passwordGenMin;
			password[i] = asciival;
		}
		return true;
	}
	char* getPassword() const  {
		return password;
	}

	const int getPasswordLength() const {
		return passwordLength;
	}
	bool setPasswordLength(int lengthG) {
		passwordLength = lengthG;
		return true;
	}
	bool randomizePasswordLength() {
		passwordLength = randomizeInt(passwordLengthMin, passwordLengthMax);
		return true;
	}


	bool setSeed(float seedG) {
		srand(seedG);
		return true;
	}
	bool randomizeSeed() {
		srand(time(0));
		return true;
	}

	bool setPasswordLengthMin(int minG) {
		passwordLengthMin = minG;
		return true;
	}
	const int getPasswordLengthMin() const  {
		return passwordLengthMin;
	}

	bool setPasswordLengthMax(int maxG) {
		passwordLengthMax = maxG;
		return true;
	}
	const int getPasswordLengthMax() const  {
		return passwordLengthMax;
	}
};