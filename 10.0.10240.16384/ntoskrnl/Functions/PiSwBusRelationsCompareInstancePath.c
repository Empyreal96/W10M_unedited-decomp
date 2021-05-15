// PiSwBusRelationsCompareInstancePath 
 
int __fastcall PiSwBusRelationsCompareInstancePath(int a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  signed int v3; // r0

  v3 = RtlCompareUnicodeString(a2, a3, 1);
  if ( v3 < 0 )
    return 0;
  if ( v3 <= 0 )
    return 2;
  return 1;
}
