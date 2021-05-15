// RtlpMuiRegGetOrAddLangInfo 
 
int __fastcall RtlpMuiRegGetOrAddLangInfo(int *a1, int a2, _WORD *a3)
{
  int v6; // r4
  int v8; // r0
  __int16 v9; // r6
  unsigned int v10; // r3
  unsigned int v11; // r2

  if ( !a1 )
    return -1073741811;
  v6 = *a1;
  if ( !*a1 || !a2 )
    return -1073741811;
  if ( !*(_WORD *)(a2 + 4) )
    return sub_819E08();
  v8 = RtlpMuiRegGetLangInfoIndex(*a1, a2);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = *(unsigned __int16 *)(v6 + 6);
    v11 = *(unsigned __int16 *)(v6 + 4);
    if ( v10 >= v11 )
    {
      if ( (int)(v10 + 4) >= (int)v11 )
        v6 = RtlpMuiRegResizeLanguages(v6);
      if ( !v6 )
        return -1073741801;
      *a1 = v6;
    }
    v9 = *(_WORD *)(v6 + 6);
    *(_WORD *)(v6 + 6) = v9 + 1;
    memmove(*(_DWORD *)(v6 + 12) + 28 * v9, a2, 0x1Cu);
  }
  if ( a3 )
    *a3 = v9;
  return 0;
}
