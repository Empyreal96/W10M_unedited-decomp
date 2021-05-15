// swprintf 
 
int swprintf(_BYTE *a1, int a2, ...)
{
  int v2; // r4
  _BYTE *v3; // r2
  _BYTE *v5; // [sp+8h] [bp-28h] BYREF
  int v6; // [sp+Ch] [bp-24h]
  _BYTE *v7; // [sp+10h] [bp-20h]
  int v8; // [sp+14h] [bp-1Ch]
  va_list varg_r2; // [sp+40h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  if ( a2 && a1 )
  {
    v7 = a1;
    v8 = 66;
    v5 = a1;
    v6 = 0x7FFFFFFF;
    v2 = woutput_l(&v5, a2, 0, (int *)varg_r2);
    if ( --v6 < 0 )
    {
      flsbuf(0, &v5);
      v3 = v5;
    }
    else
    {
      *v5 = 0;
      v3 = ++v5;
    }
    if ( --v6 < 0 )
      flsbuf(0, &v5);
    else
      *v3 = 0;
  }
  else
  {
    PopPoCoalescinCallback();
    v2 = -1;
  }
  return v2;
}
