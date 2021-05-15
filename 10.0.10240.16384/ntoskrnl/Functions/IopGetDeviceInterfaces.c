// IopGetDeviceInterfaces 
 
int __fastcall IopGetDeviceInterfaces(int a1, int a2, int a3, int a4, unsigned __int16 **a5, int a6)
{
  _DWORD *v6; // r10
  int v7; // r9
  unsigned int v8; // r7
  unsigned int v9; // r8
  unsigned __int16 *v10; // r5
  int v11; // r4
  int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r0
  int v17; // r3
  unsigned int v18; // r9
  int v19; // r0
  int v20; // r8
  unsigned int v21; // r0
  int v22; // r3
  unsigned __int16 *i; // r6
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  unsigned __int16 *v27; // r0
  int v28; // [sp+4h] [bp-FCh]
  int v29; // [sp+20h] [bp-E0h]
  int v30; // [sp+24h] [bp-DCh] BYREF
  unsigned int v31; // [sp+2Ch] [bp-D4h]
  int v32; // [sp+34h] [bp-CCh] BYREF
  _DWORD *v33; // [sp+38h] [bp-C8h]
  int v34; // [sp+3Ch] [bp-C4h]
  char v35[4]; // [sp+44h] [bp-BCh] BYREF
  unsigned int v36; // [sp+48h] [bp-B8h]
  int v37; // [sp+4Ch] [bp-B4h] BYREF
  unsigned int v38[4]; // [sp+50h] [bp-B0h] BYREF
  unsigned __int16 **v39; // [sp+60h] [bp-A0h]
  int v40; // [sp+64h] [bp-9Ch] BYREF
  int v41; // [sp+68h] [bp-98h]
  int v42; // [sp+6Ch] [bp-94h]
  int v43; // [sp+70h] [bp-90h]
  int v44[6]; // [sp+78h] [bp-88h] BYREF
  unsigned __int16 v45[56]; // [sp+90h] [bp-70h] BYREF

  v29 = a2;
  v6 = (_DWORD *)a6;
  v42 = a3;
  v43 = a4;
  v7 = a2;
  v8 = 0;
  v41 = 0;
  v39 = a5;
  *a5 = 0;
  v32 = 0;
  v33 = (_DWORD *)a6;
  v37 = 0;
  v38[0] = 0;
  v36 = 0;
  v34 = 0;
  v9 = 0;
  v31 = 0;
  v10 = 0;
  v30 = 0;
  v11 = PnpStringFromGuid(a1, (int)v45);
  if ( v11 < 0 )
    goto LABEL_57;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(__int16 *)(v12 + 0x134) - 1;
  *(_WORD *)(v12 + 308) = v13;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v12, v13);
  v14 = CmOpenInterfaceClassRegKey((int *)PiPnpRtlCtx, v45, 0, (int)&PiPnpRtlCtx, 983103, 0, (int)&v37, 0);
  v11 = v14;
  if ( v14 != -1073741772 )
  {
    if ( v14 != -1073741766 )
    {
      if ( v14 < 0 )
      {
        v7 = v29;
        v9 = 0;
        goto LABEL_26;
      }
      v15 = PnpGetObjectProperty(
              1198550608,
              1024,
              (int)v45,
              4,
              v37,
              v28,
              (int)DEVPKEY_DeviceInterfaceClass_DefaultInterface,
              (int)v35,
              v38,
              &v40,
              0);
      v11 = v15;
      if ( v15 >= 0 )
        return sub_7C8188();
      if ( v15 != -1073741772 && v15 != -1073741766 && v15 != -1073741275 )
      {
        v8 = v38[0];
        v7 = v29;
        v9 = 0;
        goto LABEL_26;
      }
      v8 = v38[0];
      v7 = v29;
      if ( v29 )
      {
        v11 = PnpUnicodeStringToWstr(&v32, 0, v29);
        v36 = v32;
        if ( v11 < 0 )
          goto LABEL_25;
      }
      memset(v44, 0, 20);
      SeCaptureSubjectContext(&v44[1]);
      v17 = 4096;
      v30 = 4096;
      v18 = 0;
      v11 = -1073741789;
      while ( v18 < 5 )
      {
        if ( v10 )
        {
          ExFreePoolWithTag((unsigned int)v10);
          v17 = v30;
        }
        v19 = ExAllocatePoolWithTag(1, 2 * v17, 538996816);
        v10 = (unsigned __int16 *)v19;
        if ( !v19 )
        {
          v11 = -1073741670;
          break;
        }
        v41 = v30;
        v20 = v19;
        v38[0] = v19;
        v32 = v30;
        v11 = CmGetMatchingFilteredDeviceInterfaceList(
                PiPnpRtlCtx,
                v45,
                v36,
                (v42 & 1) == 0,
                IopDeviceInterfaceFilterCallback,
                v44,
                v19,
                v30,
                &v30,
                0);
        v17 = v30 + ((v20 - (int)v10) >> 1);
        v30 = v17;
        ++v18;
        if ( v11 != -1073741789 )
          break;
      }
      v21 = SeReleaseSubjectContext((int)&v44[1]);
      if ( v11 >= 0 )
      {
        if ( v30 )
          goto LABEL_19;
        v30 = 1;
        if ( v41
          || (ExFreePoolWithTag((unsigned int)v10),
              v21 = ExAllocatePoolWithTag(1, 2 * v30, 538996816),
              (v10 = (unsigned __int16 *)v21) != 0) )
        {
          *v10 = 0;
LABEL_19:
          if ( !v43 )
          {
            v22 = *v10;
            for ( i = v10; v22; v22 = *i )
            {
              v11 = CmSetDeviceInterfacePathFormat(v21, i, 1);
              if ( v11 < 0 )
                break;
              v21 = wcslen(i);
              i += v21 + 1;
            }
          }
          goto LABEL_24;
        }
        v11 = -1073741670;
      }
LABEL_24:
      v7 = v29;
      v6 = v33;
LABEL_25:
      v9 = v31;
      goto LABEL_26;
    }
    v9 = 0;
  }
  v30 = 1;
  v27 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2, 538996816);
  v10 = v27;
  v7 = v29;
  if ( v27 )
  {
    *v27 = 0;
    v11 = 0;
  }
  else
  {
    v11 = -1073741670;
  }
LABEL_26:
  v24 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    KiCheckForKernelApcDelivery(v24);
  if ( v11 >= 0 )
  {
    *v39 = v10;
    if ( v6 )
      *v6 = 2 * v30;
    v10 = 0;
    goto LABEL_37;
  }
LABEL_57:
  *v39 = 0;
  if ( v6 )
    *v6 = 0;
LABEL_37:
  if ( v37 )
    ZwClose();
  PnpUnicodeStringToWstrFree(v36, v7);
  if ( v8 )
    ExFreePoolWithTag(v8);
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v11;
}
