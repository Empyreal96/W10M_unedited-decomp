// EtwpGetTraceGuidInfo 
 
int __fastcall EtwpGetTraceGuidInfo(unsigned int a1, _BYTE *a2, int *a3)
{
  int *v3; // r6
  unsigned int v4; // r4
  _BYTE *v5; // r9
  int v6; // r5
  int v7; // r7
  int v8; // r3
  int *v9; // lr
  unsigned int v10; // r6
  int v11; // r8
  _DWORD *v12; // r10
  _BYTE *v13; // r2
  int v14; // r0
  int v15; // r1
  int v16; // r2
  _DWORD *v17; // r10
  unsigned int i; // r8
  _DWORD *v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r3
  _DWORD *v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r3
  _DWORD *v35; // lr
  unsigned int v36; // r6
  int v37; // r2
  _DWORD *v38; // r9
  int v39; // r10
  _DWORD *v40; // r8
  int v41; // r1
  int v42; // r2
  int v43; // r3
  int v44; // r1
  int v45; // r2
  int v46; // r3
  _DWORD *v47; // r1
  unsigned int v48; // r6
  _BYTE *v49; // r2
  int v51; // [sp+8h] [bp-48h]
  int v52; // [sp+Ch] [bp-44h]
  int v53; // [sp+Ch] [bp-44h]
  unsigned int v54; // [sp+14h] [bp-3Ch]
  _DWORD *v56; // [sp+20h] [bp-30h]
  int *v57; // [sp+28h] [bp-28h]
  unsigned int v58; // [sp+28h] [bp-28h]
  unsigned int v59; // [sp+2Ch] [bp-24h]

  v3 = a3;
  v4 = *a3;
  v5 = a2;
  v54 = *a3;
  v6 = 0;
  v7 = EtwpFindGuidEntryByGuid(a1, 0);
  if ( !v7 )
    return -1073741163;
  memset(v5, 0, *v3);
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v9 = *(int **)(v7 + 28);
  v10 = 8;
  v11 = v7 + 28;
  while ( v9 != (int *)v11 )
  {
    v57 = v9;
    v59 = v10;
    v12 = &v5[v10];
    v10 += 16;
    v13 = &v5[v10];
    v14 = 0;
    ++v6;
    v15 = 0;
    v56 = v12;
    v52 = 0;
    if ( (*((_BYTE *)v9 + 50) & 8) != 0 )
    {
      v14 = 1;
      v11 = v7 + 28;
      if ( (*(_BYTE *)(v7 + 51) & 1) != 0 )
      {
        v10 += 32;
        v15 = 1;
        if ( v10 <= v4 )
        {
          *(_DWORD *)v13 = 1;
          v13[4] = *(_BYTE *)(v7 + 50);
          *((_DWORD *)v13 + 4) = *(_DWORD *)(v7 + 40);
          *((_DWORD *)v13 + 5) = *(_DWORD *)(v7 + 44);
          *((_WORD *)v13 + 3) = *(_WORD *)(v7 + 48);
        }
      }
    }
    else if ( *((_BYTE *)v9 + 51) || *((_BYTE *)v9 + 52) )
    {
      v16 = 0;
      v17 = &v5[v10];
      v51 = 0;
      for ( i = 0; i < 0x100; i += 32 )
      {
        v19 = (_DWORD *)(i + v7);
        if ( *(_DWORD *)(i + v7 + 88) )
        {
          if ( ((1 << v16) & *((unsigned __int8 *)v9 + 51)) != 0 )
          {
            ++v15;
            v10 += 32;
            v52 = v15;
            if ( v10 <= v54 )
            {
              v20 = v19[23];
              v21 = v19[24];
              v22 = v19[25];
              *v17 = v19[22];
              v17[1] = v20;
              v17[2] = v21;
              v17[3] = v22;
              v23 = v19[27];
              v24 = v19[28];
              v25 = v19[29];
              v17[4] = v19[26];
              v17[5] = v23;
              v17[6] = v24;
              v17[7] = v25;
              v15 = v52;
              v17 += 8;
            }
          }
          v16 = v51;
        }
        v26 = v9[5];
        if ( v26 )
        {
          v27 = (_DWORD *)(i + v26);
          if ( *(_DWORD *)(i + v26 + 88) )
          {
            if ( ((1 << v16) & (unsigned __int8)v9[13]) != 0 )
            {
              v10 += 32;
              v52 = v15 + 1;
              if ( v10 <= v54 )
              {
                v28 = v27[23];
                v29 = v27[24];
                v30 = v27[25];
                *v17 = v27[22];
                v17[1] = v28;
                v17[2] = v29;
                v17[3] = v30;
                v31 = v27[27];
                v32 = v27[28];
                v33 = v27[29];
                v17[4] = v27[26];
                v17[5] = v31;
                v17[6] = v32;
                v17[7] = v33;
                v17 += 8;
              }
            }
            v16 = v51;
          }
        }
        ++v16;
        v15 = v52;
        v51 = v16;
      }
      v4 = v54;
      v5 = a2;
      v12 = v56;
      v14 = 0;
      v11 = v7 + 28;
    }
    v9 = (int *)*v9;
    if ( v10 <= v4 )
    {
      if ( v14 == 1 )
        v12[3] = 1;
      if ( (*((_BYTE *)v57 + 50) & 2) != 0 )
        v34 = *(_DWORD *)(v57[10] + 176);
      else
        v34 = 0;
      v12[1] = v15;
      v12[2] = v34;
      if ( v9 == (int *)v11 )
      {
        *v12 = 0;
        break;
      }
      *v12 = v10 - v59;
    }
  }
  KeReleaseMutex((int)&EtwpNotificationMutex);
  if ( !v6 )
  {
    v58 = v10;
    v35 = &v5[v10];
    v36 = v10 + 16;
    v37 = 8;
    v38 = &v5[v36];
    v39 = 0;
    v40 = (_DWORD *)v7;
    v53 = 8;
    do
    {
      if ( v40[22] )
      {
        v36 += 32;
        ++v39;
        if ( v36 <= v4 )
        {
          v41 = v40[23];
          v42 = v40[24];
          v43 = v40[25];
          *v38 = v40[22];
          v38[1] = v41;
          v38[2] = v42;
          v38[3] = v43;
          v44 = v40[27];
          v45 = v40[28];
          v46 = v40[29];
          v38[4] = v40[26];
          v38[5] = v44;
          v38[6] = v45;
          v38[7] = v46;
          v4 = v54;
          v37 = v53;
          v38 += 8;
        }
      }
      v53 = --v37;
      v40 += 8;
    }
    while ( v37 );
    v5 = a2;
    if ( v36 <= v4 )
    {
      v35[1] = v39;
      v35[2] = 0;
      *v35 = v36 - v58;
      v35[3] = 2;
    }
    v47 = &a2[v36];
    v48 = v36 + 16;
    v49 = &a2[v48];
    v10 = v48 + 32;
    v6 = 2;
    if ( v10 <= v4 )
    {
      v47[2] = 0;
      v47[3] = 3;
      *v47 = 0;
      v47[1] = 0;
      *(_DWORD *)v49 = *(_BYTE *)(v7 + 51) & 1;
      if ( (*(_BYTE *)(v7 + 51) & 1) != 0 )
      {
        v47[1] = 1;
        v49[4] = *(_BYTE *)(v7 + 50);
        *((_DWORD *)v49 + 4) = *(_DWORD *)(v7 + 40);
        *((_DWORD *)v49 + 5) = *(_DWORD *)(v7 + 44);
        *((_WORD *)v49 + 3) = *(_WORD *)(v7 + 48);
      }
    }
  }
  EtwpUnreferenceGuidEntry(v7);
  if ( v10 > v4 )
  {
    v8 = -1073741789;
  }
  else
  {
    *(_DWORD *)v5 = v6;
    v8 = 0;
  }
  *a3 = v10;
  return v8;
}
