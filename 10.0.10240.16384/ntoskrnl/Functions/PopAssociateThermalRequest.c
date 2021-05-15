// PopAssociateThermalRequest 
 
int __fastcall PopAssociateThermalRequest(int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r7
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r1
  unsigned int v14; // r0
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  _BYTE *v18; // r0
  int v19; // r6
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r2
  int **v24; // r1
  unsigned int v25; // r8
  unsigned int v26; // r2
  int v27; // r0
  int v28; // r6
  unsigned int v29; // r2
  int v30; // r3
  _DWORD *v31; // r1
  int *v32; // r6
  int v33; // r1
  unsigned int v34; // r0
  int v35; // r0
  unsigned int v36; // r1
  __int16 v37; // r3
  int v38; // r1
  unsigned int v39; // r0
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r2
  unsigned int v45; // r2
  int v46; // r1
  unsigned int v47; // r0
  unsigned int v48; // r2
  int v49; // r0
  unsigned int v50; // r1
  int v51; // r3

  v6 = 0;
  v7 = PopGetDope(a2);
  if ( !v7 )
    return sub_7F17A4();
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = KeAbPreAcquire((unsigned int)&PopCoolingExtensionLock, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)&PopCoolingExtensionLock);
  while ( __strex(v12 | 1, (unsigned __int8 *)&PopCoolingExtensionLock) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopCoolingExtensionLock, v10, (unsigned int)&PopCoolingExtensionLock);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  dword_61E714 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v7 + 48) )
    goto LABEL_28;
  dword_61E714 = 0;
  __pld(&PopCoolingExtensionLock);
  v13 = PopCoolingExtensionLock;
  if ( (PopCoolingExtensionLock & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  else
    v14 = PopCoolingExtensionLock - 16;
  if ( (PopCoolingExtensionLock & 2) != 0 )
    goto LABEL_13;
  __dmb(0xBu);
  do
    v43 = __ldrex((unsigned int *)&PopCoolingExtensionLock);
  while ( v43 == v13 && __strex(v14, (unsigned int *)&PopCoolingExtensionLock) );
  if ( v43 != v13 )
LABEL_13:
    ExfReleasePushLock(&PopCoolingExtensionLock, v13);
  v15 = KeAbPostRelease((unsigned int)&PopCoolingExtensionLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  v18 = (_BYTE *)ExAllocatePoolWithTag(1, 72, 1819231056);
  v6 = (int)v18;
  if ( !v18 )
    return sub_7F17A4();
  memset(v18, 0, 72);
  *(_DWORD *)(v6 + 8) = v6 + 8;
  *(_DWORD *)(v6 + 12) = v6 + 8;
  *(_DWORD *)(v6 + 16) = 0;
  *(_DWORD *)(v6 + 20) = 0;
  *(_DWORD *)(v6 + 16) = 0;
  *(_BYTE *)(v6 + 34) = 100;
  *(_DWORD *)(v6 + 24) = a2;
  v19 = PopAcquireCoolingInterface(v6);
  if ( v19 >= 0 )
  {
    *(_BYTE *)(v6 + 32) = 1;
    if ( !a3 || (v19 = PopRegisterCoolingExtensionProtection(v6), v19 >= 0) )
    {
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v20 + 308);
      v21 = KeAbPreAcquire((unsigned int)&PopCoolingExtensionLock, 0, 0);
      v22 = v21;
      do
        v23 = __ldrex((unsigned __int8 *)&PopCoolingExtensionLock);
      while ( __strex(v23 | 1, (unsigned __int8 *)&PopCoolingExtensionLock) );
      __dmb(0xBu);
      if ( (v23 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&PopCoolingExtensionLock, v21, (unsigned int)&PopCoolingExtensionLock);
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
      dword_61E714 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( !*(_DWORD *)(v7 + 48) )
      {
        v24 = (int **)dword_61E71C;
        *(_DWORD *)v6 = &PopCoolingExtensionList;
        *(_DWORD *)(v6 + 4) = v24;
        if ( *v24 != &PopCoolingExtensionList )
          __fastfail(3u);
        *v24 = (int *)v6;
        dword_61E71C = v6;
        *(_DWORD *)(v7 + 48) = v6;
        PopDiagTraceCoolingExtensionAdd(v6);
        v6 = 0;
        a3 = 0;
      }
LABEL_28:
      if ( a3 && (v19 = PopRegisterCoolingExtensionProtection(*(_DWORD *)(v7 + 48)), v19 < 0) )
      {
        dword_61E714 = 0;
        __pld(&PopCoolingExtensionLock);
        v46 = PopCoolingExtensionLock;
        if ( (PopCoolingExtensionLock & 0xFFFFFFF0) <= 0x10 )
          v47 = 0;
        else
          v47 = PopCoolingExtensionLock - 16;
        if ( (PopCoolingExtensionLock & 2) != 0 )
          goto LABEL_93;
        __dmb(0xBu);
        do
          v48 = __ldrex((unsigned int *)&PopCoolingExtensionLock);
        while ( v48 == v46 && __strex(v47, (unsigned int *)&PopCoolingExtensionLock) );
        if ( v48 != v46 )
LABEL_93:
          ExfReleasePushLock(&PopCoolingExtensionLock, v46);
        v49 = KeAbPostRelease((unsigned int)&PopCoolingExtensionLock);
        v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v51 = (__int16)(*(_WORD *)(v50 + 0x134) + 1);
        *(_WORD *)(v50 + 308) = v51;
        if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
          KiCheckForKernelApcDelivery(v49);
      }
      else
      {
        v25 = *(_DWORD *)(v7 + 48) + 16;
        v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v26 + 308);
        v27 = KeAbPreAcquire(v25, 0, 0);
        v28 = v27;
        do
          v29 = __ldrex((unsigned __int8 *)v25);
        while ( __strex(v29 | 1, (unsigned __int8 *)v25) );
        __dmb(0xBu);
        if ( (v29 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)v25, v27, v25);
        if ( v28 )
          *(_BYTE *)(v28 + 14) |= 1u;
        *(_DWORD *)(v25 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v30 = *(_DWORD *)(v7 + 48);
        *(_DWORD *)(a1 + 16) = v30;
        v31 = *(_DWORD **)(v30 + 12);
        *(_DWORD *)a1 = v30 + 8;
        *(_DWORD *)(a1 + 4) = v31;
        if ( *v31 != v30 + 8 )
          __fastfail(3u);
        *v31 = a1;
        *(_DWORD *)(v30 + 12) = a1;
        *(_BYTE *)(a1 + 10) = 1;
        PopDiagTraceThermalRequest(a1, POP_ETW_EVENT_THERMAL_REQUEST_ADD);
        if ( *(_DWORD *)(*(_DWORD *)(a1 + 16) + 68) )
          PopThermalUpdateTelemetryClientCount(1);
        v32 = (int *)(*(_DWORD *)(v7 + 48) + 16);
        if ( *(_DWORD *)(*(_DWORD *)(v7 + 48) + 20) )
          *(_DWORD *)(*(_DWORD *)(v7 + 48) + 20) = 0;
        __pld(v32);
        v33 = *v32;
        if ( (*v32 & 0xFFFFFFF0) <= 0x10 )
          v34 = 0;
        else
          v34 = v33 - 16;
        if ( (v33 & 2) != 0 )
          goto LABEL_43;
        __dmb(0xBu);
        do
          v44 = __ldrex((unsigned int *)v32);
        while ( v44 == v33 && __strex(v34, (unsigned int *)v32) );
        if ( v44 != v33 )
LABEL_43:
          ExfReleasePushLock(v32, v33);
        v35 = KeAbPostRelease((unsigned int)v32);
        v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v37 = *(_WORD *)(v36 + 0x134) + 1;
        *(_WORD *)(v36 + 308) = v37;
        if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
          KiCheckForKernelApcDelivery(v35);
        dword_61E714 = 0;
        __pld(&PopCoolingExtensionLock);
        v38 = PopCoolingExtensionLock;
        if ( (PopCoolingExtensionLock & 0xFFFFFFF0) <= 0x10 )
          v39 = 0;
        else
          v39 = PopCoolingExtensionLock - 16;
        if ( (PopCoolingExtensionLock & 2) != 0 )
          goto LABEL_49;
        __dmb(0xBu);
        do
          v45 = __ldrex((unsigned int *)&PopCoolingExtensionLock);
        while ( v45 == v38 && __strex(v39, (unsigned int *)&PopCoolingExtensionLock) );
        if ( v45 != v38 )
LABEL_49:
          ExfReleasePushLock(&PopCoolingExtensionLock, v38);
        v40 = KeAbPostRelease((unsigned int)&PopCoolingExtensionLock);
        v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v42 = *(_WORD *)(v41 + 0x134) + 1;
        *(_WORD *)(v41 + 308) = v42;
        if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
          KiCheckForKernelApcDelivery(v40);
        v19 = 0;
      }
      goto LABEL_52;
    }
  }
LABEL_52:
  if ( v6 )
    PopCleanCoolingExtension(v6);
  return v19;
}
