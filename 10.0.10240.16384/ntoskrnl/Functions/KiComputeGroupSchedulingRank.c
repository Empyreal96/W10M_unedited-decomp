// KiComputeGroupSchedulingRank 
 
unsigned int __fastcall KiComputeGroupSchedulingRank(int a1, int a2, int a3)
{
  __int64 v4; // r2
  unsigned int result; // r0
  unsigned int v7; // r5
  __int64 v8; // r0
  unsigned int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int v12; // kr14_4
  char v13; // r3
  int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  _DWORD *i; // r3
  int v19; // r3
  int v20; // r8
  __int64 v21; // r0
  __int64 v22; // kr18_8
  int v23; // r3
  int v24; // r2
  int v25; // r2
  int v26; // r3
  unsigned int v27; // r3
  int v28; // r4
  int v29; // r3
  int v30; // r0

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 > 0 )
    return sub_5159B4(a1, a2, v4);
  v7 = *(_DWORD *)(a1 + 8);
  v8 = (*(_QWORD *)&KiCycleDivisorLongTerm * (unsigned __int64)v7) >> 7;
  if ( !v8 )
    __brkdiv0();
  *(_DWORD *)(a3 + 96) = _rt_udiv64(v8, *(_QWORD *)(a3 + 32)) + 1;
  v9 = (*(_QWORD *)&KiCycleDivisorShortTerm * (unsigned __int64)v7) >> 32;
  v10 = (__int64)(*(_QWORD *)&KiCycleDivisorShortTerm * v7) >> 7;
  v11 = *(_DWORD *)(a3 + 12);
  v12 = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(a3 + 24) = v12 + v10;
  v13 = *(_BYTE *)(a3 + 92) | 4;
  *(_BYTE *)(a3 + 92) = v13;
  *(_DWORD *)(a3 + 28) = (__PAIR64__(v11, v12) + __PAIR64__(v9 >> 7, v10)) >> 32;
  if ( (v13 & 0x10) == 0 && (v13 & 2) == 0 && *(_QWORD *)a3 > *(_QWORD *)(a3 + 16) )
    *(_BYTE *)(a3 + 92) |= 2u;
  result = KiCheckForEffectivePriorityChange(a2, a3);
  if ( (*(_BYTE *)(a3 + 92) & 1) == 0 )
    goto LABEL_8;
  if ( (*(_BYTE *)(a3 + 92) & 2) != 0 )
  {
    do
    {
      v19 = *(_DWORD *)(a3 + 236);
      if ( v19 )
        v20 = v19 + 228;
      else
        v20 = a2 + 1976;
      v21 = KeQueryInterruptTime(result);
      v23 = *(_DWORD *)(a3 + 56);
      v22 = v21 - *(_QWORD *)(a3 + 64);
      v24 = *(_DWORD *)(a3 + 60);
      *(_DWORD *)(a3 + 56) = v23 + v22;
      *(_BYTE *)(a3 + 92) &= 0xFEu;
      *(_DWORD *)(a3 + 60) = HIDWORD(v22) + __CFADD__(v23, (_DWORD)v22) + v24;
      result = RtlRbRemoveNode(v20, a3 + 80);
      a3 = *(_DWORD *)(a3 + 236);
    }
    while ( a3 && (*(_BYTE *)(a3 + 92) & 1) != 0 && !*(_DWORD *)(a3 + 228) && !*(_WORD *)(a3 + 94) );
    goto LABEL_8;
  }
  v15 = a3 + 80;
  v16 = *(_DWORD *)(a3 + 84);
  if ( v16 )
  {
    for ( i = *(_DWORD **)v16; i; i = (_DWORD *)*i )
      v16 = (unsigned int)i;
  }
  else
  {
    v17 = *(_DWORD *)(a3 + 88);
    while ( 1 )
    {
      v16 = v17 & 0xFFFFFFFC;
      if ( (v17 & 0xFFFFFFFC) == 0 || *(_DWORD *)v16 == v15 )
        break;
      v17 = *(_DWORD *)(v16 + 8);
      v15 = v16;
    }
  }
  if ( !v16 )
    goto LABEL_8;
  v25 = *(_DWORD *)(a3 + 96);
  v26 = v25 - *(_DWORD *)(v16 + 16);
  if ( !v26 )
  {
    if ( *(_WORD *)(a3 + 94) )
    {
      result = 31 - __clz(*(unsigned __int16 *)(a3 + 94));
      v27 = 0;
      if ( *(_WORD *)(v16 + 14) )
        v27 = 31 - __clz(*(unsigned __int16 *)(v16 + 14));
      v26 = v27 - result;
    }
    else
    {
      if ( !v25 )
      {
        result = *(_DWORD *)a3;
        if ( *(_QWORD *)a3 > *(_QWORD *)(v16 - 80) )
          goto LABEL_46;
        goto LABEL_8;
      }
      v26 = 1;
    }
  }
  if ( v26 > 0 )
  {
LABEL_46:
    v28 = a3;
    do
    {
      v29 = *(_DWORD *)(v28 + 236);
      if ( v29 )
        v30 = v29 + 228;
      else
        v30 = a2 + 1976;
      *(_BYTE *)(v28 + 92) &= 0xFEu;
      RtlRbRemoveNode(v30, v28 + 80);
      v28 = *(_DWORD *)(v28 + 236);
    }
    while ( v28 && (*(_BYTE *)(v28 + 92) & 1) != 0 && !*(_DWORD *)(v28 + 228) && !*(_WORD *)(v28 + 94) );
    result = KiInsertSchedulingGroupQueue(a2, a3, 0);
  }
LABEL_8:
  if ( !*(_BYTE *)(a2 + 2331) )
  {
    v14 = *(_DWORD *)(a2 + 20);
    __dmb(0xBu);
    do
      result = __ldrex((unsigned int *)&dword_6162DC);
    while ( __strex(result | (1 << v14), (unsigned int *)&dword_6162DC) );
    __dmb(0xBu);
    *(_BYTE *)(a2 + 2331) = 1;
  }
  return result;
}
