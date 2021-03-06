//---------------------------------------------------------------------//
//
// Tool: parsemyelf
//
// About: parsemyelf is a simple ELF Parser written in C++ to understand ELF binaries better. 
//
// C++ SourceFile: SectionHeaderTable.cpp
//
// Info: Has definitions of all methods declared in SectionHeaderTable.h . 
//
// Author: Adwaith V Gautham
//
// License: NONE
//
// Use the tool the way you want to, enjoy the learning and improve :)
//
//---------------------------------------------------------------------//


#include "pme/pme.h"
#include "pme/SectionHeader.h"
#include "pme/SectionHeaderTable.h"

using namespace pme;

// Constructor

Sctn64HeaderTable::Sctn64HeaderTable(unsigned char *PmeFilePtr, Elf64_Off shoff, Elf64_Half shentsize, Elf64_Half shnum, Elf64_Half shstrndx) {
	
	FilePtr = PmeFilePtr;
	e_shoff = shoff;
	e_shentsize = shentsize;
	e_shnum = shnum;
	e_shstrndx = shstrndx;

	int index = 0;
	std::string name;

	// Populate the vector
	while(index < e_shnum) {
		std::cout<<"index = "<<index<<std::endl;
		// XXX: Note that 2 objects are created here. This is a hack.
		// One object is being used because it is inserted into the table - have control over it. 
		// The other is orphan simply floating in the heap. 
		// This is not good :(
		Sctn64Header SHdr(FilePtr, e_shoff, e_shentsize, index);
		Sctn64HdrTblName.insert({SHdr.sh_name(), Sctn64Header(FilePtr, e_shoff, e_shentsize, index)});

		Sctn64HdrTblIndex.insert({index, Sctn64Header(FilePtr, e_shoff, e_shentsize, index)});

		index++;
	}

	return;
}

Sctn64HeaderTable::~Sctn64HeaderTable() {

}


// A simple display routine which you can use!
void Sctn64HeaderTable::DisplayTable() {
	
	std::cout<<"Section Header Table: "<<std::endl;
	for(std::pair<std::string, Sctn64Header> element : Sctn64HdrTblName) {
		std::cout<<"|-------------------------------------------------------------------------------|"<<std::endl;
		element.second.DisplayHeader();
	}
}


// Returns the complete table with section name as index
std::unordered_map<std::string, Sctn64Header> Sctn64HeaderTable::GetTableByName() {
	return Sctn64HdrTblName;
}

// Returns the complete table with index as index. 
std::unordered_map<unsigned, Sctn64Header> Sctn64HeaderTable::GetTableByIndex() {
	return Sctn64HdrTblIndex;
}








