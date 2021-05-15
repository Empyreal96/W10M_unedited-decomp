// MiCopyPfnEntry 
 
int __fastcall MiCopyPfnEntry(int a1, int *a2)
{
  int *v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r4
  int v6; // r5
  int v7; // r3
  unsigned int v9; // r0
  unsigned int v10; // r3
  int result; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r7
  int v16; // r3
  int v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h]
  int v19; // [sp+8h] [bp-20h]
  int v20; // [sp+Ch] [bp-1Ch]
  int v21; // [sp+10h] [bp-18h]
  int v22; // [sp+14h] [bp-14h]

  v3 = *a2;
  v4 = a2[1];
  v5 = a2[2];
  v6 = a2[3];
  v2 = a2 + 4;
  v17 = v3;
  v18 = v4;
  v19 = v5;
  v20 = v6;
  v7 = v2[1];
  v21 = *v2;
  v22 = v7;
  LOBYTE(v3) = *(_BYTE *)(a1 + 19);
  v9 = v7;
  HIBYTE(v21) = *(_BYTE *)(a1 + 19) ^ (HIBYTE(v21) ^ v3) & 0x3F;
  if ( (v7 & 0x7000000) == 50331648 )
    v9 = v7 & 0xF8FFFFFF;
  v10 = *(_DWORD *)(a1 + 20);
  BYTE2(v21) = (BYTE2(v21) ^ *(_BYTE *)(a1 + 18)) & 0x3F ^ *(_BYTE *)(a1 + 18);
  v22 = v9 & 0xFFFFFFF | (v10 >> 28 << 28);
  if ( (BYTE2(v21) & 7) != 6 )
    MiSetPfnTbFlushStamp(&v17, (*(_DWORD *)(a1 + 12) >> 20) & 0xF, 1);
  result = v17;
  v12 = v18;
  v13 = v19;
  v14 = v20;
  *(_DWORD *)a1 = v17;
  *(_DWORD *)(a1 + 4) = v12;
  *(_DWORD *)(a1 + 8) = v13;
  *(_DWORD *)(a1 + 12) = v14;
  v15 = (_DWORD *)(a1 + 16);
  v16 = v22;
  *v15 = v21;
  v15[1] = v16;
  return result;
}
