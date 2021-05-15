// RtlUlonglongByteSwap 
 
unsigned int __fastcall RtlUlonglongByteSwap(__int64 a1)
{
  return (HIDWORD(a1) << 24) | ((((WORD2(a1) & 0xFF00 | ((HIDWORD(a1) & 0xFF0000u | HIWORD(HIDWORD(a1))) >> 16)) << 16) | ((((HIDWORD(a1) & 0xFF0000 | HIWORD(HIDWORD(a1))) << 16) | ((unsigned int)(a1 >> 16) >> 16)) >> 16)) >> 8);
}
