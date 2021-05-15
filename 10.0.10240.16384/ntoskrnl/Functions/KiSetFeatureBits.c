// KiSetFeatureBits 
 
int __fastcall KiSetFeatureBits(int a1, int a2)
{
  unsigned int v2; // r9
  int v3; // r6
  int result; // r0
  int v11; // r1
  unsigned int v12; // r3
  int v13; // [sp+8h] [bp-30h]

  v13 = a1;
  v2 = __mrc(15, 0, 0, 0, 0);
  if ( (v2 & 0xF0000) != 983040 )
    KeBugCheckEx(93, 1, v2, 0, 0);
  if ( (__mrc(15, 0, 0, 2, 0) & 0xF0u) < 0x10 )
    KeBugCheckEx(93, 2, 0, 1, 0);
  if ( (__mrc(15, 0, 0, 2, 0) & 0xF00u) < 0x100 )
    KeBugCheckEx(93, 2, 0, 2, 0);
  if ( (__mrc(15, 0, 0, 2, 0) & 0xF000u) < 0x1000 )
    KeBugCheckEx(93, 2, 0, 3, 0);
  if ( (__mrc(15, 0, 0, 2, 1) & 0xF0u) < 0x10 )
    KeBugCheckEx(93, 2, 1, 1, 0);
  if ( (__mrc(15, 0, 0, 2, 1) & 0xF00u) < 0x100 )
    KeBugCheckEx(93, 2, 1, 2, 0);
  if ( (__mrc(15, 0, 0, 2, 1) & 0xF000u) < 0x2000 )
    KeBugCheckEx(93, 2, 1, 3, 0);
  if ( (__mrc(15, 0, 0, 2, 1) & 0xF0000u) < 0x10000 )
    KeBugCheckEx(93, 2, 1, 4, 0);
  if ( (__mrc(15, 0, 0, 2, 1) & 0xF00000u) < 0x100000 )
    KeBugCheckEx(93, 2, 1, 5, 0);
  if ( (__mrc(15, 0, 0, 2, 1) & 0xF000000u) < 0x3000000 )
    KeBugCheckEx(93, 2, 1, 6, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF) == 0 )
    KeBugCheckEx(93, 2, 2, 0, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF0u) < 0x40 )
    KeBugCheckEx(93, 2, 2, 1, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF000u) < 0x2000 )
    KeBugCheckEx(93, 2, 2, 3, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF0000u) < 0x30000 )
    KeBugCheckEx(93, 2, 2, 4, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF00000u) < 0x200000 )
    KeBugCheckEx(93, 2, 2, 5, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF000000u) < 0x1000000 )
    KeBugCheckEx(93, 2, 2, 6, 0);
  if ( (__mrc(15, 0, 0, 2, 2) & 0xF0000000) < 0x20000000 )
    KeBugCheckEx(93, 2, 2, 7, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF) == 0 )
    KeBugCheckEx(93, 2, 3, 0, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF0u) < 0x30 )
    KeBugCheckEx(93, 2, 3, 1, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF00u) < 0x100 )
    KeBugCheckEx(93, 2, 3, 2, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF000u) < 0x2000 )
    KeBugCheckEx(93, 2, 3, 3, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF0000u) < 0x10000 )
    KeBugCheckEx(93, 2, 3, 4, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF00000u) < 0x100000 )
    KeBugCheckEx(93, 2, 3, 5, 0);
  if ( (__mrc(15, 0, 0, 2, 3) & 0xF000000u) < 0x1000000 )
    KeBugCheckEx(93, 2, 3, 6, 0);
  if ( (__mrc(15, 0, 0, 2, 4) & 0xFu) < 2 )
    KeBugCheckEx(93, 2, 4, 0, 0);
  if ( (__mrc(15, 0, 0, 2, 4) & 0xF0u) < 0x40 )
    KeBugCheckEx(93, 2, 4, 1, 0);
  if ( (__mrc(15, 0, 0, 2, 4) & 0xF00u) < 0x100 )
    KeBugCheckEx(93, 2, 4, 2, 0);
  if ( (__mrc(15, 0, 0, 2, 4) & 0xF000u) < 0x1000 )
    KeBugCheckEx(93, 2, 4, 3, 0);
  if ( (__mrc(15, 0, 0, 2, 4) & 0xF0000u) < 0x10000 )
    KeBugCheckEx(93, 2, 4, 4, 0);
  if ( (__mrc(15, 0, 0, 2, 4) & 0xFu) < 2 )
    KeBugCheckEx(93, 2, 4, 0, 0);
  *(_WORD *)(a1 + 960) = (unsigned __int16)v2 >> 4;
  *(_WORD *)(a1 + 962) = v2 & 0xF | (((v2 >> 20) & 0xF) << 8);
  *(_BYTE *)(a1 + 1288) = HIBYTE(v2);
  *(_BYTE *)(a1 + 1289) = 0;
  if ( (__mrc(15, 0, 0, 1, 6) & 0xF0000u) < 0x30000
    || (__mrc(15, 0, 0, 1, 7) & 0xF000u) < 0x2000
    || (__mrc(15, 0, 0, 1, 7) & 0xF00000u) < 0x100000 )
  {
    KeBugCheckEx(93, 2, __mrc(15, 0, 0, 1, 6), __mrc(15, 0, 0, 1, 7), 0);
  }
  v3 = 536870921;
  LOBYTE(KiTbrConfiguration) = __mrc(15, 0, 2, 0, 0) & 0x7F;
  KiTbrConfiguration = (unsigned __int8)KiTbrConfiguration;
  if ( (__mrc(15, 0, 0, 1, 1) & 0xF0u) < 0x10 || (__mrc(15, 0, 0, 1, 2) & 0xFu) < 4 )
    KeBugCheckEx(93, 3, __mrc(15, 0, 0, 1, 1), __mrc(15, 0, 0, 1, 2), 0);
  if ( (__mrc(15, 0, 0, 2, 0) & 0xF000000u) >= 0x1000000 )
    MEMORY[0xFFFF928C] = 1;
  if ( (__mrc(15, 0, 0, 2, 2) & 0xFu) >= 2 )
  {
    __asm { VMRS            R3, c5 }
    if ( (_R3 & 0xF0u) >= 0x40 )
    {
      __asm { VMRS            R3, c5 }
      if ( (_R3 & 0xFu) >= 3 )
        MEMORY[0xFFFF9291] = 1;
    }
  }
  if ( (__mrc(15, 0, 0, 2, 5) & 0xF0u) >= 0x20
    && (__mrc(15, 0, 0, 2, 5) & 0xF00u) >= 0x100
    && (__mrc(15, 0, 0, 2, 5) & 0xF000u) >= 0x1000 )
  {
    MEMORY[0xFFFF9292] = 1;
  }
  if ( (__mrc(15, 0, 0, 2, 5) & 0xF0000u) >= 0x10000 )
    MEMORY[0xFFFF9293] = 1;
  if ( (__mrc(15, 0, 0, 1, 4) & 0xFu) >= 4 )
    v3 = 536870923;
  if ( (__mrc(15, 0, 0, 1, 4) & 0xFu) >= 5 )
    MEMORY[0xFFFF928D] = 1;
  *(_BYTE *)(a1 + 1043) = 8;
  *(_BYTE *)(a1 + 1042) = 8;
  *(_DWORD *)(a1 + 1808) = __mrc(15, 0, 0, 0, 5);
  result = KiInitializeVfp();
  v11 = result | v3;
  if ( HIBYTE(v2) == 81 && (v2 & 0xFC00) == 1024 )
  {
    v12 = (v2 >> 20) & 0xF;
    if ( !v12 )
    {
      v11 &= 0xFFFFFFFD;
      MEMORY[0xFFFF928C] = 0;
      MEMORY[0xFFFF928D] = 0;
    }
    if ( v12 <= 1 )
      MEMORY[0xFFFF928F] = 1;
  }
  if ( HIBYTE(v2) == 65 && (v2 & 0xFFF0) == 49280 )
    v11 |= 0x100u;
  *(_DWORD *)(v13 + 1292) = v11;
  return result;
}
