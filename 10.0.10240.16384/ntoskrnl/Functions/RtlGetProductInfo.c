// RtlGetProductInfo 
 
int __fastcall RtlGetProductInfo(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r6

  if ( !a5 )
    return 0;
  *a5 = 0;
  if ( sub_463C28(a1, a2, a3, a4, 6, 0, 0, 0) < 0 )
    return 0;
  ZwQueryLicenseValue();
  v6 = 1;
  *a5 = -1412584499;
  return v6;
}
