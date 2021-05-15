// PopOrphanCoolingExtension 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopOrphanCoolingExtension(unsigned __int8 *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  unsigned __int8 *v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  int i; // r5
  int v12; // r1 OVERLAPPED
  unsigned __int8 **v13; // r2 OVERLAPPED
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  int result; // r0
  unsigned int v24; // r1
  __int16 v25; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopCoolingExtensionLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&PopCoolingExtensionLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&PopCoolingExtensionLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopCoolingExtensionLock, v3, (unsigned int)&PopCoolingExtensionLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61E714 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = a1 + 16;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)(a1 + 16), 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v6);
  while ( __strex(v10 | 1, v6) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a1 + 4, v8, (unsigned int)(a1 + 16));
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *((_DWORD *)a1 + 5) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *((_DWORD *)a1 + 6) )
  {
    for ( i = *((_DWORD *)a1 + 2); (unsigned __int8 *)i != a1 + 8; i = *(_DWORD *)i )
    {
      if ( *(_BYTE *)(i + 10) )
      {
        *(_BYTE *)(i + 10) = 0;
        if ( *((_DWORD *)a1 + 17) )
        {
          PopThermalUpdatePassiveTimeTracking(i + 24, *(unsigned __int8 *)(i + 8));
          PopTraceThermalRequestPassiveHistogram(i);
          PopThermalUpdateTelemetryClientCount(0);
        }
        PopDiagTraceThermalRequest(i, (int)POP_ETW_EVENT_THERMAL_REQUEST_REMOVE);
      }
    }
    *(_DWORD *)(PopGetDope(*((_DWORD *)a1 + 6)) + 48) = 0;
    *(_QWORD *)&v12 = *(_QWORD *)a1;
    if ( *(unsigned __int8 **)(*(_DWORD *)a1 + 4) != a1 || *v13 != a1 )
      __fastfail(3u);
    *v13 = (unsigned __int8 *)v12;
    *(_DWORD *)(v12 + 4) = v13;
    *(_DWORD *)a1 = 0;
    *((_DWORD *)a1 + 6) = 0;
  }
  if ( *((_DWORD *)a1 + 5) )
    *((_DWORD *)a1 + 5) = 0;
  __pld(v6);
  v14 = *(_DWORD *)v6;
  if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
    v15 = 0;
  else
    v15 = v14 - 16;
  if ( (v14 & 2) != 0 )
    goto LABEL_35;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v6);
  while ( v16 == v14 && __strex(v15, (unsigned int *)v6) );
  if ( v16 != v14 )
LABEL_35:
    ExfReleasePushLock((_DWORD *)a1 + 4, v14);
  v17 = KeAbPostRelease((unsigned int)(a1 + 16));
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  dword_61E714 = 0;
  __pld(&PopCoolingExtensionLock);
  v20 = PopCoolingExtensionLock;
  v21 = PopCoolingExtensionLock - 16;
  if ( (PopCoolingExtensionLock & 0xFFFFFFF0) <= 0x10 )
    v21 = 0;
  if ( (PopCoolingExtensionLock & 2) != 0 )
    goto LABEL_47;
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)&PopCoolingExtensionLock);
  while ( v22 == v20 && __strex(v21, (unsigned int *)&PopCoolingExtensionLock) );
  if ( v22 != v20 )
LABEL_47:
    ExfReleasePushLock(&PopCoolingExtensionLock, v20);
  result = KeAbPostRelease((unsigned int)&PopCoolingExtensionLock);
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = *(_WORD *)(v24 + 0x134) + 1;
  *(_WORD *)(v24 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
