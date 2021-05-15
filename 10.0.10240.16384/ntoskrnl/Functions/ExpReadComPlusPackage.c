// ExpReadComPlusPackage 
 
int ExpReadComPlusPackage()
{
  int v0; // r4
  int v2; // [sp+14h] [bp-1Ch]
  int v3; // [sp+18h] [bp-18h]
  int v4; // [sp+1Ch] [bp-14h]

  v0 = ZwOpenKey();
  if ( v0 >= 0 )
  {
    v0 = ZwQueryValueKey();
    if ( v0 >= 0 && v2 == 4 && v3 == 4 )
      MEMORY[0xFFFF92E0] = v4;
    ZwClose();
    if ( v0 >= 0 )
      return 0;
  }
  if ( v0 == -1073741772 )
    return 0;
  return v0;
}
