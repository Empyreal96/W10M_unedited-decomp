// IopCheckIfMergeRequired 
 
int __fastcall IopCheckIfMergeRequired(int a1, _DWORD **a2)
{
  _DWORD *v4; // r4
  unsigned int v5; // r3
  _DWORD **v6; // r5
  _DWORD *v7; // r4
  int v9; // [sp+8h] [bp-28h] BYREF
  int v10; // [sp+Ch] [bp-24h] BYREF
  int v11[6]; // [sp+18h] [bp-18h] BYREF

  v11[0] = 0;
  v11[1] = 0;
  while ( IopEnumerateRelations(a1, v11, &v9, 0, 0) )
  {
    if ( v9 )
      v4 = *(_DWORD **)(*(_DWORD *)(v9 + 176) + 20);
    else
      v4 = 0;
    if ( PipIsDeviceInDeviceObjectList(*a2, v9, 0) )
      return 1;
    v5 = v4[2];
    if ( !v5 )
      v5 = v4[103] & 0xFFFFFFFE;
    if ( PipIsDeviceInDeviceObjectList(*a2, *(_DWORD *)(v5 + 16), 0) )
      return 1;
    v6 = (_DWORD **)PiGetProviderList(v4[4]);
    v7 = *v6;
    while ( v7 != v6 )
    {
      PiEnumerateProviderListEntry((int)v7, &v10);
      v7 = (_DWORD *)*v7;
      if ( v10 && PipIsDeviceInDeviceObjectList(*a2, v10, 0) )
        return 1;
    }
  }
  return 0;
}
