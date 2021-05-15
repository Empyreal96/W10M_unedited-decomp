// IopRegisterDeviceInterface 
 
int __fastcall IopRegisterDeviceInterface(unsigned __int16 *a1, int a2, _WORD *a3, int a4, unsigned int *a5, int *a6)
{
  int v6; // r8
  int v7; // r6
  _WORD *v8; // r0
  int v10; // r4
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int *v15; // r5
  unsigned int v16; // r2
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  BOOL v20; // r7
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  int v27; // r4
  int v28; // r9
  unsigned __int16 *v29; // r6
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r7
  int v35; // r4
  unsigned int v36; // r0
  int v37; // r0
  unsigned int v38; // r1
  int v39; // r3
  unsigned int v40; // r4
  _WORD *v41; // r0
  char v42[4]; // [sp+20h] [bp-110h] BYREF
  int v43; // [sp+24h] [bp-10Ch] BYREF
  unsigned int *v44; // [sp+28h] [bp-108h] BYREF
  unsigned __int16 *v45; // [sp+2Ch] [bp-104h]
  int v46; // [sp+30h] [bp-100h] BYREF
  int v47; // [sp+34h] [bp-FCh]
  int v48; // [sp+38h] [bp-F8h] BYREF
  int v49; // [sp+3Ch] [bp-F4h]
  int v50; // [sp+40h] [bp-F0h] BYREF
  unsigned int v51; // [sp+44h] [bp-ECh] BYREF
  _WORD *v52; // [sp+48h] [bp-E8h]
  int v53; // [sp+4Ch] [bp-E4h] BYREF
  int v54; // [sp+50h] [bp-E0h]
  char v55[4]; // [sp+54h] [bp-DCh] BYREF
  char v56[8]; // [sp+58h] [bp-D8h] BYREF
  _DWORD v57[4]; // [sp+60h] [bp-D0h] BYREF
  unsigned __int16 v58[40]; // [sp+70h] [bp-C0h] BYREF
  char v59[112]; // [sp+C0h] [bp-70h] BYREF

  v54 = a4;
  v45 = a1;
  v6 = 0;
  v7 = 0;
  *a5 = 0;
  v52 = a3;
  v53 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v43 = 0;
  v44 = 0;
  v46 = 0;
  v42[0] = 0;
  if ( PnpStringFromGuid(a2, (int)v58) < 0 )
    goto LABEL_84;
  v51 = 512;
  v8 = (_WORD *)ExAllocatePoolWithTag(1, 1024, 538996816);
  *a5 = (unsigned int)v8;
  if ( !v8 )
    return sub_7C8D70();
  v10 = CmGetDeviceInterfaceName((int)v8, v58, v45, v52, 0, v8, 0x200u, &v51);
  if ( v10 == -1073741789 )
  {
    ExFreePoolWithTag(*a5);
    v40 = v51;
    v41 = (_WORD *)ExAllocatePoolWithTag(1, 2 * v51, 538996816);
    *a5 = (unsigned int)v41;
    if ( !v41 )
      return sub_7C8D70();
    v10 = CmGetDeviceInterfaceName((int)v41, v58, v45, v52, 0, v41, v40, &v51);
  }
  if ( v10 < 0 )
LABEL_84:
    JUMPOUT(0x7C8D72);
  if ( a6 )
  {
    if ( PipCheckForDenyExecute(v58) )
      v11 = 0x800000;
    else
      v11 = 0;
    *a6 = v11;
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(__int16 *)(v12 + 0x134) - 1;
  *(_WORD *)(v12 + 308) = v13;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v12, v13);
  v14 = PiDmGetObject(3, *a5, (int *)&v44);
  v15 = v44;
  if ( v14 < 0 )
  {
    v20 = 0;
  }
  else
  {
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v16 + 308);
    v17 = KeAbPreAcquire((unsigned int)v15, 0, 0);
    v18 = v17;
    do
      v19 = __ldrex(v15);
    while ( !v19 && __strex(0x11u, v15) );
    __dmb(0xBu);
    if ( v19 )
      ExfAcquirePushLockSharedEx(v15, v17, (unsigned int)v15);
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    v20 = (v15[6] & 1) != 0;
    __pld(v15);
    v21 = *v15;
    if ( (*v15 & 0xFFFFFFF0) > 0x10 )
      v22 = v21 - 16;
    else
      v22 = 0;
    if ( (v21 & 2) != 0 )
      goto LABEL_70;
    __dmb(0xBu);
    do
      v23 = __ldrex(v15);
    while ( v23 == v21 && __strex(v22, v15) );
    if ( v23 != v21 )
LABEL_70:
      ExfReleasePushLock(v15, v21);
    v24 = KeAbPostRelease((unsigned int)v15);
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
    *(_WORD *)(v25 + 308) = v26;
    if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
      KiCheckForKernelApcDelivery(v24);
  }
  v27 = PiDmAddCacheReferenceForObject(4, v58, &v53);
  v28 = v53;
  if ( v27 < 0 )
    goto LABEL_78;
  v29 = v45;
  v27 = PiDmAddCacheReferenceForObject(1, v45, &v43);
  if ( v27 < 0 )
    goto LABEL_77;
  v30 = PnpGetObjectProperty(
          PiPnpRtlCtx,
          (int)v29,
          1,
          0,
          0,
          (int)DEVPKEY_Device_ContainerId,
          (int)v56,
          (int)v57,
          16,
          (int)v55,
          0);
  v27 = v30;
  if ( v30 == -1073741275 )
  {
    v57[0] = 0;
    v57[1] = 0;
    v57[2] = 0;
    v57[3] = 0;
    goto LABEL_30;
  }
  if ( v30 < 0 )
  {
LABEL_77:
    v7 = v43;
LABEL_78:
    v34 = 0;
    goto LABEL_41;
  }
