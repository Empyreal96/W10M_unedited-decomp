// ReadTimeStampCounter 
 
int ReadTimeStampCounter()
{
  unsigned __int64 *v0; // r2
  unsigned __int64 v1; // kr00_8
  unsigned __int64 v2; // r0

  v0 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3824);
  do
  {
    v1 = __ldrexd(v0);
    v2 = __PAIR64__(HIDWORD(v1), __mrc(15, 0, 9, 13, 0));
    if ( ((v1 ^ v2) & 0x80000000) != 0i64 )
      HIDWORD(v2) = HIDWORD(v1) + ((unsigned int)v1 >> 31);
  }
  while ( __strexd(v2, v0) );
  return v2;
}
