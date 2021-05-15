// KiTransitionSchedulingGroupGeneration 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiTransitionSchedulingGroupGeneration(int a1, unsigned __int64 a2, char a3)
{
  unsigned __int64 v4; // r4
  unsigned int v6; // r8
  unsigned __int64 v7; // r2
  int v8; // r4
  int *v9; // r10
  int *v10; // r9
  int *v11; // r7
  int result; // r0
  char v13; // lr
  int *v14; // r5
  unsigned int v15; // r1
  int v16; // r2 OVERLAPPED
  int v17; // r1 OVERLAPPED
  int v18; // r4
  unsigned int v19; // r2
  unsigned int v20; // r1
  int v21; // r3
  __int64 v22; // r0
  unsigned int v23; // r3
  __int64 v24; // r2
  unsigned int v25; // r2
  int v26; // r3
  int v27; // r4
  unsigned int v28; // r2
  int v29; // r2
  int v30; // r1
  char v31; // r3
  char v32; // r2
  unsigned int v33; // r2
  unsigned int j; // r1
  unsigned int i; // r3
  int v36; // r2
  int v37; // r3
  unsigned int v38; // r0
  unsigned int v39; // r3
  int *v40; // r9
  int v41; // r3
  int v42; // r0
  int v43; // [sp+0h] [bp-28h]
  int v44; // [sp+4h] [bp-24h]

  v4 = *(_QWORD *)(a1 + 2408);
  v6 = 1;
  if ( a2 > v4 )
  {
    v7 = a2 + (unsigned int)KiGenerationTicks - v4 - 1;
    if ( !KiGenerationTicks )
      __brkdiv0();
    v6 = _rt_udiv64((unsigned int)KiGenerationTicks, v7) + 1;
  }
  *(_QWORD *)(a1 + 2408) = *(_QWORD *)&KiGenerationEndTick;
  *(_DWORD *)(a1 + 1976) = 0;
  *(_DWORD *)(a1 + 1980) = 0;
  v8 = *(_DWORD *)(a1 + 8);
  v43 = v8;
  v44 = 0;
  if ( !v8 )
  {
    v8 = *(_DWORD *)(a1 + 4);
    v43 = v8;
  }
  v9 = *(int **)(v8 + 68);
  if ( v9 )
    v9 = (int *)((char *)v9 + *(_DWORD *)(a1 + 2352));
  v10 = (int *)(a1 + 1984);
  v11 = *(int **)(a1 + 1984);
  if ( v11 == (int *)(a1 + 1984) )
  {
LABEL_24:
    v26 = *(_DWORD *)(a1 + 20);
    *(_BYTE *)(a1 + 2331) = 0;
    __dmb(0xBu);
    v27 = ~(1 << v26);
    do
    {
      v28 = __ldrex((unsigned int *)&dword_6162DC);
      result = v28 & v27;
    }
    while ( __strex(v28 & v27, (unsigned int *)&dword_6162DC) );
    __dmb(0xBu);
    return result;
  }
  result = 32 - v6;
  v13 = v6 - 32;
  do
  {
    v14 = v11 - 18;
    if ( v6 >= 0x40 )
      return sub_52BDD0(result);
    v15 = *(v11 - 6);
    v16 = (*(v11 - 5) << v6) | (v15 >> result) | (v15 << v13);
    v17 = v15 << v6;
    if ( (v11[5] & 4) != 0 )
      v17 |= 1u;
    *((_QWORD *)v11 - 3) = *(_QWORD *)&v17;
    if ( *(__int64 *)((char *)v14 - *(_DWORD *)(a1 + 2352) + 32) > 0 )
      KiChargeSchedulingGroupCycleTime();
    if ( *((_QWORD *)v11 - 8) != *((_QWORD *)v11 - 7) )
    {
      v18 = KiGroupSchedulingNumerator;
      v19 = (1024 - KiGroupSchedulingNumerator) * *(v11 - 10);
      v20 = (*((_QWORD *)v11 - 5) * (unsigned __int64)(unsigned int)(1024 - KiGroupSchedulingNumerator)) >> 32;
      v21 = v20 << 22;
      *(v11 - 10) = v19;
      *(v11 - 9) = v20;
      *(v11 - 9) = v20 >> 10;
      v22 = *(_QWORD *)v14;
      *(v11 - 10) = v21 | (v19 >> 10);
      v23 = v22 >> 10;
      LODWORD(v22) = v18 * v23;
      HIDWORD(v22) >>= 10;
      *v14 = v23;
      *(v11 - 17) = HIDWORD(v22);
      LODWORD(v24) = *(v11 - 10);
      HIDWORD(v24) = (__PAIR64__(HIDWORD(v22), v23) * (unsigned int)v18) >> 32;
      HIDWORD(v22) = *(v11 - 9);
      v8 = v43;
      *((_QWORD *)v11 - 5) = v22 + v24;
    }
    v25 = *((unsigned __int8 *)v11 + 20);
    *v14 = 0;
    *(v11 - 17) = 0;
    v11[6] = (v25 >> 3) & 1;
    *(v11 - 8) = 0;
    *(v11 - 7) = 0;
    *(v11 - 12) = 0;
    *(v11 - 11) = 0;
    *((_BYTE *)v11 + 20) = v25 & 0xFC;
    v11[2] = 0;
    v11[3] = 0;
    v11[4] = 0;
    v11[39] = 0;
    v11[40] = 0;
    if ( v11[6] && !a3 )
    {
      if ( !*((_WORD *)v11 + 11) )
        goto LABEL_22;
      while ( 1 )
      {
        if ( (v14[23] & 2) != 0 )
        {
LABEL_43:
          v8 = v43;
          v44 = 1;
          v10 = (int *)(a1 + 1984);
          goto LABEL_22;
        }
        if ( (v14[23] & 1) == 0 )
          goto LABEL_41;
        v33 = (unsigned int)(v14 + 20);
        j = v14[20];
        if ( j )
        {
          for ( i = *(_DWORD *)(j + 4); i; i = *(_DWORD *)(i + 4) )
            j = i;
        }
        else
        {
          for ( j = v14[22] & 0xFFFFFFFC; j; j = *(_DWORD *)(j + 8) & 0xFFFFFFFC )
          {
            if ( *(_DWORD *)(j + 4) == v33 )
              break;
            v33 = j;
          }
        }
        if ( !j )
          goto LABEL_42;
        v36 = v14[24];
        v37 = v36 - *(_DWORD *)(j + 16);
        if ( v37 )
          goto LABEL_59;
        if ( *((_WORD *)v14 + 47) )
          break;
        if ( v36 || *(_QWORD *)v14 > *(_QWORD *)(j - 80) )
          goto LABEL_42;
LABEL_63:
        v40 = v14;
        do
        {
          v41 = v40[59];
          if ( v41 )
            v42 = v41 + 228;
          else
            v42 = a1 + 1976;
          *((_BYTE *)v40 + 92) &= 0xFEu;
          RtlRbRemoveNode(v42, v40 + 20);
          v40 = (int *)v40[59];
        }
        while ( v40 && (v40[23] & 1) != 0 && !v40[57] && !*((_WORD *)v40 + 47) );
LABEL_41:
        KiInsertSchedulingGroupQueue(a1, v14, 0);
LABEL_42:
        v14 = (int *)v14[59];
        if ( !v14 )
          goto LABEL_43;
      }
      v38 = 31 - __clz(*((unsigned __int16 *)v14 + 47));
      v39 = 0;
      if ( *(_WORD *)(j + 14) )
        v39 = 31 - __clz(*(unsigned __int16 *)(j + 14));
      v37 = v39 - v38;
LABEL_59:
      if ( v37 >= 0 )
        goto LABEL_42;
      goto LABEL_63;
    }
    KiMoveScbThreadsToNewReadylist(v11 - 18, 0, a1, 0, v43);
    if ( !v11[6] )
    {
      *((_BYTE *)v11 + 20) &= 0xFBu;
      if ( v14 == v9 )
      {
        if ( (*(_BYTE *)(v8 + 2) & 4) != 0 )
        {
          if ( *(char *)(v8 + 123) < 16
            && *(_DWORD *)(v8 + 68)
            && (v29 = *(_DWORD *)(v8 + 68)) != 0
            && (v30 = *(_DWORD *)(a1 + 2352) + v29) != 0
            && KiGetThreadEffectiveRankNonZero(v8, v30, 0) )
          {
            v31 = 1;
          }
          else
          {
            v31 = *(_BYTE *)(v8 + 123);
          }
          v32 = v31;
        }
        else
        {
          v32 = *(_BYTE *)(v8 + 123);
        }
        **(_BYTE **)(a1 + 28) = v32;
      }
    }
LABEL_22:
    v11 = (int *)*v11;
    result = 32 - v6;
    v13 = v6 - 32;
  }
  while ( v11 != v10 );
  if ( !v44 )
    goto LABEL_24;
  return result;
}
