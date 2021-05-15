// BiGetSystemStorePath 
 
int __fastcall BiGetSystemStorePath(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r0
  int v5; // r5
  unsigned int v7[8]; // [sp+0h] [bp-20h] BYREF

  v7[1] = a4;
  v7[0] = 0;
  v4 = BiGetFirmwareType();
  if ( v4 != 1 && (unsigned int)(v4 - 2) > 1 )
    return -1073741637;
  v5 = BiGetSystemPartition(v7);
  if ( v5 >= 0 )
    return sub_812D5C();
  if ( v7[0] )
    ExFreePoolWithTag(v7[0]);
  return v5;
}
