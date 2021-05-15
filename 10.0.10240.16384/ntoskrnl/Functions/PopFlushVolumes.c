// PopFlushVolumes 
 
int __fastcall PopFlushVolumes(int a1)
{
  char v2; // r6
  int v3; // r4
  int v4; // r7
  int v5; // r8
  unsigned int v6; // r2
  int *v7; // r7
  int *v8; // lr
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int *v12; // r1
  __int64 v13; // kr00_8
  int **v14; // lr
  int *v15; // r1
  int *v16; // r6
  int v17; // r2
  int v18; // r3
  int *v19; // r2
  __int64 v20; // kr08_8
  int **v21; // r6
  unsigned __int8 v22; // r6
  unsigned int v23; // r1
  int v24; // r6
  int v25; // r7
  unsigned int v26; // r2
  unsigned int v27; // r1
  int v29; // [sp+14h] [bp-64h] BYREF
  char v30[8]; // [sp+18h] [bp-60h] BYREF
  int v31; // [sp+20h] [bp-58h] BYREF
  int v32; // [sp+24h] [bp-54h]
  char *v33; // [sp+28h] [bp-50h]
  int v34; // [sp+2Ch] [bp-4Ch]
  int v35; // [sp+30h] [bp-48h]
  int v36; // [sp+34h] [bp-44h]
  int v37[16]; // [sp+38h] [bp-40h] BYREF

  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_FLUSHVOLUMES_START);
  memset(v37, 0, 32);
  v37[1] = (int)v37;
  v37[0] = (int)v37;
  KeInitializeEvent((int)&v37[3], 0, 0);
  if ( a1 == 6 )
  {
    v2 = 2;
  }
  else if ( byte_61EED0 )
  {
    v2 = 3;
  }
  else
  {
    v2 = PopFlushPolicy;
  }
  if ( (v2 & 4) != 0 )
    LOBYTE(v37[7]) = 1;
  if ( (v2 & 8) != 0 )
    BYTE1(v37[7]) = 1;
  if ( (v2 & 1) != 0 )
  {
    RtlInitUnicodeString((unsigned int)v30, L"\\Registry");
    v31 = 24;
    v32 = 0;
    v34 = 576;
    v33 = v30;
    v35 = 0;
    v36 = 0;
    if ( ZwOpenKey() >= 0 )
    {
      ZwFlushKey();
      ZwClose();
    }
  }
  v3 = 0;
  v4 = KeAbPreAcquire((unsigned int)&PopVolumeLock, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&PopVolumeLock);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&PopVolumeLock) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopVolumeLock, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61EAE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = (int *)PopVolumeDevices;
  dword_61EAFC = v5;
  while ( v7 != &PopVolumeDevices )
  {
    v8 = v7 - 13;
    v9 = *(v7 - 7);
    v7 = (int *)*v7;
    v10 = *(_DWORD *)(v9 + 36);
    if ( (*(_WORD *)(v10 + 4) & 1) != 0 && (*(_DWORD *)(v9 + 32) & 0x10006) == 0 )
    {
      v11 = *(_DWORD *)(v10 + 12);
      if ( !v11 || (*(_DWORD *)(v11 + 32) & 4) == 0 )
      {
        v12 = v8 + 13;
        v13 = *(_QWORD *)(v8 + 13);
        if ( *(int **)(v13 + 4) != v8 + 13 || *(int **)HIDWORD(v13) != v12 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v13) = v13;
        *(_DWORD *)(v13 + 4) = HIDWORD(v13);
        v14 = (int **)v37[1];
        *v12 = (int)v37;
        v12[1] = (int)v14;
        if ( *v14 != v37 )
          __fastfail(3u);
        *v14 = v12;
        v37[1] = (int)v12;
        ++v3;
      }
    }
  }
  if ( (v2 & 2) == 0 )
  {
    v15 = (int *)v37[0];
    while ( v15 != v37 )
    {
      v16 = v15 - 13;
      v17 = *(v15 - 7);
      v15 = (int *)*v15;
      if ( (*(_DWORD *)(v17 + 32) & 1) == 0 )
      {
        v18 = *(_DWORD *)(*(_DWORD *)(v17 + 36) + 12);
        if ( !v18 || (*(_DWORD *)(v18 + 32) & 1) == 0 )
        {
          v19 = v16 + 13;
          v20 = *(_QWORD *)(v16 + 13);
          if ( *(int **)(v20 + 4) != v16 + 13 || *(int **)HIDWORD(v20) != v19 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v20) = v20;
          *(_DWORD *)(v20 + 4) = HIDWORD(v20);
          v21 = (int **)dword_61E95C;
          *v19 = (int)&PopVolumeDevices;
          v19[1] = (int)v21;
          if ( *v21 != &PopVolumeDevices )
            __fastfail(3u);
          *v21 = v19;
          dword_61E95C = (int)v19;
          --v3;
        }
      }
    }
  }
  dword_61EAE4 = 0;
  v22 = dword_61EAFC;
  __dmb(0xBu);
  do
    v23 = __ldrex(&PopVolumeLock);
  while ( !v23 && __strex(1u, &PopVolumeLock) );
  if ( v23 )
    ExpReleaseFastMutexContended(&PopVolumeLock, v23);
  KfLowerIrql(v22);
  KeAbPostRelease((unsigned int)&PopVolumeLock);
  if ( v3 )
  {
    if ( v3 > 8 )
      v3 = 8;
    v31 = 24;
    v32 = 0;
    v34 = 512;
    v33 = 0;
    v35 = 0;
    v36 = 0;
    v37[2] = v3;
    while ( --v3 > 0 )
    {
      if ( PsCreateSystemThread(&v29, 0x1FFFFF, &v31, 0, 0, PopFlushVolumeWorker, v37) < 0 )
      {
        v24 = KeAbPreAcquire((unsigned int)&PopVolumeLock, 0, 0);
        v25 = KfRaiseIrql(1);
        do
          v26 = __ldrex((unsigned __int8 *)&PopVolumeLock);
        while ( __strex(v26 & 0xFE, (unsigned __int8 *)&PopVolumeLock) );
        __dmb(0xBu);
        if ( (v26 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&PopVolumeLock, v24);
        if ( v24 )
          *(_BYTE *)(v24 + 14) |= 1u;
        __mrc(15, 0, 13, 0, 3);
        dword_61EAFC = v25;
        v37[2] -= v3;
        dword_61EAE4 = 0;
        __dmb(0xBu);
        do
          v27 = __ldrex(&PopVolumeLock);
        while ( !v27 && __strex(1u, &PopVolumeLock) );
        if ( v27 )
          ExpReleaseFastMutexContended(&PopVolumeLock, v27);
        KfLowerIrql((unsigned __int8)v25);
        KeAbPostRelease((unsigned int)&PopVolumeLock);
        break;
      }
      ZwClose();
    }
    PopFlushVolumeWorker((int)v37);
    KeWaitForSingleObject((unsigned int)&v37[3], 0, 0, 0, 0);
  }
  return PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_FLUSHVOLUMES_STOP);
}
