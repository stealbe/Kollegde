#pragma once
class MStr {
private:
    char* str;
    int length;
public:
    MStr();
    MStr(int size);
    MStr(const char* _str);
    MStr(const MStr& _str);
    MStr(MStr&& _str);
    ~MStr();
    
    void Cpy(const MStr& st);
    bool StrStr(const char* st);
    void Print();
    int Len();
    void Inp(const char* st);
    int StrChr(char chr);
    void Cat(MStr& b);
    void DelChr(char chr);
    int StrCmp(MStr& b);
};