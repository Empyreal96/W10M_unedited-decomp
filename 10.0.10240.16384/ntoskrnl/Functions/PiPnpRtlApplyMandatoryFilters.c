// PiPnpRtlApplyMandatoryFilters 
 
int __fastcall PiPnpRtlApplyMandatoryFilters(int a1, int a2, int a3, int a4, int *a5, _BYTE *a6)
{
  int v8; // r0
  int result; // r0
  char v12; // [sp+8h] [bp-20h] BYREF
  char v13[3]; // [sp+9h] [bp-1Fh] BYREF
  char v14[28]; // [sp+Ch] [bp-1Ch] BYREF

  v8 = *a5;
  v12 = 0;
  if ( !v8 )
    v8 = a5[2];
  result = SeQuerySessionIdTokenEx(v8, v14, v13);
  if ( result >= 0 )
  {
    if ( !v13[0] )
      goto LABEL_9;
    result = PiAuIsLocalSystem(a5, &v12);
    if ( result < 0 )
      return result;
    if ( !v12 )
    {
LABEL_9:
      switch ( a3 )
      {
        case 1:
          return PiPnpRtlApplyMandatoryDeviceFilters(a1, a2, a4, (int)a5, a6);
        case 3:
          return PiPnpRtlApplyMandatoryDeviceInterfaceFilters(a1, a2, a4, a5, a6);
        case 5:
          return PiPnpRtlApplyMandatoryDeviceContainerFilters(a1, a2);
      }
    }
    *a6 = 1;
  }
  return result;
}
