// PiDrvDbLoadHive 
 
int __fastcall PiDrvDbLoadHive(int a1, int a2, _DWORD *a3)
{
  int v3; // r4
  int result; // r0

  *a3 = 0;
  v3 = ZwLoadKeyEx();
  if ( v3 < 0 || (v3 = ZwOpenKey(), v3 >= 0) )
    result = v3;
  else
    result = sub_7F0FFC();
  return result;
}
