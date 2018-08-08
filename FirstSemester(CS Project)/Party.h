#pragma once
class Party{
public:
	Party();
	~Party();
	void SetPartyName(char * Name);
	void SetPartySize(int);
	void SetPartyName();
	void SetPartySize();
	char* GetPartyName();
	int   GetPartySize();

private:
	char* PartyName;
	int Party_Size;
};


