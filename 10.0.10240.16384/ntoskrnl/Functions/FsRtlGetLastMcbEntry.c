// FsRtlGetLastMcbEntry 
 
unsigned int __fastcall FsRtlGetLastMcbEntry(__int64 a1, int a2)
{
  unsigned int result; // r0

  if ( a2 >= 32 && (a2 -= 32, a1 = SHIDWORD(a1), a2 >= 32) )
    result = HIDWORD(a1);
  else
    result = ((unsigned int)a1 >> a2) | (HIDWORD(a1) << (32 - a2));
  return result;
}
