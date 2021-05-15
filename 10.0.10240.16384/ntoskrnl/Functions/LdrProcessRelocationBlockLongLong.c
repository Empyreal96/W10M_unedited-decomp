// LdrProcessRelocationBlockLongLong 
 
int __fastcall LdrProcessRelocationBlockLongLong(int a1, int a2, int a3, unsigned __int16 *a4, int a5)
{
  unsigned __int16 *v5; // r4
  unsigned int v6; // r5
  int v9; // r0

  v5 = a4;
  v6 = (unsigned int)&a4[a3];
  if ( (unsigned int)a4 >= v6 )
    return (int)v5;
  while ( 1 )
  {
    if ( ((1 << (*v5 >> 12)) & 0x3A0) != 0 )
    {
      if ( a1 != 452 )
        return sub_80E97C();
      v9 = LdrpThumbProcessRelocation(v5, a2, a5);
    }
    else
    {
      v9 = LdrpGenericProcessRelocation(v5, a2, a5);
    }
    if ( !v9 )
      break;
    v5 += v9;
    if ( (unsigned int)v5 >= v6 )
      return (int)v5;
  }
  return 0;
}
