// RtlExpandHashTable 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlExpandHashTable(_DWORD *a1)
{
  unsigned int v2; // r2
  unsigned int v4; // r7
  int v5; // r8
  int v6; // r6
  _BYTE *v7; // r0
  _DWORD *v8; // r5
  _DWORD *v9; // r6
  int v10; // r5
  int v11; // r0
  __int64 v12; // kr00_8
  _DWORD *v13; // r0
  int v14; // r1
  _DWORD *v15; // r6
  _DWORD *v16; // r7
  _DWORD *v17; // r5
  int v18; // r1
  int v19; // r1 OVERLAPPED
  _DWORD *v20; // r2 OVERLAPPED
  _DWORD *v21; // r2
  __int64 v22; // kr08_8

  v2 = a1[2];
  if ( v2 == 0x10000 || a1[7] )
    return 0;
  v4 = v2 >> 7;
  v5 = a1[2] & 0x7F;
  if ( v2 == 128 )
  {
    v6 = a1[8];
    v7 = (_BYTE *)ExAllocatePoolWithTag(512, 2048);
    v8 = v7;
    if ( !v7 )
      return 0;
    memset(v7, 0, 2048);
    *v8 = v6;
    a1[8] = v8;
  }
  v9 = (_DWORD *)a1[8];
  v10 = v9[v4];
  if ( !v10 )
  {
    v11 = RtlpAllocateSecondLevelDir();
    v10 = v11;
    if ( !v11 )
    {
      if ( a1[2] == 128 )
      {
        a1[8] = *v9;
        ExFreePoolWithTag(v9);
      }
      return 0;
    }
    v9[v4] = v11;
  }
  v12 = *((_QWORD *)a1 + 1);
  a1[2] = v12 + 1;
  v13 = (_DWORD *)RtlpGetChainHead((int)a1, SBYTE4(v12), v2);
  a1[3] = v14 + 1;
  v15 = (_DWORD *)(v10 + 8 * v5);
  if ( (_DWORD *)*v13 != v13 )
  {
    v16 = v13;
    do
    {
      v17 = (_DWORD *)*v16;
      v18 = *(_DWORD *)(*v16 + 8) >> a1[1];
      if ( (((69069 * v18 + 1) & 0xFFFF0000 | ((unsigned int)(1103515245 * v18 + 12345) >> 16)) & ((2 * a1[4]) | 1)) == a1[2] - 1 )
      {
        *(_QWORD *)&v19 = *(_QWORD *)v17;
        if ( *(_DWORD **)(*v17 + 4) != v17 || (_DWORD *)*v20 != v17 )
          __fastfail(3u);
        *v20 = v19;
        *(_DWORD *)(v19 + 4) = v20;
        v21 = (_DWORD *)v15[1];
        *v17 = v15;
        v17[1] = v21;
        if ( (_DWORD *)*v21 != v15 )
          __fastfail(3u);
        *v21 = v17;
        v15[1] = v17;
      }
      else
      {
        v16 = (_DWORD *)*v16;
      }
    }
    while ( (_DWORD *)*v16 != v13 );
    if ( (_DWORD *)*v15 != v15 )
      ++a1[6];
    if ( (_DWORD *)*v13 == v13 )
      --a1[6];
  }
  v22 = *(_QWORD *)(a1 + 3);
  if ( (_DWORD)v22 == HIDWORD(v22) + 1 )
  {
    a1[4] = (2 * HIDWORD(v22)) | 1;
    a1[3] = 0;
  }
  return 1;
}
