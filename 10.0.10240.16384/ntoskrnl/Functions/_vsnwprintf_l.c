// _vsnwprintf_l 
 
int __fastcall vsnwprintf_l(_BYTE *a1, unsigned int a2, int a3, int a4, int a5)
{
  int v7; // r4
  int v8; // r3
  _BYTE *v9; // r2
  _BYTE *v11; // [sp+8h] [bp-30h] BYREF
  int v12; // [sp+Ch] [bp-2Ch]
  _BYTE *v13; // [sp+10h] [bp-28h]
  int v14; // [sp+14h] [bp-24h]

  if ( a3 && (!a2 || a1) )
  {
    v13 = a1;
    v14 = 66;
    v8 = 0x7FFFFFFF;
    if ( a2 <= 0x3FFFFFFF )
      v8 = 2 * a2;
    v11 = a1;
    v12 = v8;
    v7 = woutput_l(&v11, a3, a4, a5);
    if ( a1 )
    {
      if ( --v12 < 0 )
      {
        flsbuf(0, &v11);
        v9 = v11;
      }
      else
      {
        *v11 = 0;
        v9 = ++v11;
      }
      if ( --v12 < 0 )
        flsbuf(0, &v11);
      else
        *v9 = 0;
    }
  }
  else
  {
    PopPoCoalescinCallback();
    v7 = -1;
  }
  return v7;
}
