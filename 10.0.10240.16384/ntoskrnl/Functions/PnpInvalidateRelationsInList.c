// PnpInvalidateRelationsInList 
 
int __fastcall PnpInvalidateRelationsInList(int a1, int a2, int a3)
{
  _DWORD *v5; // r6
  int v7; // [sp+8h] [bp-38h] BYREF
  int *v8; // [sp+Ch] [bp-34h] BYREF
  int v9; // [sp+10h] [bp-30h] BYREF
  int v10; // [sp+18h] [bp-28h] BYREF
  int v11; // [sp+1Ch] [bp-24h]

  v5 = (_DWORD *)IopAllocateRelationList(a2);
  if ( !v5 )
    return -1073741670;
  IopSetAllRelationsTags(a1);
  v10 = 0;
  v11 = 0;
  while ( IopEnumerateRelations(a1, &v10, &v8, &v9, &v7) )
  {
    if ( !a3 || !v9 )
      return sub_81AB98();
  }
  v10 = 0;
  v11 = 0;
  while ( IopEnumerateRelations((int)v5, &v10, &v8, 0, 0) )
    PnpRequestDeviceAction(v8, 9, 0, 0, 0, 0);
  IopFreeRelationList(v5);
  return 0;
}
