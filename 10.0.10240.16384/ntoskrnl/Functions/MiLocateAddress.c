// MiLocateAddress 
 
_DWORD *__fastcall MiLocateAddress(unsigned int a1)
{
  int v2; // r6
  _DWORD *result; // r0
  unsigned int v4; // r5
  _DWORD *v5; // r4
  int v6; // r0

  v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  result = *(_DWORD **)(v2 + 640);
  if ( !result )
    return 0;
  v4 = a1 >> 12;
  if ( a1 >> 12 < result[3] || v4 > result[4] )
  {
    v5 = *(_DWORD **)(v2 + 636);
    if ( !v5 )
      return 0;
    while ( 1 )
    {
      v6 = MiVadCompareVpn(v4, (int)v5);
      if ( v6 < 0 )
      {
        v5 = (_DWORD *)*v5;
      }
      else
      {
        if ( v6 <= 0 )
        {
          *(_DWORD *)(v2 + 640) = v5;
          return v5;
        }
        v5 = (_DWORD *)v5[1];
      }
      if ( !v5 )
        return 0;
    }
  }
  return result;
}
