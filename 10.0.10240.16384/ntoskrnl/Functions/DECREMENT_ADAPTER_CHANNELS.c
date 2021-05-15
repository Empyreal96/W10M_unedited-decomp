// DECREMENT_ADAPTER_CHANNELS 
 
int __fastcall DECREMENT_ADAPTER_CHANNELS(int result)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r5
  unsigned int v4; // r5

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 112);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 + 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( *(_DWORD *)(result + 120) < 3u && v4 != *(_DWORD *)(result + 108) )
  {
    ViHalPreprocessOptions(&dword_61873C, "Driver has freed too many simultaneous adapter channels.", 4, 1, 0, 0);
    result = VfReportIssueWithOptions(230, 4, v4 != *(_DWORD *)(v1 + 108), 0, 0, &dword_61873C);
  }
  return result;
}
