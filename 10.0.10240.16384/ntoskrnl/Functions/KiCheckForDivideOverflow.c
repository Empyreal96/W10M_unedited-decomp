// KiCheckForDivideOverflow 
 
__int64 __fastcall KiCheckForDivideOverflow(int a1, int a2, int a3, int *a4)
{
  int v4; // r5
  int v5; // r0
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r4
  unsigned int v9; // r2
  int *v10; // r5
  char v11; // r3
  unsigned int v12; // r6
  int v13; // r7
  int v14; // r1
  int v15; // r1
  unsigned int v16; // r0
  int v17; // r1
  unsigned int v18; // r6
  unsigned int i; // r0
  unsigned int v20; // r5
  unsigned int v21; // r2
  int v22; // r1
  unsigned int j; // r3
  char v24; // r7
  int v25; // r1
  unsigned int v27; // [sp+0h] [bp-38h]
  int v28; // [sp+0h] [bp-38h]
  int v29; // [sp+4h] [bp-34h]
  char var30[52]; // [sp+8h] [bp-30h] BYREF
  int vars4; // [sp+3Ch] [bp+4h] BYREF

  v4 = *a4;
  *(_DWORD *)(a1 + 40) = vars4 ^ *a4 ^ a1;
  *(_DWORD *)(a1 + 32) = (unsigned int)&vars4 ^ v4;
  v5 = KfRaiseIrql(2);
  vars4 = 0;
  v6 = *(_DWORD *)(v4 + 32);
  v7 = *(_DWORD *)(v4 + 16);
  v29 = v5;
  v8 = (v7 ^ v6) & 0xFFFFFFFC;
  v27 = __ROR4__(v8, (v7 ^ v6) & 0x1C);
  var30[0] = 11;
  var30[1] = 8;
  var30[2] = 14;
  var30[3] = 3;
  var30[4] = 13;
  var30[5] = 2;
  var30[6] = 7;
  var30[7] = 12;
  var30[8] = 6;
  var30[9] = 1;
  var30[10] = 5;
  var30[11] = 15;
  var30[12] = 10;
  var30[13] = 4;
  var30[14] = 0;
  v9 = 0;
  var30[15] = 9;
  v10 = (int *)v8;
  do
  {
    v11 = var30[v9] ^ 0xB;
    __dmb(0xBu);
    var30[v9++] = v11;
  }
  while ( v9 < 0x10 );
  v12 = 0;
  v13 = 0;
  do
  {
    v14 = *v10;
    *v10 = (KiWaitAlways ^ bswap32(v27 ^ __ROR4__(KiWaitNever ^ *v10, -(char)KiWaitNever))) + v13;
    v27 = __ROL4__(__ROR4__((200 - v12) * v12, ~(_BYTE)v14 & 0x1F) ^ v27, v14 & 0x1F) + v8;
    v15 = 8;
    do
    {
      *v10 = __ROR4__(*v10 & 0xFFFFFFF0 | (unsigned __int8)var30[*v10 & 0xF], 4);
      --v15;
    }
    while ( v15 );
    ++v12;
    ++v10;
    v13 += v8;
  }
  while ( v12 < 0x32 );
  v28 = *(_DWORD *)v8 ^ 0x4790B510;
  *(_DWORD *)v8 = -71658805;
  *(_DWORD *)v8 ^= 0xBC2A27DB;
  v16 = __mrc(15, 1, 0, 0, 1);
  v17 = __mrc(15, 0, 0, 0, 0);
  v18 = (v16 >> 21) & 7;
  if ( (v17 & 0xFFF0) == 49296 && (v17 & 0xFF000000) == 1090519040 && (v17 & 0xF00000u) < 0x100000 )
    v18 = (v16 >> 27) & 7;
  for ( i = 0; i < v18; ++i )
  {
    __mcr(15, 2, 2 * (i & 7), 0, 0, 0);
    __isb(0xFu);
    v20 = __mrc(15, 1, 0, 0, 0);
    v21 = ((v20 >> 3) & 0x3FF) + 1;
    v22 = 0;
    for ( j = v21 >> 1; j; j >>= 1 )
      ++v22;
    if ( ((v20 >> 3) & 0x3FF & (((v20 >> 3) & 0x3FF) + 1)) != 0 )
      LOBYTE(v22) = v22 + 1;
    v24 = 32 - v22;
    do
    {
      --v21;
      v25 = ((v20 >> 13) & 0x7FFF) + 1;
      do
        __mcr(15, 0, (--v25 << ((v20 & 7) + 4)) | (2 * i) | (v21 << v24), 7, 10, 2);
      while ( v25 );
    }
    while ( v21 );
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 7, 5, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  *(_BYTE *)(v8 + 1) = *(_BYTE *)(v8 + 1);
  ((void (__fastcall *)(unsigned int, int, int (*)(), _DWORD))(v8 | 1))(v8 + 4, v28, WnfpNormalizeNotificationState, 0);
  return KfLowerIrql(v29);
}
