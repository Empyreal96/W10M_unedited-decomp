// sub_80D460 
 
void __fastcall sub_80D460(__int64 a1, int a2, int a3, int *a4, int **a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r4
  int v14; // r6
  int v15; // r7
  _DWORD *v16; // r2
  int v17; // r6
  int v18; // r5
  __int64 v19; // r1
  int v20; // r1
  int v21; // r3
  int v22; // r5
  __int64 v23; // r0

  if ( *(_DWORD *)HIDWORD(a1) != a2 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(a1) = v14;
  *(_DWORD *)(v14 + 4) = HIDWORD(a1);
  a5 = &a4;
  a4 = (int *)&a4;
  HIDWORD(a1) = *(_DWORD *)(v13 + 16) - 28;
  v16 = *(_DWORD **)(v13 + 16);
  v17 = *v16 - 28;
  if ( (_DWORD *)(v13 + 16) == v16 )
    goto LABEL_12;
  while ( 1 )
  {
    LODWORD(a1) = v16[1];
    v18 = *v16;
    if ( *(_DWORD **)(*v16 + 4) != v16 || *(_DWORD **)a1 != v16 )
      __fastfail(3u);
    *(_DWORD *)a1 = v18;
    *(_DWORD *)(v18 + 4) = a1;
    LODWORD(a1) = &a4;
    *(_BYTE *)(HIDWORD(a1) + 25) &= 0xFDu;
    if ( RtlpAddRange(a1, 1) < 0 )
      break;
    HIDWORD(a1) = v17;
    v16 = (_DWORD *)(v17 + 28);
    v17 = *(_DWORD *)(v17 + 28) - 28;
    if ( (_DWORD *)(v13 + 16) == v16 )
    {
      if ( a4 != (int *)&a4 )
      {
        v19 = *(_QWORD *)(v13 + 28);
        *(_DWORD *)HIDWORD(v19) = a4;
        a4[1] = HIDWORD(v19);
        *(_DWORD *)(v19 + 4) = a5;
        *a5 = (int *)v19;
        goto LABEL_15;
      }
LABEL_12:
      v23 = *(_QWORD *)(v13 + 28);
      if ( *(_DWORD *)(v23 + 4) != v13 + 28 || *(_DWORD *)HIDWORD(v23) != v13 + 28 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v23) = v23;
      *(_DWORD *)(v23 + 4) = HIDWORD(v23);
LABEL_15:
      RtlpFreeRangeListEntry(v15);
      RtlpFreeRangeListEntry(v13);
LABEL_16:
      __asm { POP.W           {R1-R8,R11,PC} }
    }
  }
  v20 = (int)(a4 - 7);
  v21 = *a4;
  while ( 1 )
  {
    v22 = v21 - 28;
    if ( &a4 == (int **)(v20 + 28) )
      break;
    RtlpAddToMergedRange(v13, v20, 1);
    v21 = *(_DWORD *)(v22 + 28);
    v20 = v22;
  }
  RtlpAddToMergedRange(v13, v15, 1);
  goto LABEL_16;
}
