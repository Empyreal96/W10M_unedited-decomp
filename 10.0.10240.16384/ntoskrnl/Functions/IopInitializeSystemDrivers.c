// IopInitializeSystemDrivers 
 
int __fastcall IopInitializeSystemDrivers(int a1, int a2, int a3)
{
  int v4; // r0
  int *v5; // r0
  int *v6; // r4
  unsigned int v7; // r8
  int v8; // r0
  int v9; // r5
  int v10; // r5
  unsigned int v11; // r7
  int v12; // r3
  int v13; // r5
  int v14; // r0
  int v15; // t1
  __int64 v16; // r4
  unsigned int v17; // [sp+8h] [bp-48h] BYREF
  int v18; // [sp+Ch] [bp-44h] BYREF
  int v19; // [sp+10h] [bp-40h] BYREF
  __int16 v20; // [sp+18h] [bp-38h]
  __int16 v21; // [sp+1Ah] [bp-36h]
  const __int16 *v22; // [sp+1Ch] [bp-34h]
  __int16 v23[2]; // [sp+20h] [bp-30h] BYREF
  unsigned int v24; // [sp+24h] [bp-2Ch]
  _DWORD v25[10]; // [sp+28h] [bp-28h] BYREF

  if ( PnpEtwHandle )
    return sub_968E24(a1, a2, a3, PnpEtwHandle | HIDWORD(PnpEtwHandle));
  if ( ExIsManufacturingModeEnabled() )
    v4 = dword_61A1C8;
  else
    v4 = 0;
  v5 = (int *)CmGetSystemDriverList(v4);
  v6 = v5;
  if ( v5 )
  {
    v7 = (unsigned int)v5;
    v8 = *v5;
    if ( *v6 )
    {
      do
      {
        if ( IopGetDriverNameFromKeyNode(v8) >= 0
          && (v9 = IopReferenceDriverObjectByName(v25), RtlFreeAnsiString(v25), v9) )
        {
          ObfDereferenceObjectWithTag(v9);
        }
        else
        {
          v21 = 10;
          v20 = 8;
          v22 = L"Enum";
          if ( IopOpenRegistryKeyEx(&v18) < 0 )
            goto LABEL_12;
          v10 = 0;
          if ( IopGetRegistryValue(v18, L"INITSTARTFAILED", 0, (int *)&v17) >= 0 )
          {
            if ( *(_DWORD *)(v17 + 12) == 4 )
              v10 = *(_DWORD *)(*(_DWORD *)(v17 + 8) + v17);
            ExFreePoolWithTag(v17);
          }
          ZwClose();
          if ( !v10 )
          {
LABEL_12:
            if ( IopGetRegistryValue(*v6, L"Group", 0, (int *)&v17) < 0 )
            {
              v13 = 0;
            }
            else
            {
              v11 = v17;
              v12 = *(_DWORD *)(v17 + 12);
              if ( v12 )
              {
                v23[0] = *(_DWORD *)(v17 + 12);
                v23[1] = v12;
                v24 = *(_DWORD *)(v17 + 8) + v17;
                v13 = PipLookupGroupName(v23, 1);
              }
              else
              {
                v13 = 0;
              }
              ExFreePoolWithTag(v11);
            }
            if ( PipCheckDependencies(*v6) )
            {
              v14 = IopLoadDriver(*v6, 1, 0, &v19);
              if ( v13 && v14 >= 0 )
                ++*(_DWORD *)(v13 + 16);
            }
            else
            {
              v14 = ZwClose();
            }
            InbvIndicateProgress(v14);
            goto LABEL_21;
          }
        }
        ZwClose();
LABEL_21:
        v15 = v6[1];
        ++v6;
        v8 = v15;
      }
      while ( v15 );
    }
    ExFreePoolWithTag(v7);
  }
  PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 17, 0, 0, 0, 0);
  if ( !PnpBootOptions )
    PnpWaitForDevicesToStart();
  PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 18, 0, 0, 0, 0);
  if ( IopGroupListHead )
    PipFreeGroupTree();
  v16 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_SystemStart_Stop) )
      EtwWrite(v16, SHIDWORD(v16), (int)KMPnPEvt_SystemStart_Stop, 0);
  }
  return 1;
}
