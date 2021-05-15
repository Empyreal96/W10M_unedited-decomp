// PiDrvDbUnloadHive 
 
int __fastcall PiDrvDbUnloadHive(int a1, int a2)
{
  int result; // r0

  if ( a2 )
    result = ZwUnloadKeyEx();
  else
    result = sub_7F0FF0();
  return result;
}
