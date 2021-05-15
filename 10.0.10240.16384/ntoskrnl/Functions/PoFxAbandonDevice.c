// PoFxAbandonDevice 
 
int __fastcall PoFxAbandonDevice(int result)
{
  int v1; // r5
  int v2; // r4

  v1 = 0;
  v2 = result;
  if ( (*(_DWORD *)(result + 168) & 1) != 0 )
  {
    v1 = *(_DWORD *)(result + 40);
    PopFxUnregisterDeviceOrWait();
    if ( *(_DWORD *)(v2 + 72) )
      return sub_7E0618();
    result = PopDiagTraceFxDevicePreparation(v2, *(_DWORD *)(v2 + 72), v2 + 160, 0);
    *(_DWORD *)(v2 + 72) = 0;
    *(_DWORD *)(v2 + 168) &= 0xFFFFFFFE;
  }
  if ( (*(_DWORD *)(v2 + 168) & 2) != 0 )
  {
    result = PopFxFreeUniqueId(v2);
    *(_DWORD *)(v2 + 168) &= 0xFFFFFFFD;
  }
  if ( (*(_DWORD *)(v2 + 168) & 0x4000) != 0 )
  {
    result = PopFxReleaseAcpiRefDevice(v1);
    *(_DWORD *)(v2 + 168) &= 0xFFFFBFFF;
  }
  return result;
}
