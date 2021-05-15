// RtlAreAnyAccessesGranted 
 
BOOL __fastcall RtlAreAnyAccessesGranted(int a1, int a2)
{
  return (a1 & a2) != 0;
}
