/* Inkluderingsdirektiv: */
#include "electrical.h"

/* Privata medlemmar tillh�rande strukten electrical: */
struct electrical_members
{
   double voltage; /* Sp�nning m�tt i Volt. */
   double current; /* Str�m m�tt i mA. */
   double resistance; /* Resistans m�tt i kOhm. */
};

/* Statiska funktioner: */
static struct electrical_vtable* vptr_new(void);
static struct electrical_members* members_new(void);
static void electrical_set(struct electrical* self, const double voltage, const double current);
static void electrical_get_input(struct electrical* self);
static void electrical_print(const struct electrical* self, FILE* stream);
static double electrical_voltage(const struct electrical* self);
static double electrical_current(const struct electrical* self);
static double electrical_resistance(const struct electrical* self);

/**********************************************************************************************
* Konstruktor f�r objekt av strukten electrical.
**********************************************************************************************/
void electrical_new(struct electrical* self)
{
   self->vptr = vptr_new();
   self->members = members_new();
   return;
}

/**********************************************************************************************
* Destruktor f�r objekt av strukten electrical.
**********************************************************************************************/
void electrical_delete(struct electrical* self)
{
   free(self->members);
   self->members = 0;
   self->vptr = 0;
   return;
}

/**********************************************************************************************
* Konstruktor f�r pekare till objekt av strukten electrical.
**********************************************************************************************/
struct electrical* electrical_ptr_new(void)
{
   struct electrical* self = (struct electrical*)malloc(sizeof(struct electrical));
   if (!self) return 0;
   self->vptr = vptr_new();
   self->members = members_new();
   return self;
}

/**********************************************************************************************
* Destruktor f�r pekare till objekt av strukten electrical.
**********************************************************************************************/
void electrical_ptr_delete(struct electrical* self)
{
   electrical_delete(self);
   free(self);
   return;
}

/**********************************************************************************************
* Initierar ny vtable-pekare f�r objekt av strukten electrical.
**********************************************************************************************/
static struct electrical_vtable* vptr_new(void)
{
   static struct electrical_vtable self;
   self.set = &electrical_set;
   self.get_input = &electrical_get_input;
   self.print = &electrical_print;
   self.voltage = &electrical_voltage;
   self.current = &electrical_current;
   self.resistance = &electrical_resistance;
   return &self;
}

/**********************************************************************************************
* Initierar ny pekare till privata medlemmar av strukten electrical.
**********************************************************************************************/
static struct electrical_members* members_new(void)
{
   struct electrical_members* self = 
      (struct electrical_members*)malloc(sizeof(struct electrical_members));
   if (!self) return 0;
   self->voltage = 0.0;
   self->current = 0.0;
   self->resistance = 0.0;
   return self;
}

/**********************************************************************************************
* S�tter v�rden p� elektriska storheter utefter ing�ende argument i kombination med Ohms lag.
**********************************************************************************************/
static void electrical_set(struct electrical* self, const double voltage, const double current)
{
   self->members->voltage = voltage;
   self->members->current = current;
   self->members->resistance = self->members->voltage / self->members->current;
   return;
}

/**********************************************************************************************
* L�ser in v�rden p� elektriska storheter via inmatning fr�n tangentbordet samt Ohms lag.
**********************************************************************************************/
static void electrical_get_input(struct electrical* self)
{
   fprintf(stdout, "Enter voltage in V:\n");
   self->members->voltage = get_double();
   fprintf(stdout, "Enter current in mA:\n");
   self->members->current = get_double();
   self->members->resistance = self->members->voltage / self->members->current;
   return;
}

/**********************************************************************************************
* Skriver ut aktuella v�rden p� de elektriska storheterna till specificerad utenhet.
* Som default genomf�rs utskrift i konsolen via standardutenheten stdout.
**********************************************************************************************/
static void electrical_print(const struct electrical* self, FILE* stream)
{
   if (!stream) stream = stdout;
   fprintf(stream, "-------------------------------------------------------------------\n");
   fprintf(stream, "Voltage: %g V\n", self->members->voltage);
   fprintf(stream, "Current: %g mA\n", self->members->current);
   fprintf(stream, "Resistance: %g kOhm\n", self->members->resistance);
   fprintf(stream, "-------------------------------------------------------------------\n\n");
   return;
}

/**********************************************************************************************
* Returnerar sp�nning m�tt i V.
**********************************************************************************************/
static double electrical_voltage(const struct electrical* self)
{
   return self->members->voltage;
}

/**********************************************************************************************
* Returnerar str�m m�tt i mA.
**********************************************************************************************/
static double electrical_current(const struct electrical* self)
{
   return self->members->current;
}

/**********************************************************************************************
* Returnerar resistans m�tt i kOhm.
**********************************************************************************************/
static double electrical_resistance(const struct electrical* self)
{
   return self->members->resistance;
}



