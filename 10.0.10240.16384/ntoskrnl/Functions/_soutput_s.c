// _soutput_s 
 
int __fastcall soutput_s(_BYTE *a1, unsigned int a2, char *a3, __int16 *a4)
{
  int v6; // r4
  int v7; // r7
  _BYTE *v9; // [sp+8h] [bp-30h] BYREF
  int v10; // [sp+Ch] [bp-2Ch]
  _BYTE *v11; // [sp+10h] [bp-28h]
  int v12; // [sp+14h] [bp-24h]

  if ( a2 )
  {
    v6 = -1;
    if ( a2 == -1 )
    {
      v10 = 0x7FFFFFFF;
    }
    else
    {
      if ( a2 > 0x7FFFFFFF )
      {
        PopPoCoalescinCallback();
        return v6;
      }
      v10 = a2;
    }
    v11 = a1;
    v12 = 66;
    v9 = a1;
    v7 = output_s((int)&v9, a3, a4);
    a1[a2 - 1] = 0;
    if ( v7 < 0 )
    {
      if ( v10 >= 0 )
      {
        if ( a1 && a2 )
          *a1 = 0;
        return v7;
      }
      return -2;
    }
    if ( --v10 < 0 )
    {
      if ( flsbuf(0, (int)&v9) == -1 )
        return -2;
    }
    else
    {
      *v9 = 0;
    }
    return v7;
  }
  PopPoCoalescinCallback();
  return -1;
}
