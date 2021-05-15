// PfTCreateTraceDump 
 
int __fastcall PfTCreateTraceDump(int *a1)
{
  int v1; // r7
  int v2; // r10
  int *v3; // r2
  int *v4; // r8
  int v5; // r4
  int v6; // r3
  _BYTE *v7; // r0
  unsigned int v8; // r9
  int v9; // r4
  int *v10; // r4
  __int16 v11; // r3
  unsigned int v12; // r6
  _DWORD *v13; // r0
  unsigned int v14; // r2
  int v15; // r3
  __int16 v16; // lr
  char *v17; // r2
  int v18; // r0
  int v19; // r1
  int v20; // r6
  int v21; // r7
  int v22; // r0
  int v23; // r4
  int v24; // r10
  int v25; // r5
  unsigned int v26; // r2
  unsigned int v27; // r0
  unsigned int v28; // r3
  int v29; // r2
  int *v30; // r9
  unsigned int v31; // r7
  unsigned int v32; // r3
  _DWORD *v33; // r4
  int v34; // r6
  int v35; // r8
  int v36; // r3
  int v38; // [sp+0h] [bp-88h]
  int v39; // [sp+4h] [bp-84h]
  int v40; // [sp+4h] [bp-84h]
  int v41; // [sp+Ch] [bp-7Ch]
  _BYTE *v43; // [sp+14h] [bp-74h]
  char v44[8]; // [sp+18h] [bp-70h] BYREF
  int v45; // [sp+20h] [bp-68h]
  char v46[8]; // [sp+24h] [bp-64h] BYREF
  int v47; // [sp+2Ch] [bp-5Ch]
  int *v48; // [sp+30h] [bp-58h] BYREF
  int v49[13]; // [sp+34h] [bp-54h] BYREF

  memset(v49, 0, sizeof(v49));
  v1 = 0;
  v2 = 0;
  v49[0] = (int)&dword_643938;
  v3 = (int *)dword_643938;
  v4 = &dword_643920;
  v39 = 0;
  v49[1] = dword_64393C;
  v5 = 0;
  v48 = &dword_643920;
  while ( v3 != &dword_643938 )
  {
    v6 = v3[6];
    v3 = (int *)*v3;
    v5 += v6;
  }
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, 2 * v5, 1951688272);
  v8 = (unsigned int)v7;
  v43 = v7;
  if ( !v7 )
  {
    v9 = -1073741670;
    goto LABEL_46;
  }
  memset(v7, 0, 2 * v5);
  v49[5] = v5;
  v10 = &dword_643920;
  v11 = *(_WORD *)(dword_64393C + 28);
  v49[3] = v8;
  LOWORD(v49[4]) = v11;
  do
  {
    v10 = (int *)v10[1];
    v12 = 0;
    if ( !v10[2] )
      continue;
    do
    {
      v13 = (_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFFC) + 8 * v12);
      v14 = *v13 & 3;
      if ( v14 < 2 )
      {
        ++v1;
      }
      else
      {
        v15 = (*v13 >> 2) & 0x3FF;
        v1 += v15;
        v12 = v15 + v12 - 1;
        if ( v14 != 2 )
          goto LABEL_18;
        v13 += 2;
      }
      PfTGetLogEntryInfo(v13, v44, &v48);
      v16 = v49[4];
      v17 = v44;
      v18 = 2;
      do
      {
        if ( *((_DWORD *)v17 + 2) )
        {
          v19 = (unsigned __int16)(*(_WORD *)v17 - v16);
          if ( *(unsigned __int16 *)(v8 + 2 * v19) != 0xFFFF )
          {
            *(_WORD *)(v8 + 2 * v19) = -1;
            ++v2;
          }
        }
        v17 += 12;
        --v18;
      }
      while ( v18 );
      v39 = v2;
LABEL_18:
      ++v12;
    }
    while ( v12 < v10[2] );
    v4 = v48;
  }
  while ( v10 != (int *)*v4 );
  if ( v1 )
  {
    v20 = 8 * v1;
    v21 = ((8 * v1 + 51) & 0xFFFFFFFC) + 16 * v2;
    v22 = ExAllocatePoolWithTag(1, v21, 1146381904);
    v41 = v22;
    if ( v22 )
    {
      v23 = v22 + 8;
      *(_DWORD *)(v22 + 8) = 0;
      *(_DWORD *)(v22 + 12) = 0;
      v24 = v22 + 24;
      *(_DWORD *)(v22 + 16) = 0;
      *(_DWORD *)(v22 + 20) = 0;
      memset((_BYTE *)(v22 + 24), 0, 24);
      *(_WORD *)v23 = 45;
      *(_WORD *)(v23 + 2) = 13;
      v25 = v23 + 40;
      v49[6] = v23 + 16;
      v49[7] = v23 + 40;
      *(_DWORD *)(v23 + 4) = 1128485697;
      *(_DWORD *)(v23 + 8) = v21 - 8;
      *(_DWORD *)(v23 + 12) = 0;
      *(_DWORD *)v24 = 24;
      v26 = (v20 + 27) & 0xFFFFFFFC;
      *(_DWORD *)(v23 + 24) = v26;
      v27 = v26 + v24;
      v28 = (v26 + 16 * v39 + 7) & 0xFFFFFFF8;
      *(_DWORD *)(v23 + 32) = v28;
      v49[8] = v27;
      v49[9] = v28 + v24;
      v29 = 0;
      v38 = 0;
      v40 = v27;
      v49[12] = *(_DWORD *)(v23 + 8) + v23;
      LOWORD(v49[11]) = 0;
      v30 = v4;
      do
      {
        v30 = (int *)v30[1];
        v31 = 0;
        if ( v30[2] )
        {
          v32 = ((unsigned int)v30 + 19) & 0xFFFFFFFC;
          do
          {
            v33 = (_DWORD *)(v32 + 8 * v31);
            v34 = v25 + 8 * v29;
            if ( (*v33 & 3u) < 2 )
            {
              v35 = 1;
            }
            else
            {
              v35 = (*v33 >> 2) & 0x3FF;
              v31 = v35 + v31 - 1;
            }
            if ( v34 + 8 * v35 > v27 )
              break;
            memmove(v34, (int)v33, 8 * v35);
            *(_DWORD *)(v24 + 4) += v35;
            v29 = v38 + v35;
            v38 = v29;
            v36 = *v33 & 3;
            v49[10] = v29;
            if ( v36 == 2 )
            {
              v33 += 2;
              v34 += 8;
            }
            if ( (*v33 & 3u) >= 2 )
            {
              v27 = v40;
            }
            else
            {
              PfTGetLogEntryInfo(v33, v44, &v48);
              if ( v45 )
                PfTDumpEntryInfo(v44, &v48, v34 + 4);
              if ( v47 )
                PfTDumpEntryInfo(v46, &v48, v34 + 6);
              v29 = v49[10];
              v25 = v49[7];
              v27 = v49[8];
              v38 = v49[10];
              v40 = v49[8];
            }
            ++v31;
            v32 = ((unsigned int)v30 + 19) & 0xFFFFFFFC;
          }
          while ( v31 < v30[2] );
          v4 = v48;
        }
      }
      while ( v30 != (int *)*v4 );
      *(_DWORD *)(v24 + 20) = v49[9] - *(_DWORD *)(v24 + 16) - v24;
      v9 = 0;
      *(_WORD *)(v24 + 14) = HIWORD(v49[11]);
      *a1 = v41;
      v8 = (unsigned int)v43;
    }
    else
    {
      v9 = -1073741670;
    }
  }
  else
  {
    v9 = -2147483622;
  }
  ExFreePoolWithTag(v8);
LABEL_46:
  PfTFreeBufferList(&algn_64390C[4]);
  PfTFreeBufferList(&unk_643928);
  return v9;
}
