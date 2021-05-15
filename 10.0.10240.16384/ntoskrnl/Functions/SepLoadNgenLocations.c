// SepLoadNgenLocations 
 
int SepLoadNgenLocations()
{
  int v0; // r0
  int v1; // r4

  v0 = ZwOpenKey();
  v1 = v0;
  if ( v0 >= 0 )
    return sub_96E194();
  if ( v0 == -1073741772 )
    v1 = 0;
  return v1;
}
