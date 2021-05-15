// PsAllocateMonitorContextServerSilo 
 
int __fastcall PsAllocateMonitorContextServerSilo(int a1, int a2, _DWORD *a3)
{
  int v6; // r0
  _BYTE *v7; // r0
  _DWORD *v8; // r4
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  _DWORD *v14; // r1
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  if ( *(_BYTE *)(a1 + 69) )
    v6 = 1;
  else
    v6 = 512;
  v7 = (_BYTE *)ExAllocatePoolWithTag(v6, a2 + 48, 1131178323);
  v8 = v7;
  if ( !v7 )
    return sub_810880();
  memset(v7, 0, 48);
  v8[2] = 1131178323;
  v8[4] = a1;
  __dmb(0xBu);
  v8[6] = 1;
  v8[3] = a2;
  if ( PspReferenceMonitorServerSilo(a1) < 0 )
    JUMPOUT(0x810884);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
  while ( __strex(v13 | 1, (unsigned __int8 *)&SiloMonitorLock) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v11, (unsigned int)&SiloMonitorLock);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v14 = *(_DWORD **)(a1 + 12);
  *v8 = a1 + 8;
  v8[1] = v14;
  if ( *v14 != a1 + 8 )
    __fastfail(3u);
  *v14 = v8;
  *(_DWORD *)(a1 + 12) = v8;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&SiloMonitorLock);
  while ( __strex(v15 - 1, (unsigned int *)&SiloMonitorLock) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
  v16 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  *a3 = v8 + 12;
  return 0;
}
