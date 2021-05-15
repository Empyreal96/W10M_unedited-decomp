// KiCustomAccessRoutine4 
 
int __fastcall KiCustomAccessRoutine4(unsigned int *a1)
{
  return KiCustomRecurseRoutine4(((unsigned __int8)a1 & 3) + 1, a1);
}
