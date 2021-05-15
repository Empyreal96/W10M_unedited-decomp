// PspRundownSingleProcess 
 
int __fastcall PspRundownSingleProcess(unsigned int *a1, int a2)
{
  int v2; // r8
  int v4; // r3
  unsigned int v5; // r7
  unsigned int *v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r3
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r1
  int v14; // r2
  int v15; // r4
  unsigned __int8 *v16; // r6
  int v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  int v23; // r0
  __int16 v24; // r3
  _BYTE v25[56]; // [sp-4h] [bp-38h] BYREF

  v2 = a2;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = v4 & 0xFFFFFFC0;
  if ( a2 )
    goto LABEL_2;
  --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x134);
  v16 = (unsigned __int8 *)(a1 + 42);
  v17 = KeAbPreAcquire((unsigned int)(a1 + 42), 0, 0);
  do
    v18 = __ldrex(v16);
  while ( __strex(v18 | 1, v16) );
  __dmb(0xBu);
  if ( (v18 & 1) == 0 )
  {
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    v19 = a1[101];
    __dmb(0xBu);
    if ( !v19 )
    {
      __dmb(0xBu);
      v20 = a1 + 48;
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x2000008, v20) );
      __dmb(0xBu);
      if ( (v21 & 0x2000000) == 0 )
        v2 = 1;
    }
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v16);
    while ( __strex(v22 - 1, (unsigned int *)v16) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 42);
    v23 = KeAbPostRelease((unsigned int)(a1 + 42));
    v24 = *(_WORD *)(v5 + 308) + 1;
    *(_WORD *)(v5 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      KiCheckForKernelApcDelivery(v23);
    if ( !v2 )
    {
      ObClearProcessHandleTable((int)a1);
      return v2;
    }
LABEL_2:
    v6 = a1 + 43;
    do
      v7 = __ldrex(v6);
    while ( !v7 && __strex(1u, v6) );
    __dmb(0xBu);
    if ( v7 && v7 != 1 )
      ExfWaitForRundownProtectionRelease(a1 + 43, v7);
    __dmb(0xBu);
    do
      v8 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    v9 = a1[72];
    __dmb(0xBu);
    if ( !v9 || (a1[47] & 1) != 0 )
      goto LABEL_9;
    v14 = a1[158];
    if ( v14 <= -1073741674 )
    {
      if ( v14 < -1073741684
        && (v14 == 0x80000000
         || v14 > -2147483644
         && (v14 <= -1073741820 || v14 > -1073741818 && v14 != -1073741795 && (v14 <= -1073741788 || v14 > -1073741786))) )
      {
        goto LABEL_29;
      }
    }
    else if ( v14 != -1073741571
           && v14 != -1073741510
           && (v14 <= -1073741133 || v14 > -1073741131 && v14 != -1073741111) )
    {
LABEL_29:
      v15 = 7;
LABEL_30:
      RtlInterlockedSetClearBits(a1 + 47, 8);
      PspSendProcessNotificationToJobChain(a1, v15, a1[44]);
LABEL_9:
      if ( (a1[48] & 0x40000) != 0 )
      {
        KiStackAttachProcess((int)a1, 0, (int)v25);
        if ( a1[84] )
          ObKillProcess(a1);
        MmCleanProcessAddressSpace(a1);
        KiUnstackDetachProcess((unsigned int)v25, 0);
      }
      v10 = a1[73];
      if ( v10 )
      {
        a1[73] = 0;
        ObfDereferenceObject(v10);
      }
      if ( (a1[48] & 0x40000) != 0 )
        KeSetProcess((int)a1);
      v11 = a1[72];
      __dmb(0xBu);
      if ( v11 )
      {
        PspRemoveProcessFromJobChain(a1, 0, 4, 0);
        PspNotifyEmptyJobsInJobChain(a1);
      }
      v12 = a1[44];
      if ( v12 )
        PspClearProcessThreadCidRefs(v5, v12, a1);
      return v2;
    }
    v15 = 8;
    goto LABEL_30;
  }
  return sub_7C0B2C(v17);
}
