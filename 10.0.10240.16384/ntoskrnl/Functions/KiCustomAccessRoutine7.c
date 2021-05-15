// KiCustomAccessRoutine7 
 
int __fastcall KiCustomAccessRoutine7(unsigned int *a1)
{
  return KiCustomRecurseRoutine7(((unsigned __int8)a1 & 3) + 1, a1);
}
