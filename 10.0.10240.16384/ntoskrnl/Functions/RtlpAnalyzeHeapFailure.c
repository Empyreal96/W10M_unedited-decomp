// RtlpAnalyzeHeapFailure 
 
int __fastcall RtlpAnalyzeHeapFailure(int a1, unsigned __int8 *a2, int a3, int a4)
{
  unsigned int v4; // r4
  _DWORD *v5; // r6
  int v6; // r5
  int v7; // r8
  int v8; // r1
  int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r2
  int v12; // lr
  int v13; // lr
  int v14; // r3
  unsigned __int16 *v15; // r3
  int v16; // r1
  int v17; // lr
  int v18; // r1
  int v19; // r0
  int v21; // [sp+10h] [bp-20h]
  int varg_r0; // [sp+38h] [bp+8h]

  v4 = (unsigned int)a2;
  varg_r0 = a1;
  v5 = 0;
  v6 = 0;
  v7 = *(_DWORD *)(a1 + 76);
  if ( (v7 & *(_DWORD *)a2) == 0 )
  {
    v6 = 10;
    if ( (*(_DWORD *)(a1 + 64) & 0x4000000) != 0 || a2[3] == (a2[2] ^ a2[1] ^ *a2) )
    {
      v6 = 1;
      v8 = a2[6];
      v5 = (_DWORD *)(*(_BYTE *)(v4 + 6) ? (v4 & 0xFFFF0000) - (v8 << 16) + 0x10000 : a1);
      if ( v5[2] == -1114130 )
      {
        v9 = *(unsigned __int8 *)(v4 + 7);
        if ( v9 == 4 || (v6 = 2, v4 >= v5[7]) && v4 < v5[10] && v5[6] == a1 )
        {
          v6 = 3;
          if ( v9 == 3 )
          {
            v10 = v4 + 8;
            v11 = *(_DWORD *)(v4 + 24);
            if ( (v11 & 0xFFF) != 0 )
              goto LABEL_33;
            if ( v11 < v5[7] )
              goto LABEL_33;
            if ( v11 + *(_DWORD *)(v4 + 28) > v5[10] )
              goto LABEL_33;
            v6 = 4;
            v12 = **(_DWORD **)(v4 + 12);
            if ( v12 != *(_DWORD *)(*(_DWORD *)v10 + 4) )
              goto LABEL_33;
            if ( v12 != v10 )
              goto LABEL_33;
            v6 = 5;
            v13 = **(_DWORD **)(v4 + 20);
            if ( v13 != *(_DWORD *)(*(_DWORD *)(v4 + 16) + 4) || v13 != v4 + 16 )
              goto LABEL_33;
          }
          else
          {
            v6 = 6;
            if ( (*(unsigned __int16 *)(a1 + 84) ^ *(unsigned __int16 *)(v4 + 8 * *(unsigned __int16 *)v4 + 4)) != *(unsigned __int16 *)v4 )
              goto LABEL_33;
          }
          v6 = 7;
          v14 = *(unsigned __int16 *)(v4 + 4) ^ *(unsigned __int16 *)(a1 + 84);
          if ( !v14 )
            goto LABEL_29;
          v15 = (unsigned __int16 *)(v4 - 8 * v14);
          if ( v7 )
          {
            v21 = *(_DWORD *)v15;
            if ( (*(_DWORD *)(a1 + 76) & *(_DWORD *)v15) != 0 )
              v21 = *(_DWORD *)(a1 + 80) ^ *(_DWORD *)v15;
            v16 = (unsigned __int16)v21;
          }
          else
          {
            v16 = *v15;
          }
          if ( v16 == (*(unsigned __int16 *)(v4 + 4) ^ *(unsigned __int16 *)(a1 + 84)) )
          {
LABEL_29:
            v6 = 8;
            if ( (*(_BYTE *)(v4 + 2) & 1) != 0
              || (v17 = **(_DWORD **)(v4 + 12), v17 == *(_DWORD *)(*(_DWORD *)(v4 + 8) + 4)) && v17 == v4 + 8 )
            {
              v6 = 9;
            }
          }
        }
      }
    }
  }
LABEL_33:
  if ( *(_DWORD *)(a1 + 76) )
  {
    *(_BYTE *)(v4 + 3) = *(_BYTE *)v4 ^ *(_BYTE *)(v4 + 2) ^ *(_BYTE *)(v4 + 1);
    *(_DWORD *)v4 ^= *(_DWORD *)(a1 + 80);
  }
  switch ( v6 )
  {
    case 0:
    case 1:
    case 6:
    case 7:
    case 10:
      v18 = a1;
      v19 = 3;
      return RtlpLogHeapFailure(v19, v18, v4, v6, 0);
    case 2:
      return RtlpLogHeapFailure(11, a1, v4, v5[6], 0);
    case 3:
      return RtlpLogHeapFailure(0, a1, v4, 3, 0);
    case 4:
    case 5:
      v18 = a1;
      v19 = 13;
      return RtlpLogHeapFailure(v19, v18, v4, v6, 0);
    case 8:
      return RtlpLogHeapFailure(12, a1, v4, 8, 0);
    default:
      v18 = a1;
      v19 = 2;
      return RtlpLogHeapFailure(v19, v18, v4, v6, 0);
  }
}
