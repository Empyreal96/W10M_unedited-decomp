// SepInitializeCodeIntegrity 
 
int SepInitializeCodeIntegrity()
{
  int v0; // r0

  memset(&SeCiCallbacks, 0, 76);
  SeCiCallbacks = 76;
  if ( KeLoaderBlock_0 )
  {
    v0 = *((_DWORD *)KeLoaderBlock_0 + 30);
    if ( v0 )
    {
      SepIsOptionPresent(v0, "DISABLE_INTEGRITY_CHECKS");
      SepIsOptionPresent(*((_DWORD *)KeLoaderBlock_0 + 30), "TESTSIGNING");
      if ( SepIsOptionPresent(*((_DWORD *)KeLoaderBlock_0 + 30), "MINTCBIGNOREKD") )
        return sub_811464();
      SepIsOptionPresent(*((_DWORD *)KeLoaderBlock_0 + 30), "FLIGHTSIGNING");
    }
  }
  return CiInitialize_0();
}
