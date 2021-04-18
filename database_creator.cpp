//	Program written and tested in Dev-C++ 5.11

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void CREATE_DEVICES();
void CREATE_MEASUREMENTS();


int main()
{
	fstream devices, measurements;
	devices.open("devices.txt");	
	measurements.open("measurements.txt");
	
	if (devices.good() && measurements.good())
	{
		cout << "Files already exist!" << endl;
	}
	
	else if (devices.good())
	{
		CREATE_MEASUREMENTS();
		
		cout << "The measurements.txt file has been added." << endl;
	}
	
	else if (measurements.good())
	{
		CREATE_DEVICES();
		
		cout << "The devices.txt file has been added." << endl;
	}
	
	else
	{
		CREATE_DEVICES();
		CREATE_MEASUREMENTS();
		
		cout << "The sample database has been created." << endl;
	}

	return 0;
}


//	Creation of the devices.txt file with sample devices if the devices.txt file does not exist.
void CREATE_DEVICES()
{
	fstream devices;

	devices.open("devices.txt", ios::in);
	if (devices.fail())
	{
		devices.open("devices.txt", ios::out);
		devices << setw(2) << "ID" << setw(15) << "IP" << setw(13) << "LowerRange" << setw(13) << "UpperRange" << setw(11) << "Unit" << setw(15) << "Resolution" << setw(8) << "State" << endl;
		devices << setw(2) << "0" << setw(15) << "232.42.2.44" << setw(13) << "5" << setw(13) << "10" << setw(11) << "V" << setw(15) << "8" << setw(8) << "a" << endl;
		devices << setw(2) << "1" << setw(15) << "232.44.33.2" << setw(13) << "0" << setw(13) << "5" << setw(11) << "W" << setw(15) << "12" << setw(8) << "a" << endl;
		devices << setw(2) << "2" << setw(15) << "754.79.5.11" << setw(13) << "-4" << setw(13) << "20" << setw(11) << "mA" << setw(15) << "8" << setw(8) << "i" << endl;
		devices << setw(2) << "3" << setw(15) << "875.24.77.2" << setw(13) << "0" << setw(13) << "7" << setw(11) << "W" << setw(15) << "12" << setw(8) << "a" << endl;
		devices << setw(2) << "4" << setw(15) << "232.49.44.11" << setw(13) << "-5" << setw(13) << "10" << setw(11) << "mA" << setw(15) << "8" << setw(8) << "i" << endl;
		devices << setw(2) << "5" << setw(15) << "654.39.2.15" << setw(13) << "4" << setw(13) << "16" << setw(11) << "mA" << setw(15) << "8" << setw(8) << "i" << endl;
		devices << setw(2) << "6" << setw(15) << "925.65.54.4" << setw(13) << "2" << setw(13) << "4" << setw(11) << "W" << setw(15) << "12" << setw(8) << "a" << endl;
	}
	devices.close();
}


//	Creation of the measurements.txt file with sample measurements, if the file measurements.txt does not exist.
void CREATE_MEASUREMENTS()
{
	fstream measurements;

	measurements.open("measurements.txt", ios::in);
	if (measurements.fail())
	{
		measurements.open("measurements.txt", ios::out);
		measurements << setw(10) << "DeviceID" << setw(15) << "Measurement" << endl;
		measurements << setw(10) << "0" << setw(15) << "887" << endl;
		measurements << setw(10) << "1" << setw(15) << "224" << endl;
		measurements << setw(10) << "2" << setw(15) << "775" << endl;
		measurements << setw(10) << "1" << setw(15) << "44" << endl;
		measurements << setw(10) << "4" << setw(15) << "1123" << endl;
		measurements << setw(10) << "3" << setw(15) << "2" << endl;
		measurements << setw(10) << "5" << setw(15) << "88" << endl;
		measurements << setw(10) << "6" << setw(15) << "93" << endl;
	}
	measurements.close();
}
