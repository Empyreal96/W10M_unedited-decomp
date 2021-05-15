// MiInitializePartitions 
 
int __fastcall MiInitializePartitions(int a1)
{
  int v2; // r0
  int v3; // r1
  int v4[22]; // [sp+8h] [bp-60h] BYREF

  if ( !a1 )
    return sub_96B8E0();
  memset(v4, 0, sizeof(v4));
  LOWORD(v4[0]) = 88;
  BYTE2(v4[0]) |= 8u;
  v4[9] = 512;
  v4[2] = 0;
  v4[3] = 131073;
  v4[4] = 131074;
  v4[5] = 1179649;
  v4[6] = 2031619;
  v4[11] = 4;
  v4[7] = 2031619;
  v4[15] = (int)MmPartitionObjectDelete;
  BYTE2(v4[0]) |= 4u;
  v2 = ObCreateObjectType();
  return v2 >= 0 && MiSystemPartitionObjectCreate(v2, v3) >= 0;
}
