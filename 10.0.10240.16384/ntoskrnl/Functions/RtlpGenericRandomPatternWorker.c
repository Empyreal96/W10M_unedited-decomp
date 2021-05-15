// RtlpGenericRandomPatternWorker 
 
int __fastcall RtlpGenericRandomPatternWorker(unsigned int a1)
{
  unsigned int *v1; // r3
  int v3; // r6
  unsigned int v4; // r8
  __int64 v5; // kr00_8
  _DWORD *v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // lr
  _DWORD *v9; // r1
  int v10; // r1
  int v11; // r1
  int v12; // r1
  int v13; // r1
  int v14; // r1
  int v15; // r0
  int v16; // r1
  int v17; // r0
  int v18; // r1
  unsigned int *v20; // [sp+8h] [bp-20h]

  v1 = (unsigned int *)GlfsrXorLookupTables;
  v3 = 0;
  while ( 1 )
  {
    v4 = *v1;
    v20 = v1 + 1;
    v5 = RtlpSeedGlfsr();
    RtlpFillMemoryRandomUp(a1, SHIDWORD(v5), v5, HIDWORD(v5), v4);
    KeInvalidateRangeAllCaches(a1, 4096);
    v6 = (_DWORD *)a1;
    v8 = HIDWORD(v5);
    v7 = v5;
    if ( a1 < a1 + 4096 )
      break;
LABEL_6:
    KeInvalidateRangeAllCaches(a1, 4096);
    if ( !RtlpTestMemoryRandomUp(a1, v10, v5, HIDWORD(v5)) )
      return 0;
    RtlpFillMemoryRandomInvertedUp(a1, v11, v5, HIDWORD(v5), v4);
    KeInvalidateRangeAllCaches(a1, 4096);
    RtlpFillMemoryRandomUp(a1, v12, v5, HIDWORD(v5), v4);
    KeInvalidateRangeAllCaches(a1, 4096);
    if ( !RtlpTestMemoryRandomUp(a1, v13, v5, HIDWORD(v5)) )
      return 0;
    v15 = RtlpFillMemoryRandomInvertedDown(a1, v14, v5, HIDWORD(v5), v4);
    KeInvalidateRangeAllCaches(v15, 4096);
    v17 = RtlpFillMemoryRandomDown(a1, v16, v5, HIDWORD(v5), v4);
    KeInvalidateRangeAllCaches(v17, 4096);
    if ( !RtlpTestMemoryRandomDown(a1, v18, v5, HIDWORD(v5)) )
      return 0;
    if ( (unsigned int)++v3 >= 5 )
      return 1;
    v1 = v20;
  }
  while ( *v6 == v7 )
  {
    *v6 = v7;
    if ( v6[1] != v8 )
      break;
    v9 = (_DWORD *)(v4 + 8 * (v7 & 0xF));
    v6[1] = v8;
    v6 += 2;
    v7 = ((v8 << 28) | (v7 >> 4)) ^ *v9;
    v8 = v9[1] ^ (v8 >> 4);
    if ( (unsigned int)v6 >= a1 + 4096 )
      goto LABEL_6;
  }
  return 0;
}
