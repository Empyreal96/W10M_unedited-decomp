// IoResolveDependency 
 
int __fastcall IoResolveDependency(int a1, int a2)
{
  int v4; // r5
  int v5; // r0
  int v6; // r3
  int v7; // r0
  int v8; // r6
  int v9; // r1
  int v10; // r0
  int v11; // r0
  int v13; // r0
  int v14; // r3
  int v15; // r3
  int v16; // r1
  int v17; // [sp+0h] [bp-18h] BYREF
  int v18; // [sp+4h] [bp-14h]

  v4 = 0;
  PnpAcquireDependencyRelationsLock(1);
  v17 = 1;
  v18 = a1;
  v5 = PipQueryBindingResolution(&v17);
  if ( !v5 )
  {
    if ( a2 )
      v6 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 44);
    else
      v6 = 0;
    if ( !v6 )
    {
      v17 = 0;
      v18 = a2;
      v7 = PipCreateDependencyNode(&v17);
      v8 = v7;
      if ( v7 )
      {
        v4 = PipAddBindingId(v7, a1);
        if ( v4 >= 0 )
        {
          PipDereferenceDependencyNode(v8);
          goto LABEL_8;
        }
        PipUnlinkDeviceObjectAndDependencyNode(a2, v8);
        PipDereferenceDependencyNode(v8);
      }
      else
      {
        v4 = -1073741670;
      }
LABEL_15:
      ((void (*)(void))PnpReleaseDependencyRelationsLock)();
      return v4;
    }
    if ( a2 )
      v13 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 44);
    else
      v13 = 0;
    v4 = PipAddBindingId(v13, a1);
    if ( v4 < 0 )
      goto LABEL_15;
LABEL_8:
    if ( a2 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
      if ( v9 )
      {
        if ( (*(_DWORD *)(v9 + 268) & 0x20000) == 0 )
        {
          if ( PipIsProviderStarted(v9) )
            PipAttemptDependentsStart(v16);
        }
      }
    }
    PipAddtoRebuildPowerRelationsQueue(a2);
    v10 = PipAddDependentsToRebuildPowerRelationsQueue(a2);
    v11 = PnpReleaseDependencyRelationsLock(v10);
    PipProcessRebuildPowerRelationsQueue(v11);
    return v4;
  }
  if ( !*(_DWORD *)(v5 + 24) )
  {
    if ( a2 )
      v14 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 44);
    else
      v14 = 0;
    if ( v14 )
    {
      if ( a2 )
        v15 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 44);
      else
        v15 = 0;
      PipMergeDependencyNodes(v15, v5);
    }
    else
    {
      PipLinkDeviceObjectAndDependencyNode(a2, v5);
    }
    goto LABEL_8;
  }
  return sub_550AE4();
}
