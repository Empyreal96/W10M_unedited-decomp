// sub_7DEC74 
 
void __fastcall sub_7DEC74(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, char a20, int a21, int a22, int a23, int a24)
{
  int v24; // r4

  v24 = a24;
  if ( a24 != 14 )
  {
    if ( (a24 != 3 || memcmp((unsigned int)&a20, (unsigned int)DEVPKEY_Device_FriendlyNameAttributes, 16))
      && (v24 != 4 || memcmp((unsigned int)&a20, (unsigned int)DEVPKEY_DriverPackage_SourceMediaPath, 16))
      && (v24 != 2 || memcmp((unsigned int)&a20, (unsigned int)DEVPKEY_WIA_DeviceType, 16)) )
    {
      JUMPOUT(0x774F4C);
    }
    JUMPOUT(0x774F4A);
  }
  JUMPOUT(0x774F3A);
}
