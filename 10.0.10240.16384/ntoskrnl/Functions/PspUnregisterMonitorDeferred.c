// PspUnregisterMonitorDeferred 
 
int __fastcall PspUnregisterMonitorDeferred(int a1)
{
  int v1; // r9
  int v2; // r0
  void (__fastcall *v3)(_DWORD, int); // r3
  int v4; // r4
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r2
  int *v8; // r5
  int v9; // r6
  unsigned __int8 v12; // r7
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r7
  unsigned int v16; // r2
  int v17; // r2
  int v18; // r1
  int v19; // r3
  int v20; // r3
  int v21; // r7
  int v22; // r3
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  int v27; // r7
  int v28; // r6
  int v29; // r9
  unsigned int v30; // r2
  unsigned int v31; // r1
  int v33; // [sp+0h] [bp-30h] BYREF
  int *v34; // [sp+4h] [bp-2Ch]
  _DWORD *v35; // [sp+8h] [bp-28h]
  int v36; // [sp+Ch] [bp-24h]
  int v37; // [sp+10h] [bp-20h]

  v34 = 0;
  v1 = a1;
  v37 = a1;
  v2 = PsGetMonitorContextServerSilo(a1, 0, &v33);
  v3 = *(void (__fastcall **)(_DWORD, int))(v1 + 36);
  v4 = v2;
  if ( v3 )
    v3(0, v33);
  if ( v4 >= 0 )
  {
    PsDeleteMonitorContextServerSilo(v33);
    PsDereferenceMonitorContextServerSilo(v33);
  }
  v5 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)&PspSiloListLock);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PspSiloListLock, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = (int *)PspSiloList;
  dword_61DA5C = v6;
  if ( (int *)PspSiloList != &PspSiloList )
  {
    while ( 1 )
    {
      v9 = (int)(v8 - 5);
      if ( v8 != (int *)20 && v8[31] )
        break;
      v8 = (int *)*v8;
      if ( v8 == &PspSiloList )
        goto LABEL_21;
    }
    if ( v8 != (int *)20 )
    {
      PspReferenceSiloObject((int)(v8 - 5));
      LOBYTE(v6) = dword_61DA5C;
    }
LABEL_21:
    while ( v8 != &PspSiloList )
    {
      v36 = PsGetMonitorContextServerSilo(v1, v9, &v33);
      while ( 1 )
      {
        v8 = (int *)*v8;
        if ( v8 == &PspSiloList )
          break;
        v34 = v8 - 5;
        if ( v8 != (int *)20 && v8[31] )
        {
          if ( v8 != (int *)20 )
            PspReferenceSiloObject((int)(v8 - 5));
          break;
        }
      }
      dword_61DA44 = 0;
      v12 = dword_61DA5C;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&PspSiloListLock);
      while ( !v13 && __strex(1u, (unsigned int *)&PspSiloListLock) );
      if ( v13 )
        ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v13);
      KfLowerIrql(v12);
      KeAbPostRelease((unsigned int)&PspSiloListLock);
      if ( !*(_DWORD *)(v1 + 36) )
        goto LABEL_59;
      v35 = PsGetServerSiloGlobals(v9);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v14 + 308);
      v15 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
      do
        v16 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
      while ( __strex(v16 | 1, (unsigned __int8 *)&SiloMonitorLock) );
      __dmb(0xBu);
      if ( (v16 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v15, (unsigned int)&SiloMonitorLock);
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
      v17 = *(_DWORD *)(v1 + 64);
      v18 = v35[8];
      v19 = *(_DWORD *)(v18 + 4 * v17);
      __dmb(0xBu);
      if ( (v19 & 1) == 0 || (v20 = *(_DWORD *)(v18 + 4 * v17), __dmb(0xBu), (v20 & 2) != 0) )
      {
        v21 = 1;
      }
      else
      {
        v21 = 0;
        v22 = *(_DWORD *)(v18 + 4 * v17) | 2;
        __dmb(0xBu);
        *(_DWORD *)(v18 + 4 * v17) = v22;
      }
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&SiloMonitorLock);
      while ( __strex(v23 - 1, (unsigned int *)&SiloMonitorLock) );
      if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
      v24 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = *(_WORD *)(v25 + 0x134) + 1;
      *(_WORD *)(v25 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery(v24);
      if ( v21 )
      {
LABEL_59:
        v27 = v33;
      }
      else
      {
        v27 = v33;
        (*(void (__fastcall **)(int, int))(v1 + 36))(v9, v33);
      }
      if ( v36 >= 0 )
      {
        PsDeleteMonitorContextServerSilo(v27);
        PsDereferenceMonitorContextServerSilo(v27);
      }
      if ( v9 )
        PspDereferenceSiloObject(v9);
      v28 = KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
      v29 = KfRaiseIrql(1);
      do
        v30 = __ldrex((unsigned __int8 *)&PspSiloListLock);
      while ( __strex(v30 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
      __dmb(0xBu);
      if ( (v30 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PspSiloListLock, v28);
      if ( v28 )
        *(_BYTE *)(v28 + 14) |= 1u;
      dword_61DA44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      LOBYTE(v6) = v29;
      dword_61DA5C = v29;
      v1 = v37;
      v9 = (int)v34;
    }
  }
  dword_61DA44 = 0;
  __dmb(0xBu);
  do
    v31 = __ldrex((unsigned int *)&PspSiloListLock);
  while ( !v31 && __strex(1u, (unsigned int *)&PspSiloListLock) );
  if ( v31 )
    ExpReleaseFastMutexContended((unsigned int *)&PspSiloListLock, v31);
  KfLowerIrql((unsigned __int8)v6);
  KeAbPostRelease((unsigned int)&PspSiloListLock);
  return 0;
}
