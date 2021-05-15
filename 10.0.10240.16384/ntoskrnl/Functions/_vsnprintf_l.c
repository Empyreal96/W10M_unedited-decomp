// _vsnprintf_l 
 
int __fastcall vsnprintf_l(_BYTE *a1, unsigned int a2, int a3, int a4, int a5)
{
  int v6; // r4
  _BYTE *v8; // [sp+8h] [bp-30h] BYREF
  unsigned int v9; // [sp+Ch] [bp-2Ch]
  _BYTE *v10; // [sp+10h] [bp-28h]
  int v11; // [sp+14h] [bp-24h]

  if ( a3 && (!a2 || a1) )
  {
    if ( a2 <= 0x7FFFFFFF )
      v9 = a2;
    else
      v9 = 0x7FFFFFFF;
    v10 = a1;
    v11 = 66;
    v8 = a1;
    v6 = output_l(&v8, a3, a4, a5);
    if ( a1 )
    {
      if ( (--v9 & 0x80000000) != 0 )
        flsbuf(0, &v8);
      else
        *v8 = 0;
    }
  }
  else
  {
    PopPoCoalescinCallback();
    v6 = -1;
  }
  return v6;
}
