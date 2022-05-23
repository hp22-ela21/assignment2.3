/* Inkluderingsdirektiv: */
#include "header.h"

/**********************************************************************************************
* Läser text inmatat från tangentbordet.
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
* Läser ett signerat heltal inmatat från tangentbordet.
**********************************************************************************************/
int get_integer(void)
{
   char s[20];
   s[0] = '\0';
   readline(s, sizeof(s));
   return (atoi)(s);
}

/**********************************************************************************************
* Läser ett flyttal inmatat från tangentbordet. Både kommatecken och punkt är giltigt.
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
* Läser ett osignerat heltal inmatat från tangentbordet.
**********************************************************************************************/
size_t get_unsigned(void) { return (size_t)(get_integer()); }






