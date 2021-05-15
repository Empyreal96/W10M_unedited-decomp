// KiCustomAccessRoutine1 
 
int __fastcall KiCustomAccessRoutine1(unsigned int *a1)
{
  return KiCustomRecurseRoutine1(((unsigned __int8)a1 & 3) + 1, a1);
}
