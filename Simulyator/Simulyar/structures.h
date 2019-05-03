#pragma once
#define PI 3.14159265358979323846 // число ПИ

#pragma pack(push, 1)
struct DATA_HEAD {
	
	char key[7];
	unsigned __int16 version;
	char amountChannel;
	unsigned __int32 amountElements;
	unsigned __int16 frequency;
	
};
#pragma pack(pop)

#pragma pack(push, 1)
struct DATA_SEGMENT {

	unsigned __int64 timeMark;
	unsigned __int32 id;
	float arr[8][4096];
	
};
#pragma pack(pop)


