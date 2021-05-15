// PiCMMandatoryFilterCallback 
 
int __fastcall PiCMMandatoryFilterCallback(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  int *v6; // [sp+8h] [bp-8h] BYREF

  v6 = a4;
  result = 0;
  LOBYTE(v6) = 0;
  if ( a4 && a3 == 1 )
  {
    if ( PiPnpRtlApplyMandatoryFilters(a1, a2, 1, 0, a4, &v6) < 0 )
      result = 0;
    else
      result = (unsigned __int8)v6;
  }
  return result;
}
