// IoGetDeviceInterfaceAlias 
 
int __fastcall IoGetDeviceInterfaceAlias(int a1, int a2, int a3)
{
  unsigned __int16 *v3; // r5
  _WORD *v4; // r6
  unsigned __int16 *v5; // r9
  int v8; // r0
  int v9; // r4
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r0
  unsigned __int16 *v15; // r0
  unsigned __int16 *v16; // r7
  char v17; // r10
  _DWORD *v18; // r10
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r4
  int v23; // r0
  unsigned __int16 *v24; // r4
  unsigned __int16 *v25; // r0
  char v26[4]; // [sp+20h] [bp-98h] BYREF
  int v27; // [sp+24h] [bp-94h] BYREF
  _DWORD *v28; // [sp+28h] [bp-90h]
  int v29; // [sp+2Ch] [bp-8Ch] BYREF
  int v30; // [sp+30h] [bp-88h] BYREF
  char v31[4]; // [sp+34h] [bp-84h] BYREF
  int v32[4]; // [sp+38h] [bp-80h] BYREF
  unsigned __int16 v33[56]; // [sp+48h] [bp-70h] BYREF

  v3 = 0;
  v4 = 0;
  v26[0] = 0;
  v5 = 0;
  v27 = 0;
  v28 = (_DWORD *)a3;
  if ( !a1 || !*(_DWORD *)(a1 + 4) || !*(_WORD *)a1 )
  {
    v9 = -1073741811;
LABEL_26:
    if ( v4 )
      ExFreePoolWithTag((unsigned int)v4);
    if ( v5 )
      ExFreePoolWithTag((unsigned int)v5);
    goto LABEL_30;
  }
  v8 = PnpUnicodeStringToWstr(&v27, 0, a1);
  v9 = v8;
  v3 = (unsigned __int16 *)v27;
  if ( v8 >= 0 )
  {
    if ( CmValidateDeviceInterfaceName(v8, (unsigned __int16 *)v27) < 0 )
      return sub_7E7074();
    SeCaptureSubjectContext(v32);
    v9 = PiPnpRtlApplyMandatoryFilters(PiPnpRtlCtx, (int)v3, 3, 0, v32, v26);
    SeReleaseSubjectContext((int)v32);
    if ( v9 >= 0 )
    {
      if ( v26[0] )
      {
        v9 = PnpStringFromGuid(a2, (int)v33);
        if ( v9 >= 0 )
        {
          v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v12 = *(__int16 *)(v11 + 0x134) - 1;
          *(_WORD *)(v11 + 308) = v12;
          ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v11, v12);
          v13 = ExAllocatePoolWithTag(1, 400, 538996816);
          v5 = (unsigned __int16 *)v13;
          if ( v13 )
          {
            v9 = PnpGetObjectProperty(
                   PiPnpRtlCtx,
                   (int)v3,
                   3,
                   0,
                   0,
                   (int)DEVPKEY_Device_InstanceId,
                   (int)&v29,
                   v13,
                   400,
                   (int)v31,
                   0);
            if ( v9 < 0 )
            {
LABEL_25:
              v19 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
              v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
              *(_WORD *)(v20 + 308) = v21;
              if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
                KiCheckForKernelApcDelivery(v19);
              goto LABEL_26;
            }
            if ( v29 != 18 )
            {
              v9 = -1073741585;
              goto LABEL_25;
            }
            v27 = 128;
            v14 = ExAllocatePoolWithTag(1, 256, 538996816);
            v4 = (_WORD *)v14;
            if ( v14 )
            {
              v9 = CmGetDeviceInterfaceReferenceString(v14, v3, v14, 128, &v27);
              if ( v9 != -1073741789 )
                goto LABEL_15;
              ExFreePoolWithTag((unsigned int)v4);
              v22 = v27;
              v23 = ExAllocatePoolWithTag(1, 2 * v27, 538996816);
              v4 = (_WORD *)v23;
              if ( v23 )
              {
                v9 = CmGetDeviceInterfaceReferenceString(v23, v3, v23, v22, &v27);
LABEL_15:
                if ( v9 == -1073741772 )
                {
                  v9 = 0;
                  ExFreePoolWithTag((unsigned int)v4);
                  v4 = 0;
                }
                if ( v9 < 0 )
                  goto LABEL_25;
                v9 = CmGetDeviceInterfacePathFormat();
                if ( v9 < 0 )
                  goto LABEL_25;
                v27 = 512;
                v15 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 1024, 538996816);
                v16 = v15;
                if ( v15 )
                {
                  v17 = v26[0];
                  v9 = CmGetDeviceInterfaceName((int)v15, v33, v5, v4, v26[0], v15, 0x200u, (unsigned int *)&v27);
                  if ( v9 != -1073741789 )
                  {
LABEL_21:
                    if ( v9 >= 0 )
                    {
                      v18 = v28;
                      v9 = RtlInitUnicodeStringEx((int)v28, v16);
                      if ( v9 >= 0 )
                      {
                        v9 = CmOpenDeviceInterfaceRegKey(
                               (int *)PiPnpRtlCtx,
                               v16,
                               48,
                               (int)&PiPnpRtlCtx,
                               131097,
                               0,
                               (int)&v30,
                               0);
                        if ( v9 < 0 )
                          RtlFreeAnsiString(v18);
                        else
                          ZwClose();
                      }
                    }
                    goto LABEL_25;
                  }
                  ExFreePoolWithTag((unsigned int)v16);
                  v24 = (unsigned __int16 *)v27;
                  v25 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v27, 538996816);
                  v16 = v25;
                  if ( v25 )
                  {
                    v9 = CmGetDeviceInterfaceName(
                           (int)v25,
                           v33,
                           v5,
                           v4,
                           v17,
                           v25,
                           (unsigned int)v24,
                           (unsigned int *)&v27);
                    goto LABEL_21;
                  }
                }
                goto LABEL_32;
              }
            }
          }
LABEL_32:
          v9 = -1073741670;
          goto LABEL_25;
        }
      }
      else
      {
        v9 = -1073741790;
      }
    }
  }
LABEL_30:
  PnpUnicodeStringToWstrFree((unsigned int)v3, a1);
  return v9;
}
