// MmReserveViewInSystemCache 
 
int MmReserveViewInSystemCache()
{
  int v0; // r0
  int result; // r0

  v0 = MiObtainSystemCacheView();
  if ( v0 )
    result = v0 << 10;
  else
    result = sub_819C38();
  return result;
}
