#include "Dictionary.h"
#include "stdafx.h"
#include <iostream>
#include <locale>
using namespace std;


int main(int argc, char* argv[]) {
	try {
		Dictionary::Instance d1 = Dictionary::Create("Workers", 5);
		Dictionary::Entry e1 = { 1,"first" }, e2 = { 2, "second" },
			e3 = { 3, "third" };
		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 3);
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry newentry1 = { 6, "Lastname" };
		Dictionary::UpdEntry(d1, 3, newentry1);
		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Students", 5);
		Dictionary::Entry s1 = { 1, "Ivanov" }, s2 = { 2, "Petrov" }, s3 = { 3, "Sidorov" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 3, "Nikolajev" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (char* e) {
		cout << e << endl;
	};


#ifdef TEST_CREATE_01
	try {
		Dictionary::Instance d1 = Dictionary::Create("Loooooooooooooooooooooooooooooooooooong", 5);
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW01, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_CREATE_01 " << res << endl;
	}
#endif

#ifdef TEST_CREATE_02
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", DICTMAXSIZE + 1);
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW02, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_CREATE_02 " << res << endl;
	}
#endif

#ifdef TEST_ADDENTRY_03
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", 1);
		Dictionary::Entry e1 = { 1,"e1"};
		Dictionary::Entry e2 = { 2,"e2"};
		Dictionary::Entry e3 = { 3,"e3"};

		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW03, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_ADDENTRY_03 " << res << endl;
	}
#endif

#ifdef TEST_ADDENTRY_04
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", 10);
		Dictionary::Entry e1 = { 1,"e1"};
		Dictionary::Entry e2 = { 1,"e2"};

		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW04, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_ADDENTRY_04 " << res << endl;
	}
#endif

#ifdef TEST_GETENTRY_05
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", 10);
		Dictionary::Entry e1 = { 1, "e1" };

		Dictionary::AddEntry(d1, e1);
		Dictionary::GetEntry(d1, 2); 
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW05, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_GETENTRY_05 " << res << endl;
	}
#endif

#ifdef TEST_GETENTRY_06
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", 10);
		Dictionary::Entry e1 = { 1, "e1" };

		Dictionary::AddEntry(d1, e1);
		Dictionary::GetEntry(d1, 2);
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW06, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_GETENTRY_06 " << res << endl;
	}
#endif

#ifdef TEST_UPDENTRY_07
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", 10);
		Dictionary::Entry e1 = { 1, "e1" };
		Dictionary::Entry e2 = { 2, "e2" };
		Dictionary::Entry new_e = { 3, "new_e" };

		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::UpdEntry(d1, 4, new_e); 
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW07, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_UPDENTRY_07 " << res << endl;
	}
#endif

#ifdef TEST_UPDENTRY_08
	try {
		Dictionary::Instance d1 = Dictionary::Create("Students", 10);
		Dictionary::Entry e1 = { 1, "e1" };
		Dictionary::Entry e2 = { 2, "e2" };
		Dictionary::Entry new_e = { 2, "new_e_duplication" };

		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::UpdEntry(d1, 1, new_e); 
	}
	catch (const char* e) {
		const char* res = 0 == strcmp(THROW08, e) ? "succeseful" : "unsucceseful";
		cout << "TEST_UPDENTRY_08 " << res << endl;
	}
#endif

	system("pause");
	return 0;
}