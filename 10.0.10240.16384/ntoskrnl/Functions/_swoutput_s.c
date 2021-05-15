// _swoutput_s 
 
int __fastcall swoutput_s(_WORD *a1, unsigned int a2, int a3, int a4)
{
  int v7; // r4
  int v8; // r3
  int v9; // r7
  _BYTE *v10; // r2
  _BYTE *v12; // [sp+8h] [bp-38h] BYREF
  int v13; // [sp+Ch] [bp-34h]
  _WORD *v14; // [sp+10h] [bp-30h]
  int v15; // [sp+14h] [bp-2Ch]

  if ( a2 )
  {
    v7 = -1;
    if ( a2 == -1 )
    {
      v8 = 0x7FFFFFFF;
    }
    else
    {
      if ( a2 > 0x3FFFFFFF )
      {
        PopPoCoalescinCallback();
        return v7;
      }
      v8 = 2 * a2;
    }
    v13 = v8;
    v14 = a1;
    v15 = 66;
    v12 = a1;
    v9 = woutput_s(&v12, a3, a4);
    a1[a2 - 1] = 0;
    if ( v9 < 0 )
    {
      if ( v13 >= 0 )
      {
        if ( a1 && a2 )
          *a1 = 0;
        return v9;
      }
      return -2;
    }
    if ( --v13 < 0 )
    {
      if ( flsbuf(0, (int)&v12) == -1 )
        return -2;
      v10 = v12;
    }
    else
    {
      *v12 = 0;
      v10 = ++v12;
    }
    if ( --v13 < 0 )
    {
      if ( flsbuf(0, (int)&v12) == -1 )
        return -2;
    }
    else
    {
      *v10 = 0;
    }
    return v9;
  }
  PopPoCoalescinCallback();
  return -1;
}
