// PspFreeMonitorContextServerSilo 
 
// local variable allocation has failed, the output may be wrong!
unsigned __int8 *__fastcall PspFreeMonitorContextServerSilo(_DWORD *a1)
{
  int v2; // r7
  void (__fastcall *v3)(_DWORD *); // r3
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  unsigned __int8 *result; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1

  v2 = a1[4];
  v3 = *(void (__fastcall **)(_DWORD *))(v2 + 48);
  if ( v3 )
    v3(a1 + 12);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
  while ( __strex(v7 | 1, (unsigned __int8 *)&SiloMonitorLock) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v5, (unsigned int)&SiloMonitorLock);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *(_QWORD *)&v8 = *(_QWORD *)a1;
  if ( *(_DWORD **)(*a1 + 4) != a1 || (_DWORD *)*v9 != a1 )
    __fastfail(3u);
  *v9 = v8;
  *(_DWORD *)(v8 + 4) = v9;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&SiloMonitorLock);
  while ( __strex(v10 - 1, (unsigned int *)&SiloMonitorLock) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
  v11 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  ExFreePoolWithTag((unsigned int)a1);
  result = (unsigned __int8 *)(v2 + 28);
  __pld((void *)(v2 + 28));
  v15 = *(_DWORD *)(v2 + 28) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)result);
  while ( v16 == v15 && __strex(v15 - 2, (unsigned int *)result) );
  if ( v16 != v15 )
    result = ExfReleaseRundownProtection(result);
  return result;
}
