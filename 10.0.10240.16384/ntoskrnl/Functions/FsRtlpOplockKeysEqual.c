// FsRtlpOplockKeysEqual 
 
int __fastcall FsRtlpOplockKeysEqual(int a1, int a2, char a3)
{
  int v6; // r4
  int v7; // r0
  int v8; // r3

  if ( (a3 & 0x40) != 0 )
    return sub_525D3C();
  if ( !a2 || !a1 )
    return 0;
  if ( a1 == a2 )
    return 1;
  v6 = IoGetOplockKeyContextEx(a1);
  v7 = IoGetOplockKeyContextEx(a2);
  if ( !v6 || !v7 || (*(_WORD *)(v7 + 2) & 2) == 0 || (a3 & 0x10) == 0 && (*(_WORD *)(v6 + 2) & 2) == 0 )
    return 0;
  if ( (a3 & 0x10) == 0 )
  {
    if ( *(_DWORD *)(v6 + 20) != *(_DWORD *)(v7 + 20)
      || *(unsigned __int16 *)(v6 + 24) != *(unsigned __int16 *)(v7 + 24)
      || *(unsigned __int16 *)(v6 + 26) != *(unsigned __int16 *)(v7 + 26)
      || *(unsigned __int8 *)(v6 + 28) != *(unsigned __int8 *)(v7 + 28)
      || *(unsigned __int8 *)(v6 + 29) != *(unsigned __int8 *)(v7 + 29)
      || *(unsigned __int8 *)(v6 + 30) != *(unsigned __int8 *)(v7 + 30)
      || *(unsigned __int8 *)(v6 + 31) != *(unsigned __int8 *)(v7 + 31)
      || *(unsigned __int8 *)(v6 + 32) != *(unsigned __int8 *)(v7 + 32)
      || *(unsigned __int8 *)(v6 + 33) != *(unsigned __int8 *)(v7 + 33)
      || *(unsigned __int8 *)(v6 + 34) != *(unsigned __int8 *)(v7 + 34) )
    {
      return 0;
    }
    v8 = *(unsigned __int8 *)(v6 + 35);
    return v8 == *(unsigned __int8 *)(v7 + 35);
  }
  if ( (*(_WORD *)(v6 + 2) & 1) == 0 )
    return 0;
  if ( *(_DWORD *)(v6 + 4) != *(_DWORD *)(v7 + 20)
    || *(unsigned __int16 *)(v6 + 8) != *(unsigned __int16 *)(v7 + 24)
    || *(unsigned __int16 *)(v6 + 10) != *(unsigned __int16 *)(v7 + 26)
    || *(unsigned __int8 *)(v6 + 12) != *(unsigned __int8 *)(v7 + 28)
    || *(unsigned __int8 *)(v6 + 13) != *(unsigned __int8 *)(v7 + 29)
    || *(unsigned __int8 *)(v6 + 14) != *(unsigned __int8 *)(v7 + 30)
    || *(unsigned __int8 *)(v6 + 15) != *(unsigned __int8 *)(v7 + 31)
    || *(unsigned __int8 *)(v6 + 16) != *(unsigned __int8 *)(v7 + 32)
    || *(unsigned __int8 *)(v6 + 17) != *(unsigned __int8 *)(v7 + 33)
    || *(unsigned __int8 *)(v6 + 18) != *(unsigned __int8 *)(v7 + 34) )
  {
    return 0;
  }
  v8 = *(unsigned __int8 *)(v6 + 19);
  return v8 == *(unsigned __int8 *)(v7 + 35);
}
