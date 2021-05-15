// _snwprintf 
 
int snwprintf(_BYTE *a1, unsigned int a2, int a3, ...)
{
  int v4; // r4
  int v5; // r3
  _BYTE *v6; // r2
  _BYTE *v8; // [sp+8h] [bp-28h] BYREF
  int v9; // [sp+Ch] [bp-24h]
  _BYTE *v10; // [sp+10h] [bp-20h]
  int v11; // [sp+14h] [bp-1Ch]
  va_list varg_r3; // [sp+44h] [bp+14h] BYREF

  va_start(varg_r3, a3);
  if ( a3 && (!a2 || a1) )
  {
    v10 = a1;
    v11 = 66;
    v5 = 0x7FFFFFFF;
    if ( a2 <= 0x3FFFFFFF )
      v5 = 2 * a2;
    v8 = a1;
    v9 = v5;
    v4 = woutput_l(&v8, a3, 0, (int *)varg_r3);
    if ( a1 )
    {
      if ( --v9 < 0 )
      {
        flsbuf(0, &v8);
        v6 = v8;
      }
      else
      {
        *v8 = 0;
        v6 = ++v8;
      }
      if ( --v9 < 0 )
        flsbuf(0, &v8);
      else
        *v6 = 0;
    }
  }
  else
  {
    PopPoCoalescinCallback();
    v4 = -1;
  }
  return v4;
}
