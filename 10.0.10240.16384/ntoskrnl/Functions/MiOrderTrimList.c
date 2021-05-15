// MiOrderTrimList 
 
unsigned int __fastcall MiOrderTrimList(_DWORD *a1, int a2)
{
  int v2; // r5
  _DWORD **v4; // r6
  unsigned int v5; // r7
  int v6; // r9
  char *v7; // r3
  int v8; // r2
  _DWORD *v9; // r1
  __int64 v10; // r2
  int v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int i; // r2
  unsigned int v19; // r3
  bool v20; // cf
  char *v21; // r2
  int v22; // r0
  int v23; // r1
  unsigned int v24; // r0
  char *v25; // r2
  int v26; // r3
  unsigned int v27; // r2
  unsigned int v28; // r0
  int v29; // r1
  char *v30; // r4
  char *v31; // r1
  int v32; // r3
  _DWORD *v33; // r3
  _DWORD *v34; // r2
  unsigned int *v35; // r1
  int v36; // t1
  int v37; // r1
  int v38; // r4
  int v39; // r2
  int v40; // r3
  __int16 v41; // r0
  unsigned int v44; // [sp+8h] [bp-A0h] BYREF
  char v45[24]; // [sp+Ch] [bp-9Ch] BYREF
  _DWORD v46[32]; // [sp+28h] [bp-80h] BYREF

  v2 = a2;
  v44 = 0;
  memset(v45, 0, sizeof(v45));
  v4 = (_DWORD **)(a1 + 879);
  if ( (_DWORD *)a1[879] == a1 + 879 )
    return 0;
  v6 = a1[878];
  v5 = 0;
  v7 = (char *)v46;
  v8 = 12;
  do
  {
    *(_DWORD *)v7 = v7;
    *((_DWORD *)v7 + 1) = v7;
    v7 += 8;
    --v8;
  }
  while ( v8 );
  while ( *v4 != v4 )
  {
    LODWORD(v10) = *v4;
    HIDWORD(v10) = (*v4)[1];
    v9 = (_DWORD *)**v4;
    if ( v10 != __PAIR64__((unsigned int)v4, v9[1]) )
      __fastfail(3u);
    *v4 = v9;
    v11 = v10 - 12;
    v9[1] = v4;
    MiUpdateClaimDistribution(v10 - 12, &v44);
    if ( v2 )
    {
      v14 = 0;
      if ( (unsigned int)(a2 - 1) < 7 )
      {
        v15 = 8 - a2;
        v16 = v11 + 4 * (a2 - 1);
        do
        {
          v17 = *(_DWORD *)(v16 + 20);
          v16 += 4;
          v14 += v17;
          --v15;
        }
        while ( v15 );
      }
    }
    else
    {
      v12 = *(_DWORD *)(v11 + 60);
      v13 = *(_DWORD *)(v11 + 48);
      if ( v12 <= v13 )
        v14 = 0;
      else
        v14 = v12 - v13;
    }
    if ( a1[168] && (*(_BYTE *)(v11 + 112) & 7) == 0 && v11 - 492 == PsInitialSystemProcess )
    {
      i = 11;
    }
    else if ( *(_BYTE *)(v11 + 114) != 2 || MiWorkingSetVeryLarge((_DWORD *)v11, 0) )
    {
      if ( !v14 || (*(_BYTE *)(v11 + 112) & 0x80) == 128 && *(_DWORD *)(v11 + 60) <= *(_DWORD *)(v11 + 48) )
      {
        i = 11;
      }
      else
      {
        for ( i = 0; i < 9; ++i )
        {
          if ( v14 >= 0x80000u >> i )
            break;
        }
      }
      if ( i < 0xA )
      {
        v19 = v14 + v5;
        v20 = v14 + v5 >= v5;
        v5 = -1;
        if ( v20 )
          v5 = v19;
      }
    }
    else
    {
      i = 10;
    }
    v21 = (char *)&v46[2 * i];
    v22 = *(_DWORD *)v21;
    v23 = v11 + 12;
    *(_DWORD *)(v11 + 12) = *(_DWORD *)v21;
    *(_DWORD *)(v11 + 16) = v21;
    if ( *(char **)(v22 + 4) != v21 )
      __fastfail(3u);
    v2 = a2;
    *(_DWORD *)(v22 + 4) = v23;
    *(_DWORD *)v21 = v23;
  }
  v24 = 0;
  v25 = (char *)v46;
  while ( *(char **)v25 == v25 )
  {
    ++v24;
    v25 += 8;
    if ( v24 >= 0xC )
      goto LABEL_46;
  }
  v26 = v46[2 * v24];
  v27 = v24;
  v28 = v24 + 1;
  a1[879] = v26;
  *(_DWORD *)(v26 + 4) = v4;
  if ( v28 < 0xC )
  {
    v29 = 2 * v27;
    do
    {
      v30 = (char *)&v46[2 * v28];
      if ( *(char **)v30 != v30 )
      {
        v31 = (char *)&v46[v29];
        **((_DWORD **)v31 + 1) = *(_DWORD *)v30;
        v32 = *((_DWORD *)v31 + 1);
        v29 = 2 * v28;
        *(_DWORD *)(*(_DWORD *)v30 + 4) = v32;
        v27 = v28;
      }
      ++v28;
    }
    while ( v28 < 0xC );
  }
  v33 = (_DWORD *)v46[2 * v27 + 1];
  a1[880] = v33;
  *v33 = v4;
LABEL_46:
  v34 = (_DWORD *)(v6 + 1256);
  v35 = &v44;
  do
  {
    v36 = *v35++;
    *v34++ = v36;
  }
  while ( v34 != (_DWORD *)(v6 + 1284) );
  v37 = 0;
  v38 = 2;
  v39 = v6 + 24;
  do
  {
    v40 = *(_DWORD *)(v39 + 1256);
    v39 -= 4;
    v37 += v40;
    --v38;
  }
  while ( v38 );
  *(_DWORD *)(v6 + 1252) = v37;
  v41 = MiComputeAgeDistribution((int)a1, 0);
  *(_BYTE *)(v6 + 46) = 1;
  *(_WORD *)(v6 + 1218) = v41;
  return v5;
}
