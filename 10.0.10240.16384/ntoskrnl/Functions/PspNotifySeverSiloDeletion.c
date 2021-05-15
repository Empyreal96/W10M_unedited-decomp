// PspNotifySeverSiloDeletion 
 
int __fastcall PspNotifySeverSiloDeletion(int a1)
{
  int v1; // r9
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  int *v6; // r5
  int *v7; // r8
  void (__fastcall *v8)(int, int); // r10
  int v9; // r3
  int v10; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r3
  int v14; // r4
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r9
  unsigned int *v21; // r0
  unsigned int v22; // r4
  unsigned int v23; // r1
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r4
  unsigned int v27; // r2
  unsigned int v28; // r2
  int result; // r0
  unsigned int v30; // r1
  __int16 v31; // r3
  int v32; // [sp+0h] [bp-30h] BYREF
  int v33; // [sp+4h] [bp-2Ch]
  int *v34; // [sp+8h] [bp-28h]
  int v35; // [sp+Ch] [bp-24h]

  v1 = *(_DWORD *)(a1 + 144);
  v33 = a1;
  v34 = 0;
  v35 = v1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned int *)&SiloMonitorLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&SiloMonitorLock) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx(&SiloMonitorLock, v3, (unsigned int)&SiloMonitorLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = (int *)dword_61DA74;
  if ( (int *)dword_61DA74 != &SiloMonitorList )
  {
    do
    {
      if ( PspReferenceMonitorServerSilo((int)v6) >= 0 )
        break;
      v6 = (int *)v6[1];
    }
    while ( v6 != &SiloMonitorList );
    if ( v6 != &SiloMonitorList )
    {
      v7 = v6;
      PspReferenceMonitorServerSilo((int)v6);
      do
      {
        v8 = (void (__fastcall *)(int, int))v7[9];
        v9 = v7[5];
        __dmb(0xBu);
        if ( (v9 & 1) != 0
          && v8
          && (v10 = v7[16], v11 = *(_DWORD *)(v1 + 32), v12 = *(_DWORD *)(v11 + 4 * v10), __dmb(0xBu), (v12 & 1) != 0)
          && (v13 = *(_DWORD *)(v11 + 4 * v10), __dmb(0xBu), (v13 & 2) == 0) )
        {
          v14 = 0;
          v15 = *(_DWORD *)(v11 + 4 * v10) | 2;
          __dmb(0xBu);
          *(_DWORD *)(v11 + 4 * v10) = v15;
        }
        else
        {
          v14 = 1;
        }
        do
        {
          v6 = (int *)v6[1];
          if ( v6 == &SiloMonitorList )
            break;
          v34 = v6;
        }
        while ( PspReferenceMonitorServerSilo((int)v6) < 0 );
        __dmb(0xBu);
        do
          v16 = __ldrex((unsigned int *)&SiloMonitorLock);
        while ( v16 == 17 && __strex(0, (unsigned int *)&SiloMonitorLock) );
        if ( v16 != 17 )
          ExfReleasePushLockShared(&SiloMonitorLock);
        v17 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v19 = *(_WORD *)(v18 + 0x134) + 1;
        *(_WORD *)(v18 + 308) = v19;
        if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
          KiCheckForKernelApcDelivery(v17);
        v20 = PsGetMonitorContextServerSilo((int)v7, v33, &v32);
        if ( !v14 )
          v8(v33, v32);
        if ( v20 >= 0 )
        {
          PsDeleteMonitorContextServerSilo(v32);
          PsDereferenceMonitorContextServerSilo(v32);
        }
        v21 = (unsigned int *)(v7 + 7);
        __pld(v7 + 7);
        v22 = v7[7] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v23 = __ldrex(v21);
        while ( v23 == v22 && __strex(v22 - 2, v21) );
        if ( v23 != v22 )
          ExfReleaseRundownProtection((unsigned __int8 *)v21);
        v7 = v34;
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v24 + 308);
        v25 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
        v26 = v25;
        do
          v27 = __ldrex((unsigned int *)&SiloMonitorLock);
        while ( !v27 && __strex(0x11u, (unsigned int *)&SiloMonitorLock) );
        __dmb(0xBu);
        if ( v27 )
          ExfAcquirePushLockSharedEx(&SiloMonitorLock, v25, (unsigned int)&SiloMonitorLock);
        if ( v26 )
          *(_BYTE *)(v26 + 14) |= 1u;
        v1 = v35;
      }
      while ( v6 != &SiloMonitorList );
    }
  }
  __dmb(0xBu);
  do
    v28 = __ldrex((unsigned int *)&SiloMonitorLock);
  while ( v28 == 17 && __strex(0, (unsigned int *)&SiloMonitorLock) );
  if ( v28 != 17 )
    ExfReleasePushLockShared(&SiloMonitorLock);
  result = KeAbPostRelease((unsigned int)&SiloMonitorLock);
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v31 = *(_WORD *)(v30 + 0x134) + 1;
  *(_WORD *)(v30 + 308) = v31;
  if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  *(_DWORD *)(v1 + 56) = 3;
  return result;
}
