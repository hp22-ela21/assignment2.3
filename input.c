/* Inkluderingsdirektiv: */
#include "header.h"

/**********************************************************************************************
* L�ser text inmatat fr�n tangentbordet.
**********************************************************************************************/
void readline(char* s, const size_t size)
{
   register char* i;
   fgets(s, (int)(size), stdin);
   fprintf(stdout, "\n");
   for (i = s; *i; i++)
      if (*i == '\n') *i = '\0';
   return;
}

/**********************************************************************************************
* L�ser ett signerat heltal inmatat fr�n tangentbordet.
**********************************************************************************************/
int get_integer(void)
{
   char s[20];
   s[0] = '\0';
   readline(s, sizeof(s));
   return (atoi)(s);
}

/**********************************************************************************************
* L�ser ett flyttal inmatat fr�n tangentbordet. B�de kommatecken och punkt �r giltigt.
**********************************************************************************************/
double get_double(void)
{
   char s[20];
   register char* i;
   s[0] = '\0';
   readline(s, sizeof(s));
   for (i = s; *i; i++)
      if (*i == ',') *i = '.';
   return (atof)(s);
}

/**********************************************************************************************
* L�ser ett osignerat heltal inmatat fr�n tangentbordet.
**********************************************************************************************/
size_t get_unsigned(void) { return (size_t)(get_integer()); }






