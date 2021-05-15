// SepIsUmciDisabled 
 
int SepIsUmciDisabled()
{
  int v0; // r4
  int v2; // [sp+34h] [bp-1Ch]
  int v3; // [sp+38h] [bp-18h]
  int v4; // [sp+3Ch] [bp-14h]

  v0 = 0;
  if ( ZwOpenKey() >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v2 == 4 && v3 == 4 && v4 == 1 )
      v0 = 1;
    ZwClose();
  }
  return v0;
}
