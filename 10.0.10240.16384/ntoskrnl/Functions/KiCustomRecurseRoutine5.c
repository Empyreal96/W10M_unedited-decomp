// KiCustomRecurseRoutine5 
 
int __fastcall KiCustomRecurseRoutine5(int a1, unsigned int *a2)
{
  int result; // r0
  unsigned int v3; // r2

  result = a1 - 1;
  if ( result )
    result = KiCustomRecurseRoutine6();
  v3 = __ldrex(a2);
  __clrex();
  return result;
}
