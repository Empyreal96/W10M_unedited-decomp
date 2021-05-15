// KiCustomAccessRoutine3 
 
int __fastcall KiCustomAccessRoutine3(unsigned int *a1)
{
  return KiCustomRecurseRoutine3(((unsigned __int8)a1 & 3) + 1, a1);
}
