#pragma once
#include <cstring>
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: exceeded the size of dict name"
#define THROW02 "Create: exceeded the size of dict capacity"
#define THROW03 "AddEntry: dictionary overflow"
#define THROW04 "AddEntry: duplicate identification"
#define THROW05 "GetEntry: element was not found"
#define THROW06 "DelEntry: element was not found"
#define THROW07 "UpdEntry: element was not found"
#define THROW08 "UpdEntry: duplicate identification"

namespace Dictionary {
	struct Entry {
		int id;  //id(unique)
		char name[ENTRYNAMEMAXSIZE];
	};
	struct Instance {
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* dictionary;
	};
	Instance Create(const char name[DICTNAMEMAXSIZE],int size);
	void AddEntry(Instance& inst,Entry ed);
	void DelEntry(Instance& inst,int id);
	void UpdEntry(Instance& inst,int id,Entry new_ed);
	Entry GetEntry(Instance inst,int id);
	void Print(Instance d);
	void Delete(Instance& d);
}

