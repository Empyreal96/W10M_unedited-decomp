// sub_903A88 
 
void sub_903A88()
{
  unsigned int v0; // r1

  do
    v0 = __ldrex(KdPrintSkippedCount);
  while ( __strex(v0 + 1, KdPrintSkippedCount) );
  __dmb(0xBu);
  JUMPOUT(0x9025A4);
}
