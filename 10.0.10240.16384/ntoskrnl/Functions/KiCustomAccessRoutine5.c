// KiCustomAccessRoutine5 
 
int __fastcall KiCustomAccessRoutine5(unsigned int *a1)
{
  return KiCustomRecurseRoutine5(((unsigned __int8)a1 & 3) + 1, a1);
}
