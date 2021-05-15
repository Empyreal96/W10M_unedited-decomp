// ExpSetTimer 
 
int __fastcall ExpSetTimer(int a1, char a2, _DWORD *a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, _BYTE *a10)
{
  int v10; // r6
  int v11; // r9
  int v12; // r4
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  int v16; // r5
  unsigned int *v17; // r10
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r2
  unsigned int v21; // r2
  int v22; // r8
  int v23; // r0
  unsigned int *v24; // r0
  unsigned int v25; // r2
  int v26; // r0
  int *v27; // lr
  unsigned __int8 *v28; // r3
  unsigned int v29; // r2
  _DWORD *v30; // r2
  _DWORD *v31; // r9
  int **v32; // r0
  int v33; // r0
  _DWORD *v34; // r1
  unsigned int v35; // r1
  int v36; // r0
  int v37; // r1
  __int16 v38; // r3
  unsigned int *v39; // r9
  unsigned int v40; // r4
  _BYTE *v41; // r1
  int v44; // [sp+10h] [bp-40h]
  int v45; // [sp+14h] [bp-3Ch] BYREF
  unsigned int v46; // [sp+18h] [bp-38h]
  int v47; // [sp+1Ch] [bp-34h]
  _DWORD *v48; // [sp+20h] [bp-30h]
  int v49; // [sp+24h] [bp-2Ch]
  int v50; // [sp+28h] [bp-28h]
  int v51; // [sp+2Ch] [bp-24h]

  v48 = a3;
  v50 = a2;
  v10 = ObReferenceObjectByHandle(a1, 2, ExTimerObjectType, a2, &v45, 0);
  v47 = v10;
  if ( v10 >= 0 )
  {
    v11 = 0;
    v46 = 0;
    v12 = a6;
    if ( a6 )
    {
      v49 = a7;
      if ( a7 )
      {
        v10 = ExpCheckIRTimerAccess(*(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
        v47 = v10;
        if ( v10 )
        {
          ObfDereferenceObjectWithTag(v45);
          return v10;
        }
      }
      if ( dword_61EA80 >= 2 || byte_61EA53 )
      {
        v11 = 1;
        v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v46 + 0x134);
        v13 = KeAbPreAcquire((unsigned int)&ExpWakeTimerLock, 0, 0);
        v14 = v13;
        do
          v15 = __ldrex((unsigned __int8 *)&ExpWakeTimerLock);
        while ( __strex(v15 | 1, (unsigned __int8 *)&ExpWakeTimerLock) );
        __dmb(0xBu);
        if ( (v15 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&ExpWakeTimerLock, v13, &ExpWakeTimerLock);
        if ( v14 )
          *(_BYTE *)(v14 + 14) |= 1u;
      }
      else
      {
        v10 = 1073741861;
        v47 = 1073741861;
        v12 = 0;
      }
    }
    else
    {
      v49 = a7;
    }
    v16 = v45;
    v17 = (unsigned int *)(v45 + 48);
    v45 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v16 + 48);
    }
    else
    {
      do
        v18 = __ldrex(v17);
      while ( __strex(1u, v17) );
      __dmb(0xBu);
      if ( v18 )
        KxWaitForSpinLockAndAcquire(v16 + 48);
    }
    if ( !v11 && *(_DWORD *)(v16 + 148) )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v16 + 48);
      }
      else
      {
        __dmb(0xBu);
        *v17 = 0;
      }
      KfLowerIrql(v45);
      v11 = 1;
      v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v46 + 308);
      v19 = KeAbPreAcquire((unsigned int)&ExpWakeTimerLock, 0, 0);
      v51 = v19;
      do
        v20 = __ldrex((unsigned __int8 *)&ExpWakeTimerLock);
      while ( __strex(v20 | 1, (unsigned __int8 *)&ExpWakeTimerLock) );
      __dmb(0xBu);
      if ( (v20 & 1) != 0 )
      {
        ExfAcquirePushLockExclusiveEx(&ExpWakeTimerLock, v19, &ExpWakeTimerLock);
        v19 = v51;
      }
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      v51 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v16 + 48);
      }
      else
      {
        do
          v21 = __ldrex(v17);
        while ( __strex(1u, v17) );
        __dmb(0xBu);
        if ( v21 )
          KxWaitForSpinLockAndAcquire(v16 + 48);
      }
      v45 = v51;
    }
    v22 = ExpCancelTimer(v16) + 1;
    v51 = *(_DWORD *)(v16 + 4);
    *(_DWORD *)(v16 + 140) = a8;
    *(_DWORD *)(v16 + 184) = a9;
    v23 = a4;
    if ( a4 )
    {
      v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      KeInitializeApc(v16 + 52, v44, 2, (int)ExpTimerApcRoutine, 0, v23, v50, a5);
      v24 = (unsigned int *)(v44 + 864);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v24);
      }
      else
      {
        do
          v25 = __ldrex(v24);
        while ( __strex(1u, v24) );
        __dmb(0xBu);
        if ( v25 )
          KxWaitForSpinLockAndAcquire(v24);
      }
      v26 = v16 + 132;
      v27 = *(int **)(v44 + 872);
      *(_DWORD *)(v16 + 132) = v44 + 868;
      *(_DWORD *)(v16 + 136) = v27;
      if ( *v27 != v44 + 868 )
        __fastfail(3u);
      *v27 = v26;
      *(_DWORD *)(v44 + 872) = v26;
      *(_BYTE *)(v16 + 144) |= 1u;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v44 + 864);
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)(v44 + 864) = 0;
      }
      --v22;
    }
    if ( (*(_BYTE *)(v16 + 144) & 2) != 0 )
    {
      v30 = v48;
      *(_DWORD *)(v16 + 176) = *v48;
      *(_DWORD *)(v16 + 180) = v30[1];
      if ( (int)v30[1] >= 0 )
      {
        *(_BYTE *)(v16 + 145) = 1;
      }
      else if ( v12 )
      {
        *(_BYTE *)(v16 + 145) = 3;
      }
      else
      {
        *(_BYTE *)(v16 + 145) = 2;
      }
    }
    else
    {
      KeSetCoalescableTimer(v16);
      if ( v12 )
      {
        __dmb(0xBu);
        v28 = (unsigned __int8 *)(v16 + 1);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 | 2, v28) );
        __dmb(0xBu);
      }
    }
    v48 = *(_DWORD **)(v16 + 148);
    *(_DWORD *)(v16 + 148) = v12;
    *(_BYTE *)(v16 + 144) ^= (*(_BYTE *)(v16 + 144) ^ (4 * v49)) & 4;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v16 + 48);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v16 + 48) = 0;
    }
    KfLowerIrql(v45);
    if ( v11 )
    {
      v31 = v48;
      if ( v48 )
      {
        if ( !v12 )
        {
          v33 = *(_DWORD *)(v16 + 152);
          v34 = *(_DWORD **)(v16 + 156);
          if ( *(_DWORD *)(v33 + 4) != v16 + 152 || *v34 != v16 + 152 )
            __fastfail(3u);
          *v34 = v33;
          *(_DWORD *)(v33 + 4) = v34;
          *(_DWORD *)(v16 + 152) = 0;
        }
      }
      else if ( v12 )
      {
        v32 = (int **)dword_61A0D4;
        *(_DWORD *)(v16 + 152) = &ExpWakeTimerList;
        *(_DWORD *)(v16 + 156) = v32;
        if ( *v32 != &ExpWakeTimerList )
          __fastfail(3u);
        *v32 = (int *)(v16 + 152);
        dword_61A0D4 = v16 + 152;
      }
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)&ExpWakeTimerLock);
      while ( __strex(v35 - 1, (unsigned int *)&ExpWakeTimerLock) );
      if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
        ExfTryToWakePushLock(&ExpWakeTimerLock);
      v36 = KeAbPostRelease((unsigned int)&ExpWakeTimerLock);
      v37 = v46;
      v38 = *(_WORD *)(v46 + 308) + 1;
      *(_WORD *)(v46 + 308) = v38;
      if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
        KiCheckForKernelApcDelivery(v36);
      if ( v31 )
        PoDestroyReasonContext(v31);
    }
    if ( v22 )
    {
      v39 = (unsigned int *)(v16 - 24);
      if ( ObpTraceFlags )
        ObpPushStackInfo(v16 - 24, 0, v22, 1953261124);
      __dmb(0xBu);
      do
        v40 = __ldrex(v39);
      while ( __strex(v40 - v22, v39) );
      if ( (int)(v40 - v22) <= 0 )
      {
        if ( v40 != v22 )
          KeBugCheckEx(24, 0, v16);
        ObpDeferObjectDeletion(v16 - 24);
      }
    }
    if ( a10 )
    {
      if ( v50 )
      {
        v41 = a10;
        if ( (unsigned int)a10 >= MmUserProbeAddress )
          v41 = (_BYTE *)MmUserProbeAddress;
        *v41 = *v41;
        *a10 = v51;
      }
      else
      {
        *a10 = v51;
      }
    }
  }
  return v10;
}
