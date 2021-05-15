// MiLockTrackerCompare 
 
int __fastcall MiLockTrackerCompare(unsigned int a1, int a2)
{
  unsigned int v2; // r3
  int result; // r0

  v2 = *(_DWORD *)(a2 + 12);
  if ( a1 >= v2 )
    result = a1 > v2;
  else
    result = -1;
  return result;
}
