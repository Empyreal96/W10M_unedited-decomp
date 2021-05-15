// DbgkRegisterErrorPort 
 
int __fastcall DbgkRegisterErrorPort(int a1, unsigned int a2)
{
  int v4; // r0
  int v5; // r4
  _DWORD *v6; // r6
  unsigned int v7; // r4
  int v8; // r10
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r1
  unsigned int *v12; // r8
  unsigned int v13; // r2
  unsigned int v14; // r0
  int v15; // r0
  __int16 v16; // r3
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r2
  _DWORD v22[8]; // [sp+28h] [bp-88h] BYREF
  _WORD v23[12]; // [sp+48h] [bp-68h] BYREF
  _DWORD v24[11]; // [sp+60h] [bp-50h] BYREF

  if ( !a2 || (a2 & 1) != 0 || a2 > 0xFFFF )
    return -1073741811;
  v4 = ExAllocatePoolWithQuotaTag(9u, a2, 1348952644);
  v22[1] = v4;
  if ( !v4 )
    return -1073741670;
  HIWORD(v22[0]) = a2;
  LOWORD(v22[0]) = a2;
  memmove(v4, a1, a2);
  v6 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, 0xCu, 1348952644);
  if ( v6 )
  {
    memset(v23, 0, sizeof(v23));
    v23[2] |= 0x8000u;
    v23[1] = 24;
    memset(v24, 0, sizeof(v24));
    v24[4] = 168;
    v24[6] = 5376;
    v24[0] = 0x100000;
    v22[2] = 24;
    v22[3] = 0;
    v22[5] = 512;
    v22[4] = 0;
    v22[6] = 0;
    v22[7] = 0;
    v5 = ZwAlpcConnectPort();
    if ( v5 >= 0 )
    {
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *v6 = 1;
      v6[1] = 0;
      v8 = *(_DWORD *)(v7 + 0x74);
      --*(_WORD *)(v7 + 308);
      v9 = KeAbPreAcquire((unsigned int)&DbgkpErrorPortLock, 0, 0);
      v10 = v9;
      do
        v11 = __ldrex((unsigned __int8 *)&DbgkpErrorPortLock);
      while ( __strex(v11 | 1, (unsigned __int8 *)&DbgkpErrorPortLock) );
      __dmb(0xBu);
      if ( (v11 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&DbgkpErrorPortLock, v9, (unsigned int)&DbgkpErrorPortLock);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      v12 = (unsigned int *)DbgkpErrorPort;
      if ( !DbgkpErrorPort )
      {
        __dmb(0xBu);
        do
          v13 = __ldrex((unsigned __int8 *)0xFFFF92F0);
        while ( __strex(v13 | 1, (unsigned __int8 *)0xFFFF92F0) );
        __dmb(0xBu);
      }
      DbgkpErrorPort = v6;
      DbgkpErrorProcess = v8;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)&DbgkpErrorPortLock);
      while ( __strex(v14 - 1, (unsigned int *)&DbgkpErrorPortLock) );
      if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&DbgkpErrorPortLock);
      v15 = KeAbPostRelease((unsigned int)&DbgkpErrorPortLock);
      v16 = *(_WORD *)(v7 + 308) + 1;
      *(_WORD *)(v7 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
        KiCheckForKernelApcDelivery(v15);
      v5 = 0;
      v6 = 0;
      if ( v12 )
      {
        __dmb(0xBu);
        v17 = (unsigned __int8 *)(v12 + 1);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 | 1, v17) );
        __dmb(0xBu);
        if ( (v18 & 1) == 0 )
          ZwAlpcDisconnectPort();
        __dmb(0xBu);
        do
        {
          v19 = __ldrex(v12);
          v20 = v19 - 1;
        }
        while ( __strex(v20, v12) );
        __dmb(0xBu);
        if ( !v20 )
          DbgkpDeleteErrorPort(v12);
      }
      KeSetEvent(DbgkErrorPortRegisteredEvent, 0, 0);
    }
    if ( v6 )
      ExFreePoolWithTag((unsigned int)v6);
  }
  else
  {
    v5 = -1073741670;
  }
  RtlFreeAnsiString(v22);
  return v5;
}
