// PiInitializeDevice 
 
int __fastcall PiInitializeDevice(unsigned __int16 *a1)
{
  int v1; // r5
  int v2; // r6
  unsigned __int16 *v3; // r9
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r4
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r7
  _DWORD *v13; // r8
  int v14; // r0
  int v15; // r0
  int v16; // r5
  int v17; // r3
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  int v28; // [sp+10h] [bp-48h] BYREF
  int v29; // [sp+14h] [bp-44h] BYREF
  int v30; // [sp+18h] [bp-40h] BYREF
  int v31; // [sp+1Ch] [bp-3Ch]
  int v32; // [sp+20h] [bp-38h] BYREF
  int v33; // [sp+24h] [bp-34h] BYREF
  int v34; // [sp+28h] [bp-30h] BYREF
  _DWORD *v35; // [sp+2Ch] [bp-2Ch] BYREF
  int v36; // [sp+30h] [bp-28h] BYREF
  int v37; // [sp+34h] [bp-24h]

  v1 = 0;
  v2 = 0;
  v29 = 0;
  v30 = 0;
  v36 = 0;
  v32 = 0;
  v3 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v5, v6);
  v37 = 1;
  v7 = PnpDeviceObjectFromDeviceInstance((int)a1);
  v35 = (_DWORD *)v7;
  if ( !v7 )
  {
    v8 = PnpUnicodeStringToWstr(&v30, 0, a1);
    if ( v8 < 0 )
    {
      v2 = v30;
      goto LABEL_47;
    }
    v8 = PiPnpRtlBeginOperation(&v29, v9, v10, v11);
    v2 = v30;
    if ( v8 < 0 )
      goto LABEL_8;
    v8 = CmOpenDeviceRegKey(PiPnpRtlCtx, v30, 16, 0, 983103, 0, (int)&v32, 0);
    if ( v8 < 0 )
      goto LABEL_8;
    v12 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 512;
    v3 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 512, 538996816);
    if ( !v3 )
    {
      v8 = -1073741670;
LABEL_8:
      v1 = v29;
      goto LABEL_47;
    }
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, v2, v32, 5, (int)&v33, (int)v3, (int)&v28) >= 0 && v33 == 1 && v28 )
    {
      if ( RtlInitUnicodeStringEx((int)&v30, v3) >= 0 )
      {
        v12 = (unsigned __int16)v30;
      }
      else
      {
        v12 = 0;
        v30 = 0;
        v31 = 0;
      }
    }
    v8 = IoCreateDevice(PnpDriverObject, 0, 0, 4u, 128, 0, &v35);
    v13 = v35;
    if ( v8 < 0 )
      goto LABEL_42;
    v14 = (int)v35;
    v35[7] |= 0x1000u;
    v15 = PipAllocateDeviceNode(v14, &v36);
    v16 = v36;
    v8 = v15;
    if ( !v36 )
    {
      if ( v15 == -1073740946 )
        v8 = -1073741670;
      goto LABEL_41;
    }
    PipSetDevNodeFlags(v36, 17);
    PipSetDevNodeState((_DWORD *)v16, 770);
    v34 = 0;
    v28 = 4;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, v2, v32, 11, (int)&v33, (int)&v34, (int)&v28) >= 0 )
    {
      if ( v33 == 4 && v28 == 4 )
      {
        v17 = v34;
      }
      else
      {
        v17 = 0;
        v34 = 0;
      }
      if ( (v17 & 0x20) != 0 )
      {
        v18 = 18;
LABEL_30:
        PipSetDevNodeProblem(v16, v18, 0, v17);
        goto LABEL_31;
      }
      if ( (v17 & 0x2000) != 0 )
      {
        v18 = 16;
        goto LABEL_30;
      }
      if ( (v17 & 0x40) != 0 )
      {
        v18 = 28;
        goto LABEL_30;
      }
    }
LABEL_31:
    v8 = PnpAllocateDeviceInstancePath(v16, *a1 + 2);
    if ( v8 >= 0 )
    {
      RtlCopyUnicodeString((unsigned __int16 *)(v16 + 20), a1);
      if ( !v12 || PnpConcatenateUnicodeStrings((unsigned __int16 *)(v16 + 28), (unsigned __int16 *)&v30) < 0 )
      {
        v20 = 0;
        *(_WORD *)(v16 + 30) = 0;
        *(_WORD *)(v16 + 28) = 0;
        *(_DWORD *)(v16 + 32) = 0;
      }
      v8 = PnpMapDeviceObjectToDeviceInstance(*(_DWORD *)(v16 + 16), v16 + 20, v19, v20);
      if ( v8 >= 0 )
      {
        PpDevNodeInsertIntoTree((_DWORD *)IopRootDeviceNode, v16);
        v21 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v23 = *(_WORD *)(v22 + 0x134) + 1;
        *(_WORD *)(v22 + 308) = v23;
        if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
          KiCheckForKernelApcDelivery(v21);
        v37 = 0;
        PnpQueryAndSaveDeviceNodeCapabilities((_DWORD *)v16);
        PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v16 + 24), 1);
        PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(v16 + 24), 14);
        PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(IopRootDeviceNode + 24), 15);
        PnpSetPlugPlayEvent((unsigned __int8 *)&GUID_DEVICE_ENUMERATED, *(_DWORD *)(v16 + 16));
LABEL_41:
        if ( v8 >= 0 )
          goto LABEL_44;
        goto LABEL_42;
      }
    }
LABEL_42:
    if ( v13 )
      IoDeleteDevice(v13);
LABEL_44:
    if ( !v37 )
    {
      v1 = v29;
      goto LABEL_51;
    }
    goto LABEL_8;
  }
  ObfDereferenceObject(v7);
  v8 = 0;
LABEL_47:
  v24 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = *(_WORD *)(v25 + 0x134) + 1;
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    KiCheckForKernelApcDelivery(v24);
LABEL_51:
  if ( v32 )
    ZwClose();
  if ( v1 )
    PiPnpRtlEndOperation(v1);
  if ( v2 )
    PnpUnicodeStringToWstrFree(v2, (int)a1);
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v8;
}
