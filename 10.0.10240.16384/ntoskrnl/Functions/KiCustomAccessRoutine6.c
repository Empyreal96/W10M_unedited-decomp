// KiCustomAccessRoutine6 
 
int __fastcall KiCustomAccessRoutine6(unsigned int *a1)
{
  return KiCustomRecurseRoutine6(((unsigned __int8)a1 & 3) + 1, a1);
}
