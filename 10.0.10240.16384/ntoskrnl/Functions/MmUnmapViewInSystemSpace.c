// MmUnmapViewInSystemSpace 
 
int __fastcall MmUnmapViewInSystemSpace(unsigned int a1)
{
  int *v2; // r1
  int v3; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r0
  int v7; // r0

  v2 = MiState;
  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( a1 < dword_63389C
    || (v4 = MiGetSystemRegionIndex(a1), *(_BYTE *)(v4 + v5 + 9692) != 1)
    && (v6 = MiGetSystemRegionIndex(a1), *((_BYTE *)v2 + v6 + 9692) != 11) )
  {
    v7 = (int)(v2 + 313);
LABEL_5:
    MiRemoveFromSystemSpace(v7, a1, 1);
    return 0;
  }
  if ( (*(_DWORD *)(v3 + 192) & 0x10000) != 0 )
  {
    v7 = *(_DWORD *)(v3 + 324) + 3200;
    goto LABEL_5;
  }
  return -1073741799;
}
