// KiCustomAccessRoutine8 
 
int __fastcall KiCustomAccessRoutine8(unsigned int *a1)
{
  return KiCustomRecurseRoutine8(((unsigned __int8)a1 & 3) + 1, a1);
}
