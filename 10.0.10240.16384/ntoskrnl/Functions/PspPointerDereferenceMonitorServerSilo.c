// PspPointerDereferenceMonitorServerSilo 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PspPointerDereferenceMonitorServerSilo(unsigned int result)
{
  _DWORD *v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v1 = (_DWORD *)result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 24);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( !v4 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
    while ( __strex(v8 | 1, (unsigned __int8 *)&SiloMonitorLock) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v6, (unsigned int)&SiloMonitorLock);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    *(_QWORD *)&v9 = *(_QWORD *)v1;
    if ( *(_DWORD **)(*v1 + 4) != v1 || (_DWORD *)*v10 != v1 )
      __fastfail(3u);
    *v10 = v9;
    *(_DWORD *)(v9 + 4) = v10;
    *(_BYTE *)((v1[16] >> 3) + dword_61DA8C) &= ~(1 << (v1[16] & 7));
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&SiloMonitorLock);
    while ( __strex(v11 - 1, (unsigned int *)&SiloMonitorLock) );
    if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
    v12 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
    v1[4] = 0;
    result = ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
