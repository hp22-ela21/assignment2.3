#ifndef ELECTRICAL_H_
#define ELECTRICAL_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

/**********************************************************************************************
* Strukt för implementering av elektriska storheter spänning, ström samt resistans.
* En vtable-pekare används för att kunna anropa funktioner ämnade för objekt av strukten i 
* fråga. En medlemspekare används för att hålla struktens medlemmar privata.
**********************************************************************************************/
struct electrical
{
   const struct electrical_vtable* vptr; /* Pekar på vtable innehållande funktionspekare. */
   struct electrical_members* members; /* Pekar på privata medlemmar. */
};

/**********************************************************************************************
* vtable innehållande pekare till publika funktioner ämnade för strukten electrical.
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
