// _vsprintf_l 
 
int __fastcall vsprintf_l(_BYTE *a1, int a2, int a3, int a4)
{
  int v4; // r4
  _BYTE *v6; // [sp+8h] [bp-28h] BYREF
  int v7; // [sp+Ch] [bp-24h]
  _BYTE *v8; // [sp+10h] [bp-20h]
  int v9; // [sp+14h] [bp-1Ch]

  if ( a2 && a1 )
  {
    v7 = 0x7FFFFFFF;
    v8 = a1;
    v9 = 66;
    v6 = a1;
    v4 = output_l(&v6, a2, a3, a4);
    if ( --v7 < 0 )
      flsbuf(0, &v6);
    else
      *v6 = 0;
  }
  else
  {
    PopPoCoalescinCallback();
    v4 = -1;
  }
  return v4;
}
