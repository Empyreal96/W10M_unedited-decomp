// PiCMDeleteDevice 
 
int __fastcall PiCMDeleteDevice(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v7; // r6
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r0
  int v14; // r2
  int v15; // r4
  unsigned __int16 *v16; // r5
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  int v35; // r1
  int v36; // r2
  int v37; // r3
  int v38; // r2
  int v40; // [sp+10h] [bp-78h] BYREF
  int v41; // [sp+14h] [bp-74h] BYREF
  int v42; // [sp+18h] [bp-70h] BYREF
  int v43; // [sp+1Ch] [bp-6Ch] BYREF
  char v44[8]; // [sp+20h] [bp-68h] BYREF
  unsigned __int16 v45[4]; // [sp+28h] [bp-60h] BYREF
  char v46[4]; // [sp+30h] [bp-58h] BYREF
  int v47; // [sp+34h] [bp-54h]
  int v48; // [sp+38h] [bp-50h]
  unsigned __int16 *v49; // [sp+3Ch] [bp-4Ch]
  int v50; // [sp+44h] [bp-44h]
  int v51; // [sp+48h] [bp-40h]
  int v52[14]; // [sp+50h] [bp-38h] BYREF

  v7 = 0;
  *a6 = 0;
  v40 = 0;
  v12 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v46);
  if ( v12 >= 0 )
  {
    v13 = PiAuDoesClientHaveAccess(2, v9, v10, v11);
    if ( !v13 )
    {
      v15 = -1073741790;
LABEL_39:
      v12 = PiCMReturnBasicResultData(v15, v51, a3, a4, a6);
      goto LABEL_40;
    }
    v16 = v49;
    if ( !v49 || v47 || v48 != 1 || v50 || !a3 || a4 < 8 )
      goto LABEL_38;
    v15 = CmValidateDeviceName(v13, v49, v14, 0);
    if ( v15 < 0 )
      goto LABEL_39;
    if ( CmIsRootDevice(v16, v17, v18, v19) )
    {
LABEL_38:
      v15 = -1073741811;
      goto LABEL_39;
    }
    v15 = PiPnpRtlBeginOperation(&v40, v20, v21, v22);
    if ( v15 >= 0 )
    {
      if ( CmGetDeviceStatus(PiPnpRtlCtx, v16, 0, &v41, &v43, &v42) >= 0 && (v41 & 2) != 0 )
      {
        if ( (v41 & 1) != 0 && (v41 & 0x2000) == 0 )
        {
          v15 = -1073741808;
          goto LABEL_18;
        }
        v15 = RtlInitUnicodeStringEx((int)v44, v16);
        if ( v15 < 0 )
          goto LABEL_18;
        PpDevNodeLockTree(3, v23);
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = *(__int16 *)(v24 + 0x134) - 1;
        *(_WORD *)(v24 + 308) = v25;
        ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v24, v25);
        PpDeviceRegistration((int)v44, 0, 0, 1);
        v15 = CmDeleteDevice(PiPnpRtlCtx, v16, 0);
        v26 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v28 = *(_WORD *)(v27 + 0x134) + 1;
        *(_WORD *)(v27 + 308) = v28;
        if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
          KiCheckForKernelApcDelivery(v26);
        PpDevNodeUnlockTree(3);
        if ( v15 < 0 )
          goto LABEL_18;
        memset(v52, 0, 28);
        if ( RtlInitUnicodeStringEx((int)v52, v16) >= 0 )
        {
          v52[2] = 1;
          v52[3] = 0x40000;
          ZwPlugPlayControl();
        }
      }
      else
      {
        v15 = RtlInitUnicodeStringEx((int)v44, v16);
        if ( v15 < 0 )
          goto LABEL_18;
        PpDevNodeLockTree(3, v29);
        v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v31 = *(__int16 *)(v30 + 0x134) - 1;
        *(_WORD *)(v30 + 308) = v31;
        ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v30, v31);
        PpDeviceRegistration((int)v44, 0, 0, 1);
        v15 = CmDeleteDevice(PiPnpRtlCtx, v16, 0);
        v32 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v34 = *(_WORD *)(v33 + 0x134) + 1;
        *(_WORD *)(v33 + 308) = v34;
        if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
          KiCheckForKernelApcDelivery(v32);
        PpDevNodeUnlockTree(3);
        if ( v15 < 0 )
          goto LABEL_18;
        if ( CmIsRootEnumeratedDevice(v16, v35, v36, v37) && RtlInitUnicodeStringEx((int)v44, L"HTREE\\ROOT\\0") >= 0 )
          PiQueueDeviceRequest((int)v44, 8, v38, 1, 0);
      }
      if ( RtlInitUnicodeStringEx((int)v45, v16) >= 0 )
        PnpSetDeviceInstancePropertyChangeEventFromDeviceInstance(v45);
    }
LABEL_18:
    v7 = v40;
    goto LABEL_39;
  }
LABEL_40:
  PiCMReleaseObjectInputData((int)v46);
  if ( v7 )
    PiPnpRtlEndOperation(v7);
  return v12;
}
