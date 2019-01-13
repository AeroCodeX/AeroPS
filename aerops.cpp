#include <iostream>
#include <fstream>
using namespace std;

void printAtFirst()
{
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "AeroPS 1.0.0" << endl;
	cout << endl;
	cout << "\t https://dev.aerocode.net" << endl;
	cout << "\t https://dev.aerocode.net/entry/AeroPS" << endl;
	cout << endl;
	cout << "-----------------------------------------------------" << endl;

}

void printUsage()
{
	cout << "Usage" << endl;
	cout << "\t aerops input {pdf | jpeg | jpg}" << endl;
	cout << endl;
	cout << endl;
	exit(0);
}

int main(int argc, const char **argv)
{
	printAtFirst();
	if (argc != 3) printUsage();

	if (strcmp(argv[2], "pdf") == 0)
	{
		// pdf
		// to pdf	./gswin32c.exe -sDEVICE=pdfwrite -o out.pdf -f in.ps
		string cmd = "gswin32c.exe  -dBATCH -dNOPAUSE -sDEVICE=pdfwrite -o ";

		cmd = cmd.append("\"");
		cmd = cmd.append(argv[1]);
		cmd = cmd.append(".");
		cmd = cmd.append(argv[2]);
		cmd = cmd.append("\"");

		cmd = cmd.append(" -f ");
		cmd = cmd.append("\"");
		cmd = cmd.append(argv[1]);
		cmd = cmd.append("\"");

		cout << cmd.c_str() << endl;
		system(cmd.c_str());
	}
	else if (strcmp(argv[2], "jpeg") == 0 || strcmp(argv[2], "jpg") == 0)
	{
		// jpeg
		// to jpeg	./gswin32c.exe -sDEVICE=jpeg -sOutputFile="OUT%03d.jpg" -dBATCH -dNOPAUSE in.ps
		string cmd = "gswin32c.exe -dBATCH -dNOPAUSE -sDEVICE=jpeg -sOutputFile=";
		
		cmd = cmd.append("\"");
		cmd = cmd.append(argv[1]);
		cmd = cmd.append("-%d");
		cmd = cmd.append(".");
		cmd = cmd.append(argv[2]);
		cmd = cmd.append("\"");

		cmd = cmd.append(" -f ");
		cmd = cmd.append("\"");
		cmd = cmd.append(argv[1]);
		cmd = cmd.append("\"");

		cout << cmd.c_str() << endl;
		system(cmd.c_str());
	}
	else printUsage();
	return 0;
}