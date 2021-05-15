// PopFxChildDeviceActive 
 
int __fastcall PopFxChildDeviceActive(int a1, _DWORD *a2)
{
  _DWORD *v2; // r10
  _DWORD *v3; // r6
  int result; // r0
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r8
  int v8; // r6
  int v9; // r2
  int v10; // r3
  int v11; // r0
  unsigned __int8 *v12; // r4
  char v13; // r5
  unsigned int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r3
  int v17; // r4
  unsigned __int8 *v18; // r3
  unsigned int v19; // r2
  int v20; // r3
  __int16 v21; // r3
  unsigned int v22; // r2
  _DWORD *v23; // r3
  _DWORD *v24; // r2
  _DWORD *v25; // r3
  unsigned int v26; // r2
  int v27; // r6
  int v28; // r4
  int v29; // r3
  int v30; // r5
  int v31; // r0
  int v32; // r2
  int v33; // r5
  int v34; // r3
  int v35; // r3
  unsigned __int8 *v36; // r2
  unsigned int v37; // r4
  unsigned int v38; // r1
  __int16 v39; // r3
  int v41; // [sp+18h] [bp-40h]
  int v42; // [sp+1Ch] [bp-3Ch]
  unsigned int v43; // [sp+20h] [bp-38h]
  char v44[48]; // [sp+28h] [bp-30h] BYREF

  v2 = *(_DWORD **)(a1 + 28);
  v3 = a2;
  result = IoGetDevicePropertyData(v2[4], DEVPKEY_Device_ClassGuid, 0);
  if ( result < 0 )
    return result;
  if ( v42 != 13 )
    return result;
  if ( v41 != 16 )
    return result;
  result = memcmp((unsigned int)&GUID_DEVICE_CLASS_USB_CONTROLLER, (unsigned int)v44, 16);
  if ( result )
    return result;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  IoControlPnpDeviceActionQueue(1);
  v6 = (int)MiState;
  v7 = -1;
  if ( KiAbEnabled && ((unsigned int)&PopFxDeviceListLock & 0x7FFFFFFC) != 0 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v9 = 0;
    }
    else
    {
      __disable_irq();
      v9 = 1;
    }
    v10 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v9 )
      __enable_irq();
    if ( (v10 & 0x10001) != 0 )
    {
      v11 = KeGetCurrentIrql(MiState);
      KeBugCheckEx(402, v8, (int)&PopFxDeviceListLock, v11, 0);
    }
    --*(_WORD *)(v8 + 310);
    if ( !*(_BYTE *)(v8 + 484) )
    {
      if ( !*(_BYTE *)(v8 + 810) )
      {
        v17 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          v6 = (int)EtwTraceAutoBoostEntryExhaustion(v8, (int)&PopFxDeviceListLock);
        goto LABEL_20;
      }
      v12 = (unsigned __int8 *)(v8 + 810);
      v13 = *(_BYTE *)(v8 + 810);
      __dmb(0xBu);
      do
        v14 = __ldrex(v12);
      while ( __strex(v14 & ~v13, v12) );
      __dmb(0xBu);
      v6 = (int)MiState;
      *(_BYTE *)(v8 + 484) |= v13;
    }
    v15 = *(unsigned __int8 *)(v8 + 484);
    v43 = __clz(__rbit(v15));
    *(_BYTE *)(v8 + 484) = v15 & ~(unsigned __int8)(1 << v43);
    v16 = v8 + 48 * v43;
    v17 = v16 + 488;
    if ( v16 != -488 )
    {
      if ( (unsigned int)&PopFxDeviceListLock >= dword_63389C
        && ((v20 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)((((unsigned int)&PopFxDeviceListLock >> 20) & 0xFFC)
                          - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v20 == 1)
         || v20 == 11) )
      {
        v6 = MmGetSessionIdEx(*(_DWORD *)(v8 + 116));
      }
      else
      {
        v6 = -1;
      }
      *(_DWORD *)(v17 + 20) = v6;
      *(_DWORD *)(v17 + 16) = (unsigned int)&PopFxDeviceListLock & 0x7FFFFFFC;
      goto LABEL_31;
    }
