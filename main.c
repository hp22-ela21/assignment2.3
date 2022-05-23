/* Inkluderingsdirektiv: */
#include "header.h"

/**********************************************************************************************
* Objektet e1 används för att läsa in spänning samt ström från tangentbordet, där resistansen
* sedan beräknas med Ohms lag. Inmatade värde skrivs ut i konsolen och skrivs även till en
* textfil döpt data.txt. Eventuellt tidigare innehåll skrivs över. Pekare e2 används för
* att lagra motsvarande storheter, fast med storheterna justerade med en given ratio,
* inmatad av användaren. Spänningen multipliceras med denna faktor, men strömmen divideras.
* Innehållet skrivs ut i konsolen och läggs dessutom till längst ned i textfilen data.txt.
**********************************************************************************************/
int main(void)
{
   struct electrical e1, *e2;
   FILE* fstream;
   double ratio;

   electrical_new(&e1);
   e1.vptr->get_input(&e1);
   e1.vptr->print(&e1, stdout);
   fstream = fopen("data.txt", "w");
   e1.vptr->print(&e1, fstream);

   fprintf(stdout, "Enter a change ratio for the electrical quantities:\n");
   ratio = get_double();

   e2 = electrical_ptr_new();
   e2->vptr->set(e2, e1.vptr->voltage(&e1) * ratio, e1.vptr->current(&e1) / ratio);
   e2->vptr->print(e2, stdout);
   fstream = fopen("data.txt", "a");
   e2->vptr->print(e2, fstream);
   fclose(fstream);

   electrical_delete(&e1);
   electrical_ptr_delete(e2);
   return 0;
}

