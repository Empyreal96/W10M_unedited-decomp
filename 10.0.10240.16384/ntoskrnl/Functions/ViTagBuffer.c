// ViTagBuffer 
 
int __fastcall ViTagBuffer(int result, int a2, char a3)
{
  int v5; // r4

  v5 = result;
  if ( (a3 & 1) != 0 )
    result = memcpy_strict_align(result - 8, (char *)ViDmaVerifierTag, 8u);
  if ( (a3 & 2) != 0 )
    result = memcpy_strict_align(v5 + a2, (char *)ViDmaVerifierTag, 8u);
  return result;
}
