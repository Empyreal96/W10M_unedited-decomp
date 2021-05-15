// ExpTranslateHexStringToULONGLONG 
 
int __fastcall ExpTranslateHexStringToULONGLONG(unsigned __int16 *a1, unsigned int *a2)
{
  unsigned __int16 *v3; // r9
  unsigned int v4; // r0
  unsigned int v5; // r5
  unsigned int v7; // r6
  unsigned int v8; // r4
  unsigned int v9; // r8
  int v10; // t1
  unsigned int v11; // r0
  __int64 v12; // r2

  v3 = a1;
  v4 = wcslen(a1);
  v5 = v4;
  if ( v4 > 0x10 )
    return -1073741811;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  if ( v4 )
  {
    do
    {
      v10 = *v3++;
      v11 = towlower(v10);
      if ( v11 < 0x30 || v11 > 0x39 )
      {
        if ( v11 < 0x61 || v11 > 0x66 )
          return -1073741811;
        LODWORD(v12) = v11 - 87;
      }
      else
      {
        LODWORD(v12) = v11 - 48;
      }
      HIDWORD(v12) = (v7 >> 28) | (16 * v9);
      v9 = (v12 + __PAIR64__((int)v12 >> 31, 16 * v7)) >> 32;
      v7 = v12 + 16 * v7;
      ++v8;
    }
    while ( v8 < v5 );
  }
  *a2 = v7;
  a2[1] = v9;
  return 0;
}
