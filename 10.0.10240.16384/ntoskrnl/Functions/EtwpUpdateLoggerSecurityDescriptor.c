// EtwpUpdateLoggerSecurityDescriptor 
 
unsigned int *__fastcall EtwpUpdateLoggerSecurityDescriptor(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int *v5; // r0
  unsigned int *v6; // r6
  unsigned int *v7; // r1
  int v8; // r2
  unsigned int v9; // r8
  unsigned int v10; // r2
  char v11; // r3
  int v12; // r4
  unsigned int v13; // r1
  __int16 v14; // r3
  __int64 v15; // kr00_8
  int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a4;
  v5 = (unsigned int *)ObLogSecurityDescriptor(a2, v17, 8);
  v6 = v5;
  if ( (int)v5 >= 0 )
  {
    v7 = (unsigned int *)(a1 + 576);
    v8 = v17[0] | 7;
    if ( !v17[0] )
      v8 = 0;
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( __strex(v8, v7) );
    __dmb(0xBu);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    __dmb(0xFu);
    v11 = EtwpSecurityLock;
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
    {
      v12 = KeAbPreAcquire((unsigned int)&EtwpSecurityLock, 0, 0);
      ExfAcquirePushLockExclusiveEx(&EtwpSecurityLock, v12, (unsigned int)&EtwpSecurityLock);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      v5 = ExfReleasePushLockExclusive((unsigned int *)&EtwpSecurityLock);
      if ( v12 )
        v5 = (unsigned int *)KeAbPostRelease((unsigned int)&EtwpSecurityLock);
    }
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery((int)v5);
    ObDereferenceSecurityDescriptor(v9 & 0xFFFFFFF8, (v9 & 7) + 1);
    v15 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_CHANGE_SESSION_SD) )
      EtwpEventWriteTemplateSession(v15, SHIDWORD(v15), ETW_EVENT_CHANGE_SESSION_SD, a1);
  }
  return v6;
}
