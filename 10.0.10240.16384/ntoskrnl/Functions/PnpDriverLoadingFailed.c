// PnpDriverLoadingFailed 
 
int __fastcall PnpDriverLoadingFailed(int a1, int a2)
{
  int v5; // r4
  unsigned int v6; // r6
  unsigned int i; // r8
  int v8; // r0
  int v9; // r7
  int v10; // r3
  _DWORD *v11; // r4
  unsigned int v12; // r2
  _DWORD *v13; // r4
  int v14; // r3
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r10
  int v19; // r3
  unsigned int v20; // r2
  int v21; // r7
  unsigned int j; // r4
  int v23; // r3
  __int16 v24; // r3
  _DWORD *v25; // r8
  int v26; // r3
  __int16 v27; // r3
  int v28; // r0
  unsigned int v29; // r1
  int v30; // r3
  __int16 v31; // [sp+18h] [bp-88h] BYREF
  __int16 v32; // [sp+1Ah] [bp-86h]
  const __int16 *v33; // [sp+1Ch] [bp-84h]
  _DWORD *v34; // [sp+20h] [bp-80h] BYREF
  unsigned __int16 *v35; // [sp+24h] [bp-7Ch] BYREF
  unsigned int v36; // [sp+28h] [bp-78h]
  int v37; // [sp+2Ch] [bp-74h]
  int v38; // [sp+30h] [bp-70h]
  unsigned __int16 v39; // [sp+38h] [bp-68h] BYREF
  unsigned int v40; // [sp+3Ch] [bp-64h]
  int v41; // [sp+40h] [bp-60h]
  int v42; // [sp+44h] [bp-5Ch]
  __int16 *v43; // [sp+48h] [bp-58h]
  int v44; // [sp+4Ch] [bp-54h]
  int v45; // [sp+50h] [bp-50h]
  int v46; // [sp+54h] [bp-4Ch]
  unsigned __int16 v47[36]; // [sp+58h] [bp-48h] BYREF

  v34 = (_DWORD *)a1;
  v37 = 0;
  if ( !a1 )
    return sub_818840();
  v32 = 10;
  v31 = 8;
  v42 = a1;
  v33 = L"Enum";
  v41 = 24;
  v44 = 576;
  v43 = &v31;
  v45 = 0;
  v46 = 0;
  v5 = ZwOpenKey();
  if ( v5 >= 0 )
  {
    v32 = 32;
    v31 = 30;
    v33 = L"INITSTARTFAILED";
    v38 = 1;
    ZwSetValueKey();
    v5 = IopGetRegistryValue(0, L"Count", 0, (int *)&v34);
    v6 = 0;
    if ( v5 < 0 )
      goto LABEL_50;
    if ( v34[1] == 4 && v34[3] >= 4u )
      v6 = *(_DWORD *)((char *)v34 + v34[2]);
    ExFreePoolWithTag((unsigned int)v34);
    if ( v6 )
    {
      v36 = v6;
      for ( i = 0; i < v6; ++i )
      {
        if ( PipServiceInstanceToDeviceInstance(a1, a2, i, &v39, 0, 0) >= 0 )
        {
          v8 = PnpDeviceObjectFromDeviceInstance((int)&v39);
          v9 = v8;
          if ( v8 )
          {
            v10 = *(_DWORD *)(v8 + 176);
            v11 = *(_DWORD **)(v10 + 20);
            if ( v11 )
            {
              if ( !PipIsDevNodeDNStarted(*(_DWORD *)(v10 + 20)) )
                IopReleaseDeviceResources(v11, 1);
            }
          }
          v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v12 + 308);
          ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
          if ( v9 )
          {
            v13 = *(_DWORD **)(*(_DWORD *)(v9 + 176) + 20);
            if ( v13 )
            {
              if ( (v13[67] & 1) != 0 )
              {
                v14 = v13[43];
                if ( v14 == 776 || v14 == 775 )
                {
                  PoFxAbandonDevice((int)v13);
                  PipSetDevNodeState(v13, 786);
                  PipSetDevNodeProblem((int)v13, 24, 0, v19);
                }
              }
            }
            ObfDereferenceObject(v9);
          }
          ExFreePoolWithTag(v40);
          v15 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
          v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
          *(_WORD *)(v16 + 308) = v17;
          if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
            KiCheckForKernelApcDelivery(v15);
        }
      }
      v18 = v37;
      if ( v36 != v6 )
      {
        v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v20 + 308);
        ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
        if ( v36 )
        {
          v21 = 0;
          for ( j = 0; j < v6; ++j )
          {
            v35 = v47;
            RtlStringCchPrintfExW((int)v47, 10, &v35, 0, 0, L"%u");
            v23 = v35 - v47;
            v32 = 20;
            if ( v23 == -1 )
              v24 = 20;
            else
              v24 = 2 * v23;
            v31 = v24;
            v33 = (const __int16 *)v47;
            if ( IopGetRegistryValue(0, v47, 0, (int *)&v34) >= 0 )
            {
              v25 = v34;
              if ( j != v21 )
              {
                ZwDeleteValueKey();
                v35 = v47;
                RtlStringCchPrintfExW((int)v47, 10, &v35, 0, 0, L"%u");
                v26 = v35 - v47;
                v32 = 20;
                if ( v26 == -1 )
                  v27 = 20;
                else
                  v27 = 2 * v26;
                v31 = v27;
                v33 = (const __int16 *)v47;
                ZwSetValueKey();
              }
              ExFreePoolWithTag((unsigned int)v25);
              ++v21;
            }
          }
          v18 = v37;
        }
        v32 = 12;
        v31 = 10;
        v33 = L"Count";
        ZwSetValueKey();
        v32 = 26;
        v31 = 24;
        v33 = L"NextInstance";
        ZwSetValueKey();
        v28 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
        v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v30 = (__int16)(*(_WORD *)(v29 + 0x134) + 1);
        *(_WORD *)(v29 + 308) = v30;
        if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
          KiCheckForKernelApcDelivery(v28);
      }
      ZwClose();
      if ( v18 )
        ZwClose();
      v5 = 0;
    }
    else
    {
LABEL_50:
      ZwClose();
    }
  }
  return v5;
}
