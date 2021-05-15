// MiPageInRange 
 
int __fastcall MiPageInRange(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r0
  int result; // r0

  v4 = 0;
  v5 = *(_DWORD *)(a1 + 4) | 0x80000000;
  if ( v5 >= 0xC0000000 )
  {
    while ( v5 <= 0xC03FFFFF && (a4 != 1 || ((v5 >> 10) & 0x3FFFFC) != 3148800) )
    {
      if ( v5 >= a2 && v5 <= a3 )
      {
        if ( v4 )
          result = 2;
        else
          result = 1;
        return result;
      }
      if ( v4 != 1 || a4 != 1 )
      {
        v5 <<= 10;
        ++v4;
        a2 &= 0xFFFFF000;
        if ( v5 >= 0xC0000000 )
          continue;
      }
      return 0;
    }
  }
  return 0;
}
