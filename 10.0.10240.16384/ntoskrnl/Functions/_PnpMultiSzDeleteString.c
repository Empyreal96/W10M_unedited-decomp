// _PnpMultiSzDeleteString 
 
int __fastcall PnpMultiSzDeleteString(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r4
  unsigned int v5; // r5
  int v6; // r0
  unsigned int v7; // r6
  int v8; // r0
  unsigned int v9; // r7

  v2 = a1;
  if ( !a1 || !a2 )
    return 0;
  while ( 1 )
  {
    if ( !*v2 )
      return 1;
    if ( !wcsicmp((int)v2, a2) )
      break;
    v2 += wcslen(v2) + 1;
  }
  v5 = wcslen(v2) + 1;
  if ( !v2[v5] )
  {
    *v2 = 0;
    v2[1] = 0;
    return 1;
  }
  v6 = PnpMultiSzGetLen(&v2[v5]);
  v7 = 2 * v6;
  if ( 2 * v6 )
  {
    v8 = ExAllocatePoolWithTag(1, 2 * v6, 1380994640);
    v9 = v8;
    if ( v8 )
    {
      memmove(v8, (int)&v2[v5], v7);
      memmove((int)v2, v9, v7);
      ExFreePoolWithTag(v9);
      return 1;
    }
  }
  return 0;
}
