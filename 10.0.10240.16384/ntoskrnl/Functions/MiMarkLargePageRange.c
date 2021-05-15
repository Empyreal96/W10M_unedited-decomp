// MiMarkLargePageRange 
 
unsigned int __fastcall MiMarkLargePageRange(unsigned int result, unsigned int a2)
{
  unsigned int *v2; // r6
  unsigned int v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // r4
  unsigned int v6; // r3
  unsigned int v7; // t1

  v2 = (unsigned int *)(((result >> 20) & 0xFFC) - 1070596096);
  v3 = ((a2 >> 20) & 0xFFC) - 1070596096;
  v4 = 0;
  if ( (unsigned int)v2 > v3 )
    v5 = 0;
  else
    v5 = (v3 - (unsigned int)v2 + 3) >> 2;
  if ( v5 )
  {
    do
    {
      v7 = *v2++;
      v6 = v7;
      if ( (v7 & 2) != 0 && (v6 & 0x400) != 0 )
        result = (unsigned int)RtlSetBits(&dword_634C90, v6 >> 22, 1u);
      ++v4;
    }
    while ( v4 < v5 );
  }
  return result;
}
