// PopDeactiveThermalRequest 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopDeactiveThermalRequest(int a1)
{
  unsigned int v2; // r5
  int v3; // r9
  unsigned __int8 *v4; // r4
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r8
  unsigned int v18; // r2
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r8
  unsigned int v22; // r2
  int v23; // r1 OVERLAPPED
  _DWORD *v24; // r2 OVERLAPPED
  int v25; // r0
  int v26; // r1 OVERLAPPED
  _DWORD *v27; // r2 OVERLAPPED
  int v28; // r1
  unsigned int v29; // r0
  unsigned int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v34; // r1
  unsigned int v35; // r0
  unsigned int v36; // r2
  int result; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  unsigned int v40; // r2
  int v41; // r0
  int v42; // r6
  unsigned int v43; // r2
  int v44; // r1
  unsigned int v45; // r0
  unsigned int v46; // r2
  int v47; // r0
  unsigned int v48; // r1
  __int16 v49; // r3
  unsigned int v50; // r2
  int v51; // r0
  int v52; // r6
  unsigned int v53; // r2
  int v54; // r1
  unsigned int v55; // r0
  unsigned int v56; // r2
  int v57; // r0
  unsigned int v58; // r1
  __int16 v59; // r3
  char v60[48]; // [sp+8h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 16);
  v3 = 0;
  v4 = (unsigned __int8 *)(v2 + 16);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire(v2 + 16, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v4);
  while ( __strex(v8 | 1, v4) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 16), v6, v2 + 16);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  *(_DWORD *)(v2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(a1 + 10) )
  {
    if ( *(_DWORD *)(v2 + 68) )
    {
      PopThermalUpdatePassiveTimeTracking(a1 + 24, *(unsigned __int8 *)(a1 + 8));
      PopTraceThermalRequestPassiveHistogram(a1);
      PopThermalUpdateTelemetryClientCount(0);
    }
    PopDiagTraceThermalRequest(a1, (int)POP_ETW_EVENT_THERMAL_REQUEST_REMOVE);
    *(_BYTE *)(a1 + 10) = 0;
    PopPropogateCoolingChange(v2);
  }
  if ( *(_DWORD *)(v2 + 20) )
    *(_DWORD *)(v2 + 20) = 0;
  __pld(v4);
  v9 = *(_DWORD *)v4;
  v10 = *(_DWORD *)v4 - 16;
  if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (v9 & 2) != 0 )
    goto LABEL_20;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v4);
  while ( v11 == v9 && __strex(v10, (unsigned int *)v4) );
  if ( v11 != v9 )
LABEL_20:
    ExfReleasePushLock((_DWORD *)(v2 + 16), v9);
  v12 = KeAbPostRelease(v2 + 16);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v15 + 308);
  v16 = KeAbPreAcquire((unsigned int)&PopCoolingExtensionLock, 0, 0);
  v17 = v16;
  do
    v18 = __ldrex((unsigned __int8 *)&PopCoolingExtensionLock);
  while ( __strex(v18 | 1, (unsigned __int8 *)&PopCoolingExtensionLock) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopCoolingExtensionLock, v16, (unsigned int)&PopCoolingExtensionLock);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  dword_61E714 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v19 + 308);
  v20 = KeAbPreAcquire(v2 + 16, 0, 0);
  v21 = v20;
  do
    v22 = __ldrex(v4);
  while ( __strex(v22 | 1, v4) );
  __dmb(0xBu);
  if ( (v22 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 16), v20, v2 + 16);
  if ( v21 )
    *(_BYTE *)(v21 + 14) |= 1u;
  *(_DWORD *)(v2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_QWORD *)&v23 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v24 != a1 )
    __fastfail(3u);
  *v24 = v23;
  *(_DWORD *)(v23 + 4) = v24;
  if ( *(_DWORD *)(v2 + 8) == v2 + 8 )
  {
    v25 = *(_DWORD *)(v2 + 24);
    if ( v25 )
    {
      *(_DWORD *)(PopGetDope(v25) + 48) = 0;
      if ( *(_BYTE *)(v2 + 32) )
        PopDiagTraceCoolingExtension(v2, (int)POP_ETW_EVENT_COOLING_EXTENSION_REMOVE);
      *(_QWORD *)&v26 = *(_QWORD *)v2;
      if ( *(_DWORD *)(*(_DWORD *)v2 + 4) != v2 || *v27 != v2 )
        __fastfail(3u);
      *v27 = v26;
      *(_DWORD *)(v26 + 4) = v27;
      *(_DWORD *)v2 = 0;
    }
    v3 = 1;
  }
  if ( *(_DWORD *)(v2 + 20) )
    *(_DWORD *)(v2 + 20) = 0;
  __pld(v4);
  v28 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
    v29 = 0;
  else
    v29 = v28 - 16;
  if ( (v28 & 2) != 0 )
    goto LABEL_58;
  __dmb(0xBu);
  do
    v30 = __ldrex((unsigned int *)v4);
  while ( v30 == v28 && __strex(v29, (unsigned int *)v4) );
  if ( v30 != v28 )
