// PsReportProcessMemoryLimitViolation 
 
void PsReportProcessMemoryLimitViolation()
{
  unsigned int v0; // r5
  int v1; // r8
  int v2; // r3
  _DWORD *v3; // r6
  unsigned int *v4; // r7
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  __int16 v13; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(_DWORD *)(v0 + 0x74);
  v2 = *(_DWORD *)(v1 + 288);
  __dmb(0xBu);
  v3 = *(_DWORD **)(v2 + 380);
  if ( v3 && (v3[44] & 0x100) != 0 )
  {
    --*(_WORD *)(v0 + 310);
    v4 = v3 + 138;
    v5 = KeAbPreAcquire((unsigned int)(v3 + 138), 0, 0);
    v6 = v5;
    do
      v7 = __ldrex(v4);
    while ( !v7 && __strex(0x11u, v4) );
    __dmb(0xBu);
    if ( v7 )
      ExfAcquirePushLockSharedEx(v3 + 138, v5, (unsigned int)(v3 + 138));
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    if ( v3[53] )
    {
      if ( (v3[107] & 0x200) != 0 )
      {
        v8 = *(_DWORD *)(v1 + 188);
        if ( (v8 & 4) != 0 && (v8 & 0x20) == 0 )
        {
          __dmb(0xBu);
          v9 = (unsigned int *)(v1 + 188);
          do
            v10 = __ldrex(v9);
          while ( __strex(v10 | 0x20, v9) );
          __dmb(0xBu);
          PspSendJobNotification((int)v3);
        }
      }
    }
    __dmb(0xBu);
    do
      v11 = __ldrex(v4);
    while ( v11 == 17 && __strex(0, v4) );
    if ( v11 != 17 )
      ExfReleasePushLockShared(v3 + 138);
    v12 = KeAbPostRelease((unsigned int)(v3 + 138));
    v13 = *(_WORD *)(v0 + 310) + 1;
    *(_WORD *)(v0 + 310) = v13;
    if ( !v13 && *(_DWORD *)(v0 + 100) != v0 + 100 )
      KiCheckForKernelApcDelivery(v12);
  }
}
