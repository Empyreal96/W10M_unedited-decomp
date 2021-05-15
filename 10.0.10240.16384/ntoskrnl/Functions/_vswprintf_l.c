// _vswprintf_l 
 
int __fastcall vswprintf_l(_BYTE *a1, int a2, int a3, int a4)
{
  int v4; // r4
  _BYTE *v5; // r2
  _BYTE *v7; // [sp+8h] [bp-28h] BYREF
  int v8; // [sp+Ch] [bp-24h]
  _BYTE *v9; // [sp+10h] [bp-20h]
  int v10; // [sp+14h] [bp-1Ch]

  if ( a2 && a1 )
  {
    v9 = a1;
    v10 = 66;
    v7 = a1;
    v8 = 0x7FFFFFFF;
    v4 = woutput_l(&v7, a2, a3, a4);
    if ( --v8 < 0 )
    {
      flsbuf(0, &v7);
      v5 = v7;
    }
    else
    {
      *v7 = 0;
      v5 = ++v7;
    }
    if ( --v8 < 0 )
      flsbuf(0, &v7);
    else
      *v5 = 0;
  }
  else
  {
    PopPoCoalescinCallback();
    v4 = -1;
  }
  return v4;
}
