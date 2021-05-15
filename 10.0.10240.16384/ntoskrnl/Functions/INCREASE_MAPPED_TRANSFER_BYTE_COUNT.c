// INCREASE_MAPPED_TRANSFER_BYTE_COUNT 
 
int __fastcall INCREASE_MAPPED_TRANSFER_BYTE_COUNT(int a1, int a2, int a3)
{
  unsigned int v3; // r7
  unsigned int *v4; // r4
  unsigned int v5; // r6
  int result; // r0
  unsigned int v7; // r5

  v3 = *(_DWORD *)(a1 + 88) << 12;
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 116);
  do
  {
    v5 = __ldrex(v4);
    result = __strex(v5 + a2, v4);
  }
  while ( result );
  __dmb(0xBu);
  v7 = v5 + a2;
  if ( !a3 && v7 > v3 )
  {
    ViHalPreprocessOptions(&dword_618740, "Driver did not flush adapter buffers -- bytes mapped: %x (%x max).", 13, v7);
    result = VfReportIssueWithOptions(230, 13, v7, v3, 0, &dword_618740);
  }
  return result;
}
