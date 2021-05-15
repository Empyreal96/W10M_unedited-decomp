// MiIsVadEligibleForCommitRelease 
 
BOOL __fastcall MiIsVadEligibleForCommitRelease(int a1)
{
  __int16 v1; // r1
  int v2; // r2
  unsigned int v3; // r2
  BOOL result; // r0

  result = 0;
  if ( ((1 << (*(_DWORD *)(a1 + 28) & 7)) & 0x55) != 0 && !MiVadMapsLargeImage(a1) )
  {
    v3 = *(_DWORD *)(v2 + 32) & 0x7FFFFFFF;
    if ( v3 )
    {
      if ( v3 < 0x7FFFE && (v1 & 0x4000) == 0 )
        result = 1;
    }
  }
  return result;
}
