// BiGetPartitionInformation 
 
int __fastcall BiGetPartitionInformation(int a1, int a2, int a3)
{
  int v4; // r4
  int v5; // r0
  char v7[208]; // [sp+40h] [bp-D0h] BYREF

  v4 = ZwCreateEvent();
  if ( v4 >= 0 )
  {
    v5 = ZwDeviceIoControlFile();
    v4 = v5;
    if ( v5 == 259 )
      return sub_8133A0();
    if ( v5 < 0 )
      JUMPOUT(0x8133B6);
    memmove(a3, (int)v7, 0x90u);
  }
  return v4;
}