LABEL_30:
  if ( !PnpIsNullGuid((int)v57) )
  {
    v27 = PnpStringFromGuid((int)v57, (int)v59);
    if ( v27 < 0 )
      goto LABEL_77;
    v27 = PiDmAddCacheReferenceForObject(5, v59, &v50);
    v6 = v50;
    if ( v27 < 0 )
      goto LABEL_77;
  }
  if ( v20 )
  {
    v34 = 0;
    goto LABEL_35;
  }
  v27 = PiPnpRtlBeginOperation(&v46, v31, v32, v33);
  if ( v27 >= 0 )
  {
    v27 = CmCreateDeviceInterface(PiPnpRtlCtx, *a5, 2, &v48, v42, 0);
    v34 = v46;
    v47 = v48;
    if ( v27 < 0 )
    {
LABEL_48:
      v7 = v43;
      goto LABEL_41;
    }
    v49 = (unsigned __int8)v42[0];
LABEL_35:
    if ( v15 || (v27 = PiDmGetObject(3, *a5, (int *)&v44), v15 = v44, v27 >= 0) )
    {
      PiDmListAddObject(0, v28, v15, 0);
      if ( v49 )
        v35 = 0x20000;
      else
        v35 = 0;
      v36 = wcslen(v45);
      v27 = PnpSetObjectProperty(
              PiPnpRtlCtx,
              *a5,
              3,
              v47,
              0,
              (int)DEVPKEY_Device_InstanceId,
              18,
              (int)v45,
              2 * (v36 + 1),
              v35);
      if ( v27 >= 0 )
      {
        v7 = v43;
        PiDmListAddObject(1, v43, v15, 0);
        if ( v6 )
          PiDmListAddObject(2, v6, v15, 0);
        goto LABEL_41;
      }
      if ( v49 )
        CmDeleteDeviceInterface(PiPnpRtlCtx, *a5, 0);
    }
    goto LABEL_48;
  }
  v7 = v43;
  v34 = v46;
LABEL_41:
  v37 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v39 = (__int16)(*(_WORD *)(v38 + 0x134) + 1);
  *(_WORD *)(v38 + 308) = v39;
  if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
    v37 = KiCheckForKernelApcDelivery(v37);
  if ( v27 < 0 )
    JUMPOUT(0x7C8D74);
  if ( !v54 )
    v27 = CmSetDeviceInterfacePathFormat(v37, *a5, 1);
  if ( v47 )
    ZwClose();
  if ( v34 )
    PiPnpRtlEndOperation(v34);
  if ( v15 )
    PiDmObjectRelease((int)v15);
  if ( v28 )
  {
    PiDmRemoveCacheReferenceForObject(*(_DWORD *)(v28 + 20), *(_DWORD *)(v28 + 12));
    PiDmObjectRelease(v28);
  }
  if ( v7 )
  {
    PiDmRemoveCacheReferenceForObject(*(_DWORD *)(v7 + 20), *(_DWORD *)(v7 + 12));
    PiDmObjectRelease(v7);
  }
  if ( v6 )
  {
    PiDmRemoveCacheReferenceForObject(*(_DWORD *)(v6 + 20), *(_DWORD *)(v6 + 12));
    PiDmObjectRelease(v6);
  }
  return v27;
}
