#ifndef ELECTRICAL_H_
#define ELECTRICAL_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

/**********************************************************************************************
* Strukt f�r implementering av elektriska storheter sp�nning, str�m samt resistans.
* En vtable-pekare anv�nds f�r att kunna anropa funktioner �mnade f�r objekt av strukten i 
* fr�ga. En medlemspekare anv�nds f�r att h�lla struktens medlemmar privata.
**********************************************************************************************/
struct electrical
{
   const struct electrical_vtable* vptr; /* Pekar p� vtable inneh�llande funktionspekare. */
   struct electrical_members* members; /* Pekar p� privata medlemmar. */
};

/**********************************************************************************************
* vtable inneh�llande pekare till publika funktioner �mnade f�r strukten electrical.
**********************************************************************************************/
struct electrical_vtable
{
   void (*set)(struct electrical* self, const double voltage, const double current);
   void (*get_input)(struct electrical* self);
   void (*print)(const struct electrical* self, FILE* stream);
   double (*voltage)(const struct electrical* self);
   double (*current)(const struct electrical* self);
   double (*resistance)(const struct electrical* self);
};

/* Externa funktioner: */
void electrical_new(struct electrical* self);
void electrical_delete(struct electrical* self);
struct electrical* electrical_ptr_new(void);
void electrical_ptr_delete(struct electrical* self);

#endif /* ELECTRICAL_H_ */
