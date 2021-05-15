// PopCoolingExtensionPnpNotification 
 
int __fastcall PopCoolingExtensionPnpNotification(int a1, int a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r6
  unsigned int v18; // r2
  int v19; // r3
  int v20; // r6
  void (__fastcall *v21)(int); // r5
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  unsigned __int8 *v28; // r4
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r6
  unsigned int v32; // r2
  int v33; // r1
  unsigned int v34; // r0
  unsigned int v35; // r2
  int v36; // r0
  unsigned int v37; // r1
  __int16 v38; // r3
  char v40[40]; // [sp+8h] [bp-28h] BYREF

  if ( !memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_QUERY_REMOVE, 16) )
  {
    v4 = a2 + 16;
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = KeAbPreAcquire(a2 + 16, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v8 | 1, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 16), v6, a2 + 16);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    *(_DWORD *)(a2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_BYTE *)(a2 + 32) = 0;
    PopDiagTraceCoolingExtensionRemove(a2);
    KeInitializeEvent((int)v40, 0, 0);
    *(_DWORD *)(a2 + 40) = v40;
    PopPropogateCoolingChange(a2);
    if ( *(_DWORD *)(a2 + 20) )
      *(_DWORD *)(a2 + 20) = 0;
    __pld((void *)v4);
    v9 = *(_DWORD *)v4;
    v10 = *(_DWORD *)v4 - 16;
    if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
      v10 = 0;
    if ( (v9 & 2) != 0 )
      goto LABEL_17;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)v4);
    while ( v11 == v9 && __strex(v10, (unsigned int *)v4) );
    if ( v11 != v9 )
LABEL_17:
      ExfReleasePushLock((_DWORD *)(a2 + 16), v9);
    v12 = KeAbPostRelease(a2 + 16);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
    KeWaitForSingleObject((unsigned int)v40, 0, 0, 0, 0);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v15 + 308);
    v16 = KeAbPreAcquire(a2 + 16, 0, 0);
    v17 = v16;
    do
      v18 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v18 | 1, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( (v18 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 16), v16, a2 + 16);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    *(_DWORD *)(a2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a2 + 40) = 0;
    v19 = *(_DWORD *)(a2 + 20);
    v20 = *(_DWORD *)(a2 + 48);
    v21 = *(void (__fastcall **)(int))(a2 + 56);
    if ( v19 )
      *(_DWORD *)(v4 + 4) = 0;
    __pld((void *)v4);
    v22 = *(_DWORD *)v4;
    v23 = *(_DWORD *)v4 - 16;
    if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
      v23 = 0;
    if ( (v22 & 2) != 0 )
      goto LABEL_37;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)v4);
    while ( v24 == v22 && __strex(v23, (unsigned int *)v4) );
    if ( v24 != v22 )
LABEL_37:
      ExfReleasePushLock((_DWORD *)v4, v22);
    v25 = KeAbPostRelease(v4);
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v27 = *(_WORD *)(v26 + 0x134) + 1;
    *(_WORD *)(v26 + 308) = v27;
    if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
      KiCheckForKernelApcDelivery(v25);
    v21(v20);
  }
  else
  {
    if ( !memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_COMPLETE, 16) )
      goto LABEL_68;
    if ( memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_CANCELLED, 16) )
      return 0;
    if ( PopAcquireCoolingInterface(a2) < 0 )
    {
LABEL_68:
      PopOrphanCoolingExtension(a2);
      return 0;
    }
    v28 = (unsigned __int8 *)(a2 + 16);
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v29 + 308);
    v30 = KeAbPreAcquire(a2 + 16, 0, 0);
    v31 = v30;
    do
      v32 = __ldrex(v28);
    while ( __strex(v32 | 1, v28) );
    __dmb(0xBu);
    if ( (v32 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a2 + 16), v30, a2 + 16);
    if ( v31 )
      *(_BYTE *)(v31 + 14) |= 1u;
    *(_DWORD *)(a2 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_BYTE *)(a2 + 32) = 1;
    PopDiagTraceCoolingExtensionAdd(a2);
    if ( *(_DWORD *)(a2 + 8) != a2 + 8 )
      PopPropogateCoolingChange(a2);
    if ( *(_DWORD *)(a2 + 20) )
      *(_DWORD *)(a2 + 20) = 0;
    __pld(v28);
    v33 = *(_DWORD *)v28;
    v34 = *(_DWORD *)v28 - 16;
    if ( (*(_DWORD *)v28 & 0xFFFFFFF0) <= 0x10 )
      v34 = 0;
    if ( (v33 & 2) != 0 )
      goto LABEL_63;
    __dmb(0xBu);
    do
      v35 = __ldrex((unsigned int *)v28);
    while ( v35 == v33 && __strex(v34, (unsigned int *)v28) );
    if ( v35 != v33 )
LABEL_63:
      ExfReleasePushLock((_DWORD *)(a2 + 16), v33);
    v36 = KeAbPostRelease(a2 + 16);
    v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v38 = *(_WORD *)(v37 + 0x134) + 1;
    *(_WORD *)(v37 + 308) = v38;
    if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
      KiCheckForKernelApcDelivery(v36);
  }
  return 0;
}
