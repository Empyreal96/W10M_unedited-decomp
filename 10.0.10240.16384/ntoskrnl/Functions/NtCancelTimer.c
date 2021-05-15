// NtCancelTimer 
 
int __fastcall NtCancelTimer(int a1, _BYTE *a2)
{
  int v3; // r1
  _BYTE *v4; // r2
  int v5; // r5
  _DWORD *v6; // r9
  unsigned int *v7; // r4
  unsigned int v8; // r2
  int v9; // r6
  int v10; // r6
  unsigned int v11; // r2
  int v12; // r6
  unsigned int v13; // r2
  int v14; // r0
  _DWORD *v15; // r1
  unsigned int v16; // r1
  int v17; // r0
  __int16 v18; // r3
  unsigned int *v19; // r10
  unsigned int v20; // r4
  int v22; // [sp+Ch] [bp-3Ch]
  int v23; // [sp+10h] [bp-38h]
  unsigned int v24; // [sp+14h] [bp-34h]
  unsigned int v25; // [sp+14h] [bp-34h]
  int v26; // [sp+18h] [bp-30h]
  _DWORD _20[14]; // [sp+20h] [bp-28h] BYREF

  _20[13] = a2;
  _20[12] = a1;
  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( a2 && v3 )
  {
    v4 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v4 = (_BYTE *)MmUserProbeAddress;
    *v4 = *v4;
  }
  v5 = ObReferenceObjectByHandle(a1, 2, ExTimerObjectType, v3, _20, 0);
  _20[2] = v5;
  if ( v5 >= 0 )
  {
    v24 = 0;
    v23 = 0;
    v6 = (_DWORD *)_20[0];
    v7 = (unsigned int *)(_20[0] + 48);
    v22 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v6 + 12);
    }
    else
    {
      do
        v8 = __ldrex(v7);
      while ( __strex(1u, v7) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire(v6 + 12);
    }
    v9 = v6[37];
    _20[0] = v9;
    if ( v9 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v6 + 12);
      }
      else
      {
        __dmb(0xBu);
        *v7 = 0;
      }
      KfLowerIrql(v22);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v24 + 308);
      v10 = KeAbPreAcquire(&ExpWakeTimerLock, 0, 0);
      do
        v11 = __ldrex((unsigned __int8 *)&ExpWakeTimerLock);
      while ( __strex(v11 | 1, (unsigned __int8 *)&ExpWakeTimerLock) );
      __dmb(0xBu);
      if ( (v11 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&ExpWakeTimerLock, v10, &ExpWakeTimerLock);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      v23 = 1;
      v12 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v6 + 12);
      }
      else
      {
        do
          v13 = __ldrex(v7);
        while ( __strex(1u, v7) );
        __dmb(0xBu);
        if ( v13 )
          KxWaitForSpinLockAndAcquire(v6 + 12);
      }
      v22 = v12;
      v9 = v6[37];
      _20[0] = v9;
      v6[37] = 0;
    }
    v26 = ExpCancelTimer(v6) + 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v6 + 12);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    KfLowerIrql(v22);
    if ( v23 )
    {
      if ( v9 )
      {
        v14 = v6[38];
        v15 = (_DWORD *)v6[39];
        if ( *(_DWORD **)(v14 + 4) != v6 + 38 || (_DWORD *)*v15 != v6 + 38 )
          __fastfail(3u);
        *v15 = v14;
        *(_DWORD *)(v14 + 4) = v15;
        v6[38] = 0;
      }
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&ExpWakeTimerLock);
      while ( __strex(v16 - 1, (unsigned int *)&ExpWakeTimerLock) );
      if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
        ExfTryToWakePushLock(&ExpWakeTimerLock);
      v17 = KeAbPostRelease(&ExpWakeTimerLock);
      v18 = *(_WORD *)(v24 + 308) + 1;
      *(_WORD *)(v24 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(v17);
    }
    v25 = v6[1];
    v19 = v6 - 6;
    if ( ObpTraceFlags )
      ObpPushStackInfo(v6 - 6, 0, v26, 1953261124);
    __dmb(0xBu);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 - v26, v19) );
    if ( (int)(v20 - v26) <= 0 )
    {
      if ( v20 != v26 )
        KeBugCheckEx(24, 0, v6);
      ObpDeferObjectDeletion((unsigned int)(v6 - 6));
    }
    if ( a2 )
      *a2 = v25;
    if ( v9 )
      PoDestroyReasonContext(v9);
  }
  return v5;
}
