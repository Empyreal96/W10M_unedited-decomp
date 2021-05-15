// HvpViewMapUnpinForFileOffset 
 
int __fastcall HvpViewMapUnpinForFileOffset(int a1, int a2, int a3)
{
  unsigned int v3; // r9
  unsigned int v5; // r8
  int v6; // r0
  unsigned int v7; // r10
  unsigned int v8; // r7
  char v9; // r1
  unsigned int v10; // r4
  int v11; // r0
  __int64 v12; // r5
  int v14; // [sp+8h] [bp-30h]
  int v15; // [sp+Ch] [bp-2Ch]
  unsigned int v16; // [sp+10h] [bp-28h]
  int v17; // [sp+14h] [bp-24h]
  int v18; // [sp+18h] [bp-20h]

  v3 = a2 & 0xFFFFF000;
  v5 = (a2 - (a2 & 0xFFFFF000) + a3 + 4095) & 0xFFFFF000;
  v6 = 0;
  v14 = 0;
  v15 = a1;
  if ( v5 )
  {
    do
    {
      v7 = HvpViewMapContiguousBytesAfterFileOffset(a1, v3);
      v16 = v3 & 0xFFFC0000;
      if ( v5 < v7 )
        v7 = v5;
      v8 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * (((v3 & 0xFFFC0000) >> 24) & 0x7F))
         + 24 * (((v3 & 0xFFFC0000) >> 18) & 0x3F);
      v9 = 64 - (v7 >> 12);
      v10 = (0xFFFFFFFF >> v9) | (-1 << ((v7 >> 12) - 32)) | (0xFFFFFFFF >> (32 - (v7 >> 12)));
      v11 = (v3 >> 12) & 0x3F;
      v12 = *(_QWORD *)(v8 + 8);
      v17 = (__PAIR64__(0xFFFFFFFF >> v9, v10) << v11 >> 32) & HIDWORD(v12);
      v18 = (v10 << v11) & v12;
      v14 += HvpViewMapCountPinMaskSetBits(v18, v17);
      *(_DWORD *)(v8 + 8) = v12 & ~v18;
      *(_DWORD *)(v8 + 12) = HIDWORD(v12) & ~v17;
      a1 = v15;
      if ( !(*(_DWORD *)(v8 + 12) | (unsigned int)v12 & ~v18) )
        HvpViewMapUnpinViewOfPrimaryFile(v15, v16);
      HvpViewMapLogPinChange(v15, v16);
      v3 += v7;
      v5 -= v7;
    }
    while ( v5 );
    v6 = v14;
  }
  return HvpViewMapReleaseChargesForPinnedPages(a1, v6);
}
