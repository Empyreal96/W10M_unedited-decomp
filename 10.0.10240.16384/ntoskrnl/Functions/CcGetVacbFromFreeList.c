// CcGetVacbFromFreeList 
 
int __fastcall CcGetVacbFromFreeList(int a1)
{
  int v1; // r4
  int v3; // r0
  _DWORD *v4; // r2
  int v5; // r0
  unsigned int v6; // r2

  v1 = 0;
  if ( a1 )
    return sub_53B4B4();
  if ( (int *)CcVacbFreeList != &CcVacbFreeList )
  {
    v1 = CcVacbFreeList - 8;
    v3 = *(_DWORD *)CcVacbFreeList;
    ++CcNumberOfMappedVacbs;
    v4 = *(_DWORD **)(CcVacbFreeList + 4);
    if ( *(_DWORD *)(v3 + 4) != CcVacbFreeList || *v4 != CcVacbFreeList )
      __fastfail(3u);
    *v4 = v3;
    *(_DWORD *)(v3 + 4) = v4;
    if ( !CcNumberOfFreeVacbs )
      KeBugCheckEx(52, 790, -1073740768);
    --CcNumberOfFreeVacbs;
    v5 = *(_DWORD *)(v1 + 16);
    v6 = (v1 - v5 - 16) / 24;
    if ( v6 > *(_DWORD *)(v5 + 8) )
      *(_DWORD *)(v5 + 8) = v6;
    if ( !*(_DWORD *)v1 )
      CcReferenceVacbArray(**(_DWORD **)(v1 + 16));
    *(_DWORD *)(v1 + 4) = -1;
  }
  return v1;
}
