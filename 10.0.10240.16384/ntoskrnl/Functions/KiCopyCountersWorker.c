// KiCopyCountersWorker 
 
int __fastcall KiCopyCountersWorker(int a1, int a2)
{
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r2
  int v8; // r9
  unsigned __int64 v9; // kr00_8
  int v10; // r3
  int v11; // r10
  int v12; // r0
  int v13; // r8
  unsigned int v14; // lr
  unsigned int v15; // r1
  _DWORD *v16; // r4
  _DWORD *v17; // r0
  int v18; // r1
  _DWORD *v19; // r3
  int v20; // r2
  int v21; // r3
  int v23; // [sp+0h] [bp-30h]

  v4 = *(_DWORD *)(a2 + 8);
  KeGetCurrentProcessorNumberEx(v4 + 4);
  *(_QWORD *)(v4 + 56) = *(_QWORD *)(a1 + 48) - *(_QWORD *)(a2 + 24);
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = *(_DWORD *)(v5 + 3784);
  v7 = *(_DWORD *)(v5 + 3788);
  *(_DWORD *)(v4 + 48) = v6;
  *(_DWORD *)(v4 + 52) = v7;
  v8 = 1;
  if ( (*(_DWORD *)(a2 + 12) & 1) != 0 )
  {
    *(_DWORD *)(v4 + 8) = *(_DWORD *)(a2 + 16);
    if ( *(_QWORD *)a2 )
    {
      __dmb(0xBu);
      do
        v9 = __ldrexd((unsigned __int64 *)a2);
      while ( __strexd(0i64, (unsigned __int64 *)a2) );
      __dmb(0xBu);
      v10 = *(_DWORD *)(v4 + 28) | HIDWORD(v9);
      *(_DWORD *)(v4 + 24) |= v9;
      *(_DWORD *)(v4 + 28) = v10;
    }
  }
  v11 = *(_DWORD *)(a2 + 32);
  v12 = *(_DWORD *)(a2 + 36);
  v23 = v12;
  if ( *(_QWORD *)(a2 + 32) )
  {
    v13 = 0;
    v14 = 0;
    v15 = KiHwCountersCount;
    while ( v14 < v15 )
    {
      if ( v13 & v12 | v8 & v11 )
      {
        v16 = (_DWORD *)(v4 + 24 * v14);
        v16[17] = KiHwCounters[v14];
        v17 = (_DWORD *)(a2 + 24 * v14);
        v18 = v17[13];
        v19 = (_DWORD *)(v4 + 24 * (v14 + 3));
        *v19 = v17[12];
        v19[1] = v18;
        v20 = v17[15];
        v16[20] = v17[14];
        v16[21] = v20;
        v15 = KiHwCountersCount;
        v12 = v23;
      }
      v21 = (unsigned __int64)(unsigned int)v8 >> 31;
      v8 *= 2;
      v13 = v21 | (2 * v13);
      ++v14;
    }
    *(_DWORD *)(v4 + 12) = v15;
  }
  ++*(_QWORD *)(v4 + 16);
  return 0;
}
