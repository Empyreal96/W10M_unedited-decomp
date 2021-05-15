// MmOutSwapVirtualAddresses 
 
int __fastcall MmOutSwapVirtualAddresses(int a1, unsigned int *a2, int a3, int **a4)
{
  int v4; // r7
  int v7; // r4
  int v8; // r9
  int v9; // r4
  int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r7
  unsigned int v13; // r8
  int v14; // r10
  unsigned int v15; // r0
  int v16; // r0
  __int16 v17; // r3
  int *v19; // r4
  unsigned int *v20; // r7
  unsigned int *v21; // r8
  _DWORD *v22; // r0
  int v23; // r10
  int v24; // r3
  int v25; // r3
  unsigned __int8 *v26; // r3
  unsigned int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r1
  int *v30; // r6
  int v31; // [sp+8h] [bp-98h]
  unsigned int v32; // [sp+8h] [bp-98h]
  int v34; // [sp+10h] [bp-90h] BYREF
  unsigned int v35; // [sp+14h] [bp-8Ch] BYREF
  int *v36; // [sp+18h] [bp-88h]
  int **v37; // [sp+1Ch] [bp-84h]
  int v38[18]; // [sp+20h] [bp-80h] BYREF
  int v39[14]; // [sp+68h] [bp-38h] BYREF

  v4 = a1;
  v31 = a3;
  v37 = a4;
  v7 = __mrc(15, 0, 13, 0, 3);
  v8 = v7 & 0xFFFFFFC0;
  if ( MiFindBestOutswapPagefile((int)MiSystemPartition, (int)&v34) == 2 )
    return -1073741497;
  v39[0] = 2;
  EtwTraceWorkingSetSwap(v4, 2, v39, 2);
  MiValidateMemoryRangeEntries(a2, a3, &v35);
  memset(v38, 0, sizeof(v38));
  --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x136);
  v10 = KeAbPreAcquire((unsigned int)&dword_63F98C, 0, 0);
  do
    v11 = __ldrex((unsigned __int8 *)&dword_63F98C);
  while ( __strex(v11 | 1, (unsigned __int8 *)&dword_63F98C) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_63F98C, v10, (unsigned int)&dword_63F98C);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = v34;
  v13 = v35;
  while ( 1 )
  {
    v9 = MiReserveWorkingSetSwapSpace(MiSystemPartition, &v38[4]);
    if ( v9 >= 0 )
      break;
    if ( v12 < 2 )
    {
      v9 = MiExtendWorkingSetSwapPagefile(MiSystemPartition, v13, v12);
      if ( v9 >= 0 )
        continue;
    }
    v14 = a1;
    goto LABEL_14;
  }
  v19 = (int *)MiAllocateWorkingSetSwapSupport(v13);
  v14 = a1;
  v36 = v19;
  if ( v19 )
  {
    v20 = (unsigned int *)(a1 + 492);
    v38[2] = a1 + 492;
    v38[0] = (int)v19;
    LOCK_ADDRESS_SPACE_SHARED(v8, a1);
    if ( a2 < &a2[2 * v31] )
    {
      v21 = &a2[2 * v31];
      do
      {
        v22 = MiLocateAddress(*a2);
        v23 = (int)v22;
        if ( v22 )
        {
          v24 = v22[7];
          if ( (v24 & 7) == 0 && (v24 & 0x8000) != 0 )
          {
            v32 = *a2 + a2[1] - 1;
            if ( v22[4] >= v32 >> 12 )
            {
              v34 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v20);
              }
              else
              {
                v26 = (unsigned __int8 *)(a1 + 495);
                do
                  v27 = __ldrex(v26);
                while ( __strex(v27 | 0x80, v26) );
                __dmb(0xBu);
                if ( v27 >> 7 )
                  ExpWaitForSpinLockExclusiveAndAcquire(v20);
                while ( 1 )
                {
                  v28 = *v20;
                  if ( (*v20 & 0xBFFFFFFF) == 0x80000000 )
                    break;
                  if ( (v28 & 0x40000000) == 0 )
                  {
                    do
                      v29 = __ldrex(v20);
                    while ( v29 == v28 && __strex(v28 | 0x40000000, v20) );
                    __dmb(0xBu);
                  }
                  __dmb(0xAu);
                  __yield();
                }
              }
              LOBYTE(v38[3]) = v34;
              if ( MiVadDeleted(v23) )
              {
                v25 = v34;
              }
              else
              {
                MiEnumerateLeafPtes(
                  *a2,
                  v32,
                  (int (__fastcall *)(int, unsigned int, unsigned int))MiOutSwapWorkingSetCallback,
                  (int)v38);
                v25 = LOBYTE(v38[3]);
              }
              MiUnlockWorkingSetExclusive((int)v20, v25);
            }
          }
        }
        a2 += 2;
      }
      while ( a2 < v21 );
      v13 = v35;
      v19 = v36;
      v14 = a1;
    }
    UNLOCK_ADDRESS_SPACE_SHARED(v8, v14);
    if ( v19[2] < v13 )
    {
      v30 = MiReAllocateWorkingSetSwapSupport(v19);
      if ( v30 )
      {
        ExFreePoolWithTag(v19);
        v19 = v30;
      }
    }
    v13 = v19[3];
    *v37 = v19;
    v9 = 0;
  }
  else
  {
    v9 = -1073741670;
  }
LABEL_14:
  MiFreeReservationRuns(MiSystemPartition, &v38[4]);
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&dword_63F98C);
  while ( __strex(v15 - 1, (unsigned int *)&dword_63F98C) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_63F98C);
  v16 = KeAbPostRelease((unsigned int)&dword_63F98C);
  v17 = *(_WORD *)(v8 + 310) + 1;
  *(_WORD *)(v8 + 310) = v17;
  if ( !v17 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    KiCheckForKernelApcDelivery(v16);
  v39[0] = v13;
  v39[1] = v38[15];
  v39[4] = v9;
  v39[2] = v38[16];
  v39[3] = v38[17];
  EtwTraceWorkingSetSwap(v14, 0, v39, v38[17]);
  return v9;
}
