// BiGetSystemPartition 
 
int __fastcall BiGetSystemPartition(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r4
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a4;
  v4 = SyspartGetSystemPartition(0, 0, v7);
  v5 = v4;
  if ( v4 == -1073741789 )
    return sub_812DCC();
  if ( v4 >= 0 )
    v5 = -1073741823;
  return v5;
}
