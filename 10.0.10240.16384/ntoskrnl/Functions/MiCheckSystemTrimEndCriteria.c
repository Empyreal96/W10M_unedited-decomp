// MiCheckSystemTrimEndCriteria 
 
int __fastcall MiCheckSystemTrimEndCriteria(int a1, unsigned __int8 *a2, unsigned int a3)
{
  int v4; // r3
  int v5; // r5
  unsigned int v8; // r1
  unsigned int v9; // r2
  unsigned int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r1
  int v14; // r0
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r6
  unsigned int v20; // r0
  int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r1
  int v24; // r2
  int v25; // r3
  unsigned __int8 *v26; // r3
  int v27; // r2
  unsigned int v29; // r2
  unsigned int v30; // r3

  v4 = a2[2];
  v5 = *(_DWORD *)(a1 + 3512);
  if ( v4 == 3 || v4 == 2 )
  {
    v29 = *(_DWORD *)(v5 + 1228);
    if ( *((_DWORD *)a2 + 12) < v29 )
      v30 = v29 - *((_DWORD *)a2 + 10);
    else
      v30 = 0;
    *(_DWORD *)(v5 + 1228) = v30;
    return 1;
  }
  if ( (*a2 & 0x7Fu) >= 4 )
    return 1;
  v8 = *(_DWORD *)(a1 + 3712);
  v9 = *((_DWORD *)a2 + 9);
  if ( v8 >= v9 )
    return 1;
  v10 = *((_DWORD *)a2 + 1) + v8;
  if ( v10 < v8 || v10 >= v9 )
    return 1;
  if ( *((_DWORD *)a2 + 12) >= *((_DWORD *)a2 + 10) )
  {
    if ( v8 < 0x400 )
    {
      *((_DWORD *)a2 + 12) = 0;
      goto LABEL_10;
    }
    return 1;
  }
LABEL_10:
  *((_DWORD *)a2 + 1) = 0;
  v11 = 7;
  v12 = v5;
  do
  {
    *(_DWORD *)(v12 + 1256) = *(_DWORD *)&a2[v12 - v5 + 8];
    v12 += 4;
    --v11;
  }
  while ( v11 );
  v13 = 0;
  v14 = 2;
  v15 = v5 + 20;
  do
  {
    v16 = *(_DWORD *)(v15 + 1256);
    v15 += 4;
    v13 += v16;
    --v14;
  }
  while ( v14 );
  *(_DWORD *)(v5 + 1252) = v13;
  KeReleaseInStackQueuedSpinLock(a3);
  KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
  v17 = *(_DWORD *)(a1 + 3712);
  v18 = *((_DWORD *)a2 + 9);
  if ( v17 >= v18 )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, a3);
    return 1;
  }
  v19 = v18 - v17;
  v20 = 0;
  v21 = *a2 & 0x7F;
  v22 = *((unsigned __int8 *)MiTrimPassToAge + v21);
  if ( *((_BYTE *)MiTrimPassToAge + v21) )
    --v22;
  if ( v22 < 7 )
  {
    v23 = 7 - v22;
    v24 = v5 + 4 * v22;
    do
    {
      v25 = *(_DWORD *)(v24 + 1256);
      v24 += 4;
      v20 += v25;
      --v23;
    }
    while ( v23 );
  }
  v26 = a2 + 8;
  do
  {
    *(_DWORD *)v26 = 0;
    v26 += 4;
  }
  while ( v26 != a2 + 36 );
  if ( v20 < v19 + 256 || (v27 = *a2, (v27 & 0xFFFFFF80) != 0) )
    *a2 = *a2 & 0x80 | (*a2 + 1) & 0x7F;
  else
    *a2 = v27 | 0x80;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, a3);
  return 0;
}
