#pragma once

class Base
{
private:

    char* m_bufferA;

    void Assign(const char* string);

public:

    Base();
    Base(const Base& obj);
    Base(const char* string);

    virtual ~Base();

    Base& operator=(const Base& right);

    void Show() const;
};