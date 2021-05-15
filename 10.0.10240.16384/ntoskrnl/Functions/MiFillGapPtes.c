// MiFillGapPtes 
 
unsigned int __fastcall MiFillGapPtes(unsigned int a1, unsigned int a2, int a3, int a4, int a5)
{
  unsigned int v6; // r5
  unsigned int *v7; // r0
  unsigned int result; // r0

  v6 = a2;
  v7 = (unsigned int *)(a3 + 8 * a5);
  if ( a1 < *v7 )
    a1 = *v7;
  result = v7[1];
  if ( a2 > result )
    v6 = result;
  if ( a1 <= v6 )
  {
    while ( (*(_DWORD *)a1 & 2) != 0 )
    {
      if ( a5 && (a5 != 1 || (*(_DWORD *)a1 & 0x400) == 0) )
      {
        MiFillGapPtes(a1 << 10);
        JUMPOUT(0x50B6E6);
      }
      a1 += 4;
      if ( a1 > v6 )
        return result;
    }
    result = sub_50B648();
  }
  return result;
}
