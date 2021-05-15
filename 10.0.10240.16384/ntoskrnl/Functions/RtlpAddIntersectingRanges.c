// RtlpAddIntersectingRanges 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlpAddIntersectingRanges(int a1, int a2, int a3, int a4)
{
  int v5; // r9
  int v7; // r10
  int v9; // r0
  _DWORD *v10; // r1
  int v11; // r0
  int v12; // r5
  int v13; // r3
  int v14; // r4
  int v15; // r7
  int v16; // r1
  int v17; // r3
  __int64 v18; // kr00_8
  int v19; // r2
  int v20; // r10
  int v21; // r1 OVERLAPPED
  _DWORD *v22; // r2 OVERLAPPED
  int v23; // r1 OVERLAPPED
  _DWORD *v24; // r2 OVERLAPPED

  v5 = a4;
  v7 = a1;
  if ( (a4 & 1) == 0 )
    return sub_80D520();
  if ( (*(_WORD *)(a2 + 26) & 1) == 0 )
  {
    v9 = RtlpCopyRangeListEntry(a2);
    if ( !v9 )
      return -1073741670;
    if ( (*(_BYTE *)(a2 + 25) & 0x10) != 0 )
    {
      --**(_DWORD **)(a2 + 16);
      *(_BYTE *)(a2 + 25) &= 0xEFu;
    }
    *(_DWORD *)(a2 + 16) = a2 + 16;
    *(_DWORD *)(a2 + 20) = a2 + 16;
    *(_WORD *)(a2 + 26) = 1;
    v10 = (_DWORD *)(v9 + 28);
    v11 = *(_DWORD *)(a2 + 16);
    *v10 = v11;
    v10[1] = a2 + 16;
    if ( *(_DWORD *)(v11 + 4) != a2 + 16 )
      __fastfail(3u);
    *(_DWORD *)(v11 + 4) = v10;
    *(_DWORD *)(a2 + 16) = v10;
  }
  v12 = *(_DWORD *)(a2 + 28) - 28;
  v13 = **(_DWORD **)(a2 + 28);
  while ( 1 )
  {
    v14 = v12 + 28;
    v15 = v13 - 28;
    if ( v7 == v12 + 28 || *(_QWORD *)(a3 + 8) < *(_QWORD *)v12 )
      break;
    if ( (*(_WORD *)(v12 + 26) & 1) != 0 )
    {
      v16 = *(_DWORD *)(v12 + 16) - 28;
      v17 = **(_DWORD **)(v12 + 16);
      while ( 1 )
      {
        v19 = v16 + 28;
        v20 = v17 - 28;
        if ( v12 + 16 == v16 + 28 )
          break;
        v18 = *(_QWORD *)v19;
        if ( *(_DWORD *)(*(_DWORD *)v19 + 4) != v19 || *(_DWORD *)HIDWORD(v18) != v19 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v18) = v18;
        *(_DWORD *)(v18 + 4) = HIDWORD(v18);
        RtlpAddToMergedRange(a2, v16, a4);
        v17 = *(_DWORD *)(v20 + 28);
        v16 = v20;
      }
      *(_QWORD *)&v21 = *(_QWORD *)v14;
      if ( *(_DWORD *)(*(_DWORD *)v14 + 4) != v14 || *v22 != v14 )
        __fastfail(3u);
      *v22 = v21;
      *(_DWORD *)(v21 + 4) = v22;
      RtlpFreeRangeListEntry(v12);
      v7 = a1;
      v5 = a4;
    }
    else
    {
      *(_QWORD *)&v23 = *(_QWORD *)v14;
      if ( *(_DWORD *)(*(_DWORD *)v14 + 4) != v14 || *v24 != v14 )
        __fastfail(3u);
      *v24 = v23;
      *(_DWORD *)(v23 + 4) = v24;
      RtlpAddToMergedRange(a2, v12, v5);
    }
    v13 = *(_DWORD *)(v15 + 28);
    v12 = v15;
  }
  return RtlpAddToMergedRange(a2, a3, v5);
}
