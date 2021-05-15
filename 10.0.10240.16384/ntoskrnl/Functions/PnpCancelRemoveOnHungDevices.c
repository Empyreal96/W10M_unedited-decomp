// PnpCancelRemoveOnHungDevices 
 
int __fastcall PnpCancelRemoveOnHungDevices(_DWORD *a1, int a2, int a3, int a4)
{
  int v7; // r4
  int v8; // r5
  int v9; // r3
  _DWORD *v10; // r0
  int v11; // r3
  int v12; // r2
  unsigned __int16 *v13; // r5
  int v15; // [sp+8h] [bp-30h] BYREF
  unsigned __int16 *v16; // [sp+Ch] [bp-2Ch]
  int v17; // [sp+10h] [bp-28h] BYREF
  int v18; // [sp+18h] [bp-20h] BYREF
  int v19; // [sp+1Ch] [bp-1Ch]

  v16 = 0;
  if ( a2 != 4 && a2 )
    __fastfail(5u);
  v7 = PnpCompileDeviceInstancePaths(a2, a4);
  if ( v7 >= 0 )
  {
    v8 = IopAllocateRelationList(a2);
    if ( v8 )
    {
      v18 = 2;
      v19 = 0;
      while ( IopEnumerateRelations(a4, &v18, &v15, &v17, 0) )
      {
        if ( v15 )
          v9 = *(_DWORD *)(*(_DWORD *)(v15 + 176) + 20);
        else
          v9 = 0;
        if ( v9 )
        {
          if ( (*(_DWORD *)(v9 + 456) & 2) != 0 )
          {
            v7 = IopAddRelationToList(v8, v15, v17, 0);
            if ( v7 < 0 )
              return v7;
          }
        }
      }
      *(_BYTE *)(v8 + 4) = 1;
      v18 = 1;
      v19 = 0;
      while ( IopEnumerateRelations(v8, &v18, &v15, 0, 0) )
      {
        if ( v15 )
          v10 = *(_DWORD **)(*(_DWORD *)(v15 + 176) + 20);
        else
          v10 = 0;
        if ( v10[43] == 784 )
          PnpDeleteLockedDeviceNode(v10, 1, 0, 0, 0);
      }
      v18 = 1;
      v19 = 0;
      while ( IopEnumerateRelations(v8, &v18, &v15, 0, 0) )
      {
        if ( v15 )
          v11 = *(_DWORD *)(*(_DWORD *)(v15 + 176) + 20);
        else
          v11 = 0;
        v12 = *(_DWORD *)(v11 + 172);
        if ( v12 != 786 && v12 != 770 && v12 != 769 )
          PnpNotifyTargetDeviceChange(&GUID_TARGET_DEVICE_REMOVE_CANCELLED, v15, 0);
      }
      v7 = PnpCompileDeviceInstancePaths(a2, v8);
      v13 = v16;
      if ( v7 >= 0 )
        v7 = PnpNotifyUserModeDeviceRemoval(a1, v16, &GUID_TARGET_DEVICE_REMOVE_CANCELLED, 0, 0);
      if ( v13 )
        ExFreePoolWithTag((unsigned int)v13);
    }
    else
    {
      v7 = -1073741801;
    }
  }
  return v7;
}
