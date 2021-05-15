// KiEmulateDivide 
 
int __fastcall KiEmulateDivide(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r7
  signed int v18; // r4
  signed int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  signed int v23; // r4
  signed int v24; // r6
  bool v25; // cc
  int (__fastcall *v26)(signed int, int, int, int, int, int, int); // r6

  __asm { SRS.W           SP, #0x1B }
  a11 = a1;
  a7 = v11;
  a8 = v12;
  ((void (__fastcall *)(int, int, int, int))((char *)sub_4220E6 + 4 * (HIWORD(v13) & 0xF)))(a1, a2, a3, a4);
  v18 = (signed int)sub_4220E6 + 4 * (v13 & 0xF);
  v19 = ((int (__fastcall *)(char *))v18)((char *)sub_4220E6 + 4 * (HIWORD(v13) & 0xF));
  if ( (v13 & 0x200000) == 0 )
  {
    if ( (v19 ^ v18) >= 0 )
      v13 ^= 0x200000u;
    if ( v19 < 0 )
      v19 = -v19;
    if ( v18 < 0 )
      v18 = -v18;
  }
  if ( !v18
    || (v23 = __clz(v18),
        v24 = __clz(v19),
        v25 = v23 < v24,
        v26 = (int (__fastcall *)(signed int, int, int, int, int, int, int))((char *)&loc_421D82
                                                                           - 2 * (v23 - v24)
                                                                           + -8 * (v23 - v24)),
        v25) )
  {
    ((void (*)())((char *)sub_42216A + 4 * ((v13 >> 8) & 0xF)))();
    a5 += 4;
    __asm { RFEFD.W         SP }
  }
  return v26(v19, v20, v21, v22, a5, a6, a7);
}
