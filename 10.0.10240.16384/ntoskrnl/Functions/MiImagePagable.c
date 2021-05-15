// MiImagePagable 
 
int *__fastcall MiImagePagable(int *a1, unsigned int a2)
{
  int *v3; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r0
  int v7; // r1

  v3 = a1;
  if ( (dword_681250 & 1) != 0 || (*(_DWORD *)(((a2 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return 0;
  if ( !a1 )
    v3 = MiLookupDataTableEntry(a2, 0);
  if ( a2 >= dword_63389C )
  {
    v4 = MiGetSystemRegionIndex(a2);
    if ( *(_BYTE *)(v4 + v5 + 9692) == 1 )
      return 0;
    v6 = MiGetSystemRegionIndex(a2);
    if ( *(_BYTE *)(v6 + v7 + 9692) == 11 )
      return 0;
  }
  return v3;
}
