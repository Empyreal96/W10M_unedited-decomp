// MiSanitizePfnProtection 
 
unsigned int __fastcall MiSanitizePfnProtection(int a1, int a2, int a3)
{
  int v4; // r3

  if ( a3 != 24 )
  {
    if ( a2 == 24 )
      return sub_5432CC();
    v4 = a2 & 0x18;
    if ( (a2 & 0x18) != 0 )
    {
      if ( v4 != 16 )
      {
        if ( v4 == 8 )
          return a3 & 0xFFFFFFE7 | 8;
        if ( v4 == 24 )
          a3 |= 0x18u;
        return a3;
      }
    }
    else
    {
      if ( (a3 & 0x18) == 24 )
        return a3 & 0xFFFFFFE7;
      if ( (a3 & 0x18) != 8 )
        return a3;
    }
    return a3 & 0xFFFFFFF7;
  }
  return 24;
}
