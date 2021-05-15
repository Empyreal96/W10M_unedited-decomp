// KdpSearchMemory 
 
int __fastcall KdpSearchMemory(_DWORD *a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r6
  _BYTE *v4; // r9
  unsigned int v5; // r7
  unsigned int v6; // r8
  unsigned int v7; // r3
  int v8; // r2
  unsigned int v9; // r5
  unsigned int v10; // r6
  int v11; // r10
  int v12; // r0
  int v13; // r1
  unsigned int v14; // lr
  unsigned int v15; // r8
  unsigned int v16; // r9
  unsigned __int8 *v17; // r4
  int v18; // t1
  char v20[4]; // [sp+8h] [bp-68h] BYREF
  int v21; // [sp+Ch] [bp-64h] BYREF
  int v22; // [sp+10h] [bp-60h]
  unsigned int v23; // [sp+14h] [bp-5Ch]
  _BYTE *v24; // [sp+18h] [bp-58h]
  _DWORD *v25; // [sp+1Ch] [bp-54h]
  __int16 v26; // [sp+20h] [bp-50h]
  __int16 v27; // [sp+22h] [bp-4Eh]
  _DWORD *v28; // [sp+24h] [bp-4Ch]
  unsigned int v29; // [sp+28h] [bp-48h]
  int v30; // [sp+2Ch] [bp-44h]
  int v31[4]; // [sp+30h] [bp-40h] BYREF
  int v32[12]; // [sp+40h] [bp-30h]

  v2 = a1;
  v3 = a1[4];
  v4 = *(_BYTE **)(a2 + 4);
  v5 = a1[8];
  v6 = a1[6] + v3;
  a1[2] = -2147483622;
  v24 = v4;
  v25 = a1;
  v29 = v6;
  v23 = v5;
  if ( v5 <= 3 )
    v7 = 0xFFFFFFFF >> (8 * (4 - v5));
  else
    v7 = -1;
  v32[0] = v7;
  v32[1] = v7 << 8;
  v32[2] = v7 << 16;
  v32[3] = v7 << 24;
  v8 = v5;
  if ( v5 >= 5 )
    v8 = 4;
  v31[0] = 0;
  KdpQuickMoveMemory((int)v31, v4, v8);
  v9 = v3 & 3;
  v10 = v3 & 0xFFFFFFFC;
  v31[1] = v31[0] << 8;
  v31[2] = v31[0] << 16;
  v31[3] = v31[0] << 24;
  while ( v10 < v6 )
  {
    if ( MmDbgCopyMemory(v10, 0, (int)&v21, 4u, 4u) >= 0 )
    {
      v11 = (int)&v4[-v9 + 4];
      v12 = 4 - v9;
      v13 = v21;
      v22 = 4 - v9;
      v14 = v5 - 4;
      while ( 1 )
      {
        if ( (v32[v9] & v13) == v31[v9] )
        {
          if ( 4 - v9 >= v5 )
            goto LABEL_22;
          v30 = v11;
          v15 = v14 + v9;
          if ( !(v14 + v9) )
            goto LABEL_22;
          v16 = v12 + v9 + v10;
          v17 = (unsigned __int8 *)v11;
          do
          {
            if ( MmDbgCopyMemory(v16, 0, (int)v20, 1u, 1u) < 0 )
              break;
            v18 = *v17++;
            if ( (unsigned __int8)v20[0] != v18 )
              break;
            ++v16;
            --v15;
          }
          while ( v15 );
          v2 = v25;
          v5 = v23;
          if ( !v15 )
          {
LABEL_22:
            v2[4] = v9 + v10;
            v2[2] = 0;
            v2[5] = 0;
            goto LABEL_23;
          }
          v13 = v21;
          v12 = v22;
          v14 = v23 - 4;
        }
        ++v9;
        v22 = --v12;
        --v11;
        if ( v9 >= 4 )
        {
          v6 = v29;
          v4 = v24;
          break;
        }
      }
    }
    v10 += 4;
    v9 = 0;
  }
LABEL_23:
  v27 = 56;
  v26 = 56;
  v28 = v2;
  return KdSendPacket_0();
}
