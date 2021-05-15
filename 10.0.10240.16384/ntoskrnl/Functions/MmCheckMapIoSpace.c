// MmCheckMapIoSpace 
 
int __fastcall MmCheckMapIoSpace(__int64 a1, int a2, int a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r6
  int v5; // r7
  int v6; // r5
  int result; // r0

  v3 = a1 >> 12;
  v4 = ((unsigned int)(a1 & 0xFFF) + a2 + 4095) >> 12;
  v5 = a1;
  v6 = MmPfnDatabase + 24 * v3;
  do
  {
    result = MI_IS_PFN(v3);
    if ( result == 1 && !*(_WORD *)(v6 + 16) )
    {
      result = VerifierBugCheckIfAppropriate(196, 131, v5);
      v5 = a1;
    }
    v6 += 24;
    ++v3;
    --v4;
  }
  while ( v4 );
  return result;
}
