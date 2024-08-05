#include "Dictionary.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace Dictionary {

	Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
		if (strlen(name) >= DICTNAMEMAXSIZE){
			throw THROW01;
		}
		if (size > DICTMAXSIZE) {
			throw THROW02;
		}
		Instance instance;
		strncpy_s(instance.name, name, strlen(name));
		instance.name[DICTNAMEMAXSIZE - 1] = '\0';
		instance.maxsize = size;
		instance.size = 0;
		instance.dictionary = new Entry[size];

		return instance;
	}

	void AddEntry(Instance& inst, Entry ed) {
		if (inst.size >= inst.maxsize) {
			throw THROW03;
		}
		//checking for duplication
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i].id == ed.id) {
				throw THROW04;
			}
		}
		inst.dictionary[inst.size] = ed;
		inst.size++;
	}

	void DelEntry(Instance& inst, int id) {
		bool found = false;
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i].id == id) {

				found = true;

				//all elements 1 place left
				for (int k = i; k < inst.size - 1; k++) {
					inst.dictionary[k] = inst.dictionary[k+1];
				}
				inst.size--;
				break;
			}
		}
		if (!found){
			throw THROW06;
		}
	}

	Entry GetEntry(Instance inst, int id) {
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i].id == id) {
				return inst.dictionary[i];
			}
		}
		throw THROW05;
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) {
		bool found = false;
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i].id == id) {
				for (int k = 0; k < inst.dictionary[k].id; k++) {
					if (k != i && inst.dictionary[k].id == new_ed.id) {
						throw THROW07;
					}
				}
				inst.dictionary[i] = new_ed;
				found = true;
				break;
			}
		}
		if (!found) {
			throw THROW08;
		}
	}

	void Delete(Instance& d) {
		delete[]d.dictionary;
		d.dictionary = NULL;
		d.size = 0;
		d.maxsize = 0;
	}

	void Print(Instance d) {
		for (int i = 0; i < d.size; i++) {
			cout << "Id: " << d.dictionary[i].id << endl;
			cout << "Name: " << d.dictionary[i].name << endl;
		}
	}

}

