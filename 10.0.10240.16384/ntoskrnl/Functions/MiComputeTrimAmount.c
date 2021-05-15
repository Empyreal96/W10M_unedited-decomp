// MiComputeTrimAmount 
 
unsigned int __fastcall MiComputeTrimAmount(int a1, int a2, int a3)
{
  unsigned int v3; // r9
  unsigned int v4; // r10
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned int v8; // r6
  unsigned int v9; // lr
  int v10; // r5
  int v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r5
  unsigned int v15; // r3
  int v16; // r7
  int v17; // r4
  int v18; // r3
  unsigned int v19; // r7
  unsigned int v20; // r0
  char v21; // r3
  unsigned int v22; // r4
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1

  v3 = *(_DWORD *)(a1 + 40);
  v4 = *(_DWORD *)(a1 + 48);
  if ( v3 == v4 )
    return 0;
  v6 = *(_DWORD *)(a1 + 36);
  if ( (dword_640580 >= v6 || *(_DWORD *)(a1 + 4) + dword_640580 >= v6)
    && (*(unsigned __int8 *)(a1 + 3) < 3u || (*(_BYTE *)a1 & 0x7F) != 0) )
  {
    return 0;
  }
  v7 = *(_DWORD *)(a2 + 60);
  v8 = v7;
  v9 = a3 == 1 ? *(_DWORD *)(*(_DWORD *)(a2 + 92) + 4) : *(_DWORD *)(a2 + 48);
  if ( v7 <= v9 )
    return 0;
  v10 = *(unsigned __int8 *)(a2 + 112);
  v11 = 0;
  if ( (v10 & 7) != 0 )
  {
    if ( (v10 & 7) == 1 && (v10 & 0xFFFFFF80) == 128 && v7 <= *(_DWORD *)(a2 + 48) )
      return 0;
LABEL_21:
    v12 = *(_DWORD *)(a2 + 48);
    if ( v7 <= v12 )
      v8 = 0;
    else
      v8 = v7 - v12;
    goto LABEL_24;
  }
  if ( (*(_DWORD *)(a2 - 300) & 0x40) != 0 )
    v11 = 1;
  if ( (v10 & 0xFFFFFF80) == 128 )
  {
    if ( v7 <= *(_DWORD *)(a2 + 48) )
      return 0;
    v11 = 0;
  }
  if ( !v11 )
    goto LABEL_21;
LABEL_24:
  if ( *(_BYTE *)(a1 + 1) )
  {
    v15 = *(unsigned __int8 *)(a1 + 1) - 1;
    v14 = 0;
    if ( v15 >= 7 )
      return 0;
    v16 = 8 - *(unsigned __int8 *)(a1 + 1);
    v17 = a2 + 4 * v15;
    do
    {
      v18 = *(_DWORD *)(v17 + 20);
      v17 += 4;
      v14 += v18;
      --v16;
    }
    while ( v16 );
    if ( !v14 )
      return 0;
  }
  else
  {
    v13 = *(_DWORD *)(a2 + 48);
    if ( v7 <= v13 )
      v14 = 0;
    else
      v14 = v7 - v13;
  }
  v19 = *(_BYTE *)a1 & 0x7F;
  if ( v19 <= 1 )
  {
    v20 = *(_DWORD *)(a1 + 52);
    if ( *(_BYTE *)(a2 + 114) == 2 )
      v21 = 3;
    else
      v21 = 1;
    v22 = v14 >> v21;
    if ( v20 >= v14 )
    {
      if ( !v20 )
        __brkdiv0();
      v23 = 100 * v14 / v20;
      if ( v22 < v23 * v14 / 0x64 )
        v22 = v23 * v14 / 0x64;
    }
LABEL_52:
    if ( v22 > v8 )
      v22 = v8;
    goto LABEL_54;
  }
  if ( v19 != 4 || (unsigned int)dword_640580 >= 0xC0 )
  {
    if ( v4 <= v3 )
    {
      v24 = *(_DWORD *)(a1 + 44);
      v22 = v14;
      if ( *(_BYTE *)(a2 + 114) != 2 )
      {
        v25 = *(_DWORD *)(a1 + 52);
        if ( v25 > v24 )
        {
          if ( !v24 )
            __brkdiv0();
          if ( !(v25 / v24) )
            __brkdiv0();
          v22 = v14 / (v25 / v24);
        }
      }
      goto LABEL_52;
    }
    return 0;
  }
  v22 = v7 - v9;
LABEL_54:
  if ( v22 > v3 - v4 )
    v22 = v3 - v4;
  ++*(_DWORD *)(dword_6404B8 + 4 * v19 + 1340);
  return v22;
}
