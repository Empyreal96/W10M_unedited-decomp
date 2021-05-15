// PiPnpRtlApplyMandatoryDeviceFilters 
 
int __fastcall PiPnpRtlApplyMandatoryDeviceFilters(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int result; // r0
  char v6; // [sp+20h] [bp-30h]

  *a5 = 0;
  result = SeQuerySessionIdTokenEx();
  if ( result < 0 )
    goto LABEL_7;
  if ( !v6 )
    return sub_7C741C();
  *a5 = 1;
  if ( *a5 )
    result = PiPnpRtlIsDeviceEnumerableForUser(result);
  if ( result < 0 )
LABEL_7:
    *a5 = 0;
  return result;
}
