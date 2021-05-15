// BvgaReleaseResources 
 
int BvgaReleaseResources()
{
  int v0; // r4
  int i; // r5
  int result; // r0

  v0 = 1;
  for ( i = 0; !*(_DWORD *)((char *)&unk_631BC4 + i - 4); i += 4 )
  {
    if ( (unsigned int)++v0 >= 7 )
      return result;
  }
  return sub_5508D0();
}
