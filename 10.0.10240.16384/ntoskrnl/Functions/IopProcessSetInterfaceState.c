// IopProcessSetInterfaceState 
 
int __fastcall IopProcessSetInterfaceState(int a1, int a2, int a3)
{
  int v3; // r6
  unsigned int v5; // r5
  unsigned __int16 *v6; // r10
  unsigned __int16 *v8; // r9
  int v9; // r0
  int v10; // r4
  unsigned __int16 *v11; // r2
  int v13; // r0
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r6
  int v18; // r1
  int *v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r2
  int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r2
  int v27; // r0
  unsigned int v28; // r1
  int v29; // r3
  GUID *v30; // r0
  unsigned int v31; // r2
  int v32; // r0
  int v33; // r6
  unsigned int v34; // r2
  unsigned int i; // [sp+24h] [bp-8Ch] BYREF
  unsigned int v37; // [sp+28h] [bp-88h] BYREF
  int v38; // [sp+2Ch] [bp-84h]
  unsigned __int16 *v39; // [sp+30h] [bp-80h]
  unsigned __int16 *v40; // [sp+34h] [bp-7Ch] BYREF
  int v41; // [sp+38h] [bp-78h]
  int v42; // [sp+3Ch] [bp-74h]
  __int16 v43; // [sp+40h] [bp-70h] BYREF
  int v44; // [sp+42h] [bp-6Eh]
  __int16 v45; // [sp+46h] [bp-6Ah]
  int v46[8]; // [sp+48h] [bp-68h] BYREF
  char v47[8]; // [sp+68h] [bp-48h] BYREF
  char v48[8]; // [sp+70h] [bp-40h] BYREF
  char v49[8]; // [sp+78h] [bp-38h] BYREF
  char v50[48]; // [sp+80h] [bp-30h] BYREF

  v3 = a2;
  v5 = 0;
  v39 = 0;
  v40 = 0;
  v6 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v37 = 0;
  v38 = 0;
  v41 = 0;
  v42 = 0;
  v8 = 0;
  if ( !a1 || !*(_DWORD *)(a1 + 4) || !*(_WORD *)a1 )
  {
    v10 = -1073741811;
LABEL_51:
    if ( v42 )
    {
      v30 = v3 ? &GUID_DEVICE_INTERFACE_ARRIVAL : &GUID_DEVICE_INTERFACE_REMOVAL;
      PnpSetDeviceClassChange(v30, v50, a1);
      if ( *(_DWORD *)(PiPnpRtlCtx + 156) )
        PnpInterfaceRaisePropertyChangeEventWorker(
          PiPnpRtlCtx,
          (int)v8,
          0,
          0,
          (int)DEVPKEY_DeviceInterface_Enabled,
          *(void (__fastcall **)(int, int, int, int, _DWORD *))(PiPnpRtlCtx + 156));
    }
    if ( v38 )
      PiDmRemoveCacheReferenceForObject(3, v8);
    goto LABEL_58;
  }
  v9 = PnpUnicodeStringToWstr((int *)&v40, 0, (unsigned __int16 *)a1);
  v10 = v9;
  v8 = v40;
  if ( v9 < 0 )
    goto LABEL_58;
  v10 = CmGetDeviceInterfaceClassGuid(v9, v40, v50);
  if ( v10 < 0 )
    goto LABEL_58;
  v10 = IopBuildGlobalSymbolicLinkString(a1, &v43);
  if ( v10 < 0 )
    goto LABEL_58;
  v11 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 400, 538996816);
  v39 = v11;
  if ( !v11 )
    return sub_7C89E8();
  v13 = PnpGetObjectProperty(
          PiPnpRtlCtx,
          (int)v8,
          3,
          0,
          0,
          (int)DEVPKEY_Device_InstanceId,
          (int)v46,
          (int)v11,
          400,
          (int)v47,
          0);
  v10 = v13;
  if ( v13 == -1073741275 )
    goto LABEL_83;
  if ( v13 < 0 )
    goto LABEL_58;
  if ( v46[0] != 18 )
    goto LABEL_83;
  v10 = RtlInitUnicodeStringEx((int)v48, v39);
  if ( v10 < 0 )
    goto LABEL_58;
  v14 = PnpDeviceObjectFromDeviceInstance((int)v48);
  v41 = v14;
  if ( !v14 )
  {
    if ( !v3 )
      goto LABEL_58;
    goto LABEL_83;
  }
  v15 = *(_DWORD *)(v14 + 176);
  v16 = v3;
  v17 = *(_DWORD *)(v15 + 20);
  if ( !a2 )
    goto LABEL_17;
  if ( !PipCanEnableInterfaces(*(_DWORD *)(v15 + 20)) )
  {
LABEL_83:
    v10 = -1073741808;
    goto LABEL_58;
  }
  v16 = a2;
