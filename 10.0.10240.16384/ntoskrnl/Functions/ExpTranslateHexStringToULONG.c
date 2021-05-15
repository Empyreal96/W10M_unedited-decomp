// ExpTranslateHexStringToULONG 
 
int __fastcall ExpTranslateHexStringToULONG(unsigned __int16 *a1, int *a2)
{
  unsigned __int16 *v3; // r8
  unsigned int v4; // r0
  unsigned int v5; // r6
  int v7; // r4
  unsigned int v8; // r5
  int v9; // t1
  unsigned int v10; // r0

  v3 = a1;
  v4 = wcslen(a1);
  v5 = v4;
  if ( v4 > 8 )
    return -1073741811;
  v7 = 0;
  v8 = 0;
  if ( v4 )
  {
    do
    {
      v9 = *v3++;
      v10 = towlower(v9);
      if ( v10 < 0x30 || v10 > 0x39 )
      {
        if ( v10 < 0x61 || v10 > 0x66 )
          return -1073741811;
        v7 = v10 + 16 * v7 - 87;
      }
      else
      {
        v7 = v10 + 16 * v7 - 48;
      }
      ++v8;
    }
    while ( v8 < v5 );
  }
  *a2 = v7;
  return 0;
}
