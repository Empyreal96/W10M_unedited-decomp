// PsSetMonitorContextServerSilo 
 
int __fastcall PsSetMonitorContextServerSilo(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r5
  int v7; // r6
  int v9; // r4
  unsigned int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r3
  int v16; // r5
  int v17; // r3
  int v18; // r2
  int v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r1
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  unsigned int *v30; // r2
  unsigned int v31; // r1
  unsigned int *v32; // r2
  unsigned int v33; // r1
  int v35; // [sp+4h] [bp-2Ch]
  unsigned int v36; // [sp+8h] [bp-28h]
  _DWORD *v37; // [sp+Ch] [bp-24h]

  v5 = a2;
  if ( a5 )
    *a5 = 0;
  v7 = a4 - 48;
  if ( *(_BYTE *)(a4 - 4) )
    return sub_550568();
  if ( *(_DWORD *)(a4 - 32) != a1 )
    return -1073741811;
  v9 = PspReferenceMonitorServerSilo(a1);
  if ( v9 >= 0 )
  {
    v10 = *(_DWORD *)(a1 + 64);
    v36 = v10;
    v37 = PsGetServerSiloGlobals(v5);
    if ( v10 >= v37[9] )
    {
      v9 = -1073741811;
    }
    else
    {
      if ( *(_BYTE *)(a1 + 69) )
      {
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v11 + 308);
        v12 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
        v13 = v12;
        do
          v14 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
        while ( __strex(v14 | 1, (unsigned __int8 *)&SiloMonitorLock) );
        __dmb(0xBu);
        if ( (v14 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v12, (unsigned int)&SiloMonitorLock);
        if ( v13 )
          *(_BYTE *)(v13 + 14) |= 1u;
        v10 = v36;
        v35 = 0;
      }
      else
      {
        v35 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(&SiloMonitorNonpagedContextSpinLock);
        }
        else
        {
          do
            v26 = __ldrex((unsigned int *)&SiloMonitorNonpagedContextSpinLock);
          while ( __strex(1u, (unsigned int *)&SiloMonitorNonpagedContextSpinLock) );
          __dmb(0xBu);
          if ( v26 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&SiloMonitorNonpagedContextSpinLock);
        }
      }
      v15 = *(_DWORD *)(v37[8] + 4 * v10);
      __dmb(0xBu);
      v16 = v15 & 0xFFFFFFFC;
      if ( (v15 & 0xFFFFFFFC) != 0 )
      {
        if ( a3 )
        {
          v27 = *(_DWORD *)(v37[8] + 4 * v10);
          __dmb(0xBu);
          v28 = v27 & 3 | v7;
          v29 = v37[8];
          __dmb(0xBu);
          *(_DWORD *)(v29 + 4 * v10) = v28;
          *(_BYTE *)(v7 + 44) = 1;
          *(_DWORD *)(v7 + 20) = a2;
          __dmb(0xBu);
          v30 = (unsigned int *)(v7 + 24);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 + 1, v30) );
          __dmb(0xBu);
          *(_DWORD *)(v16 + 20) = 0;
          *(_BYTE *)(v16 + 44) = 0;
          if ( a5 )
          {
            *a5 = v16 + 48;
            v16 = 0;
          }
          v9 = 0;
        }
        else
        {
          if ( a5 )
          {
            __dmb(0xBu);
            v32 = (unsigned int *)(v16 + 24);
            do
              v33 = __ldrex(v32);
            while ( __strex(v33 + 1, v32) );
            __dmb(0xBu);
            *a5 = v16 + 48;
          }
          v9 = -1071906814;
          v16 = 0;
        }
      }
      else
      {
        v17 = *(_DWORD *)(v37[8] + 4 * v10);
        __dmb(0xBu);
        v18 = v17 & 3 | v7;
        v19 = v37[8];
        __dmb(0xBu);
        *(_DWORD *)(v19 + 4 * v10) = v18;
        *(_BYTE *)(v7 + 44) = 1;
        *(_DWORD *)(v7 + 20) = a2;
        if ( a2 )
          ObfReferenceObject(a2);
        __dmb(0xBu);
        v20 = (unsigned int *)(v7 + 24);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 + 1, v20) );
        __dmb(0xBu);
        v9 = 0;
      }
      if ( *(_BYTE *)(a1 + 69) )
      {
        __dmb(0xBu);
        do
          v22 = __ldrex((unsigned int *)&SiloMonitorLock);
        while ( __strex(v22 - 1, (unsigned int *)&SiloMonitorLock) );
        if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
        v23 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = *(_WORD *)(v24 + 0x134) + 1;
        *(_WORD *)(v24 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
          KiCheckForKernelApcDelivery(v23);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&SiloMonitorNonpagedContextSpinLock);
        }
        else
        {
          __dmb(0xBu);
          SiloMonitorNonpagedContextSpinLock = 0;
        }
        KfLowerIrql(v35);
      }
      if ( v16 )
        PspDereferenceMonitorContextServerSilo(v16);
    }
    PspDereferenceMonitorServerSilo(a1);
  }
  return v9;
}
