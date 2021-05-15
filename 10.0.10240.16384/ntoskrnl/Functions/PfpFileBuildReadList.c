// PfpFileBuildReadList 
 
int __fastcall PfpFileBuildReadList(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v8; // r1
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r3
  unsigned __int64 v12; // kr00_8
  _DWORD *v13; // r0
  unsigned int v14; // r1
  int v15; // r4
  int v16; // r3
  unsigned int v17; // r6
  unsigned int v18; // lr
  unsigned int v19; // r2
  unsigned __int64 v20; // r6
  _DWORD *v21; // r3

  if ( (*a2 & 1) != 0 && !a3 )
    return sub_80EE00();
  v8 = a2[4];
  v9 = 0;
  if ( v8 )
  {
    v10 = a2[5];
    do
    {
      v11 = *(_DWORD *)(v10 + 8);
      v10 += 16;
      v9 += (v11 >> 12) + 2;
      --v8;
    }
    while ( v8 );
  }
  v12 = 8 * v9 + __PAIR64__(v9 >> 29, 16);
  if ( HIDWORD(v12) )
    return -1073741675;
  v13 = (_DWORD *)ExAllocatePoolWithTag(1, v12, 1280468560);
  if ( !v13 )
    return -1073741670;
  *v13 = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  if ( (*a2 & 1) != 0 )
    v13[2] = 1;
  v14 = 0;
  if ( a2[4] )
  {
    v15 = 0;
    do
    {
      v16 = a2[5];
      v17 = *(_DWORD *)(v16 + v15);
      v18 = *(_DWORD *)(v16 + v15 + 4);
      v19 = v17;
      if ( (*(_DWORD *)(*(_DWORD *)a1 + 56) & 2) != 0 )
        v19 = v17 & 0xFFFFF000;
      v20 = __PAIR64__(v18, v17) + *(unsigned int *)(v16 + v15 + 8);
      if ( v18 > HIDWORD(v20) )
        goto LABEL_20;
      if ( v18 < HIDWORD(v20) )
        goto LABEL_18;
      while ( v19 < (unsigned int)v20 )
      {
        do
        {
LABEL_18:
          v21 = &v13[2 * v13[1]];
          v21[4] = v19;
          v21[5] = v18;
          v18 = (__PAIR64__(v18, v19) + 4096) >> 32;
          v19 += 4096;
          ++v13[1];
        }
        while ( v18 < HIDWORD(v20) );
        if ( v18 > HIDWORD(v20) )
          break;
      }
LABEL_20:
      ++v14;
      v15 += 16;
    }
    while ( v14 < a2[4] );
  }
  *a4 = v13;
  return 0;
}
