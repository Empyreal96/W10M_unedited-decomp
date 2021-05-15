// KiCustomAccessRoutine9 
 
int __fastcall KiCustomAccessRoutine9(unsigned int *a1)
{
  return KiCustomRecurseRoutine9(((unsigned __int8)a1 & 3) + 1, a1);
}