LABEL_58:
    ExfReleasePushLock((_DWORD *)(v2 + 16), v28);
  v31 = KeAbPostRelease(v2 + 16);
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = *(_WORD *)(v32 + 0x134) + 1;
  *(_WORD *)(v32 + 308) = v33;
  if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
    KiCheckForKernelApcDelivery(v31);
  dword_61E714 = 0;
  __pld(&PopCoolingExtensionLock);
  v34 = PopCoolingExtensionLock;
  v35 = PopCoolingExtensionLock - 16;
  if ( (PopCoolingExtensionLock & 0xFFFFFFF0) <= 0x10 )
    v35 = 0;
  if ( (PopCoolingExtensionLock & 2) != 0 )
    goto LABEL_70;
  __dmb(0xBu);
  do
    v36 = __ldrex((unsigned int *)&PopCoolingExtensionLock);
  while ( v36 == v34 && __strex(v35, (unsigned int *)&PopCoolingExtensionLock) );
  if ( v36 != v34 )
LABEL_70:
    ExfReleasePushLock(&PopCoolingExtensionLock, v34);
  result = KeAbPostRelease((unsigned int)&PopCoolingExtensionLock);
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v39 = *(_WORD *)(v38 + 0x134) + 1;
  *(_WORD *)(v38 + 308) = v39;
  if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v3 )
  {
    v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v40 + 308);
    v41 = KeAbPreAcquire(v2 + 16, 0, 0);
    v42 = v41;
    do
      v43 = __ldrex(v4);
    while ( __strex(v43 | 1, v4) );
    __dmb(0xBu);
    if ( (v43 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 16), v41, v2 + 16);
    if ( v42 )
      *(_BYTE *)(v42 + 14) |= 1u;
    *(_DWORD *)(v2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( *(_BYTE *)(v2 + 35) )
    {
      KeInitializeEvent((int)v60, 0, 0);
      *(_DWORD *)(v2 + 36) = v60;
      if ( *(_DWORD *)(v2 + 20) )
        *(_DWORD *)(v2 + 20) = 0;
      __pld(v4);
      v44 = *(_DWORD *)v4;
      v45 = *(_DWORD *)v4 - 16;
      if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
        v45 = 0;
      if ( (v44 & 2) != 0 )
        goto LABEL_92;
      __dmb(0xBu);
      do
        v46 = __ldrex((unsigned int *)v4);
      while ( v46 == v44 && __strex(v45, (unsigned int *)v4) );
      if ( v46 != v44 )
LABEL_92:
        ExfReleasePushLock((_DWORD *)(v2 + 16), v44);
      v47 = KeAbPostRelease(v2 + 16);
      v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v49 = *(_WORD *)(v48 + 0x134) + 1;
      *(_WORD *)(v48 + 308) = v49;
      if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
        KiCheckForKernelApcDelivery(v47);
      KeWaitForSingleObject((unsigned int)v60, 0, 0, 0, 0);
      v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v50 + 308);
      v51 = KeAbPreAcquire(v2 + 16, 0, 0);
      v52 = v51;
      do
        v53 = __ldrex(v4);
      while ( __strex(v53 | 1, v4) );
      __dmb(0xBu);
      if ( (v53 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 16), v51, v2 + 16);
      if ( v52 )
        *(_BYTE *)(v52 + 14) |= 1u;
      *(_DWORD *)(v2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v2 + 36) = 0;
    }
    if ( *(_DWORD *)(v2 + 20) )
      *(_DWORD *)(v2 + 20) = 0;
    __pld(v4);
    v54 = *(_DWORD *)v4;
    v55 = *(_DWORD *)v4 - 16;
    if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
      v55 = 0;
    if ( (v54 & 2) != 0 )
      goto LABEL_113;
    __dmb(0xBu);
    do
      v56 = __ldrex((unsigned int *)v4);
    while ( v56 == v54 && __strex(v55, (unsigned int *)v4) );
    if ( v56 != v54 )
LABEL_113:
      ExfReleasePushLock((_DWORD *)(v2 + 16), v54);
    v57 = KeAbPostRelease(v2 + 16);
    v58 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v59 = *(_WORD *)(v58 + 0x134) + 1;
    *(_WORD *)(v58 + 308) = v59;
    if ( !v59 && *(_DWORD *)(v58 + 100) != v58 + 100 && !*(_WORD *)(v58 + 310) )
      KiCheckForKernelApcDelivery(v57);
    result = PopCleanCoolingExtension(v2);
  }
  return result;
}
