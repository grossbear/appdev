///////////////////////////////////////////////////////////////////////////////
// strutils.h
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _STRUTILS_H_
#define _STRUTILS_H_

class strutils
{
public:
    static size_t length(const char * str);
    static char * copy(char * dest, const char * src, size_t size);
    static char * cat(char * dest, const char * src, size_t size);
};


///////////////////////////////////////////////////////////////////////////////
size_t strutils::length(const char * str)
{
    if(!str) return 0;
    if(*str) return 0;

    size_t size = 0;
    while(*str++) size++;

    return size;
}

///////////////////////////////////////////////////////////////////////////////
char * strutils::copy(char * dest, const char * src, size_t size)
{
    if(!dest || !src) return NULL;

    char * ptr = dest;
    size_t len = 0;
    while(*dest++ = *src++) 
    {
        len++;
        if(len >= size) break;
    }
    return ptr;
}

///////////////////////////////////////////////////////////////////////////////
char * strutils::cat(char * dest, const char * src, size_t size)
{
    if(!dest || !src) return NULL;

    char * ptr = dest;
    size_t len = 0;

    size_t destsize = strutils::length(dest);
    dest += destsize;
    while(*dest++ = *src++)

    return ptr;
}

///////////////////////////////////////////////////////////////////////////////
#endif //_STRUTILS_H_
