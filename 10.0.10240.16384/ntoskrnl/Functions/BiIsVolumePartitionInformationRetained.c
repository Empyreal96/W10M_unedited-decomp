// BiIsVolumePartitionInformationRetained 
 
int __fastcall BiIsVolumePartitionInformationRetained(unsigned __int16 *a1)
{
  int v1; // r0
  char v4[344]; // [sp+60h] [bp-158h] BYREF

  RtlInitUnicodeString((unsigned int)v4, a1);
  if ( ZwOpenFile() < 0 || ZwCreateEvent() < 0 )
    return 0;
  v1 = ZwDeviceIoControlFile();
  if ( v1 == 259 )
    return sub_814710();
  if ( v1 < 0 )
    JUMPOUT(0x814724);
  return 1;
}
