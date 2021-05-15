// sprintf 
 
int sprintf(_BYTE *a1, int a2, ...)
{
  int v2; // r4
  _BYTE *v4; // [sp+8h] [bp-28h] BYREF
  int v5; // [sp+Ch] [bp-24h]
  _BYTE *v6; // [sp+10h] [bp-20h]
  int v7; // [sp+14h] [bp-1Ch]
  va_list varg_r2; // [sp+40h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  if ( a2 && a1 )
  {
    v5 = 0x7FFFFFFF;
    v6 = a1;
    v7 = 66;
    v4 = a1;
    v2 = output_l(&v4, a2, 0, (int *)varg_r2);
    if ( --v5 < 0 )
      flsbuf(0, &v4);
    else
      *v4 = 0;
  }
  else
  {
    PopPoCoalescinCallback();
    v2 = -1;
  }
  return v2;
}
