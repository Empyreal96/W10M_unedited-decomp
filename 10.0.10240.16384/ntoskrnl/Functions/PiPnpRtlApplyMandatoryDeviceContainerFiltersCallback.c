// PiPnpRtlApplyMandatoryDeviceContainerFiltersCallback 
 
int __fastcall PiPnpRtlApplyMandatoryDeviceContainerFiltersCallback(int a1, int a2, _BYTE *a3)
{
  int result; // r0

  result = PiPnpRtlApplyMandatoryDeviceFilters(
             *(_DWORD *)a2,
             *(_DWORD *)(a1 + 12),
             0,
             *(_DWORD *)(a2 + 4),
             (_BYTE *)(a2 + 8));
  if ( result >= 0 )
    *a3 = *(_BYTE *)(a2 + 8);
  return result;
}
