// DECREMENT_SCATTER_GATHER_LISTS 
 
int __fastcall DECREMENT_SCATTER_GATHER_LISTS(int result)
{
  int v1; // r6
  unsigned int *v2; // r2
  unsigned int v3; // r5
  signed int v4; // r5

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 96);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( v4 < 0 )
  {
    ViHalPreprocessOptions(
      &dword_618738,
      "Driver has freed too many scatter gather lists %x allocated, %x freed.",
      6,
      *(_DWORD *)(result + 92));
    result = VfReportIssueWithOptions(230, 6, *(_DWORD *)(v1 + 92), *(_DWORD *)(v1 + 92) - v4, 0, &dword_618738);
  }
  return result;
}
