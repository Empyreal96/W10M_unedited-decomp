// SiValidateSystemPartition 
 
int __fastcall SiValidateSystemPartition(int a1)
{
  int v1; // r4
  int v3[8]; // [sp+0h] [bp-98h] BYREF
  char v4[120]; // [sp+20h] [bp-78h] BYREF

  v1 = SiGetDiskPartitionInformation(a1, v3);
  if ( v1 >= 0 )
  {
    v1 = -1073741823;
    if ( v3[0] != 1 )
      return sub_5521EC();
    if ( !memcmp((unsigned int)v4, (unsigned int)PARTITION_SYSTEM_GUID, 16) )
      v1 = 0;
  }
  return v1;
}
