// EtwpGetTraceGroupInfo 
 
int __fastcall EtwpGetTraceGroupInfo(unsigned int a1, _BYTE *a2, int *a3)
{
  int *v3; // r5
  unsigned int v5; // r10
  int v6; // r9
  int v7; // r4
  int v8; // r4
  unsigned int v9; // r6
  int v10; // r3
  _DWORD *v11; // r7
  _DWORD *v12; // lr
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r6
  _DWORD *v20; // r5
  _DWORD *v21; // lr
  unsigned int v22; // r7
  int v23; // r1
  int v24; // r2
  int v25; // r3
  _DWORD *v26; // r4
  unsigned int v27; // r7
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v32; // [sp+8h] [bp-30h]
  _DWORD *v33; // [sp+8h] [bp-30h]
  int v34; // [sp+Ch] [bp-2Ch]
  int *v35; // [sp+10h] [bp-28h]

  v3 = a3;
  v5 = *a3;
  v6 = 0;
  v7 = EtwpFindGuidEntryByGuid(a1, 2);
  v34 = v7;
  if ( !v7 )
    return -1073741163;
  memset(a2, 0, *v3);
  KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v9 = 4;
  if ( v5 >= 4 )
    *(_DWORD *)a2 = 8;
  v10 = 8;
  v32 = 8;
  v11 = a2 + 4;
  v12 = (_DWORD *)v7;
  do
  {
    v9 += 32;
    if ( v9 <= v5 )
    {
      v13 = v12[23];
      v14 = v12[24];
      v15 = v12[25];
      *v11 = v12[22];
      v11[1] = v13;
      v11[2] = v14;
      v11[3] = v15;
      v16 = v12[27];
      v17 = v12[28];
      v18 = v12[29];
      v11[4] = v12[26];
      v11[5] = v16;
      v11[6] = v17;
      v11[7] = v18;
      v10 = v32;
      v11 += 8;
    }
    v32 = --v10;
    v12 += 8;
  }
  while ( v10 );
  v35 = (int *)&a2[v9];
  v19 = v9 + 4;
  v20 = &a2[v19];
  v21 = *(_DWORD **)(v7 + 28);
  v33 = &a2[v19];
  v22 = 0;
  if ( v21 != (_DWORD *)(v7 + 28) )
  {
    do
    {
      v19 += 16;
      ++v22;
      if ( v19 <= v5 )
      {
        v23 = *(_DWORD *)(v21[2] + 16);
        v24 = *(_DWORD *)(v21[2] + 20);
        v25 = *(_DWORD *)(v21[2] + 24);
        *v33 = *(_DWORD *)(v21[2] + 12);
        v33[1] = v23;
        v33[2] = v24;
        v33[3] = v25;
        v33 += 4;
      }
      v21 = (_DWORD *)*v21;
    }
    while ( v21 != (_DWORD *)(v7 + 28) );
    v6 = 0;
  }
  if ( v19 > v5 )
  {
    v8 = -1073741789;
  }
  else
  {
    if ( v22 == 1 )
    {
      v6 = 1;
    }
    else if ( v22 > 1 )
    {
      qsort((unsigned int)v20, v22, 0x10u, (int (__fastcall *)(unsigned int, _BYTE *))EtwpCompareGuid);
      v26 = v20 + 4;
      v6 = 1;
      v27 = v22 - 1;
      do
      {
        if ( memcmp((unsigned int)v26, (unsigned int)v20, 16) )
        {
          v20 += 4;
          if ( v20 != v26 )
          {
            v28 = v26[1];
            v29 = v26[2];
            v30 = v26[3];
            *v20 = *v26;
            v20[1] = v28;
            v20[2] = v29;
            v20[3] = v30;
          }
          ++v6;
        }
        v26 += 4;
        --v27;
      }
      while ( v27 );
    }
    v8 = 0;
    *v35 = v6;
  }
  KeReleaseMutex((int)&EtwpNotificationMutex);
  EtwpUnreferenceGuidEntry(v34);
  *a3 = v19;
  return v8;
}
