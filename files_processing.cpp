//	Program written and tested in Dev-C++ 5.11

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;


void MENU();
void BACK_TO_MENU();

void SHOW_DEVICES();
void SHOW_ALL_DEVICES();
void SHOW_ACTIVE_DEVICES();
void SHOW_INACTIVE_DEVICES();
void ADD_A_DEVICE();

void SHOW_MEASUREMENTS();
void ADD_A_MEASUREMENT();

void PROCESSING_OF_MEASUREMENTS();


int main()
{
	MENU();

	return 0;
}


void MENU()
{
	system("CLS");

	cout << "Show devices - type 1." << endl;
	cout << "Add a device - type 2." << endl;
	cout << "Show measurements - type 3." << endl;
	cout << "Add a measurement - type 4." << endl;
	cout << "Processing of measurements - type 5." << endl;

	int n;

	do
	{
		cin >> n;

		switch (n)
		{
		case 1: SHOW_DEVICES();
			break;
		case 2: ADD_A_DEVICE();
			break;
		case 3: SHOW_MEASUREMENTS();
			break;
		case 4: ADD_A_MEASUREMENT();
			break;
		case 5: PROCESSING_OF_MEASUREMENTS();
			break;
		}
	} while (n != 0);
}


void BACK_TO_MENU()
{
	cout << endl;
	cout << "Back to MENU - type 1." << endl;

	int n;

	do
	{
		cin >> n;

		switch (n)
		{
		case 1: MENU();
			break;
		}
	} while (n != 0);
}


void SHOW_DEVICES()
{
	system("CLS");

	cout << "Show all devices - type 1." << endl;
	cout << "Show active devices - type 2." << endl;
	cout << "Show inactive devices - type 3." << endl;
	cout << endl;
	cout << "Back to MENU - type 4." << endl;

	int n;

	do
	{
		cin >> n;

		switch (n)
		{
		case 1: SHOW_ALL_DEVICES();
			break;
		case 2: SHOW_ACTIVE_DEVICES();
			break;
		case 3: SHOW_INACTIVE_DEVICES();
			break;
		case 4: MENU();
			break;
		}
	} while (n != 0);
}


void SHOW_ALL_DEVICES()
{
	system("CLS");

	fstream devices;
	devices.open("devices.txt", ios::in);

	string line;

	while(getline(devices, line))
	{
		cout << line << endl;
	}

	devices.close();

	BACK_TO_MENU();
}


void SHOW_ACTIVE_DEVICES()
{
	system("CLS");

	fstream devices;
	devices.open("devices.txt", ios::in);

	string line;

	while(getline(devices, line))
	{
		if (line[76] == 'a' || line[0] == 'I')
		{
			cout << line << endl;
		}
	}

	devices.close();

	BACK_TO_MENU();
}


void SHOW_INACTIVE_DEVICES()
{
	system("CLS");

	fstream devices;
	devices.open("devices.txt", ios::in);

	string line;

	while(getline(devices, line))
	{
		if (line[76] == 'i' || line[0] == 'I')
		{
			cout << line << endl;
		}
	}

	devices.close();

	BACK_TO_MENU();
}


void ADD_A_DEVICE()
{
	system("CLS");

	int ID;
	string IP;
	char State;
	int LowerRange;
	int UpperRange;
	string Unit;
	int Resolution;
	fstream devices;

	cout << "Enter the device ID: ";
	cin >> ID;
	cout << "Enter the device IP: ";
	cin >> IP;
	cout << "Enter the LOWER range of measured values: ";
	cin >> LowerRange;
	cout << "Enter the UPPER range of measured values: ";
	cin >> UpperRange;
	cout << "Enter the unit of the measured value: ";
	cin >> Unit;
	cout << "Enter converter Resolution: ";
	cin >> Resolution;
	cout << "Define device state (active-a / inactive-i): ";
	cin >> State;

	devices.open("devices.txt", ios::out | ios::app);
	devices << setw(2) << ID << setw(15) << IP << setw(13) << LowerRange << setw(13) << UpperRange << setw(11) << Unit << setw(15) << Resolution << setw(8) << State << endl;
	devices.close();

	cout << endl;
	cout << "Back to MENU - type 1." << endl;
	cout << "Add another device - type 2." << endl;

	int n;

	do
	{
		cin >> n;
		switch (n)
		{
		case 1: MENU();
			break;
		case 2: ADD_A_DEVICE();
			break;
		}
	} while (n != 0);
}


void SHOW_MEASUREMENTS()
{
	system("CLS");

	fstream measurements;
	measurements.open("measurements.txt", ios::in);

	string line;

	while(getline(measurements, line))
	{
		cout << line << endl;
	}

	measurements.close();

	BACK_TO_MENU();
}


void ADD_A_MEASUREMENT()
{
	system("CLS");

	int ID;
	int measurement;
	fstream measurements;

	cout << "Enter the device ID:";
	cin >> ID;
	cout << "Enter the measurement value:";
	cin >> measurement;

	measurements.open("measurements.txt", ios::out | ios::app);
	measurements << setw(10) << ID << setw(15) << measurement << endl;
	measurements.close();

	cout << endl;
	cout << "Back to MENU - type 1." << endl;
	cout << "Add another measurement - type 2." << endl;

	int n;

	do
	{
		cin >> n;
		switch (n)
		{
		case 1: MENU();
			break;
		case 2: ADD_A_MEASUREMENT();
			break;
		}
	} while (n != 0);
}


void PROCESSING_OF_MEASUREMENTS()
{
	system("CLS");

	float result;
	string line_device, line_measurement;
	float measurement_result;
	float resolution;
	float lower_range;
	float upper_range;
	fstream measurements;
	fstream devices;

	cout << setw(10) << "Result" << setw(10) << "Unit" << setw(15) << "Device" << endl;

	measurements.open("measurements.txt");
	
	while (getline(measurements, line_measurement))
	{
		devices.open("devices.txt");
		
		do
		{
			getline(devices, line_device);
		} while (line_measurement[9] != line_device[1]);

		devices.close();
	
		//	Reading the values needed for calculations from files to the program and changing the way of saving them (string-> float).
		string MeasurementResult = line_measurement.substr(10, 15);
		istringstream(MeasurementResult) >> measurement_result;

		string Resolution = line_device.substr(54, 15);
		istringstream(Resolution) >> resolution;

		string LowerRange = line_device.substr(17, 13);
		istringstream(LowerRange) >> lower_range;

		string UpperRange = line_device.substr(30, 13);
		istringstream(UpperRange) >> upper_range;

		int j = 2;
		for (int i = 1; i < resolution; i++)
		{
			j *= 2;
		}

		result = (measurement_result / j)*(upper_range - lower_range) + lower_range;

		if (line_device[1] != 'D')
		{
			cout << setw(10) << result << setw(9) << line_device[52] << line_device[53] << setw(14) << "device " << line_device[1] << endl;
		}
	} 
	
	measurements.close();

	BACK_TO_MENU();
}
