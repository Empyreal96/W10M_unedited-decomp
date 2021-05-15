// KitpReadUlongFromKey 
 
int __fastcall KitpReadUlongFromKey(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  *a3 = 0;
  result = ZwQueryValueKey();
  if ( result >= 0 )
    result = sub_81B83C();
  return result;
}
