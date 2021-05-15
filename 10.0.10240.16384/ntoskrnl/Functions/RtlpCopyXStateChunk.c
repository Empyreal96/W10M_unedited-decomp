// RtlpCopyXStateChunk 
 
int __fastcall RtlpCopyXStateChunk(char a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r6
  int v8; // r9
  int v9; // r4
  unsigned __int64 v10; // r2
  BOOL v11; // r8
  int v12; // r10
  int v13; // r2
  int v14; // r3
  int v15; // r9
  int v16; // lr
  int v17; // r4
  int v18; // r3
  unsigned int v19; // r5
  int v20; // r1
  unsigned int v21; // lr
  int v22; // r2
  int v23; // r9
  int v25; // [sp+0h] [bp-58h]
  int v26; // [sp+4h] [bp-54h]
  int v27; // [sp+8h] [bp-50h]
  int v28; // [sp+Ch] [bp-4Ch]
  int v29; // [sp+10h] [bp-48h]
  int v30; // [sp+14h] [bp-44h]
  int v31; // [sp+18h] [bp-40h]
  unsigned int v32; // [sp+1Ch] [bp-3Ch]
  unsigned int v33; // [sp+20h] [bp-38h]
  int v34; // [sp+24h] [bp-34h]
  int v35; // [sp+28h] [bp-30h]

  v5 = a1;
  v26 = 64;
  v6 = 64;
  v7 = 0;
  v32 = *(_DWORD *)(a3 + 20);
  v33 = *(_DWORD *)(a5 + 20);
  if ( v32 < 0x40 || *(_DWORD *)(a5 + 20) < 0x40u )
    return -2147483643;
  v8 = *(_DWORD *)(a5 + 16) + a4;
  v34 = v8;
  v9 = *(_DWORD *)(a3 + 16) + a2;
  v35 = v9;
  memset((_BYTE *)v9, 0, 64);
  v10 = *(_QWORD *)v8 & MEMORY[0xFFFF93D8] & 0xFFFFFFFFFFFFFFFCui64;
  *(_QWORD *)v9 = v10;
  v25 = HIDWORD(v10);
  v27 = v10;
  v11 = (MEMORY[0xFFFF93EC] & 2) != 0;
  if ( (MEMORY[0xFFFF93EC] & 2) != 0 )
  {
    v12 = MEMORY[0xFFFF95FC];
    v13 = (MEMORY[0xFFFF93D8] | 3) & *(_DWORD *)(v8 + 8);
    v14 = *(_DWORD *)(v8 + 12);
    v15 = MEMORY[0xFFFF95F8];
    v16 = MEMORY[0xFFFF93DC] & v14;
  }
  else
  {
    v13 = 0;
    v16 = 0;
    v15 = 0;
    v12 = 0;
  }
  v30 = v15;
  v31 = v12;
  v28 = v13;
  v29 = v16;
  *(_DWORD *)(v9 + 8) = v13;
  *(_DWORD *)(v9 + 12) = v16;
  if ( v5 == 1 )
  {
    v17 = -27672;
    v18 = v25;
    v19 = 2;
    while ( v18 | v27 )
    {
      if ( v11 )
      {
        v20 = 1 << (v19 - 32);
        if ( v20 & v16 | v13 & (1 << v19) )
        {
          v21 = v6;
          v26 = v6;
          if ( v20 & v12 | (1 << v19) & v15 )
          {
            v21 = (v6 + 63) & 0xFFFFFFC0;
            v26 = v21;
            v7 = (__PAIR64__(v7, v6) + 63) >> 32;
          }
          v7 = (__PAIR64__(v7, *(_DWORD *)(v17 + 28)) + v21) >> 32;
          v6 = *(_DWORD *)(v17 + 28) + v21;
        }
        else
        {
          v21 = v26;
        }
      }
      else
      {
        v22 = *(_DWORD *)(v17 + 24);
        v21 = v22 - 512;
        v26 = v22 - 512;
        v6 = *(_DWORD *)(v17 + 28) + v22 - 512;
        v7 = 0;
      }
      v23 = 1 << (v19 - 32);
      if ( v25 & v23 | (1 << v19) & v27 )
      {
        if ( v7 || v6 > v32 || v6 > v33 )
          return -2147483643;
        memmove(v21 + v35, v21 + v34, *(_DWORD *)(v17 + 28));
        v27 &= ~(1 << v19);
        v18 = v25 & ~v23;
        v25 = v18;
      }
      else
      {
        v18 = v25;
      }
      ++v19;
      v17 += 8;
      if ( v19 >= 0x40 )
        return 0;
      v13 = v28;
      v16 = v29;
      v15 = v30;
      v12 = v31;
    }
  }
  return 0;
}
