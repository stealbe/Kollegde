#pragma once

class AuthorBook
{
private:

    char m_author[80];

public:

    void SetAuthor(const char* author);

    void ShowAuthor() const;
};