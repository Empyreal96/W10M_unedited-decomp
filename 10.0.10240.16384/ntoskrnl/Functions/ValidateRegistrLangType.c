// ValidateRegistrLangType 
 
int __fastcall ValidateRegistrLangType(int a1)
{
  int result; // r0
  int *v3; // r5
  int v4; // r4
  int v5; // t1

  result = 0;
  if ( (a1 & 0x18) != 0 && (a1 & 7) != 0 )
  {
    v3 = &ulInvalidTypes;
    v4 = 0;
    while ( 1 )
    {
      v5 = *v3++;
      if ( v5 == (v5 & a1) )
        break;
      if ( ++v4 >= 8 )
      {
        if ( (a1 & 1) == 0 )
          return sub_80C168(0);
        if ( (a1 & 0x10) != 0 )
          return result;
        return -1073741811;
      }
    }
  }
  return -1073741811;
}