LABEL_17:
  if ( a3 && (*(_DWORD *)(v15 + 16) & 0x10) != 0 )
  {
    if ( v16 )
      v10 = PiDeferSetInterfaceState(v17, a1);
    else
      PiRemoveDeferredSetInterfaceState(v17, a1);
    goto LABEL_58;
  }
  if ( v16 )
  {
    v18 = 512;
    for ( i = 512; ; v18 = i )
    {
      if ( v6 )
      {
        ExFreePoolWithTag((unsigned int)v6);
        v18 = i;
      }
      v19 = (int *)ExAllocatePoolWithTag(1, v18, 538996816);
      v6 = (unsigned __int16 *)v19;
      if ( !v19 )
        break;
      v10 = IoGetDeviceProperty(v41, 11, i, v19, &i);
      if ( v10 != -1073741789 )
        goto LABEL_27;
    }
    v10 = -1073741670;
LABEL_27:
    if ( v10 < 0 || !i )
      goto LABEL_58;
    RtlInitUnicodeString((unsigned int)v49, v6);
    v10 = PiDmAddCacheReferenceForObject(3, v8, &v37);
    if ( v10 >= 0 )
    {
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v20 + 308);
      v5 = v37;
      v21 = KeAbPreAcquire(v37, 0, 0);
      v22 = v21;
      do
        v23 = __ldrex((unsigned __int8 *)v5);
      while ( __strex(v23 | 1, (unsigned __int8 *)v5) );
      __dmb(0xBu);
      if ( (v23 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)v5, v21, v5);
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
      if ( (*(_DWORD *)(v5 + 24) & 1) != 0 )
      {
        if ( *(_DWORD *)(v5 + 28) )
        {
          v38 = 1;
          v10 = 0x40000000;
        }
        else
        {
          v46[2] = 24;
          v46[3] = 0;
          v46[5] = 576;
          v46[4] = (int)&v43;
          v46[6] = SePublicDefaultUnrestrictedSd;
          v46[7] = 0;
          v10 = ZwOpenSymbolicLinkObject();
          if ( v10 == -1073741772 )
            v10 = ZwCreateSymbolicLinkObject();
          if ( v10 >= 0 )
            v42 = 1;
        }
        goto LABEL_42;
      }
      v38 = 1;
      goto LABEL_80;
    }
  }
  else
  {
    v10 = PiDmGetObject(3, (int)v8, (int *)&v37);
    if ( v10 >= 0 )
    {
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v31 + 308);
      v5 = v37;
      v32 = KeAbPreAcquire(v37, 0, 0);
      v33 = v32;
      do
        v34 = __ldrex((unsigned __int8 *)v5);
      while ( __strex(v34 | 1, (unsigned __int8 *)v5) );
      __dmb(0xBu);
      if ( (v34 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)v5, v32, v5);
      if ( v33 )
        *(_BYTE *)(v33 + 14) |= 1u;
      if ( *(_DWORD *)(v5 + 28) )
      {
        ZwClose();
        *(_DWORD *)(v5 + 28) = 0;
        v38 = 1;
        v42 = 1;
LABEL_42:
        __pld((void *)v5);
        v24 = *(_DWORD *)v5;
        if ( (*(_DWORD *)v5 & 0xFFFFFFF0) > 0x10 )
          v25 = v24 - 16;
        else
          v25 = 0;
        if ( (v24 & 2) != 0 )
          goto LABEL_87;
        __dmb(0xBu);
        do
          v26 = __ldrex((unsigned int *)v5);
        while ( v26 == v24 && __strex(v25, (unsigned int *)v5) );
        if ( v26 != v24 )
LABEL_87:
          ExfReleasePushLock((_DWORD *)v5, v24);
        v27 = KeAbPostRelease(v5);
        v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
        *(_WORD *)(v28 + 308) = v29;
        if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
          KiCheckForKernelApcDelivery(v27);
        v3 = a2;
        goto LABEL_51;
      }
LABEL_80:
      v10 = -1073741772;
      goto LABEL_42;
    }
  }
  v5 = v37;
LABEL_58:
  RtlFreeAnsiString(&v43);
  PnpUnicodeStringToWstrFree((unsigned int)v8, a1);
  if ( v41 )
    ObfDereferenceObject(v41);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  if ( v39 )
    ExFreePoolWithTag((unsigned int)v39);
  if ( v5 )
    PiDmObjectRelease(v5);
  return v10;
}
