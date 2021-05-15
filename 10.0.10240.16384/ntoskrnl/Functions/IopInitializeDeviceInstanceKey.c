// IopInitializeDeviceInstanceKey 
 
int __fastcall IopInitializeDeviceInstanceKey(int a1, unsigned __int16 *a2, int a3)
{
  __int64 v7; // r2
  int v8; // r0
  int v9; // r7
  _DWORD *v10; // r6
  int v11; // r0
  int v12; // r4
  int v13; // r0
  __int16 v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v19; // r1
  unsigned int v20; // r7
  unsigned int v21; // r6
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r7
  int v25; // [sp+20h] [bp-38h] BYREF
  int v26; // [sp+24h] [bp-34h] BYREF
  _DWORD *v27; // [sp+28h] [bp-30h] BYREF
  int v28; // [sp+2Ch] [bp-2Ch] BYREF
  _DWORD *v29; // [sp+30h] [bp-28h] BYREF
  int v30[9]; // [sp+34h] [bp-24h] BYREF

  v25 = 0;
  v30[0] = 0;
  if ( IopGetRegistryValue(a1, L"Phantom", 0, &v27) >= 0 )
    return sub_7C9D68();
  v7 = *(_QWORD *)(a3 + 4);
  if ( HIDWORD(v7) == (_DWORD)v7 )
  {
    v21 = 4 * (v7 + 256);
    v22 = ExAllocatePoolWithTag(1, v21, 1684303952);
    v23 = v22;
    if ( !v22 )
    {
      *(_DWORD *)a3 = -1073741670;
      return 0;
    }
    memmove(v22, *(_DWORD *)(a3 + 12), 4 * *(_DWORD *)(a3 + 8));
    ExFreePoolWithTag(*(_DWORD *)(a3 + 12));
    *(_DWORD *)(a3 + 4) = v21 >> 2;
    *(_DWORD *)(a3 + 12) = v23;
  }
  v8 = PnpDeviceObjectFromDeviceInstance((int)a2);
  v29 = (_DWORD *)v8;
  if ( v8 )
  {
    *(_DWORD *)(*(_DWORD *)(a3 + 12) + 4 * *(_DWORD *)(a3 + 8)) = v8;
LABEL_6:
    ++*(_DWORD *)(a3 + 8);
    return 1;
  }
  v9 = IoCreateDevice(PnpDriverObject, 0, 0, 4, 128, 0, &v29);
  if ( v9 >= 0 )
  {
    v10 = v29;
    v11 = (int)v29;
    v29[7] |= 0x1000u;
    *(_DWORD *)(*(_DWORD *)(v11 + 176) + 16) |= 0x10u;
    if ( PipAllocateDeviceNode(v11, v30) == -1073740946 || (v12 = v30[0]) == 0 )
    {
      IoDeleteDevice(v10);
      v9 = -1073741670;
    }
    else
    {
      v9 = PnpAllocateDeviceInstancePath(v30[0], *a2 + 2);
      if ( v9 >= 0 )
      {
        RtlCopyUnicodeString((unsigned __int16 *)(v12 + 20), a2);
        PipSetDevNodeFlags(v12, 17);
        PipSetDevNodeState((_DWORD *)v12, 770);
        PpDevNodeInsertIntoTree((_DWORD *)IopRootDeviceNode, v12);
        v26 = 0;
        v28 = 4;
        v13 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v12 + 24), a1, 11, (int)&v25, (int)&v26, (int)&v28);
        if ( v13 < 0 )
        {
          v18 = -1073741275;
          if ( v13 != -1073741275 )
            goto LABEL_18;
          v19 = 1;
        }
        else
        {
          if ( v25 == 4 && v28 == 4 )
          {
            v14 = v26;
          }
          else
          {
            v14 = 0;
            v26 = 0;
          }
          if ( (v14 & 0x20) != 0 )
          {
            v18 = 0;
            v19 = 18;
          }
          else if ( (v14 & 0x2000) != 0 )
          {
            v18 = 0;
            v19 = 16;
          }
          else
          {
            if ( (v14 & 0x40) == 0 )
            {
LABEL_18:
              if ( IopGetRegistryValue(a1, L"NoResourceAtInitTime", 0, &v27) >= 0 )
              {
                v20 = (unsigned int)v27;
                if ( v27[1] == 4 && v27[3] >= 4u && *(_DWORD *)((char *)v27 + v27[2]) )
                  PipSetDevNodeFlags(v12, 256);
                ExFreePoolWithTag(v20);
              }
              PnpQueryAndSaveDeviceNodeCapabilities(v12);
              if ( (*(_DWORD *)(v12 + 368) & 0x4000) != 0
                && ((*(_DWORD *)(v12 + 268) & 0x2000) == 0 || *(_DWORD *)(v12 + 276) != 1) )
              {
                PipClearDevNodeProblem(v12);
                PipSetDevNodeProblem(v12, 29, 0);
              }
              if ( ((*(_DWORD *)(v12 + 268) & 0x6000) != 0
                 || PnpGetObjectProperty(
                      PiPnpRtlCtx,
                      *(_DWORD *)(v12 + 24),
                      1,
                      a1,
                      0,
                      (int)DEVPKEY_Device_FirmwareDependencies,
                      (int)&v25,
                      0,
                      0,
                      (int)&v28,
                      0) == -1073741789
                 && v25 == 8210)
                && (*(_DWORD *)(v12 + 368) & 0x4000) == 0
                && (v26 & 1) == 0 )
              {
                PpDevCfgProcessDevice(v12, a1, 0);
              }
              v15 = *(_DWORD *)(v12 + 268);
              if ( (v15 & 0x2000) == 0 || (v15 = *(_DWORD *)(v12 + 276), v15 != 22) )
              {
                if ( (*(_DWORD *)(v12 + 268) & 0x2000) == 0 || (v15 = *(_DWORD *)(v12 + 276), v15 != 29) )
                {
                  if ( !PnpIsDeviceInstanceEnabled(a1, (unsigned __int16 *)(v12 + 20), 1, v15) )
                  {
                    PipClearDevNodeProblem(v12);
                    PipSetDevNodeProblem(v12, 22, 0);
                  }
                }
              }
              PpDeviceRegistration(v12 + 20, 1, v12 + 28, 0);
              PnpMapDeviceObjectToDeviceInstance(*(_DWORD *)(v12 + 16), v12 + 20, v16, v17);
              ObfReferenceObject((int)v10);
              v30[0] = 0;
              if ( PnpGetDeviceResourcesFromRegistry(v10, 0, 4, v30, &v29) >= 0 )
              {
                v24 = v30[0];
                if ( v30[0] )
                {
                  if ( IopAllocateBootResourcesRoutine(4, *(_DWORD *)(v12 + 16), v30[0]) >= 0 )
                    PipSetDevNodeFlags(v12, 64);
                  ExFreePoolWithTag(v24);
                }
              }
              ObfReferenceObject((int)v10);
              *(_DWORD *)(*(_DWORD *)(a3 + 12) + 4 * *(_DWORD *)(a3 + 8)) = v10;
              goto LABEL_6;
            }
            v18 = 0;
            v19 = 28;
          }
        }
        PipSetDevNodeProblem(v12, v19, v18);
        goto LABEL_18;
      }
      IoDeleteDevice(v10);
    }
  }
  *(_DWORD *)a3 = v9;
  return 0;
}
