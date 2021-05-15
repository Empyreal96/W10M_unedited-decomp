// VfWdSetCancelTimeout 
 
int __fastcall VfWdSetCancelTimeout(unsigned int a1)
{
  int v1; // r4
  unsigned int v2; // r2

  v1 = 0;
  if ( a1 )
  {
    if ( a1 > 0xEA60 )
      return -1073741811;
    v2 = (a1 + 999) / 0x3E8;
  }
  else
  {
    v2 = 0;
  }
  __dmb(0xBu);
  VfWdCancelTimeoutTicks = v2;
  if ( ViVerifierDriverAddedThunkListHead )
    VfWdCheckForSettingsChange(MmVerifierData);
  return v1;
}
