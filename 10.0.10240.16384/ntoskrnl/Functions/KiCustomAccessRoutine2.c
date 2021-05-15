// KiCustomAccessRoutine2 
 
int __fastcall KiCustomAccessRoutine2(unsigned int *a1)
{
  return KiCustomRecurseRoutine2(((unsigned __int8)a1 & 3) + 1, a1);
}
