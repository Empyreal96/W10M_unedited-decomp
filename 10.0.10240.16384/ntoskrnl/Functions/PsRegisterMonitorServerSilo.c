// PsRegisterMonitorServerSilo 
 
int __fastcall PsRegisterMonitorServerSilo(int a1, unsigned __int16 *a2, unsigned __int16 *a3, unsigned int *a4)
{
  int result; // r0
  int v8; // r1
  unsigned int v9; // r7
  _BYTE *v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r9
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int v21; // r1
  int v22; // r0
  __int16 v23; // r3
  int **v24; // r1

  if ( !a1 && (!a2 || !*a2) || !*a3 || *a3 > 1u )
    return -1073741811;
  if ( PsIsCurrentThreadInServerSilo() )
    return sub_8108BC();
  v8 = 72;
  if ( a1 )
  {
    v9 = 0;
  }
  else
  {
    v9 = 2 * wcslen(a2);
    v8 = v9 + 72;
  }
  v10 = (_BYTE *)ExAllocatePoolWithTag(512, v8, 1298950483);
  v11 = (unsigned int)v10;
  if ( !v10 )
    return -1073741670;
  memset(v10, 0, 72);
  *(_DWORD *)(v11 + 16) = 1298950483;
  *(_DWORD *)(v11 + 8) = v11 + 8;
  *(_DWORD *)(v11 + 12) = v11 + 8;
  *(_BYTE *)(v11 + 69) = a3[1] & 1;
  *(_DWORD *)(v11 + 32) = *((_DWORD *)a3 + 1);
  *(_DWORD *)(v11 + 36) = *((_DWORD *)a3 + 2);
  *(_DWORD *)(v11 + 40) = *((_DWORD *)a3 + 3);
  *(_DWORD *)(v11 + 44) = *((_DWORD *)a3 + 4);
  *(_DWORD *)(v11 + 48) = *((_DWORD *)a3 + 5);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = KeAbPreAcquire((unsigned int)&SiloMonitorLock, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
  while ( __strex(v15 | 1, (unsigned __int8 *)&SiloMonitorLock) );
  __dmb(0xBu);
  if ( (v15 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v13, (unsigned int)&SiloMonitorLock);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v16 = RtlFindClearBitsAndSet(&MonitorContextIndexBitmap, 1u, 0);
  if ( v16 == -1 )
  {
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&SiloMonitorLock);
    while ( __strex(v21 - 1, (unsigned int *)&SiloMonitorLock) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
    KeAbPostRelease((unsigned int)&SiloMonitorLock);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery(v22);
    ExFreePoolWithTag(v11);
    result = -1073741789;
  }
  else
  {
    *(_DWORD *)(v11 + 64) = v16;
    if ( a1 )
    {
      ObfReferenceObject(a1);
      *(_BYTE *)(v11 + 68) = 1;
      *(_DWORD *)(v11 + 60) = a1;
      *(_DWORD *)(v11 + 52) = *(_DWORD *)(a1 + 28);
      *(_DWORD *)(v11 + 56) = *(_DWORD *)(a1 + 32);
    }
    else
    {
      *(_DWORD *)(v11 + 56) = v11 + 72;
      *(_BYTE *)(v11 + 68) = 0;
      *(_WORD *)(v11 + 52) = v9;
      *(_WORD *)(v11 + 54) = v9;
      memmove(v11 + 72, (int)a2, v9);
    }
    __dmb(0xBu);
    *(_DWORD *)(v11 + 24) = 1;
    *(_DWORD *)(v11 + 28) = 0;
    PspReferenceMonitorServerSilo(v11);
    v24 = (int **)dword_61DA74;
    *(_DWORD *)v11 = &SiloMonitorList;
    *(_DWORD *)(v11 + 4) = v24;
    if ( *v24 != &SiloMonitorList )
      __fastfail(3u);
    *v24 = (int *)v11;
    dword_61DA74 = v11;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&SiloMonitorLock);
    while ( __strex(v17 - 1, (unsigned int *)&SiloMonitorLock) );
    if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&SiloMonitorLock);
    v18 = KeAbPostRelease((unsigned int)&SiloMonitorLock);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
    result = 0;
    *a4 = v11;
  }
  return result;
}
