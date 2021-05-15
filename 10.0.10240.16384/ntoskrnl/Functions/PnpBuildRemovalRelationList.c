// PnpBuildRemovalRelationList 
 
int __fastcall PnpBuildRemovalRelationList(int a1, int a2, int a3, int a4, int *a5)
{
  int v5; // r9
  int v8; // r4
  int v9; // r5

  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  *a5 = 0;
  v8 = IopAllocateRelationList(a2);
  if ( !v8 )
    return -1073741670;
  v9 = PnpProcessRelation(v5, a2, 2, a3);
  if ( v9 < 0 )
  {
    IopFreeRelationList(v8);
  }
  else
  {
    *a5 = v8;
    IopSortRelationListForRemove(v8);
  }
  return v9;
}
