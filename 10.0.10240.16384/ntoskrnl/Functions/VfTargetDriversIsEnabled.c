// VfTargetDriversIsEnabled 
 
BOOL __fastcall VfTargetDriversIsEnabled(unsigned int a1, int a2)
{
  BOOL result; // r0
  int v4; // r3

  result = 0;
  if ( !VfSafeMode )
  {
    v4 = ViTargetInitialized;
    __dmb(0xBu);
    if ( v4 )
      result = VfTargetDriversGetVerifierData(a1, a2, a1) != 0;
  }
  return result;
}
