// sub_970284 
 
_DWORD *sub_970284()
{
  _DWORD *v0; // r6
  __int64 v1; // r0
  int v2; // r3
  __int64 v3; // r0
  _QWORD *v4; // r7
  char *v5; // r3
  int v6; // r0
  unsigned int v7; // r1
  int v8; // r8
  char v9; // lr
  char v10; // r9
  int v11; // r10
  unsigned int v12; // r1
  unsigned int v13; // r5
  int v14; // r4
  unsigned int v15; // t1
  unsigned int v16; // r1
  unsigned int v17; // r5
  int v18; // r4
  __int64 v19; // kr20_8
  unsigned int v20; // r7
  unsigned int v21; // r8
  unsigned __int64 v22; // r0
  __int64 v23; // r2
  unsigned __int64 v24; // kr28_8

  LODWORD(v1) = ReadTimeStampCounter();
  v2 = (41929663 * (v1 >> 4)) ^ 0xF93;
  v0[20] = v2;
  v0[21] = 0;
  if ( !v2 )
  {
    v0[20] = 1;
    v0[21] = 0;
  }
  LODWORD(v3) = ReadTimeStampCounter();
  v0[22] = (41929663 * (v3 >> 4)) ^ 0x531;
  v0[23] = 0;
  v4 = (_QWORD *)(__mrc(15, 0, 12, 0, 0) & 0xFFFFFFE0);
  v5 = (char *)v4;
  if ( v4 < v4 + 4 )
  {
    do
    {
      __pld(v5);
      v5 += 128;
    }
    while ( v5 < (char *)v4 + 32 );
  }
  v6 = v0[21];
  v7 = v0[20];
  v8 = 32;
  v9 = v0[22] & 0x3F;
  v10 = 64 - v9;
  v11 = 4;
  do
  {
    v8 -= 8;
    v13 = (__PAIR64__(v6, v7) - *v4) >> 32;
    v12 = v7 - *(_DWORD *)v4;
    v14 = __PAIR64__(v13, v12) << v10 >> 32;
    v7 = (v12 << v10) | (__PAIR64__(v13, v12) >> v9);
    ++v4;
    v6 = v14 | (v13 >> v9);
    --v11;
  }
  while ( v11 );
  for ( ; v8; --v8 )
  {
    v15 = *(unsigned __int8 *)v4;
    v4 = (_QWORD *)((char *)v4 + 1);
    v17 = (__PAIR64__(v6, v7) - v15) >> 32;
    v16 = v7 - v15;
    v18 = __PAIR64__(v17, v16) << v10 >> 32;
    v7 = (v16 << v10) | (__PAIR64__(v17, v16) >> v9);
    v6 = v18 | (v17 >> v9);
  }
  v0[26] = v7;
  v0[27] = v6;
  do
  {
    v19 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v20 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v21 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v20 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v19 != MEMORY[0xFFFF93B0] );
  LODWORD(v22) = ReadTimeStampCounter();
  _rt_udiv64(80000000000i64, 41929663 * (v22 >> 4));
  v24 = v23 - v19 + __PAIR64__(v20, v21);
  v0[24] = v24 + 237191168;
  v0[25] = __CFADD__((_DWORD)v24, 237191168) + HIDWORD(v24) + 67;
  CmpLazyCommitDpc = 19;
  byte_632221 = 1;
  word_632222 = 0;
  dword_63222C = (int)CmpLazyCommitDpcRoutine;
  dword_632230 = 0;
  dword_63223C = 0;
  dword_632228 = 0;
  KeInitializeTimerEx(CmpLazyCommitTimer, 0);
  CmpDelayFreeRMListHead = (int)&CmpDelayFreeRMListHead;
  dword_631FC4 = (int)&CmpDelayFreeRMListHead;
  CmpDelayFreeRMLock = 1;
  dword_631FE4 = 0;
  unk_631FE8 = 0;
  byte_631FEC = 1;
  byte_631FED = 0;
  byte_631FEE = 4;
  dword_631FF0 = 0;
  dword_631FF8 = (int)&dword_631FF4;
  dword_631FF4 = (int)&dword_631FF4;
  dword_632008 = (int)CmpDelayFreeRMWorker;
  dword_63200C = 0;
  CmpDelayFreeRMWorkItem = 0;
  CmpDelayFreeRMDpc = 19;
  byte_632021 = 1;
  word_632022 = 0;
  dword_63202C = (int)CmpDelayFreeRMDpcRoutine;
  dword_632030 = 0;
  dword_63203C = 0;
  dword_632028 = 0;
  return KeInitializeTimerEx(CmpDelayFreeRMTimer, 0);
}
