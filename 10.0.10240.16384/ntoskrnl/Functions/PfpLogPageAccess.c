// PfpLogPageAccess 
 
unsigned int __fastcall PfpLogPageAccess(int a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  __int16 v6; // r7
  int v7; // r0
  unsigned int v8; // r4
  unsigned int v11; // r6
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r8
  int v15; // r5
  int v16; // r1
  int v17; // r0
  int v18; // r1
  _DWORD *v19; // r7
  unsigned int v20; // r0
  int v21; // r3
  int v22; // r2
  int v23; // r0
  unsigned int v24; // r2
  int v25; // r2
  int v26; // r1
  __int64 v27; // r2
  unsigned int v28; // r2
  int v29; // r2
  int v30; // r2
  _DWORD *v32; // [sp+0h] [bp-28h] BYREF
  int v33; // [sp+4h] [bp-24h] BYREF
  int v34; // [sp+8h] [bp-20h]

  v32 = a2;
  v33 = (int)a3;
  v34 = a4;
  v6 = -1;
  v7 = *a2 & 0x1FF;
  v8 = 0;
  v34 = 0xFFFF;
  if ( v7 )
  {
    v11 = *(_DWORD *)(a4 - 4 * v7);
    LOBYTE(v32) = 1;
    v12 = PfTAcquireEntryInfo((int)&unk_643928, v11 & 0xFFFFFFFC, &v33, (char *)&v32);
    if ( !v12 )
      return v8;
    v34 = (unsigned __int16)(*(_WORD *)(v12 + 28) + v33);
    if ( (_BYTE)v32 )
    {
      v13 = ((v12 + 35) & 0xFFFFFFFC) + 20 * (unsigned __int16)v33;
      *(_DWORD *)(v13 + 4) = *(_DWORD *)(v13 + 4) & 8 | (16 * v11) | 4;
      *(_WORD *)(v13 + 8) ^= ((unsigned __int8)*(_WORD *)(v13 + 8) ^ (v11 >> 28)) & 0xF;
    }
  }
  if ( a1 < 0 )
  {
    if ( !a5 )
    {
      v16 = (*(_DWORD *)(a1 + 204) ^ *(_DWORD *)(a1 + 200) ^ a1) & 0x1FFFFFFF ^ (*(_DWORD *)(a1 + 200) >> 3) & 0x1C000000;
      goto LABEL_13;
    }
LABEL_11:
    v16 = a1;
LABEL_13:
    v17 = PfTAcquireEntryInfo((int)&unk_643928, v16 & 0xFFFFFFFC | 1, &v33, (char *)&v32);
    if ( !v17 )
      return v8;
    v18 = (unsigned __int16)v33;
    v14 = 2;
    v33 = (unsigned __int16)(*(_WORD *)(v17 + 28) + v33);
    v19 = (_DWORD *)(((v17 + 35) & 0xFFFFFFFC) + 20 * v18);
    if ( (_BYTE)v32 || (v19[1] & 4) != 0 )
    {
      if ( a5 )
      {
        v19[1] = v19[1] & 0xFFFFFFF8 | 5;
      }
      else
      {
        v20 = v19[1] & 0xFFFFFFF8 | 1;
        v19[1] = v20;
        v19[1] = v20 & 7 | (*(_DWORD *)(a1 + 200) & 0xE0000007 ^ (8 * (*(_DWORD *)(a1 + 204) ^ a1))) & 0xFFFFFFF8 ^ (8 * *(_DWORD *)(a1 + 200));
        v19[4] = *(_DWORD *)(a1 + 408);
        v21 = *(_DWORD *)(a1 + 176);
        v19[2] = a1;
        v19[3] = v21;
      }
    }
    v6 = v33;
    goto LABEL_20;
  }
  if ( a5 )
    goto LABEL_11;
  if ( a1 )
  {
    v15 = (a1 & 0x7FFFFFFF) - 1;
    v14 = 1;
    goto LABEL_21;
  }
  v14 = 0;
LABEL_20:
  v15 = 0;
LABEL_21:
  if ( (*a3 & 3) == 2 )
    v22 = 2;
  else
    v22 = 1;
  v23 = PfTAcquireLogEntry((int)&algn_64390C[4], &v33, v22);
  if ( v23 )
  {
    v8 = ((v23 + 19) & 0xFFFFFFFC) + 8 * v33;
    if ( (*a3 & 3) == 2 )
    {
      *(_DWORD *)v8 = *a3;
      *(_DWORD *)(v8 + 4) = a3[1];
      *(_DWORD *)v8 = *(_DWORD *)v8 & 0xFFFFF003 | 8;
      v8 += 8;
    }
    if ( (*a2 & 0x1FF) != 0 )
    {
      v24 = *(_DWORD *)v8 & 0xFFFFFFFC;
      *(_DWORD *)v8 = v24;
      v25 = v24 ^ ((unsigned __int8)v24 ^ (unsigned __int8)(*a2 >> 7)) & 4;
      *(_DWORD *)v8 = v25;
      v26 = ((unsigned __int8)v25 ^ (unsigned __int8)(*a2 >> 7)) & 8 ^ v25;
      *(_DWORD *)v8 = v26;
      v27 = *(_QWORD *)a2;
      *(_WORD *)(v8 + 6) = v6;
      *(_DWORD *)v8 = v26 & 0xF | (16 * (v27 >> 12));
      *(_WORD *)(v8 + 4) = v34;
    }
    else
    {
      v28 = *(_DWORD *)v8 & 0xFFFFFFFC | 1;
      *(_DWORD *)v8 = v28;
      v29 = v28 ^ ((unsigned __int8)v28 ^ (unsigned __int8)(*a2 >> 7)) & 4;
      v30 = v29 ^ ((unsigned __int8)v29 ^ (unsigned __int8)(8 * v14)) & 0x18;
      *(_DWORD *)v8 = v30;
      *(_DWORD *)v8 = *a2 & 0xFFFFF000 | v30 & 0xFFF;
      if ( v14 == 2 )
        *(_WORD *)(v8 + 6) = v6;
      else
        *(_DWORD *)(v8 + 4) = v15;
    }
  }
  return v8;
}
