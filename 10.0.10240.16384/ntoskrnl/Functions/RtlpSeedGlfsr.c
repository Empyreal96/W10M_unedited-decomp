// RtlpSeedGlfsr 
 
// local variable allocation has failed, the output may be wrong!
int RtlpSeedGlfsr()
{
  int v0; // r5 OVERLAPPED
  int v1; // r6 OVERLAPPED
  int v2; // r0
  unsigned int i; // r1
  unsigned int v4; // r2
  int v5; // r3
  unsigned int v6; // r2

  *(_QWORD *)&v0 = *(_QWORD *)((char *)RtlpSeedGlfsr + 1);
  v2 = ReadTimeStampCounter();
  for ( i = 0; i < 0x20; ++i )
  {
    v4 = (1 << i) & v2;
    v5 = (v4 << (i - 32)) | (v4 >> (32 - i));
    v6 = v4 << i;
    v1 ^= v5;
    v0 ^= v6;
  }
  return v0;
}
