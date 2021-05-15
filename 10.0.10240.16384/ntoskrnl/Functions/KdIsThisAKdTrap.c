// KdIsThisAKdTrap 
 
BOOL __fastcall KdIsThisAKdTrap(_DWORD *a1)
{
  unsigned int v1; // r3
  BOOL result; // r0

  result = 0;
  if ( *a1 == -2147483645 )
  {
    if ( a1[4] )
    {
      v1 = a1[5];
      if ( v1 )
      {
        if ( v1 < 6 )
          result = 1;
      }
    }
  }
  return result;
}
