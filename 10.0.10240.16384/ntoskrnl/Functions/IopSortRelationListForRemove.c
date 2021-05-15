// IopSortRelationListForRemove 
 
int __fastcall IopSortRelationListForRemove(int a1, int a2)
{
  int v3; // r7
  unsigned int v4; // r10
  int v5; // r9
  int v6; // r4
  int v7; // r6
  int v8; // r3
  int v10; // r8
  _DWORD **v11; // r0
  int v12; // r2
  _DWORD *v13; // r6
  unsigned int v14; // r3
  int v15; // r4
  int v16; // [sp+0h] [bp-30h] BYREF
  _DWORD *v17; // [sp+4h] [bp-2Ch]
  int v18; // [sp+8h] [bp-28h]
  char v19[36]; // [sp+Ch] [bp-24h] BYREF

  if ( *(_BYTE *)(a1 + 4) )
    return 0;
  PnpAcquireDependencyRelationsLock(0, a2);
  v3 = 0;
  v4 = 0;
  if ( !**(_DWORD **)a1 )
    goto LABEL_26;
  v5 = 0;
  do
  {
    v6 = v5 + *(_DWORD *)a1;
    v7 = *(_DWORD *)(v6 + 16);
    if ( v7 )
      v8 = *(_DWORD *)(*(_DWORD *)(v7 + 176) + 20);
    else
      v8 = 0;
    if ( !*(_DWORD *)(v8 + 8) )
      return sub_7DF2C8();
    v10 = ((int (*)(void))PipIsDeviceInDeviceObjectList)();
    v18 = 0;
    v11 = (_DWORD **)PiGetProviderList(v7);
    v13 = *v11;
    v17 = v11;
    if ( v13 != v11 )
    {
      while ( 1 )
      {
        PiEnumerateProviderListEntry(v13, &v16, v19);
        if ( v16 )
        {
          if ( PipIsDeviceInDeviceObjectList(*(_DWORD *)a1, v16, 0) )
            break;
        }
        v13 = (_DWORD *)*v13;
        if ( v13 == v17 )
        {
          v12 = v18;
          goto LABEL_9;
        }
      }
      v12 = 1;
    }
LABEL_9:
    if ( v10 || v12 )
    {
      v14 = *(_DWORD *)(v6 + 28) & 0xFFFFFFFB;
    }
    else
    {
      ++v3;
      v14 = *(_DWORD *)(v6 + 28) | 4;
    }
    *(_DWORD *)(v6 + 28) = v14;
    ++v4;
    v5 += 16;
  }
  while ( v4 < **(_DWORD **)a1 );
  if ( v3 )
  {
    v15 = PipSortDeviceObjectList(a1, 1);
    if ( v15 >= 0 )
      *(_BYTE *)(a1 + 4) = 1;
  }
  else
  {
LABEL_26:
    v15 = -1073741823;
  }
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  return v15;
}
