// PipCallDriverAddDevice 
 
int __fastcall PipCallDriverAddDevice(int a1, int a2)
{
  int v4; // r10
  int v5; // r3
  int v6; // r5
  int v7; // r3
  unsigned __int8 j; // r7
  int *v9; // r4
  int v11; // r2
  int v12; // r2
  int v13; // r0
  int v14; // r3
  int v15; // r3
  int v16; // r0
  int *v17; // r6
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r7
  unsigned int v22; // r5
  unsigned int v23; // r6
  _DWORD *i; // r5
  int v25; // r3
  int v26; // r1
  int v27; // r8
  int v28; // r0
  int v29; // r2
  unsigned __int16 *v30; // r5
  int v31; // r0
  int v32; // [sp+20h] [bp-C8h] BYREF
  int v33; // [sp+24h] [bp-C4h] BYREF
  int v34; // [sp+28h] [bp-C0h] BYREF
  int v35; // [sp+2Ch] [bp-BCh] BYREF
  unsigned int v36; // [sp+30h] [bp-B8h] BYREF
  int v37; // [sp+34h] [bp-B4h]
  int v38; // [sp+38h] [bp-B0h]
  int v39; // [sp+3Ch] [bp-ACh]
  int v40[2]; // [sp+40h] [bp-A8h] BYREF
  unsigned __int16 v41; // [sp+48h] [bp-A0h]
  char v42[4]; // [sp+4Ch] [bp-9Ch] BYREF
  char v43[4]; // [sp+50h] [bp-98h] BYREF
  int v44; // [sp+54h] [bp-94h] BYREF
  int v45; // [sp+58h] [bp-90h] BYREF
  _DWORD v46[6]; // [sp+5Ch] [bp-8Ch] BYREF
  unsigned __int16 v47[56]; // [sp+78h] [bp-70h] BYREF

  v33 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v45 = 0;
  memset(v46, 0, sizeof(v46));
  v47[0] = 0;
  v4 = 0;
  v39 = 0;
  v5 = *(unsigned __int8 *)(a1 + 448);
  v37 = 0;
  if ( v5 && !*(_BYTE *)(a2 + 4) )
    goto LABEL_3;
  *(_BYTE *)(a1 + 448) = 0;
  v6 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 16, 0, 131097, 0, (int)&v35, 0);
  if ( v6 >= 0 )
  {
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 16) + 28) & 0x2000000) != 0 )
    {
      if ( PnpGetObjectProperty(
             PiPnpRtlCtx,
             *(_DWORD *)(a1 + 24),
             1,
             v35,
             0,
             (int)DEVPKEY_Device_DebuggerSafe,
             (int)v42,
             (int)&v36,
             4,
             (int)v43,
             0) >= 0 )
        return sub_7CAE50();
      v29 = 53;
LABEL_103:
      PnpRequestDeviceRemoval(a1, 0, v29);
      v6 = -1073741106;
      goto LABEL_4;
    }
    if ( *(_DWORD *)(a1 + 420) == -1 )
    {
      if ( PnpQueryProximityNode
        && PnpGetObjectProperty(
             PiPnpRtlCtx,
             *(_DWORD *)(a1 + 24),
             1,
             v35,
             0,
             (int)DEVPKEY_Device_Numa_Proximity_Domain,
             (int)v42,
             (int)&v36,
             4,
             (int)v43,
             0) >= 0
        && v36 <= 0xFF
        && PnpQueryProximityNode() >= 0 )
      {
        *(_DWORD *)(a1 + 420) = v41;
      }
      if ( *(_DWORD *)(a1 + 420) == -1 )
      {
        v14 = *(_DWORD *)(a1 + 8);
        if ( v14 )
          v15 = *(_DWORD *)(v14 + 420);
        else
          v15 = -2;
        *(_DWORD *)(a1 + 420) = v15;
      }
      if ( *(_DWORD *)(a1 + 420) != -2 )
      {
        v36 = *(_DWORD *)(a1 + 420);
        PnpSetObjectProperty(
          PiPnpRtlCtx,
          *(_DWORD *)(a1 + 24),
          1,
          v35,
          0,
          (int)DEVPKEY_Device_Numa_Node,
          7,
          (int)&v36,
          4,
          0);
      }
    }
    v34 = 78;
    if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v35, 9, (int)&v44, (int)v47, (int)&v34) >= 0
      && v44 == 1
      && v34 )
    {
      RtlInitUnicodeStringEx((int)v40, v47);
      if ( InitSafeBootMode && !IopSafebootDriverLoad(v40) )
      {
        v34 = 256;
        v30 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 256, 1852141648);
        if ( v30 )
        {
          v31 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), v35, 1, (int)&v44, (int)v30, (int)&v34);
          if ( v31 == -1073741789 )
          {
            ExFreePoolWithTag((unsigned int)v30);
            v30 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v34, 1852141648);
          }
          else if ( v31 >= 0 )
          {
            RtlInitUnicodeString((unsigned int)v40, v30);
          }
        }
        IopBootLog(v40, 0);
        if ( v30 )
          ExFreePoolWithTag((unsigned int)v30);
        goto LABEL_3;
      }
      CmOpenInstallerClassRegKey((int *)PiPnpRtlCtx, v47, v11, (int)&v33, 131097, 0, (int)&v33, 0);
    }
    v45 = a1;
    v46[0] = a2;
    v6 = 0;
    v34 = 512;
    v4 = ExAllocatePoolWithTag(1, 512, 1852141648);
    v32 = v4;
    if ( v4 )
    {
      if ( (*(_DWORD *)(a1 + 268) & 0x4000000) == 0 )
      {
        v16 = PnpCallDriverQueryServiceHelper(&v32, &v34, 19, *(_DWORD *)(a1 + 24), v35, 0, 0, &v45);
        v6 = v16;
        if ( v16 == -1073741275 || v16 == -1073741772 )
        {
          PipSetDevNodeFlags(a1, 0x4000000);
          v6 = 0;
        }
        if ( v6 < 0 )
          goto LABEL_35;
        v4 = v32;
      }
      v12 = v33;
      if ( v33 && (*(_DWORD *)(a1 + 268) & 0x8000000) == 0 )
      {
        v18 = PnpCallDriverQueryServiceHelper(&v32, &v34, 19, v47, v33, 1, 1, &v45);
        v6 = v18;
        if ( v18 == -1073741275 || v18 == -1073741772 )
        {
          PipSetDevNodeFlags(a1, 0x8000000);
          v6 = 0;
        }
        v4 = v32;
        v12 = v33;
      }
      if ( v6 >= 0 )
      {
        if ( (*(_DWORD *)(a1 + 268) & 0x10000000) == 0 )
        {
          v13 = PnpCallDriverQueryServiceHelper(&v32, &v34, 5, *(_DWORD *)(a1 + 24), v35, 0, 2, &v45);
          v6 = v13;
          if ( v13 == -1073741275 || v13 == -1073741772 )
          {
            v6 = -1073741772;
            PipSetDevNodeFlags(a1, 0x10000000);
          }
LABEL_35:
          v4 = v32;
          v12 = v33;
          goto LABEL_36;
        }
        v6 = -1073741772;
      }
    }
    else
    {
      v6 = -1073741670;
      v12 = v33;
    }
