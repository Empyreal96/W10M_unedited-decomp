// _wchartodigit 
 
int __fastcall wchartodigit(unsigned int a1)
{
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r3

  if ( a1 >= 0x30 )
  {
    if ( a1 < 0x3A )
      return a1 - 48;
    v2 = 65296;
    if ( a1 >= 0xFF10 )
    {
      v4 = 65306;
    }
    else
    {
      if ( a1 < 0x660 )
        return -1;
      if ( a1 < 0x66A )
        return a1 - 1632;
      if ( a1 < 0x6F0 )
        return -1;
      if ( a1 < 0x6FA )
        return a1 - 1776;
      v3 = 2406;
      if ( a1 < 0x966 )
        return -1;
      if ( a1 < 0x970 )
        return a1 - v3;
      v3 = 2534;
      if ( a1 < 0x9E6 )
        return -1;
      if ( a1 < 0x9F0 )
        return a1 - v3;
      v3 = 2662;
      if ( a1 < 0xA66 )
        return -1;
      if ( a1 < 0xA70 )
        return a1 - v3;
      v3 = 2790;
      if ( a1 < 0xAE6 )
        return -1;
      if ( a1 < 0xAF0 )
        return a1 - v3;
      v3 = 2918;
      if ( a1 < 0xB66 )
        return -1;
      if ( a1 < 0xB70 )
        return a1 - v3;
      v3 = 3174;
      if ( a1 < 0xC66 )
        return -1;
      if ( a1 < 0xC70 )
        return a1 - v3;
      v3 = 3302;
      if ( a1 < 0xCE6 )
        return -1;
      if ( a1 < 0xCF0 )
        return a1 - v3;
      v3 = 3430;
      if ( a1 < 0xD66 )
        return -1;
      if ( a1 < 0xD70 )
        return a1 - v3;
      if ( a1 < 0xE50 )
        return -1;
      if ( a1 < 0xE5A )
        return a1 - 3664;
      if ( a1 < 0xED0 )
        return -1;
      if ( a1 < 0xEDA )
        return a1 - 3792;
      if ( a1 < 0xF20 )
        return -1;
      if ( a1 < 0xF2A )
        return a1 - 3872;
      if ( a1 < 0x1040 )
        return -1;
      if ( a1 < 0x104A )
        return a1 - 4160;
      if ( a1 < 0x17E0 )
        return -1;
      if ( a1 < 0x17EA )
        return a1 - 6112;
      v2 = 6160;
      if ( a1 < 0x1810 )
        return -1;
      v4 = 6170;
    }
    if ( a1 < v4 )
      return a1 - v2;
  }
  return -1;
}
