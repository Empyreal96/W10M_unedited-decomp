// PfpScenCtxPrefetchWait 
 
unsigned int __fastcall PfpScenCtxPrefetchWait(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int v4; // r10
  int v5; // r7
  int v6; // r9
  unsigned int v8; // r8
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r9
  int v15; // r4
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned __int64 v20; // kr10_8
  int v21; // r4
  int v22; // r3
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  int v30; // [sp+Ch] [bp-44h]
  int v31[2]; // [sp+10h] [bp-40h] BYREF
  __int64 v32; // [sp+18h] [bp-38h] BYREF
  int v33[12]; // [sp+20h] [bp-30h] BYREF

  v3 = a3;
  v4 = 0;
  v5 = 2000;
  v30 = a2;
  if ( dword_643A6C >= (unsigned int)dword_643A70 )
    v5 = 0;
  v6 = a2;
  v8 = 0;
  while ( 1 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = KeAbPreAcquire(a1, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v12 | 1, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v10, a1);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( *(_DWORD *)(a1 + 28) != v6 || (*(_DWORD *)(a1 + 4) & 0xC) == 8 )
      break;
    if ( v4 )
    {
      v22 = *(_DWORD *)(a1 + 4);
LABEL_36:
      v23 = *(_DWORD *)(a1 + 24);
      *(_DWORD *)(a1 + 4) = v22 & 0xFFFFFFF3 | 8;
      if ( v23 )
        KeSetEvent(v23, 0, 0);
      break;
    }
    KeResetEvent(a1 + 8);
    v13 = *(_DWORD *)(a1 + 4);
    if ( (v13 & 3) == 1 )
    {
      v14 = 2;
      v15 = v3 - v8;
    }
    else
    {
      if ( (v13 & 3) != 0 || !v5 )
      {
        v22 = *(_DWORD *)(a1 + 4);
        if ( (v22 & 3) != 0 )
          break;
        goto LABEL_36;
      }
      v15 = v5;
      v14 = 1;
      v5 = 0;
    }
    *(_DWORD *)(a1 + 4) = v13 & 0xFFFFFFF3 | 4;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)a1);
    while ( __strex(v16 - 1, (unsigned int *)a1) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)a1);
    v17 = KeAbPostRelease(a1);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
    v32 = -10000i64 * (unsigned int)v15;
    KeQueryTickCount(v31);
    v20 = (((unsigned int)v31[0] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
        + (((unsigned int)v31[1] * (unsigned __int64)MEMORY[0xFFFF9004]) << 8);
    v33[3] = HIDWORD(v20);
    v21 = KeWaitForSingleObject(a1 + 8, 0, 0, 0, (int *)&v32);
    KeQueryTickCount(v33);
    v3 = a3;
    v8 += ((__int64)((unsigned int)v33[0] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
        + ((MEMORY[0xFFFF9004] * v33[1]) << 8)
        - v20;
    if ( v21 == 258 || v8 >= a3 )
    {
      v4 = 1;
    }
    else if ( v14 == 2 )
    {
      return v8;
    }
    v6 = v30;
  }
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)a1);
  while ( __strex(v24 - 1, (unsigned int *)a1) );
  if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  v25 = KeAbPostRelease(a1);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = *(_WORD *)(v26 + 0x134) + 1;
  *(_WORD *)(v26 + 308) = v27;
  if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
    KiCheckForKernelApcDelivery(v25);
  return v8;
}
