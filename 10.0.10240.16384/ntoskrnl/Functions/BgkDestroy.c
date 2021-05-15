// BgkDestroy 
 
int __fastcall BgkDestroy(int a1)
{
  int result; // r0

  if ( !byte_637609 )
    return 0;
  BgkpDisableConsole(a1);
  byte_63761D = 0;
  byte_637609 = 0;
  BgDisplayProgressIndicator(0);
  byte_63760A = 0;
  BgDisplayBackgroundUpdate(0);
  byte_63761C = 0;
  if ( dword_637614 )
    result = sub_8DEDE0();
  else
    result = BgLibraryDestroy();
  return result;
}