LABEL_36:
    if ( (*(_DWORD *)(a1 + 268) & 0x1000) != 0 )
    {
LABEL_84:
      v6 = 0;
      goto LABEL_4;
    }
    if ( v6 >= 0 )
    {
      if ( !*(_DWORD *)(v46[3] + 4) )
      {
        v40[0] = 0;
        goto LABEL_61;
      }
      PipSetDevNodeProblem(a1, 19, -1073741438);
    }
    else
    {
      if ( v6 != -1073741772 )
        goto LABEL_4;
      if ( (*(_DWORD *)(a1 + 368) & 0x100) != 0 )
      {
        PipClearDevNodeProblem(a1);
        v12 = v33;
        v40[0] = 1;
        v38 = 1;
        v6 = 0;
LABEL_61:
        if ( (*(_DWORD *)(a1 + 268) & 0x20000000) == 0 )
        {
          v19 = PnpCallDriverQueryServiceHelper(&v32, &v34, 18, *(_DWORD *)(a1 + 24), v35, 0, 3, &v45);
          v6 = v19;
          if ( v19 == -1073741275 || v19 == -1073741772 )
          {
            PipSetDevNodeFlags(a1, 0x20000000);
            v6 = 0;
          }
          v4 = v32;
          v12 = v33;
        }
        if ( v6 < 0 )
          goto LABEL_4;
        if ( v12 && (*(_DWORD *)(a1 + 268) & 0x40000000) == 0 )
        {
          v20 = PnpCallDriverQueryServiceHelper(&v32, &v34, 18, v47, v12, 1, 4, &v45);
          v6 = v20;
          if ( v20 == -1073741275 || v20 == -1073741772 )
          {
            PipSetDevNodeFlags(a1, 0x40000000);
            v6 = 0;
          }
          v4 = v32;
        }
        if ( v6 < 0 )
          goto LABEL_4;
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v37 = IoGetAttachedDeviceReference(*(_DWORD *)(a1 + 16));
        while ( 2 )
        {
          if ( v23 == 2 )
          {
            v39 = IoGetAttachedDeviceReference(*(_DWORD *)(a1 + 16));
            if ( v38 )
            {
              if ( !*(&v45 + v22 + 2) )
                PipSetDevNodeState((_DWORD *)a1, 771);
            }
          }
          for ( i = (_DWORD *)*(&v45 + v22 + 2); i; i = (_DWORD *)i[1] )
          {
            v27 = PnpCallAddDevice(a1, *i, *(_DWORD *)(*(_DWORD *)(*i + 24) + 4), v23);
            *(_DWORD *)(*i + 8) |= 0x400u;
            if ( v27 < 0 )
            {
              if ( v23 == 2 )
              {
                IovUtilMarkStack(*(_DWORD *)(a1 + 16), *(_DWORD *)(v37 + 16), v21, 0);
                *(_DWORD *)(a1 + 264) = v27;
                v29 = 31;
                goto LABEL_103;
              }
            }
            else
            {
              if ( v23 == 2 )
                v21 = *(_DWORD *)(v39 + 16);
              PipSetDevNodeState((_DWORD *)a1, 771);
            }
            v28 = IoGetAttachedDeviceReference(*(_DWORD *)(a1 + 16));
            ObfDereferenceObject(v28);
          }
          v22 = (unsigned __int8)(v23 + 1);
          v23 = v22;
          if ( v22 < 5 )
            continue;
          break;
        }
        v25 = !v21 || v38;
        IovUtilMarkStack(*(_DWORD *)(a1 + 16), *(_DWORD *)(v37 + 16), v21, v25);
        if ( PipChangeDeviceObjectFromRegistryProperties(*(_DWORD *)(a1 + 16), v35, v47, v33, v40[0]) >= 0 )
        {
          if ( IopQueryLegacyBusInformation(*(_DWORD *)(a1 + 16), v26, a1 + 300, a1 + 304) >= 0 )
          {
            IopInsertLegacyBusDeviceNode(a1, *(_DWORD *)(a1 + 300), *(_DWORD *)(a1 + 304));
          }
          else
          {
            *(_DWORD *)(a1 + 300) = -1;
            *(_DWORD *)(a1 + 304) = -16;
          }
          PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 23);
          goto LABEL_84;
        }
        v29 = 50;
        goto LABEL_103;
      }
    }
LABEL_3:
    v6 = -1073741823;
  }
LABEL_4:
  v7 = 0;
  for ( j = 0; j < 5u; v7 = ++j )
  {
    v9 = (int *)*(&v45 + v7 + 2);
    while ( v9 )
    {
      v17 = v9;
      v9 = (int *)v9[1];
      if ( PnPBootDriversInitialized )
        PnpUnloadAttachedDriver(*v17);
      ObfDereferenceObject(*v17);
      ExFreePoolWithTag((unsigned int)v17);
    }
  }
  if ( v35 )
    ZwClose();
  if ( v33 )
    ZwClose();
  if ( v37 )
    ObfDereferenceObject(v37);
  if ( v39 )
    ObfDereferenceObject(v39);
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v6;
}
