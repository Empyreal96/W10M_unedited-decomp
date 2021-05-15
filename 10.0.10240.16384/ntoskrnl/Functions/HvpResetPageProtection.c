// HvpResetPageProtection 
 
int __fastcall HvpResetPageProtection(int result)
{
  int v1; // r7
  unsigned int v2; // r5
  unsigned int v3; // r6
  unsigned int i; // r4
  unsigned int j; // r0

  v1 = result;
  v2 = *(_DWORD *)(result + 36);
  v3 = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v3; i < v2; ++i )
      {
        if ( ((*(int *)(*(_DWORD *)(v1 + 40) + 4 * (i >> 5)) >> (i & 0x1F)) & 1) != 0 )
          break;
      }
      for ( j = i; i < v2; ++i )
      {
        if ( ((*(int *)(*(_DWORD *)(v1 + 40) + 4 * (i >> 5)) >> (i & 0x1F)) & 1) == 0 )
          break;
      }
      v3 = i;
      result = HvpSetRangeProtection(v1, j << 9, (i - j) << 9, 2);
    }
    while ( i < v2 );
  }
  return result;
}
