// sub_8109CC 
 
int sub_8109CC()
{
  unsigned int *v0; // r4
  int v1; // r5
  unsigned int v2; // r7
  int v3; // r6
  BOOL v4; // r3
  int *v5; // r5
  unsigned int v6; // r2
  int v7; // r7
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int v12; // r3
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17; // r7
  unsigned int v18; // r1
  int v19; // r6
  int v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r1
  int *v24; // r9
  BOOL v25; // r3
  int v26; // [sp+0h] [bp-30h]
  int v27; // [sp+4h] [bp-2Ch]
  _DWORD *v28; // [sp+4h] [bp-2Ch]
  char v29; // [sp+4h] [bp-2Ch]
  int (__fastcall *v30)(_DWORD, int, int); // [sp+2Ch] [bp-4h]

  ExpAcquireFastMutexContended((int)v0, v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v0[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (int *)PspSiloList;
  v0[7] = v2;
  v24 = 0;
  if ( v5 != &PspSiloList )
  {
    while ( 1 )
    {
      v3 = (int)(v5 - 5);
      v4 = v5 != (int *)20 && v5[31];
      if ( v4 && PsGetServerSiloState((int)(v5 - 5)) == 1 )
        break;
      v5 = (int *)*v5;
      if ( v5 == &PspSiloList )
        goto LABEL_12;
    }
    if ( v5 != (int *)20 )
    {
      PspReferenceSiloObject((int)(v5 - 5));
      v2 = v0[7];
    }
LABEL_12:
    while ( v5 != &PspSiloList )
    {
      v28 = PsGetServerSiloGlobals(v3);
      v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v6 + 308);
      v7 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
      do
        v8 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
      while ( __strex(v8 | 1, (unsigned __int8 *)&SiloMonitorLock) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v7, (unsigned int)&SiloMonitorLock);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      v9 = *(_DWORD *)(v26 + 64);
      v10 = v28[8];
      v11 = *(_DWORD *)(v10 + 4 * v9);
      v29 = v11;
      __dmb(0xBu);
      if ( (v11 & 1) == 0 )
      {
        v12 = *(_DWORD *)(v10 + 4 * v9) | 1;
        __dmb(0xBu);
        *(_DWORD *)(v10 + 4 * v9) = v12;
      }
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&SiloMonitorLock);
      while ( __strex(v13 - 1, (unsigned int *)&SiloMonitorLock) );
      if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
      v14 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(_WORD *)(v15 + 0x134) + 1;
      *(_WORD *)(v15 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
        KiCheckForKernelApcDelivery(v14);
      while ( 1 )
      {
        v5 = (int *)*v5;
        if ( v5 == &PspSiloList )
          break;
        v24 = v5 - 5;
        v25 = v5 != (int *)20 && v5[31];
        if ( v25 && PsGetServerSiloState((int)(v5 - 5)) == 1 )
        {
          if ( v5 != (int *)20 )
            PspReferenceSiloObject((int)(v5 - 5));
          break;
        }
      }
      v0[1] = 0;
      v17 = v0[7];
      __dmb(0xBu);
      do
        v18 = __ldrex(v0);
      while ( !v18 && __strex(1u, v0) );
      if ( v18 )
        ExpReleaseFastMutexContended(v0, v18);
      KfLowerIrql((unsigned __int8)v17);
      KeAbPostRelease((unsigned int)v0);
      if ( (v29 & 1) == 0 )
        (*(void (__fastcall **)(int))(v26 + 32))(v3);
      if ( v3 )
        PspDereferenceSiloObject(v3);
      v19 = KeAbPreAcquire((unsigned int)v0, 0, 0);
      v20 = KfRaiseIrql(1);
      v27 = v20;
      do
        v21 = __ldrex((unsigned __int8 *)v0);
      while ( __strex(v21 & 0xFE, (unsigned __int8 *)v0) );
      __dmb(0xBu);
      if ( (v21 & 1) == 0 )
      {
        ExpAcquireFastMutexContended((int)v0, v19);
        v20 = v27;
      }
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      v0[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v0[7] = v20;
      LOBYTE(v2) = v20;
      v3 = (int)v24;
    }
  }
  v0[1] = 0;
  __dmb(0xBu);
  do
    v22 = __ldrex(v0);
  while ( !v22 && __strex(1u, v0) );
  if ( v22 )
    ExpReleaseFastMutexContended(v0, v22);
  KfLowerIrql((unsigned __int8)v2);
  KeAbPostRelease((unsigned int)v0);
  return v30(0, v26, v27);
}
