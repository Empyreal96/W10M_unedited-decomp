// PpmDeepestHardwareIdleState 
 
unsigned int __fastcall PpmDeepestHardwareIdleState(int a1)
{
  unsigned int v1; // r3
  int i; // r2

  v1 = 1;
  if ( a1 )
  {
    for ( i = *(_DWORD *)(a1 + 28); i; --i )
    {
      if ( *(unsigned __int8 *)(a1 + 308) > v1 )
        v1 = *(unsigned __int8 *)(a1 + 308);
      a1 += 64;
    }
  }
  return v1;
}
