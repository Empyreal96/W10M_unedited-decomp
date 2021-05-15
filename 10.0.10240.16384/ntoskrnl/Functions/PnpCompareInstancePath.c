// PnpCompareInstancePath 
 
int __fastcall PnpCompareInstancePath(int a1, int a2, int a3)
{
  int v3; // r0

  v3 = RtlCompareUnicodeStrings(
         *(_DWORD *)(*(_DWORD *)(a2 + 4) + 4),
         **(unsigned __int16 **)(a2 + 4) >> 1,
         *(_DWORD *)(*(_DWORD *)(a3 + 4) + 4),
         **(unsigned __int16 **)(a3 + 4) >> 1);
  if ( v3 < 0 )
    return 0;
  if ( v3 <= 0 )
    return 2;
  return 1;
}
