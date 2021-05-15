// AslpDetermineDosPathNameType 
 
int __fastcall AslpDetermineDosPathNameType(unsigned __int16 *a1)
{
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3

  if ( wcslen(a1) <= 4 )
    return 0;
  v3 = *a1;
  if ( v3 == 92 || v3 == 47 )
  {
    v5 = a1[1];
    if ( v5 != 92 && v5 != 47 )
      return 4;
    v6 = a1[2];
    if ( v6 == 46 || v6 == 63 )
    {
      v7 = a1[3];
      if ( v7 == 92 || v7 == 47 )
        return 6;
      if ( !a1[3] )
        return 7;
    }
    return 1;
  }
  if ( !*a1 || a1[1] != 58 )
    return 5;
  v4 = a1[2];
  if ( v4 == 92 || v4 == 47 )
    result = 2;
  else
    result = 3;
  return result;
}
