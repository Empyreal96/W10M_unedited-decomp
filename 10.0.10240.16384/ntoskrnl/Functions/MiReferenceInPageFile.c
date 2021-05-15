// MiReferenceInPageFile 
 
int __fastcall MiReferenceInPageFile(int a1)
{
  int v2; // r5
  int result; // r0
  int v4; // r7
  unsigned __int64 *v5; // r3
  unsigned __int64 v6; // kr00_8
  int v7; // r3
  _DWORD *v8; // r9

  v2 = *(_DWORD *)(a1 + 120);
  if ( !v2 )
    return 0;
  result = MI_REFERENCE_CONTROL_AREA_FILE(*(_DWORD *)(a1 + 120));
  v4 = result;
  if ( (*(_DWORD *)(v2 + 28) & 0x20) != 0 )
  {
    v5 = (unsigned __int64 *)(v2 + 64);
    do
      v6 = __ldrexd(v5);
    while ( __strexd(v6 + 1, v5) );
    v7 = *(_DWORD *)(a1 + 144);
    v8 = *(_DWORD **)(v2 + 56);
    if ( !v7 )
      v7 = a1 + 152;
    *(_DWORD *)(a1 + 108) = MiComputeImagePteIndex(MmPfnDatabase + 24 * *(_DWORD *)(v7 + 28));
    if ( *v8 && (*(_BYTE *)(a1 + 114) |= 8u, (BYTE2(MiFlags) & 3) == 3) )
      result = sub_543DBC();
    else
      result = v4;
  }
  else
  {
    *(_DWORD *)(a1 + 120) = 0;
  }
  return result;
}
