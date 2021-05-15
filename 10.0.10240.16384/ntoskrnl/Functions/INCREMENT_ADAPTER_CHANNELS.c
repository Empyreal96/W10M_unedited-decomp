// INCREMENT_ADAPTER_CHANNELS 
 
int __fastcall INCREMENT_ADAPTER_CHANNELS(int result)
{
  int v1; // r6
  unsigned int *v2; // r2
  unsigned int v3; // r5
  unsigned int v4; // r5
  int v5; // r2

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 108);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 + 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( *(_DWORD *)(result + 120) < 3u )
  {
    v5 = *(_DWORD *)(result + 112);
    if ( v4 != v5 + 1 )
    {
      ViHalPreprocessOptions(
        &dword_618744,
        "Driver has allocated too many simultaneous adapter channels.",
        11,
        v4 - v5,
        0,
        0);
      result = VfReportIssueWithOptions(230, 11, v4 - *(_DWORD *)(v1 + 112), 0, 0, &dword_618744);
    }
  }
  return result;
}
