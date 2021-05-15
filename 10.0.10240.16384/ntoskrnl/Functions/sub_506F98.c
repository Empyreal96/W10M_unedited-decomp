// sub_506F98 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_506F98(int a1, int a2)
{
  _DWORD *v2; // r7
  int v3; // r3
  int v4; // r3
  unsigned int v5; // r3
  unsigned int v6; // r5
  int v7; // r3
  __int64 v8; // kr08_8
  __int64 v9; // kr10_8
  unsigned int v10; // r1
  int v11; // r3
  int v12; // r0
  unsigned __int64 v13; // r2
  int v14; // r4
  unsigned int v15; // r2
  int v16; // r3
  int (__fastcall *v18)(int, int); // [sp-4h] [bp-4h]

  v3 = KiVerifyPass - 1;
  __dmb(0xBu);
  KiVerifyPass = v3;
  v4 = KiVerifyPass;
  __dmb(0xBu);
  if ( !v4 )
  {
    v5 = __mrc(15, 0, 9, 13, 0);
    v6 = v5 << 29;
    v7 = v5 ^ (v5 >> 3);
    v2[142] = v7;
    v2[30] = v6;
    v2[106] = 67117057;
    v2[34] = 1880096896;
    v8 = 67117057i64 * (unsigned int)v7;
    v9 = 1880096896i64 * (unsigned int)v7 + 67117057i64 * v6;
    v2[12] = 1880096896 * v6 + HIDWORD(v9);
    v10 = (1880096896i64 * v6 + (unsigned __int64)HIDWORD(v9)) >> 32;
    v11 = 1880096896 * v6 + HIDWORD(v9);
    v2[13] = v10;
    v12 = v9 + HIDWORD(v8);
    v2[73] = v9 + HIDWORD(v8);
    v2[72] = v8;
    if ( (unsigned int)(v9 + HIDWORD(v8)) < HIDWORD(v8) )
    {
      v2[12] = v11 + 1;
      v10 = (__PAIR64__(v10, v11++) + 1) >> 32;
      v2[13] = v10;
    }
    v2[76] = v8;
    v2[77] = v12;
    v2[80] = v11;
    v2[81] = v10;
    v2[84] = v8;
    v2[85] = v12;
    LODWORD(v13) = v8 ^ v11;
    HIDWORD(v13) = v12 ^ v10;
    v14 = (unsigned __int8)KdDebuggerNotPresent | (unsigned __int8)KdPitchDebugger;
    a1 = _rt_udiv64(100i64, v13);
    if ( !v16 && (v14 < 0 || v15 < v14) )
    {
      *v2 = ((int (__fastcall *)(int))KdDisableDebugger)(a1);
      _jump_unwind((int)(v2 + 190), (int)&loc_930286 + 1);
    }
  }
  return v18(a1, a2);
}
