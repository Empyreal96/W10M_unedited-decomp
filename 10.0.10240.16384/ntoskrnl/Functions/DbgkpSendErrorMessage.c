// DbgkpSendErrorMessage 
 
int __fastcall DbgkpSendErrorMessage(int a1, int a2, int a3)
{
  unsigned int v4; // r6
  int v5; // r8
  int v7; // r5
  int *v8; // r3
  int v9; // r0
  __int16 v10; // r3
  int v11; // r4
  unsigned int *v12; // r9
  int v13; // r10
  unsigned int v14; // r2
  int v15; // r10
  char *v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r0
  int v21; // r10
  unsigned int v22; // r1
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  int v27; // r0
  unsigned int v28; // r1
  int v29; // r3
  int v30; // [sp+10h] [bp-A0h]
  __int64 v32; // [sp+18h] [bp-98h] BYREF
  unsigned int v33; // [sp+20h] [bp-90h] BYREF
  int v34[34]; // [sp+28h] [bp-88h] BYREF

  v30 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(v4 + 0x150);
  if ( (*(_DWORD *)(v5 + 736) & 1) != 0 )
    return sub_7D6960();
  MmGetSectionInformation(*(_DWORD *)(v5 + 292), 1, v34);
  if ( MmGetSessionIdEx(v5) && v34[4] != 1 )
    v30 = DbgkpSuspendProcess(v5);
  v7 = DbgkpStartSystemErrorHandler();
  if ( v7 < 0 )
    goto LABEL_13;
  if ( DbgkErrorPortStartTimeout == -1 )
  {
    v8 = 0;
  }
  else
  {
    v32 = -10000i64 * DbgkErrorPortStartTimeout;
    v8 = (int *)&v32;
  }
  if ( KeWaitForSingleObject(DbgkErrorPortRegisteredEvent, 0, 0, 0, v8) != 258 && DbgkpErrorPort )
  {
    v7 = 0;
    --*(_WORD *)(v4 + 308);
    v12 = 0;
    LODWORD(v32) = 0;
    v20 = KeAbPreAcquire((unsigned int)&DbgkpErrorPortLock, 0, 0);
    v21 = v20;
    do
      v22 = __ldrex((unsigned int *)&DbgkpErrorPortLock);
    while ( !v22 && __strex(0x11u, (unsigned int *)&DbgkpErrorPortLock) );
    __dmb(0xBu);
    if ( v22 )
      ExfAcquirePushLockSharedEx(&DbgkpErrorPortLock, v20, (unsigned int)&DbgkpErrorPortLock);
    if ( v21 )
      *(_BYTE *)(v21 + 14) |= 1u;
    if ( v5 == DbgkpErrorProcess )
    {
      v7 = -1073741420;
    }
    else
    {
      v12 = (unsigned int *)DbgkpErrorPort;
      if ( DbgkpErrorPort )
      {
        v13 = DbgkpErrorProcess;
        LODWORD(v32) = DbgkpErrorProcess;
        ObfReferenceObjectWithTag(DbgkpErrorProcess);
        __dmb(0xBu);
        do
          v14 = __ldrex(v12);
        while ( __strex(v14 + 1, v12) );
        __dmb(0xBu);
        goto LABEL_52;
      }
      v7 = -1073740973;
    }
    v13 = 0;
LABEL_52:
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)&DbgkpErrorPortLock);
    while ( v23 == 17 && __strex(0, (unsigned int *)&DbgkpErrorPortLock) );
    if ( v23 != 17 )
      ExfReleasePushLockShared(&DbgkpErrorPortLock);
    v9 = KeAbPostRelease((unsigned int)&DbgkpErrorPortLock);
    v10 = *(_WORD *)(v4 + 308) + 1;
    *(_WORD *)(v4 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v9);
    if ( v7 < 0 )
      goto LABEL_13;
    memset((_BYTE *)a3, 0, 24);
    *(_DWORD *)a3 = 10748044;
    *(_DWORD *)(a3 + 4) = 8;
    *(_WORD *)(a3 + 4) = -32761;
    *(_DWORD *)(a3 + 24) = 7;
    *(_DWORD *)(a3 + 28) = -2147418111;
    memmove(a3 + 32, a1, 0x50u);
    memmove(a3 + 112, (int)v34, 0x30u);
    *(_DWORD *)(a3 + 160) = 0;
    if ( (*(_BYTE *)(v5 + 734) & 7) != 0 )
      *(_DWORD *)(a3 + 160) = 1;
    if ( PspCheckForInvalidAccessByProtection(1, *(unsigned __int8 *)(v13 + 734), *(unsigned __int8 *)(v5 + 734)) )
      v15 = 1055744;
    else
      v15 = 0x1FFFFF;
    AlpcInitializeMessageAttribute(0x10000000, v34, 0x64u, &v33);
    v34[1] = 0x10000000;
    v16 = AlpcGetMessageAttribute(v34, 0x10000000);
    *((_DWORD *)v16 + 2) = 4;
    *((_DWORD *)v16 + 3) = v15;
    *(_DWORD *)v16 = 0;
    *((_DWORD *)v16 + 1) = -2;
    v33 = 168;
    KeTestAlertThread(0);
    if ( (*(_DWORD *)(v4 + 960) & 1) != 0 )
      v7 = -1073741749;
    if ( v7 < 0 || (v19 = ZwAlpcSendWaitReceivePort(), v7 = v19, v19 < 0) )
    {
      if ( v7 == -1073741769 )
        DbgkpRemoveErrorPort(v4, v12);
    }
    else if ( v19 == 257 )
    {
      v7 = -1073741749;
    }
    else
    {
      if ( (*(_WORD *)(a3 + 4) & 0x2000) != 0 )
        ZwAlpcSendWaitReceivePort();
      v7 = *(_DWORD *)(a3 + 28);
      if ( v7 >= 0 )
      {
        if ( v7 == 65538 )
        {
          v11 = v30;
          if ( v30 )
          {
            v24 = PsThawProcess(v5, 0);
            v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v26 = *(_WORD *)(v25 + 0x134) + 1;
            *(_WORD *)(v25 + 308) = v26;
            if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
              KiCheckForKernelApcDelivery(v24);
            v11 = 0;
          }
          if ( DbgkForwardException(a1, 1, 1) )
            v7 = 0;
          else
            v7 = -1073741500;
          goto LABEL_33;
        }
        ZwFlushInstructionCache();
      }
    }
    v11 = v30;
LABEL_33:
    ObfDereferenceObjectWithTag(v32);
    __dmb(0xBu);
    do
    {
      v17 = __ldrex(v12);
      v18 = v17 - 1;
    }
    while ( __strex(v18, v12) );
    __dmb(0xBu);
    if ( !v18 )
      DbgkpDeleteErrorPort(v12);
    goto LABEL_14;
  }
  v7 = -1073740973;
LABEL_13:
  v11 = v30;
LABEL_14:
  if ( v11 )
  {
    v27 = PsThawProcess(v5, 0);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v27);
  }
  return v7;
}
