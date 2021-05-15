// _snprintf 
 
int snprintf(_BYTE *a1, unsigned int a2, int a3, ...)
{
  int v4; // r4
  _BYTE *v6; // [sp+8h] [bp-28h] BYREF
  unsigned int v7; // [sp+Ch] [bp-24h]
  _BYTE *v8; // [sp+10h] [bp-20h]
  int v9; // [sp+14h] [bp-1Ch]
  va_list varg_r3; // [sp+44h] [bp+14h] BYREF

  va_start(varg_r3, a3);
  if ( a3 && (!a2 || a1) )
  {
    if ( a2 <= 0x7FFFFFFF )
      v7 = a2;
    else
      v7 = 0x7FFFFFFF;
    v8 = a1;
    v9 = 66;
    v6 = a1;
    v4 = output_l(&v6, a3, 0, (int *)varg_r3);
    if ( a1 )
    {
      if ( (--v7 & 0x80000000) != 0 )
        flsbuf(0, &v6);
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
