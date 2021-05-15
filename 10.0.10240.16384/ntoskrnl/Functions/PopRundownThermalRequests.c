// PopRundownThermalRequests 
 
int PopRundownThermalRequests()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r2
  int v4; // r3
  int v5; // r6
  unsigned __int8 *v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r2
  int i; // r7
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int result; // r0
  unsigned int v22; // r1
  __int16 v23; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopCoolingExtensionLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&PopCoolingExtensionLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&PopCoolingExtensionLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopCoolingExtensionLock, v1, (unsigned int)&PopCoolingExtensionLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = PopCoolingExtensionList;
  for ( dword_61E714 = v4 & 0xFFFFFFC0; (int *)v5 != &PopCoolingExtensionList; v5 = *(_DWORD *)v5 )
  {
    if ( *(_BYTE *)(v5 + 32) )
    {
      v6 = (unsigned __int8 *)(v5 + 16);
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v7 + 308);
      v8 = KeAbPreAcquire(v5 + 16, 0, 0);
      v9 = v8;
      do
        v10 = __ldrex(v6);
      while ( __strex(v10 | 1, v6) );
      __dmb(0xBu);
      if ( (v10 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 16), v8, v5 + 16);
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
      *(_DWORD *)(v5 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      PopDiagTraceCoolingExtension(v5, (int)POP_ETW_EVENT_COOLING_EXTENSION_RUNDOWN);
      for ( i = *(_DWORD *)(v5 + 8); i != v5 + 8; i = *(_DWORD *)i )
      {
        if ( *(_BYTE *)(i + 10) )
          PopDiagTraceThermalRequest(i, (int)POP_ETW_EVENT_THERMAL_REQUEST_RUNDOWN);
      }
      if ( *(_DWORD *)(v5 + 20) )
        *(_DWORD *)(v5 + 20) = 0;
      __pld(v6);
      v12 = *(_DWORD *)v6;
      v13 = *(_DWORD *)v6 - 16;
      if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
        v13 = 0;
      if ( (v12 & 2) != 0 )
        goto LABEL_29;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)v6);
      while ( v14 == v12 && __strex(v13, (unsigned int *)v6) );
      if ( v14 != v12 )
LABEL_29:
        ExfReleasePushLock((_DWORD *)(v5 + 16), v12);
      v15 = KeAbPostRelease(v5 + 16);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = *(_WORD *)(v16 + 0x134) + 1;
      *(_WORD *)(v16 + 308) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v15);
    }
  }
  dword_61E714 = 0;
  __pld(&PopCoolingExtensionLock);
  v18 = PopCoolingExtensionLock;
  v19 = PopCoolingExtensionLock - 16;
  if ( (PopCoolingExtensionLock & 0xFFFFFFF0) <= 0x10 )
    v19 = 0;
  if ( (PopCoolingExtensionLock & 2) != 0 )
    goto LABEL_42;
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)&PopCoolingExtensionLock);
  while ( v20 == v18 && __strex(v19, (unsigned int *)&PopCoolingExtensionLock) );
  if ( v20 != v18 )
LABEL_42:
    ExfReleasePushLock(&PopCoolingExtensionLock, v18);
  result = KeAbPostRelease((unsigned int)&PopCoolingExtensionLock);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
