// PipRemoveDevicesInRelationList 
 
int __fastcall PipRemoveDevicesInRelationList(int *a1, int a2)
{
  int v3; // r3
  int v4; // r5
  int v6; // r7

  v3 = a1[7];
  if ( v3 )
    v4 = *(_DWORD *)(*(_DWORD *)(v3 + 176) + 20);
  else
    v4 = 0;
  if ( v4 )
  {
    if ( (*(_DWORD *)(v4 + 268) & 0x10) == 0 )
      return sub_819874();
    v6 = IopSortRelationListForRemove(a1[8], a2);
    PnpDeleteLockedDeviceNodes(a1[7], a1[8], 2, 0, a1[11], 0, 0);
  }
  else
  {
    v6 = -1073741823;
  }
  IopFreeRelationList((_DWORD *)a1[8]);
  ExFreePoolWithTag((unsigned int)a1);
  return v6;
}
