// MiDeleteExcessWorkingSetPages 
 
int __fastcall MiDeleteExcessWorkingSetPages(int a1, unsigned int a2, int a3)
{
  return MiDeletePteRange(a1, a2, a3, 16);
}
