// PiCompareDDBCacheEntries 
 
int __fastcall PiCompareDDBCacheEntries(int a1, int a2, int a3)
{
  signed int v6; // r0
  unsigned int v8; // r3
  unsigned int v9; // r2

  v6 = RtlCompareUnicodeString((unsigned __int16 *)(a2 + 8), (unsigned __int16 *)(a3 + 8), 1);
  if ( v6 < 0 )
    return 0;
  if ( v6 > 0 )
    return 1;
  if ( *(_DWORD *)(a1 + 52) )
    return 2;
  v8 = *(_DWORD *)(a2 + 16);
  v9 = *(_DWORD *)(a3 + 16);
  if ( v8 < v9 )
    return 0;
  if ( v8 > v9 )
    return 1;
  return 2;
}
