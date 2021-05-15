// BcpConvertBugDataToString 
 
int __fastcall BcpConvertBugDataToString(unsigned int a1, int a2)
{
  unsigned int v2; // r3
  _WORD *v3; // r4
  char v4; // r1
  unsigned int v5; // r5
  unsigned int i; // r2
  __int16 v7; // r3
  unsigned int v8; // r3

  v2 = *(unsigned __int16 *)(a2 + 2);
  v3 = *(_WORD **)(a2 + 4);
  v4 = 28;
  v5 = v2 >> 1;
  for ( i = 0; i < v5; ++i )
  {
    if ( i )
    {
      if ( i == 1 )
      {
        v3[1] = 120;
      }
      else
      {
        if ( i == v5 - 1 )
        {
          v7 = 0;
        }
        else
        {
          v8 = (a1 >> v4) & 0xF;
          if ( v8 >= 0xA )
            v7 = (unsigned __int8)(v8 - 10) + 65;
          else
            v7 = v8 + 48;
          v4 -= 4;
        }
        v3[i] = v7;
      }
    }
    else
    {
      *v3 = 48;
    }
  }
  return 0;
}
