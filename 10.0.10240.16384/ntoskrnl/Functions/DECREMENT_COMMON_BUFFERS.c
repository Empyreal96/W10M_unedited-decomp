// DECREMENT_COMMON_BUFFERS 
 
int __fastcall DECREMENT_COMMON_BUFFERS(int result)
{
  int v1; // r6
  unsigned int *v2; // r2
  unsigned int v3; // r5
  unsigned int v4; // r5
  unsigned int v5; // r3

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 104);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 + 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  v5 = *(_DWORD *)(result + 100);
  if ( v4 > v5 )
  {
    ViHalPreprocessOptions(&dword_618748, "Freed too many common buffers.", 3, v4 - v5, 0, 0);
    result = VfReportIssueWithOptions(230, 3, v4 - *(_DWORD *)(v1 + 100), 0, 0, &dword_618748);
  }
  return result;
}
