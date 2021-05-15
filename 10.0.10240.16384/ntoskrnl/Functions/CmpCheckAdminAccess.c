// CmpCheckAdminAccess 
 
int __fastcall CmpCheckAdminAccess(int a1, int a2, char *a3)
{
  char v6; // r4
  int v7; // r5
  unsigned int v9; // [sp+18h] [bp-28h] BYREF
  unsigned int v10; // [sp+1Ch] [bp-24h] BYREF
  char v11[4]; // [sp+20h] [bp-20h] BYREF
  char v12[28]; // [sp+24h] [bp-1Ch] BYREF

  v9 = 0;
  v6 = 0;
  v7 = CmpBuildAdminInformation((int)&v10);
  if ( v7 >= 0 )
  {
    if ( SeAccessCheckFromState(a2, v10, 0, a1, 0, (int)&v9, (int)CmKeyObjectType + 52, 1, (int)v12, (int)v11) )
      v6 = 1;
    if ( v9 )
      ExFreePoolWithTag(v9);
    ExFreePoolWithTag(v10);
    *a3 = v6;
  }
  return v7;
}
