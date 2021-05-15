// BiAddBootEntry 
 
int __fastcall BiAddBootEntry(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r1
  int v6; // r2
  int v7; // r3
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  v4 = BiAcquirePrivilege(22, (int)v9, a3, a4);
  if ( v4 >= 0 )
  {
    v4 = ZwAddBootEntry();
    BiReleasePrivilege((int)v9, v5, v6, v7);
  }
  return v4;
}
