// EtwpLogMemInfoWs 
 
int *__fastcall EtwpLogMemInfoWs(int *a1, unsigned int a2)
{
  int *v3; // r10
  int v4; // r6
  int *result; // r0
  int *v6; // r4
  unsigned int v7; // r5
  int *v8; // r8
  int v9; // r7
  int v10; // t1
  int *v11; // r7
  int *v12; // r5
  int v13; // r3
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r3
  int v19; // r0
  int v20; // r7
  unsigned int v21; // r8
  int v22; // r9
  int v23; // r0
  int v24; // r6
  unsigned int v25; // r2
  int *v26; // r6
  unsigned int v27; // r2
  __int16 v28; // r3
  int v29; // r3
  int v30; // r3
  int *v31; // [sp+8h] [bp-688h]
  int *v32; // [sp+14h] [bp-67Ch]
  unsigned int v34; // [sp+20h] [bp-670h]
  char v35[512]; // [sp+48h] [bp-648h] BYREF
  int v36[8]; // [sp+640h] [bp-50h] BYREF
  int v37[12]; // [sp+660h] [bp-30h] BYREF

  v37[1] = 119;
  v37[2] = 120;
  v3 = a1;
  v37[0] = 81;
  EtwpLogSessionWorkingSetInfo();
  v4 = -1;
  result = (int *)ExAllocatePoolWithTag(512, 2308, 1953985605);
  v31 = result;
  if ( result )
  {
    v6 = result + 1;
    *result = 0;
    v7 = 0;
    v32 = result + 577;
    v8 = v37;
    do
    {
      v10 = *v8++;
      v9 = v10;
      if ( ZwQuerySystemInformation() )
      {
        v11 = v31;
        goto LABEL_60;
      }
      *v6 = v4;
      v6 += 9;
      *(v6 - 1) = 0;
      *(v6 - 8) = v34 >> 12;
      *(v6 - 5) = v34 >> 12;
      *(v6 - 7) = v34 >> 12;
      *(v6 - 6) = v34 >> 12;
      *(v6 - 3) = 0;
      *(v6 - 4) = 0;
      *(v6 - 2) = 0;
      if ( v9 == 119 && a2 > *(v6 - 7) )
      {
        *(v6 - 7) = a2;
        *(v6 - 6) = a2;
      }
      v11 = v31;
      ++v7;
      --v4;
      ++*v31;
    }
    while ( v7 < 3 );
    v12 = (int *)PsIdleProcess;
    if ( PsIdleProcess )
    {
      do
      {
        v13 = v12[48];
        if ( (v13 & 0x4000000) != 0 )
        {
          if ( (v13 & 4) == 0 || !v12[1] || (v29 = v12[101], __dmb(0xBu), v29) || (int *)v12[10] != v12 + 10 )
          {
            if ( v6 == v32 )
              return (int *)sub_80313C();
            *v6 = v12[44];
            v6 += 9;
            *(v6 - 8) = v12[136];
            *(v6 - 5) = v12[137];
            v14 = v12[121];
            __dmb(0xBu);
            *(v6 - 7) = v14;
            v15 = v12[216];
            __dmb(0xBu);
            *(v6 - 1) = v15;
            *(v6 - 6) = (unsigned int)v12[57] >> 12;
            v16 = *(v6 - 7);
            if ( v16 >= *(v6 - 6) )
              v16 = *(v6 - 6);
            v17 = *(v6 - 8);
            *(v6 - 7) = v16;
            v18 = *(v6 - 5);
            if ( v18 >= v17 )
              v18 = v17;
            *(v6 - 5) = v18;
            *(v6 - 4) = 0;
            *(v6 - 3) = 0;
            *(v6 - 2) = v12[152];
            if ( v12 == (int *)PsInitialSystemProcess )
              v19 = 0;
            else
              v19 = (int)v12;
            if ( SmpProcessQueryStoreStats(v19, (int)v35, v17, PsInitialSystemProcess) >= 0 )
              JUMPOUT(0x80319C);
            ++*v11;
          }
        }
        if ( v12 == (int *)PsIdleProcess )
          v20 = 0;
        else
          v20 = (int)v12;
        v12 = 0;
        v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v22 = 0;
        --*(_WORD *)(v21 + 0x136);
        v23 = KeAbPreAcquire((unsigned int)&PspActiveProcessLock, 0, 0);
        v24 = v23;
        do
          v25 = __ldrex((unsigned int *)&PspActiveProcessLock);
        while ( !v25 && __strex(0x11u, (unsigned int *)&PspActiveProcessLock) );
        __dmb(0xBu);
        if ( v25 )
          ExfAcquirePushLockSharedEx(&PspActiveProcessLock, v23, (unsigned int)&PspActiveProcessLock);
        if ( v24 )
          *(_BYTE *)(v24 + 14) |= 1u;
        if ( v20 )
          v26 = *(int **)(v20 + 180);
        else
          v26 = (int *)PsActiveProcessHead;
        if ( v26 != &PsActiveProcessHead )
        {
          v12 = v26 - 45;
          if ( !ObReferenceObjectSafeWithTag((int)(v26 - 45)) )
            JUMPOUT(0x8031D4);
          v22 = 1;
        }
        __dmb(0xBu);
        do
          v27 = __ldrex((unsigned int *)&PspActiveProcessLock);
        while ( v27 == 17 && __strex(0, (unsigned int *)&PspActiveProcessLock) );
        if ( v27 != 17 )
          ExfReleasePushLockShared(&PspActiveProcessLock);
        KeAbPostRelease((unsigned int)&PspActiveProcessLock);
        v28 = *(_WORD *)(v21 + 310) + 1;
        *(_WORD *)(v21 + 310) = v28;
        if ( !v28 && *(_DWORD *)(v21 + 100) != v21 + 100 )
          JUMPOUT(0x8031E8);
        if ( v20 )
          ObfDereferenceObjectWithTag(v20);
        if ( !v22 )
          v12 = 0;
        v11 = v31;
      }
      while ( v12 );
      v3 = a1;
    }
    v36[1] = 0;
    v36[2] = 4;
    v36[3] = 0;
    v36[0] = (int)v11;
    v30 = *v11;
    v36[4] = (int)(v11 + 1);
    v36[5] = 0;
    v36[6] = 36 * v30;
    v36[7] = 0;
    if ( v3 )
    {
      EtwpLogKernelEvent(v36, *v3, 2, 637, (int)&dword_401804);
    }
    else
    {
      EtwTraceKernelEvent(v36, 2, 0x20800000u, 637, (int)&dword_401804);
      if ( (dword_61AD44 & 0x800000) != 0 )
        EtwWrite(EtwpMemoryProvRegHandle, unk_61A944, (int)KERNEL_MEM_EVENT_MEMINFO_WS, 0);
    }
LABEL_60:
    result = (int *)ExFreePoolWithTag((unsigned int)v11);
  }
  return result;
}
