// PipProcessStartPhase3 
 
int __fastcall PipProcessStartPhase3(unsigned int a1, int a2, int a3)
{
  int v3; // r8
  int v6; // r5
  int *v7; // r6
  int v8; // r3
  int v9; // r1
  int v10; // r2
  int v11; // r3
  unsigned __int16 *v12; // r5
  unsigned __int16 *v13; // r6
  int v14; // r9
  int v15; // r10
  unsigned int v16; // r2
  int v17; // r3
  int v18; // r1
  int v19; // r2
  int v20; // r0
  int v21; // r10
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  char v29[4]; // [sp+18h] [bp-50h] BYREF
  int v30; // [sp+1Ch] [bp-4Ch]
  int v31; // [sp+20h] [bp-48h] BYREF
  int v32; // [sp+24h] [bp-44h] BYREF
  int v33; // [sp+28h] [bp-40h] BYREF
  int v34; // [sp+2Ch] [bp-3Ch] BYREF
  int v35; // [sp+30h] [bp-38h] BYREF
  int v36[2]; // [sp+38h] [bp-30h] BYREF
  int *v37; // [sp+40h] [bp-28h]
  int v38; // [sp+44h] [bp-24h]

  v35 = 0;
  v3 = a2;
  v38 = a2;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    return sub_7CBD5C();
  v6 = PiPnpRtlBeginOperation(&v35, a2, a3, Microsoft_Windows_Kernel_PnPEnableBits);
  if ( v6 >= 0 )
  {
    v7 = *(int **)(a1 + 16);
    v8 = *(_DWORD *)(a1 + 268);
    v37 = v7;
    if ( (v8 & 0x20) != 0 || PnpDeviceObjectToDeviceInstance((int)v7) < 0 )
    {
LABEL_5:
      if ( (*(_DWORD *)(a1 + 268) & 0x2000) != 0 && *(_DWORD *)(a1 + 276) == 9 )
      {
        v6 = -1073741823;
      }
      else
      {
        if ( v3 )
          PipSetDevNodeFlags(a1, 8);
        PnpQueryAndSaveDeviceNodeCapabilities((_DWORD *)a1);
        v6 = PiProcessQueryDeviceState(v7, v9, v10, v11);
        PnpSetPlugPlayEvent(&GUID_DEVICE_ARRIVAL, *(_DWORD *)(a1 + 16));
        PnpSetDeviceInstanceStartedEvent(a1);
        if ( v6 >= 0 )
        {
          PpvUtilTestStartedPdoStack();
          PipSetDevNodeState((_DWORD *)a1, 776);
          PnpStartedDeviceNodeDependencyCheck(a1);
          PiCreateDriverSwDevices(a1);
          if ( SeAuditingWithTokenForSubcategory(137) )
            PiAuditStartedDevice(a1);
          v6 = 0;
        }
      }
      goto LABEL_12;
    }
    PnpQueryID(a1, 1, (unsigned int *)&v31, &v32);
    PnpQueryID(a1, 2, (unsigned int *)&v34, &v33);
    v12 = (unsigned __int16 *)v34;
    v13 = (unsigned __int16 *)v31;
    PnpGenerateDeviceIdsHash(v31, v34, (_DWORD *)(a1 + 444));
    if ( !v13 && !v12 )
    {
LABEL_42:
      PnpSetObjectProperty(
        PiPnpRtlCtx,
        *(_DWORD *)(a1 + 24),
        1,
        v30,
        0,
        (int)DEVPKEY_Device_HardwareConfigurationIndex,
        7,
        (int)&PnpCurrentHardwareConfigurationIndex,
        4,
        0);
      RtlInitUnicodeString((unsigned int)v36, L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}");
      RtlGUIDFromString((unsigned __int16 *)v36, (_BYTE *)(a1 + 424));
      PipSetDevNodeFlags(a1, 32);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v25 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      PiDcUpdateDeviceContainerMembership(*(_DWORD *)(a1 + 24), v30, L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}");
      v26 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v28 = *(_WORD *)(v27 + 0x134) + 1;
      *(_WORD *)(v27 + 308) = v28;
      if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
        KiCheckForKernelApcDelivery(v26);
      ZwClose();
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 1);
      PnpSetPlugPlayEvent(&GUID_DEVICE_ENUMERATED, *(_DWORD *)(a1 + 16));
      v7 = v37;
      v3 = v38;
      goto LABEL_5;
    }
    v14 = 0;
    v15 = 0;
    v29[0] = 0;
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v16 + 308);
    ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
    v34 = 4;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v30, 11, (int)v36, (int)&v31, (int)&v34) >= 0
      && v36[0] == 4
      && v34 == 4 )
    {
      v17 = v31;
      if ( (v31 & 0x20) == 0 || (v31 & 1) != 0 )
      {
LABEL_23:
        v19 = v32;
        v18 = v33;
        if ( (v17 & 0x400) != 0 )
          goto LABEL_31;
        v20 = 0;
        if ( v13 )
        {
          v20 = PnpCheckDeviceIdsChanged(a1, v30, v13, v32, 1, v29);
          v15 = (unsigned __int8)v29[0];
          v17 = v31;
          if ( v29[0] )
            goto LABEL_29;
          v18 = v33;
        }
        if ( v12 )
        {
          v20 = PnpCheckDeviceIdsChanged(a1, v30, v12, v18, 0, v29);
          v15 = (unsigned __int8)v29[0];
          v17 = v31;
        }
LABEL_29:
        v19 = v32;
        if ( v20 >= 0 && v15 )
        {
          v21 = 1;
          v31 = v17 | 0x400;
          v14 = 1;
          goto LABEL_32;
        }
LABEL_31:
        v21 = 0;
LABEL_32:
        if ( v13 )
        {
          CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v30, 2, 7, (int)v13, v19, 0);
          ExFreePoolWithTag((unsigned int)v13);
        }
        if ( v12 )
        {
          CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v30, 3, 7, (int)v12, v33, 0);
          ExFreePoolWithTag((unsigned int)v12);
        }
        if ( v21 )
          CmSetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v30, 11, 4, (int)&v31, 4, 0);
        v22 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v24 = *(_WORD *)(v23 + 0x134) + 1;
        *(_WORD *)(v23 + 308) = v24;
        if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
          KiCheckForKernelApcDelivery(v22);
        if ( v14 )
          PpDevCfgProcessDevice(a1, v30, 0);
        goto LABEL_42;
      }
    }
    else
    {
      v17 = 0;
      v31 = 0;
    }
    v14 = 1;
    goto LABEL_23;
  }
LABEL_12:
  if ( v35 )
    PiPnpRtlEndOperation(v35);
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_ProcessDeviceStart_Stop,
      *(_DWORD *)(a1 + 24),
      3,
      *(unsigned __int16 **)(a1 + 24));
  return v6;
}