LABEL_20:
    v18 = (unsigned __int8 *)(v8 + 81);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
LABEL_31:
    v21 = *(_WORD *)(v8 + 310) + 1;
    *(_WORD *)(v8 + 310) = v21;
    if ( !v21 && *(_DWORD *)(v8 + 100) != v8 + 100 )
      v6 = KiCheckForKernelApcDelivery(v6);
    v3 = a2;
    goto LABEL_36;
  }
  v17 = 0;
  do
LABEL_36:
    v22 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v22 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v22 )
    v6 = ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v17, (unsigned int)&PopFxDeviceListLock);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  v23 = (_DWORD *)v2[1];
  v24 = v2;
  while ( v23 )
  {
    v24 = v23;
    v23 = (_DWORD *)v23[1];
  }
  while ( v24 != v2 )
  {
    if ( v24[20] == 1 )
    {
      *v3 = v24;
      break;
    }
    v25 = (_DWORD *)*v24;
    if ( *v24 )
    {
      do
      {
        v24 = v25;
        v25 = (_DWORD *)v25[1];
      }
      while ( v25 );
    }
    else
    {
      v24 = (_DWORD *)v24[2];
    }
  }
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v26 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v26 != 17 )
    v6 = (int)ExfReleasePushLockShared(&PopFxDeviceListLock);
  if ( !KiAbEnabled || ((unsigned int)&PopFxDeviceListLock & 0x7FFFFFFC) == 0 )
    goto LABEL_83;
  v27 = 0;
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (unsigned int)&PopFxDeviceListLock >= dword_63389C )
  {
    v6 = 4092;
    v29 = *((unsigned __int8 *)&MiState[2423]
          + ((int)((((unsigned int)&PopFxDeviceListLock >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v29 == 1 || v29 == 11 )
    {
      v6 = *(_DWORD *)(v28 + 116);
      v30 = *(_DWORD *)(v6 + 324);
      if ( v30 )
      {
        v6 = PsIsSystemProcess(v6);
        if ( !v6 )
          v7 = *(_DWORD *)(v30 + 8);
      }
    }
  }
  if ( (unsigned int)KeGetCurrentIrql(v6) <= 1 )
  {
    v27 = 1;
    --*(_WORD *)(v28 + 310);
  }
  v31 = KiAbThreadClearAcquiredLockEntry(v28, (int)&PopFxDeviceListLock, v7);
  v33 = v31;
  if ( !v31 )
  {
    if ( (*(_DWORD *)(v28 + 80) & 0x8000) == 0 )
      KeBugCheckEx(354, v28, (int)&PopFxDeviceListLock, v7, 0);
    if ( !v27 )
      goto LABEL_83;
    goto LABEL_73;
  }
  *(_BYTE *)(v31 + 16) |= 2u;
  if ( *(int *)(v31 + 16) < 0 )
    KiAbEntryRemoveFromTree(v31);
  v31 = KiAbEntryRemoveBoosts(v33, v28, v32);
  *(_BYTE *)(v33 + 13) &= 0xFEu;
  *(_DWORD *)(v33 + 16) = 0;
  v35 = (v33 - v28 - 488) / 48;
  if ( v27 )
  {
    *(_BYTE *)(v28 + 484) |= 1 << v35;
LABEL_73:
    v34 = (__int16)(*(_WORD *)(v28 + 310) + 1);
    *(_WORD *)(v28 + 310) = v34;
    if ( !v34 && *(_DWORD *)(v28 + 100) != v28 + 100 )
      KiCheckForKernelApcDelivery(v31);
    goto LABEL_83;
  }
  __dmb(0xBu);
  v36 = (unsigned __int8 *)(v28 + 810);
  do
    v37 = __ldrex(v36);
  while ( __strex(v37 | (1 << v35), v36) );
  __dmb(0xBu);
LABEL_83:
  result = IoControlPnpDeviceActionQueue(0);
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v39 = *(_WORD *)(v38 + 0x134) + 1;
  *(_WORD *)(v38 + 308) = v39;
  if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
