// RtlGetIntegerAtom 
 
int __fastcall RtlGetIntegerAtom(unsigned int a1, _WORD *a2)
{
  unsigned __int16 *v4; // r2
  int v5; // r0
  unsigned int i; // r3
  unsigned int v7; // t1
  unsigned int v8; // [sp+0h] [bp-18h] BYREF
  __int16 v9[2]; // [sp+8h] [bp-10h] BYREF
  int v10; // [sp+Ch] [bp-Ch]

  if ( (a1 & 0xFFFF0000) == 0 )
    return sub_7C02A0();
  if ( *(_WORD *)a1 == 35 )
  {
    v4 = (unsigned __int16 *)(a1 + 2);
    v7 = *(unsigned __int16 *)(a1 + 2);
    v5 = a1 + 2;
    for ( i = v7; i; i = *v4 )
    {
      if ( i < 0x30 || i > 0x39 )
        return 0;
      ++v4;
    }
    v8 = 0;
    v10 = v5;
    v9[0] = (_WORD)v4 - v5;
    v9[1] = (_WORD)v4 - v5;
    if ( RtlUnicodeStringToInteger(v9, 10, &v8) >= 0 )
    {
      if ( a2 )
      {
        if ( !v8 || v8 > 0xC000 )
          JUMPOUT(0x7C02B6);
        *a2 = v8;
      }
      JUMPOUT(0x7C02B8);
    }
  }
  return 0;
}
