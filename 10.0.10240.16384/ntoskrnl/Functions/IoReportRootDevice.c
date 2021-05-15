// IoReportRootDevice 
 
int __fastcall IoReportRootDevice(int a1, int a2, int a3)
{
  int v3; // r8
  int v5; // r5
  int v6; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r3
  __int16 v17; // r3
  int v18; // r7
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r2
  unsigned int v23; // r1
  char *v24; // r3
  char v25[8]; // [sp+18h] [bp-378h] BYREF
  unsigned __int16 v26[2]; // [sp+20h] [bp-370h] BYREF
  _WORD *v27; // [sp+24h] [bp-36Ch]
  char v28[4]; // [sp+28h] [bp-368h] BYREF
  int v29; // [sp+2Ch] [bp-364h] BYREF
  int v30; // [sp+30h] [bp-360h] BYREF
  unsigned __int16 v31[2]; // [sp+38h] [bp-358h] BYREF
  char *v32; // [sp+3Ch] [bp-354h]
  _WORD *v33; // [sp+40h] [bp-350h] BYREF
  int v34; // [sp+44h] [bp-34Ch] BYREF
  _WORD v35[200]; // [sp+48h] [bp-348h] BYREF
  char v36; // [sp+1D8h] [bp-1B8h] BYREF

  v25[0] = 0;
  v27 = v35;
  v26[1] = 400;
  v26[0] = 0;
  v32 = &v36;
  v3 = *(_DWORD *)(a1 + 24);
  v31[1] = 402;
  v5 = 0;
  v31[0] = 0;
  v29 = 0;
  v30 = 0;
  v6 = RtlAppendUnicodeToString(v26, (int)L"ROOT\\", a3, 0);
  if ( v6 >= 0 )
  {
    v6 = RtlAppendUnicodeStringToString(v26, (unsigned __int16 *)(v3 + 12));
    if ( v6 >= 0 )
    {
      if ( v26[0] > 0x18Eu )
        return sub_817AF8();
      RtlCopyUnicodeString(v31, v26);
      v6 = PiPnpRtlBeginOperation(&v29, v8, v9, v10);
      if ( v6 < 0 )
        goto LABEL_11;
      PpDevNodeLockTree(1, v11);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(__int16 *)(v12 + 0x134) - 1;
      *(_WORD *)(v12 + 308) = v13;
      ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v12, v13);
      v6 = RtlAppendUnicodeToString(v26, (int)L"\\", v14, v15);
      if ( v6 < 0 )
        goto LABEL_11;
      v33 = &v35[v26[0] >> 1];
      RtlStringCchPrintfExW((int)v33, (400 - (unsigned int)v26[0]) >> 1, &v33, 0, 0, L"%04u");
      v16 = &v33[-(v26[0] >> 1)] - v35;
      if ( v16 == -1 )
        v17 = 400 - v26[0];
      else
        v17 = 2 * v16;
      v26[0] += v17;
      v6 = CmCreateDevice(PiPnpRtlCtx, (int)v27, 983103, &v30, v25, 0);
      v18 = (unsigned __int8)v25[0];
      v5 = v30;
      if ( v6 >= 0 )
      {
        if ( !v25[0] )
          goto LABEL_11;
        v22 = (int)v32;
        v23 = v31[0] + 4;
        v24 = &v32[2 * (v23 >> 1)];
        *((_WORD *)v24 - 1) = 0;
        *((_WORD *)v24 - 2) = 0;
        v6 = CmSetDeviceRegProp(PiPnpRtlCtx, (int)v27, v5, 2, 7, v22, v23, 0);
        if ( v6 >= 0 )
        {
          v34 = 32;
          v6 = CmSetDeviceRegProp(PiPnpRtlCtx, (int)v27, v5, 11, 4, (int)&v34, 4, 0);
          if ( v6 >= 0 )
          {
            v28[0] = -1;
            v6 = PnpSetObjectProperty(PiPnpRtlCtx, (int)v27, 1, v5, 0, (int)DEVPKEY_Device_Reported, 17, (int)v28, 1, 0);
            if ( v6 >= 0 )
            {
              v6 = CmSetDeviceRegProp(
                     PiPnpRtlCtx,
                     (int)v27,
                     v5,
                     5,
                     1,
                     *(_DWORD *)(v3 + 16),
                     *(unsigned __int16 *)(v3 + 12) + 2,
                     0);
              if ( v6 >= 0 )
              {
                *(_DWORD *)(a1 + 8) |= 0x800u;
                PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 8, 0, 0, 0, 0);
LABEL_11:
                v19 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
                v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
                *(_WORD *)(v20 + 308) = v21;
                if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
                  KiCheckForKernelApcDelivery(v19);
                PpDevNodeUnlockTree(1);
                if ( v5 )
                  ZwClose();
                if ( v29 )
                  PiPnpRtlEndOperation(v29);
                return v6;
              }
            }
          }
        }
      }
      if ( v18 )
      {
        CmDeleteDevice(PiPnpRtlCtx, v27, 0);
        PnpCleanupDeviceRegistryValues((int)v26);
      }
      goto LABEL_11;
    }
  }
  return v6;
}
