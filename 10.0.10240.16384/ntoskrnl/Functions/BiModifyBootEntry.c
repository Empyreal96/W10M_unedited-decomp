// BiModifyBootEntry 
 
int __fastcall BiModifyBootEntry(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r1
  int v6; // r2
  int v7; // r3
  _DWORD v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = BiAcquirePrivilege(22, (int)v9, a3, a4);
  if ( v4 >= 0 )
  {
    v4 = ZwModifyBootEntry();
    BiReleasePrivilege((int)v9, v5, v6, v7);
  }
  return v4;
}
