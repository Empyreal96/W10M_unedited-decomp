// CmpConvertLangId 
 
int __fastcall CmpConvertLangId(int a1, unsigned int a2)
{
  int result; // r0
  unsigned int v4; // r4
  unsigned int v5; // r2

  result = 0;
  v4 = 0;
  if ( a2 >> 1 )
  {
    while ( 1 )
    {
      v5 = *(unsigned __int16 *)(a1 + 2 * v4);
      if ( v5 < 0x30 || v5 > 0x39 )
        break;
      if ( (unsigned __int16)(v5 - 48) < 0x10u )
      {
        result = (unsigned __int16)((v5 - 48) | (16 * result));
        v4 = (unsigned __int16)(v4 + 1);
        if ( v4 < a2 >> 1 )
          continue;
      }
      return result;
    }
    if ( v5 >= 0x41 )
      result = sub_96848C();
  }
  return result;
}
