// HvpViewMapPinForFileOffset 
 
int __fastcall HvpViewMapPinForFileOffset(int a1, int a2, int a3)
{
  unsigned int v3; // r3
  unsigned int v4; // r10
  int v6; // r9
  unsigned int v7; // r7
  int v8; // r8
  unsigned int v9; // r3
  char v10; // r1
  unsigned int v11; // r4
  unsigned int v13; // r4
  unsigned int v14; // r7
  int v15; // r10
  unsigned int v16; // r9
  unsigned int v17; // r5
  unsigned int v18; // r8
  int v19; // r9
  unsigned int v20; // r7
  char v21; // r1
  unsigned int v22; // r4
  int v23; // r0
  int v24; // r3
  _DWORD *v25; // r10
  unsigned int v26; // [sp+0h] [bp-30h]
  int v27; // [sp+0h] [bp-30h]
  unsigned int v28; // [sp+4h] [bp-2Ch]
  unsigned int v29; // [sp+8h] [bp-28h]
  int v30; // [sp+Ch] [bp-24h]

  v3 = (a2 + a3 + 4095) & 0xFFFFF000;
  v28 = a2 & 0xFFFFF000;
  v29 = v3 - (a2 & 0xFFFFF000);
  v4 = v29;
  v6 = 0;
  v7 = a2 & 0xFFFFF000;
  if ( v3 != (a2 & 0xFFFFF000) )
  {
    v8 = *(_DWORD *)(a1 + 12);
    do
    {
      v30 = *(_DWORD *)(v8 + 4 * (HIBYTE(v7) & 0x7F)) + 24 * ((v7 >> 18) & 0x3F);
      v9 = HvpViewMapContiguousBytesAfterFileOffset(a1, v7);
      v26 = v9;
      if ( v9 > v4 )
      {
        v9 = v4;
        v26 = v4;
      }
      v10 = 64 - (v9 >> 12);
      v11 = (0xFFFFFFFF >> v10) | (-1 << ((v9 >> 12) - 32)) | (0xFFFFFFFF >> (32 - (v9 >> 12)));
      v6 += HvpViewMapCountPinMaskSetBits(
              (v11 << ((v7 >> 12) & 0x3F)) & ~*(_DWORD *)(v30 + 8),
              ((0xFFFFFFFF >> v10 << ((v7 >> 12) & 0x3F)) | (v11 >> (32 - ((v7 >> 12) & 0x3F))) | (v11 << (((v7 >> 12) & 0x3F) - 32))) & ~*(_DWORD *)(v30 + 12));
      v4 -= v26;
      v7 += v26;
    }
    while ( v4 );
    if ( v6 )
    {
      if ( !HvpViewMapAcquireChargesForPinnedPages(a1, v6) )
        return sub_548798();
      v13 = v28;
      v14 = v29;
      do
      {
        v15 = *(_DWORD *)(a1 + 12);
        v27 = *(_DWORD *)(v15 + 4 * (HIBYTE(v13) & 0x7F));
        v16 = HvpViewMapContiguousBytesAfterFileOffset(a1, v13);
        if ( v16 > v14 )
          v16 = v14;
        if ( (*(_DWORD *)(v27 + 24 * ((v13 >> 18) & 0x3F)) & 1) == 0 )
        {
          v25 = (_DWORD *)(*(_DWORD *)(v15 + 4 * (((v13 & 0xFFFC0000) >> 24) & 0x7F))
                         + 24 * (((v13 & 0xFFFC0000) >> 18) & 0x3F));
          if ( (*v25 & 1) == 0 )
            MmProtectSystemCacheView(*v25 & 0xFFFFFFFE, (v25[4] + 4095) & 0xFFFFF000, 4);
          *v25 |= 1u;
        }
        v14 -= v16;
        v13 += v16;
      }
      while ( v14 );
      v17 = v28;
      v18 = v29;
      do
      {
        v19 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * (HIBYTE(v17) & 0x7F)) + 24 * ((v17 >> 18) & 0x3F);
        v20 = HvpViewMapContiguousBytesAfterFileOffset(a1, v17);
        if ( v20 > v18 )
          v20 = v18;
        v21 = 64 - (v20 >> 12);
        v22 = (0xFFFFFFFF >> v21) | (-1 << ((v20 >> 12) - 32)) | (0xFFFFFFFF >> (32 - (v20 >> 12)));
        v23 = (v17 >> 12) & 0x3F;
        v18 -= v20;
        v24 = *(_DWORD *)(v19 + 12);
        v17 += v20;
        *(_DWORD *)(v19 + 8) |= v22 << v23;
        *(_DWORD *)(v19 + 12) = v24 | (__PAIR64__(0xFFFFFFFF >> v21, v22) << v23 >> 32);
      }
      while ( v18 );
    }
  }
  return 0;
}
