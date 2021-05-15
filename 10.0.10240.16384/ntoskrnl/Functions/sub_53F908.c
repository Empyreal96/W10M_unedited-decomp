// sub_53F908 
 
void sub_53F908()
{
  int v0; // r4
  _DWORD *v1; // r8
  unsigned int v2; // r6
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  __int64 v6; // r0
  unsigned int v7; // r1
  int v8; // r0
  __int16 v9; // r3

  v1 = *(_DWORD **)(v0 + 148);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&ExpWakeTimerLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&ExpWakeTimerLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&ExpWakeTimerLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpWakeTimerLock, v3, (unsigned int)&ExpWakeTimerLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = *(_QWORD *)(v0 + 152);
  if ( *(_DWORD *)(v6 + 4) == v0 + 152 && *(_DWORD *)HIDWORD(v6) == v0 + 152 )
  {
    *(_DWORD *)HIDWORD(v6) = v6;
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    *(_DWORD *)(v0 + 152) = 0;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&ExpWakeTimerLock);
    while ( __strex(v7 - 1, (unsigned int *)&ExpWakeTimerLock) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ExpWakeTimerLock);
    v8 = KeAbPostRelease((unsigned int)&ExpWakeTimerLock);
    v9 = *(_WORD *)(v2 + 308) + 1;
    *(_WORD *)(v2 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
      KiCheckForKernelApcDelivery(v8);
    if ( v1 )
      PoDestroyReasonContext(v1);
    JUMPOUT(0x4A8F50);
  }
  __fastfail(3u);
}
