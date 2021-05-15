// BgpFoDetermineFontInformation 
 
int __fastcall BgpFoDetermineFontInformation(unsigned int a1, int a2, int a3, _DWORD *a4, unsigned int *a5, void ***a6)
{
  int result; // r0
  void **v9; // r6
  unsigned int v10; // r4
  unsigned int v11; // r2
  void **v12; // [sp+0h] [bp-30h] BYREF
  unsigned int v13; // [sp+4h] [bp-2Ch]
  int v14[3]; // [sp+8h] [bp-28h] BYREF
  unsigned int v15; // [sp+14h] [bp-1Ch]
  int v16; // [sp+18h] [bp-18h]

  result = BgpFoGetFontHandle(0, &v12);
  if ( result >= 0 )
  {
    v14[0] = 0;
    v9 = v12;
    v14[1] = -1;
    v14[2] = (int)v12;
    v10 = 4;
    v16 = 0;
    do
    {
      v15 = ++v10;
      result = BgpFoGetTextMetrics((int)v14, (int)&v12);
      if ( result < 0 )
        return result;
      v11 = v13;
    }
    while ( v13 < a1 );
    if ( v13 <= a1 )
    {
LABEL_6:
      *a4 = v12;
      a4[1] = v11;
      result = 0;
      *a5 = v10;
      *a6 = v9;
      return result;
    }
    if ( v10 <= 5 )
    {
      result = -1073741823;
    }
    else
    {
      v15 = --v10;
      result = BgpFoGetTextMetrics((int)v14, (int)&v12);
      if ( result >= 0 )
      {
        v11 = v13;
        goto LABEL_6;
      }
    }
  }
  return result;
}
