// SeTokenCanImpersonate 
 
int __fastcall SeTokenCanImpersonate(int a1, _DWORD *a2, int a3, _BYTE *a4)
{
  int v6; // r4
  char v8[94]; // [sp+6h] [bp-5Eh] BYREF

  v8[0] = 0;
  *a4 = 0;
  if ( a3 < 2 || a2[6] == 998 && !a2[7] )
    return 0;
  v6 = RtlSidDominatesForTrust(*(_DWORD *)(a1 + 640), a2[160], v8);
  if ( v6 >= 0 )
  {
    if ( !v8[0] )
      *a4 = 1;
    if ( (*(_DWORD *)(a1 + 72) & 0x20000000) == 0 )
      return sub_7F4EDC();
    return 0;
  }
  return v6;
}
