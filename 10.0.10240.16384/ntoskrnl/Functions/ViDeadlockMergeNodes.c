// ViDeadlockMergeNodes 
 
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall ViDeadlockMergeNodes(_DWORD *a1, int a2, int *a3)
{
  int v3; // r3
  int v7; // r4
  int v8; // r5
  int v9; // r6
  int v10; // r4
  int v11; // r5
  int v12; // r6
  int v13; // r3
  int v14; // r4
  int v15; // r5
  int v16; // r6
  _DWORD *v17; // r7
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r2
  _QWORD *v23; // r5
  _DWORD *v24; // r6
  _DWORD *v25; // r4
  int v26; // r1 OVERLAPPED
  _DWORD *v27; // r2 OVERLAPPED
  _DWORD *v28; // r1
  __int64 v29; // kr00_8
  __int64 result; // r0
  int v31; // r3

  v3 = *(_DWORD *)(a2 + 32);
  if ( v3 )
  {
    a1[8] = v3;
    v7 = *(_DWORD *)(a2 + 48);
    v8 = *(_DWORD *)(a2 + 52);
    v9 = *(_DWORD *)(a2 + 56);
    a1[11] = *(_DWORD *)(a2 + 44);
    a1[12] = v7;
    a1[13] = v8;
    a1[14] = v9;
    v10 = *(_DWORD *)(a2 + 64);
    v11 = *(_DWORD *)(a2 + 68);
    v12 = *(_DWORD *)(a2 + 72);
    a1[15] = *(_DWORD *)(a2 + 60);
    a1[16] = v10;
    a1[17] = v11;
    a1[18] = v12;
    v13 = *(_DWORD *)(a2 + 80);
    v14 = *(_DWORD *)(a2 + 84);
    v15 = *(_DWORD *)(a2 + 88);
    v16 = a2 + 92;
    a1[19] = *(_DWORD *)(a2 + 76);
    a1[20] = v13;
    a1[21] = v14;
    a1[22] = v15;
    v17 = a1 + 23;
    v18 = *(_DWORD *)(a2 + 92);
    v19 = *(_DWORD *)(a2 + 96);
    v20 = *(_DWORD *)(v16 + 8);
    v21 = *(_DWORD *)(v16 + 12);
    *v17 = v18;
    v17[1] = v19;
    v17[2] = v20;
    v17[3] = v21;
  }
  v22 = *(_DWORD *)(a2 + 36) & 1;
  if ( v22 )
    a1[9] = a1[9] & 0xFFFFFFFE | v22;
  v23 = *(_QWORD **)(a2 + 4);
  while ( v23 != (_QWORD *)(a2 + 4) )
  {
    v24 = (_DWORD *)v23 - 3;
    v25 = v23;
    *(_QWORD *)&v26 = *v23;
    v23 = *(_QWORD **)v23;
    if ( *(_DWORD **)(v26 + 4) != v25 || (_DWORD *)*v27 != v25 )
      __fastfail(3u);
    *v27 = v26;
    *(_DWORD *)(v26 + 4) = v27;
    ViDeadlockUpdateChildrenCount(a2, -1 - v24[10]);
    *v24 = a1;
    v28 = (_DWORD *)a1[2];
    *v25 = a1 + 1;
    v25[1] = v28;
    if ( (_DWORD *)*v28 != a1 + 1 )
      __fastfail(3u);
    *v28 = v25;
    a1[2] = v25;
    ViDeadlockUpdateChildrenCount(a1, v24[10] + 1);
  }
  if ( *(_DWORD *)a2 )
  {
    v29 = *(_QWORD *)(a2 + 12);
    if ( *(_DWORD *)(v29 + 4) != a2 + 12 || *(_DWORD *)HIDWORD(v29) != a2 + 12 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v29) = v29;
    *(_DWORD *)(v29 + 4) = HIDWORD(v29);
    ViDeadlockUpdateChildrenCount(*(_DWORD *)a2, -1);
  }
  *(_WORD *)(*(_DWORD *)(a2 + 28) + 4) = *(_DWORD *)(*(_DWORD *)(a2 + 28) + 4) - 1;
  result = *(_QWORD *)(a2 + 20);
  if ( *(_DWORD *)(result + 4) != a2 + 20 || *(_DWORD *)HIDWORD(result) != a2 + 20 )
    __fastfail(3u);
  v31 = *a3;
  *(_DWORD *)HIDWORD(result) = result;
  *(_DWORD *)(result + 4) = HIDWORD(result);
  *(_DWORD *)a2 = v31;
  *a3 = a2;
  return result;
}
