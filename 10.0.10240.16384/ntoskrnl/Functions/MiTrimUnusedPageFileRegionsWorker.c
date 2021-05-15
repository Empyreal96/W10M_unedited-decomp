// MiTrimUnusedPageFileRegionsWorker 
 
int __fastcall MiTrimUnusedPageFileRegionsWorker(int a1)
{
  unsigned int v2; // r5
  unsigned int *v3; // r7
  unsigned int v4; // r4
  unsigned int v5; // r1
  __int64 v6; // r0
  unsigned __int8 *v7; // r8
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  __int16 v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r9
  int v14; // r4
  unsigned int v15; // r8
  int v16; // r10
  __int16 v17; // r3
  int v18; // r3
  int v19; // r4
  int v20; // r7
  unsigned int v21; // r1
  int v22; // r0
  __int16 v23; // r3
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int v26; // r4
  unsigned int v27; // r7
  unsigned int v29; // [sp+18h] [bp-B0h]
  int v30; // [sp+1Ch] [bp-ACh]
  int v31; // [sp+20h] [bp-A8h] BYREF
  int v32; // [sp+24h] [bp-A4h]
  int v33[10]; // [sp+28h] [bp-A0h] BYREF
  int v34; // [sp+50h] [bp-78h] BYREF
  unsigned int v35; // [sp+54h] [bp-74h]
  int v36; // [sp+58h] [bp-70h]
  char v37[48]; // [sp+60h] [bp-68h] BYREF
  _QWORD v38[3]; // [sp+90h] [bp-38h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = (unsigned int *)(a1 + 564);
  __pld((void *)(a1 + 564));
  v34 = 0;
  v35 = v2;
  v4 = *(_DWORD *)(a1 + 564) & 0xFFFFFFFE;
  do
    v5 = __ldrex(v3);
  while ( v5 == v4 && __strex(v4 + 2, v3) );
  __dmb(0xBu);
  if ( v5 == v4 || (LODWORD(v6) = ExfAcquireRundownProtection((_DWORD *)(a1 + 564)), (_DWORD)v6) )
  {
    --*(_WORD *)(v2 + 310);
    v7 = (unsigned __int8 *)(a1 + 652);
    v8 = KeAbPreAcquire(a1 + 652, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex(v7);
    while ( __strex(v10 | 1, v7) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      v8 = ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 652), v8, a1 + 652);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    v11 = *(_WORD *)(v2 + 310) + 1;
    *(_WORD *)(v2 + 310) = v11;
    if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 )
      KiCheckForKernelApcDelivery(v8);
    v12 = *(_DWORD *)(a1 + 3596);
    v29 = v12;
    __dmb(0xBu);
    v13 = 0;
    if ( v12 )
    {
      v14 = a1;
      v32 = a1;
      v15 = v12;
      do
      {
        v16 = *(_DWORD *)(v14 + 3600);
        v17 = *(_WORD *)(v16 + 96);
        if ( (v17 & 0x40) == 0 && (v17 & 0x10) != 0 )
        {
          memset(v33, 0, 36);
          LOWORD(v33[0]) = 0;
          BYTE2(v33[0]) = 4;
          v33[1] = 0;
          v33[3] = (int)&v33[2];
          v33[4] = a1;
          v33[2] = (int)&v33[2];
          v33[5] = v13;
          v33[6] = 0x2000;
          if ( *(_DWORD *)(v16 + 28) >= 0x2000u )
          {
            do
            {
              MiQueueSyncModifiedWriterApc(
                a1,
                (int)v37,
                (int)MiTrimUnusedPageFileRegionsApc,
                (int)v33,
                (unsigned int)v33);
              if ( !v33[8] )
                break;
              memset(v38, 0, sizeof(v38));
              HIDWORD(v38[0]) = 1;
              v38[1] = (unsigned __int64)(unsigned int)v33[7] << 12;
              v38[2] = (unsigned __int64)(unsigned int)v33[8] << 12;
              KeResetEvent((int)v33);
              v30 = ZwFsControlFile();
              if ( v30 == 259 )
              {
                KeWaitForSingleObject((unsigned int)v33, 0, 0, 0, 0);
                v30 = v36;
              }
              MI_SET_PAGING_FILE_INFO(&v31, &v34, v16, v33[7], 3);
              v18 = v33[8];
              v33[9] = v33[8];
              if ( v33[8] )
              {
                v19 = v31;
                v20 = v33[8];
                do
                {
                  MiReleasePageFileInfo(a1, v19, 0, v18);
                  v18 = (v19 & 0xFFFFE000) + 0x2000;
                  v19 = v19 & 0x1FFF ^ v18;
                  --v20;
                }
                while ( v20 );
                v31 = v19;
              }
              if ( v30 < 0 )
                break;
              KeResetEvent((int)v33);
              v33[7] += v33[8];
              v33[8] = 0;
            }
            while ( v33[7] < *(_DWORD *)v16 );
            v14 = v32;
            v15 = v29;
          }
        }
        ++v13;
        v14 += 4;
        v32 = v14;
      }
      while ( v13 < v15 );
      v2 = v35;
      v3 = (unsigned int *)(a1 + 564);
      v7 = (unsigned __int8 *)(a1 + 652);
    }
    --*(_WORD *)(v2 + 310);
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v7);
    while ( __strex(v21 - 1, (unsigned int *)v7) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v7);
    v22 = KeAbPostRelease((unsigned int)v7);
    v23 = *(_WORD *)(v2 + 310) + 1;
    *(_WORD *)(v2 + 310) = v23;
    if ( !v23 && *(_DWORD *)(v2 + 100) != v2 + 100 )
      KiCheckForKernelApcDelivery(v22);
    MiContractWsSwapPageFile(a1);
    __pld(v3);
    v24 = *v3 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v25 = __ldrex(v3);
    while ( v25 == v24 && __strex(v24 - 2, v3) );
    if ( v25 != v24 )
      ExfReleaseRundownProtection((unsigned __int8 *)v3);
    do
    {
      v6 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v26 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v27 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v26 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v6 != MEMORY[0xFFFF93B0] );
    *(_QWORD *)(a1 + 624) = __PAIR64__(v26, v27) - v6;
    __dmb(0xFu);
    *(_DWORD *)(a1 + 620) = 0;
  }
  return v6;
}
