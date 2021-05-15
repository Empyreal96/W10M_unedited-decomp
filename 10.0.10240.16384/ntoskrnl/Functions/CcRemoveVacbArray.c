// CcRemoveVacbArray 
 
unsigned int __fastcall __spoils<R0,R2,R3,R12> CcRemoveVacbArray(int *a1)
{
  int v2; // r6
  int v3; // r2
  _DWORD *v4; // r0
  unsigned int result; // r0
  _DWORD *v7; // r2
  __int64 v8; // kr00_8

  if ( a1[1] )
    KeBugCheckEx(52, 484, -1073740768, 0, 0);
  v2 = *a1;
  if ( *(int **)(CcVacbArrays + 4 * *a1) != a1 )
    KeBugCheckEx(52, 490, -1073740768, 0, 0);
  v3 = CcVacbArraysHighestUsedIndex;
  if ( v2 == CcVacbArraysHighestUsedIndex && CcVacbArraysHighestUsedIndex )
  {
    v4 = (_DWORD *)(CcVacbArrays + 4 * CcVacbArraysHighestUsedIndex);
    while ( !*v4-- )
    {
      if ( !--v3 )
        goto LABEL_10;
    }
    CcVacbArraysHighestUsedIndex = v3;
  }
LABEL_10:
  result = 0;
  *(_DWORD *)(CcVacbArrays + 4 * v2) = 0;
  if ( !CcVacbArraysAllocated )
    KeBugCheckEx(52, 518, -1073740768, 0, 0);
  --CcVacbArraysAllocated;
  v7 = a1 + 6;
  do
  {
    v8 = *(_QWORD *)v7;
    if ( *(_DWORD **)(*v7 + 4) != v7 || *(_DWORD **)HIDWORD(v8) != v7 )
      __fastfail(3u);
    ++result;
    *(_DWORD *)HIDWORD(v8) = v8;
    v7 += 6;
    *(_DWORD *)(v8 + 4) = HIDWORD(v8);
  }
  while ( result < 0x1554 );
  CcNumberOfFreeVacbs -= 5460;
  return result;
}
