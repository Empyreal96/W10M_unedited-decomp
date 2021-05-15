// MiUnmapLargePages 
 
__int16 *__fastcall MiUnmapLargePages(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // r6
  int v7; // [sp+18h] [bp-B8h] BYREF
  char v8; // [sp+1Ch] [bp-B4h]
  char v9; // [sp+1Dh] [bp-B3h]
  int v10; // [sp+20h] [bp-B0h]
  int v11; // [sp+24h] [bp-ACh]
  int v12; // [sp+28h] [bp-A8h]
  int v13; // [sp+2Ch] [bp-A4h]

  v3 = a3;
  if ( a3 == 9 )
    v3 = 16;
  v11 = 0;
  v12 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 33;
  v13 = 0;
  if ( (a2 & 0x3FFFFF) != 0 )
    return (__int16 *)sub_555870();
  MiInsertTbFlushEntry((int)&v7, a1, a2 >> 22, 1);
  return MiReturnSystemVa(a1, a2 + a1, v3, (unsigned int)&v7);
}
