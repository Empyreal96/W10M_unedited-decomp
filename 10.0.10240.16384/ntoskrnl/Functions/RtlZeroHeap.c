// RtlZeroHeap 
 
int __fastcall RtlZeroHeap(_DWORD *a1, int a2)
{
  _DWORD *v2; // r5
  _BYTE *v3; // r6
  int v4; // r3
  _DWORD *v5; // r9
  unsigned __int8 *v6; // r4
  int v7; // r2
  int v8; // r3
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r6
  int *v13; // r8
  int v14; // r1
  int *v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r3
  unsigned int v18; // r8
  _DWORD **v19; // r6
  _DWORD *v20; // r0
  int v21; // r2
  unsigned int v22; // r3
  _DWORD *v23; // r6
  int *v24; // r3
  _DWORD *v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r3
  int v28; // r2
  unsigned int v29; // r1
  char v31; // [sp+8h] [bp-40h]
  _BYTE *v32; // [sp+Ch] [bp-3Ch]
  int v34; // [sp+20h] [bp-28h]

  v2 = a1;
  v3 = 0;
  v32 = 0;
  v31 = 0;
  if ( a1[2] != -571548178 )
  {
    v4 = a1[17] | a2;
    if ( (v4 & 1) == 0 )
    {
      ExAcquireResourceExclusiveLite(a1[50], 1, 0, v4);
      v31 = 1;
    }
    v5 = (_DWORD *)v2[41];
LABEL_5:
    if ( v5 != v2 + 41 )
    {
      v6 = (unsigned __int8 *)v5[5];
      while ( 1 )
      {
        while ( 1 )
        {
          if ( (unsigned int)v6 >= v5[6] )
          {
            v5 = (_DWORD *)*v5;
            goto LABEL_5;
          }
          if ( v3 && v2[19] )
          {
            v3[3] = *v3 ^ v3[2] ^ v3[1];
            *(_DWORD *)v3 ^= v2[20];
          }
          if ( v2[19] )
          {
            *(_DWORD *)v6 ^= v2[20];
            v7 = v6[2] ^ v6[1] ^ *v6;
            v8 = v6[3];
            if ( v8 != v7 )
              RtlpAnalyzeHeapFailure((int)v2, v6, v7, v8);
          }
          v3 = v6;
          v32 = v6;
          v9 = *(unsigned __int16 *)v6;
          v10 = 8 * v9;
          v11 = v6[2];
          if ( (v11 & 1) == 0 )
            break;
LABEL_55:
          if ( v6[7] == 3 )
            v6 += *((_DWORD *)v6 + 7) + 32;
          else
            v6 += 8 * *(unsigned __int16 *)v6;
        }
        if ( (v11 & 8) == 0 )
        {
          if ( (v2[16] & 0x40) != 0 && (v11 & 4) != 0 )
          {
            v28 = -17891602;
            v29 = v10 - 16;
          }
          else
          {
            v29 = v10 - 16;
            v28 = 0;
          }
          RtlFillMemoryUlong((_DWORD *)v6 + 4, v29, v28);
          goto LABEL_55;
        }
        v12 = *((_DWORD *)v6 + 2);
        v13 = (int *)*((_DWORD *)v6 + 3);
        v14 = *(_DWORD *)(v12 + 4);
        if ( *v13 == v14 && (unsigned __int8 *)*v13 == v6 + 8 )
        {
          v2[29] -= v9;
          v15 = (int *)v2[45];
          if ( v15 )
          {
            v16 = *(unsigned __int16 *)v6;
            while ( 1 )
            {
              v17 = v15[1];
              if ( v16 < v17 )
                break;
              v11 = *v15;
              if ( !*v15 )
              {
                v16 = v17 - 1;
                break;
              }
              v15 = (int *)*v15;
            }
            RtlpHeapRemoveListEntry((int)v2, v15, v11, (_DWORD *)v6 + 2, v16);
          }
          *v13 = v12;
          *(_DWORD *)(v12 + 4) = v13;
          v18 = *(unsigned __int16 *)v6;
          v6[2] = 0;
          v6[7] = 0;
          v19 = (_DWORD **)(v2 + 48);
          if ( v2[45] )
            v20 = (_DWORD *)RtlpFindEntry((int)v2, v18);
          else
            v20 = *v19;
          while ( v19 != v20 )
          {
            if ( v2[19] )
            {
              v21 = *(v20 - 2);
              LOWORD(v34) = v21;
              if ( (v2[19] & v21) != 0 )
                v34 = v2[20] ^ v21;
              v22 = (unsigned __int16)v34;
            }
            else
            {
              v22 = *((unsigned __int16 *)v20 - 4);
            }
            if ( v18 <= v22 )
              break;
            v20 = (_DWORD *)*v20;
          }
          v23 = v6 + 8;
          v24 = (int *)v20[1];
          if ( (_DWORD *)*v24 == v20 )
          {
            *v23 = v20;
            *((_DWORD *)v6 + 3) = v24;
            *v24 = (int)v23;
            v20[1] = v23;
          }
          else
          {
            RtlpLogHeapFailure(12, 0, (int)v20, 0, *v24);
          }
          v2[29] += *(unsigned __int16 *)v6;
          v25 = (_DWORD *)v2[45];
          if ( v25 )
          {
            v26 = *(unsigned __int16 *)v6;
            while ( 1 )
            {
              v27 = v25[1];
              if ( v26 < v27 )
                break;
              if ( !*v25 )
              {
                v26 = v27 - 1;
                break;
              }
              v25 = (_DWORD *)*v25;
            }
            RtlpHeapAddListEntry((int)v2, v25, v26, (int)(v6 + 8), v26);
          }
          if ( v2[19] )
          {
            v6[3] = *v6 ^ v6[2] ^ v6[1];
            *(_DWORD *)v6 ^= v2[20];
          }
        }
        else
        {
          RtlpLogHeapFailure(12, (int)v2, (int)(v6 + 8), v14, *v13);
        }
        v3 = 0;
        v32 = 0;
      }
    }
    if ( v32 && a1[19] )
    {
      v32[3] = *v32 ^ v32[2] ^ v32[1];
      *(_DWORD *)v32 ^= a1[20];
    }
    if ( v31 )
      ExReleaseResourceLite(a1[50]);
  }
  return 0;
}
