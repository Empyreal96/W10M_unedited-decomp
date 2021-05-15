// PsDeleteMonitorContextServerSilo 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall PsDeleteMonitorContextServerSilo(int a1)
{
  int v1; // r6
  int v2; // r7 OVERLAPPED
  int v3; // r8 OVERLAPPED
  unsigned int v4; // r9
  _DWORD *result; // r0
  _DWORD *v6; // r10
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r2
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r3
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // [sp+0h] [bp-28h]
  int v20; // [sp+4h] [bp-24h]
  int v21; // [sp+4h] [bp-24h]
  int vars4; // [sp+2Ch] [bp+4h]

  v1 = a1 - 48;
  *(_QWORD *)&v2 = *(_QWORD *)(a1 - 32);
  v4 = *(_DWORD *)(v2 + 64);
  v20 = *(_DWORD *)(a1 - 32);
  result = PsGetServerSiloGlobals(*(_DWORD *)(a1 - 28));
  v6 = result;
  if ( v4 < result[9] )
  {
    if ( *(_BYTE *)(v2 + 69) )
    {
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v7 + 308);
      v8 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
      v9 = v8;
      do
        v10 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
      while ( __strex(v10 | 1, (unsigned __int8 *)&SiloMonitorLock) );
      __dmb(0xBu);
      if ( (v10 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v8, (unsigned int)&SiloMonitorLock);
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
      v2 = v20;
      v19 = 0;
    }
    else
    {
      v19 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)&SiloMonitorNonpagedContextSpinLock);
      }
      else
      {
        do
          v11 = __ldrex((unsigned int *)&SiloMonitorNonpagedContextSpinLock);
        while ( __strex(1u, (unsigned int *)&SiloMonitorNonpagedContextSpinLock) );
        __dmb(0xBu);
        if ( v11 )
          KxWaitForSpinLockAndAcquire((unsigned int *)&SiloMonitorNonpagedContextSpinLock);
      }
    }
    v21 = *(unsigned __int8 *)(v1 + 44);
    if ( *(_BYTE *)(v1 + 44) )
    {
      v12 = *(_DWORD *)(v6[8] + 4 * v4);
      __dmb(0xBu);
      if ( (v12 & 0xFFFFFFFC) == v1 )
      {
        v13 = *(_DWORD *)(v6[8] + 4 * v4);
        __dmb(0xBu);
        v14 = v13 & 3;
        v15 = v6[8];
        __dmb(0xBu);
        *(_DWORD *)(v15 + 4 * v4) = v14;
        *(_DWORD *)(v1 + 20) = 0;
        *(_BYTE *)(v1 + 44) = 0;
      }
    }
    if ( *(_BYTE *)(v2 + 69) )
    {
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&SiloMonitorLock);
      while ( __strex(v16 - 1, (unsigned int *)&SiloMonitorLock) );
      if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
      result = (_DWORD *)KeAbPostRelease((unsigned int)&SiloMonitorLock);
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = *(_WORD *)(v17 + 0x134) + 1;
      *(_WORD *)(v17 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
        result = (_DWORD *)KiCheckForKernelApcDelivery((int)result);
    }
    else
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&SiloMonitorNonpagedContextSpinLock, vars4);
      }
      else
      {
        __dmb(0xBu);
        SiloMonitorNonpagedContextSpinLock = 0;
      }
      result = (_DWORD *)KfLowerIrql(v19);
    }
    if ( v21 )
    {
      result = (_DWORD *)PspDereferenceMonitorContextServerSilo(v1);
      if ( v3 )
        result = (_DWORD *)ObfDereferenceObjectWithTag(v3);
    }
  }
  return result;
}
