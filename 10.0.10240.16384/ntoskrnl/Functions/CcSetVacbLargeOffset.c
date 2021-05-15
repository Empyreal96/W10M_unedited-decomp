// CcSetVacbLargeOffset 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcSetVacbLargeOffset(int a1, int a2, unsigned int a3, int a4, unsigned int a5, int *a6)
{
  int *v6; // r9
  _DWORD *v7; // r6
  __int64 v8; // r4
  int v9; // lr
  int v11; // r7
  char v12; // r10
  __int64 v13; // r0
  char v14; // r10
  int v15; // r4
  int v16; // r2
  BOOL v17; // r5
  int v18; // r1
  int v19; // r1 OVERLAPPED
  _DWORD *v20; // r2 OVERLAPPED
  _DWORD *i; // r0
  int *v22; // r5
  int v23; // r1
  int v24; // r0
  int v25; // r2
  unsigned int v26; // r5
  int v27; // r10
  int j; // r5
  int v30; // r3
  bool v31; // zf
  int v32; // r2
  _DWORD *v33; // r3
  void *v34; // r0
  int v35; // [sp+8h] [bp-90h]
  int v36; // [sp+Ch] [bp-8Ch]
  int *v37; // [sp+10h] [bp-88h]
  unsigned int v38; // [sp+14h] [bp-84h]
  int v39[4]; // [sp+18h] [bp-80h] BYREF
  int v40; // [sp+28h] [bp-70h]
  unsigned int v41; // [sp+2Ch] [bp-6Ch]
  int v42; // [sp+30h] [bp-68h]
  _DWORD v43[24]; // [sp+38h] [bp-60h]

  v36 = a4;
  v6 = a6;
  v7 = *(_DWORD **)(a1 + 64);
  v8 = *(_QWORD *)(a1 + 24);
  v37 = a6;
  v38 = a3;
  v9 = a3;
  v40 = a4;
  v41 = a3;
  v35 = 0;
  v11 = 0;
  v12 = 25;
  do
  {
    v12 += 7;
    ++v11;
    LODWORD(v13) = 1 << v12;
    HIDWORD(v13) = 1 << (v12 - 32);
  }
  while ( v8 > v13 );
  v14 = v12 - 7;
  do
  {
    --v11;
    v42 = __SPAIR64__(a4, v9) >> v14;
    v15 = v7[v42];
    v43[v35 + 8] = v42;
    v43[v35++] = v7;
    if ( !v15 )
    {
      v16 = *(_DWORD *)(a1 + 96) & 0x200;
      v17 = v16 && !v11;
      if ( !v6 )
      {
        v39[1] = (int)v39;
        v39[0] = (int)v39;
        v39[2] = 0;
        v39[3] = 0;
        if ( !CcAllocateVacbLevels(v11 + 1, v16 != 0, v39) )
          return 0;
        v6 = v39;
        v37 = v39;
      }
      if ( v17 )
      {
        v15 = v6[2];
        v6[2] = 0;
        memset((_BYTE *)v15, 0, 512);
        *(_DWORD *)(v15 + 1024) = 0;
        *(_DWORD *)(v15 + 1028) = 0;
      }
      else
      {
        v15 = *v6;
        if ( (int *)*v6 == v6 )
          KeBugCheckEx(52, 4324, -1073740768, 0, 0);
        *(_QWORD *)&v19 = *(_QWORD *)v15;
        if ( *(_DWORD *)(*(_DWORD *)v15 + 4) != v15 || *v20 != v15 )
          __fastfail(3u);
        *v20 = v19;
        *(_DWORD *)(v19 + 4) = v20;
        --v6[3];
        memset((_BYTE *)v15, 0, 520);
      }
      *(_DWORD *)v15 = 0;
      if ( v17 )
      {
        for ( i = CcGetBcbListHeadLargeOffset((_DWORD *)a1, v18, v41, v40, 0);
              *(_WORD *)(i[1] - 16) == 765;
              i = (_DWORD *)i[1] )
        {
          ;
        }
        v22 = (int *)i[1];
        v23 = v15 + 512;
        i[1] = v15 + 512;
        *(_DWORD *)(v15 + 512) = i;
        v24 = 63;
        do
        {
          v25 = v23 + 8;
          *(_DWORD *)(v23 + 4) = v23 + 8;
          *(_DWORD *)(v23 + 8) = v23;
          v23 += 8;
          --v24;
        }
        while ( v24 );
        *(_DWORD *)(v25 + 4) = v22;
        *v22 = v25;
      }
      v7[v42] = v15;
      ReferenceVacbLevel(a1, v7, v11 + 1, 1, 0);
    }
    v9 = v38 & ((1 << v14) - 1);
    v7 = (_DWORD *)v15;
    a4 = v36 & ((__PAIR64__(1 << (v14 - 32), 1 << v14) - 1) >> 32);
    v36 = a4;
    v38 = v9;
    v14 -= 7;
  }
  while ( v11 );
  v26 = a5;
  if ( a5 >= 0xFFFFFFFE )
  {
    if ( a5 == -2 )
      v26 = 0;
    v27 = 1;
  }
  else
  {
    *(_DWORD *)(v15 + 4 * (__SPAIR64__(a4, v9) >> v14)) = a5;
    v27 = 0;
  }
  if ( v26 )
  {
    ReferenceVacbLevel(a1, v15, 0, 1, v27);
  }
  else
  {
    for ( j = v35; ; v7[v43[j + 8]] = 0 )
    {
      ReferenceVacbLevel(a1, v7, v11, -1, v27);
      v27 = 0;
      if ( v11 || (*(_DWORD *)(a1 + 96) & 0x200) == 0 )
        v30 = 0;
      else
        v30 = 128;
      if ( *(_QWORD *)&v7[v30 + 128] || !j )
        break;
      --j;
      v31 = v11++ == 0;
      if ( v31 && (*(_DWORD *)(a1 + 96) & 0x200) != 0 )
      {
        v32 = v7[128];
        v33 = (_DWORD *)v7[255];
        v34 = &CcVacbLevelWithBcbListHeadsLookasideList;
        *(_DWORD *)(v32 + 4) = v33;
        *v33 = v32;
      }
      else
      {
        v34 = &CcVacbLevelLookasideList;
      }
      ExFreeToNPagedLookasideList((int)v34, v7);
      v7 = (_DWORD *)v43[j];
    }
    v6 = v37;
  }
  if ( v6 == v39 )
    CcFreeUnusedVacbLevels(v6);
  return 1;
}
