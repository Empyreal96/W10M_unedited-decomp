// ViDeadlockRemoveNode 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ViDeadlockRemoveNode(_DWORD *a1, int a2)
{
  _DWORD *v3; // r2
  __int64 v4; // r0 OVERLAPPED
  int *v5; // r0
  int *v6; // r6
  int *v7; // r1
  __int64 v8; // kr00_8
  int v9; // r2
  int **v10; // r6
  __int64 v11; // r0
  _DWORD *v12; // r2 OVERLAPPED
  _QWORD *v13; // r1
  _QWORD *v14; // r5
  _DWORD *v15; // r0
  _QWORD *v16; // r2
  __int64 v17; // kr08_8

  if ( a2 )
  {
    v3 = a1 + 5;
    v4 = *(_QWORD *)(a1 + 5);
    if ( *(_DWORD **)(v4 + 4) != v3 || *(_DWORD **)HIDWORD(v4) != v3 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  }
  else
  {
    if ( *a1 )
    {
      v5 = (int *)a1[1];
      while ( v5 != a1 + 1 )
      {
        v6 = v5 - 3;
        v7 = v5;
        v8 = *(_QWORD *)v5;
        v5 = (int *)*v5;
        if ( *(int **)(v8 + 4) != v7 || *(int **)HIDWORD(v8) != v7 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v8) = v8;
        *(_DWORD *)(v8 + 4) = HIDWORD(v8);
        a1[10] = a1[10] - v6[10] - 1;
        *v6 = *a1;
        v9 = *a1 + 4;
        v10 = *(int ***)(*a1 + 8);
        *v7 = v9;
        v7[1] = (int)v10;
        if ( *v10 != (int *)v9 )
          __fastfail(3u);
        *v10 = v7;
        *(_DWORD *)(v9 + 4) = v7;
      }
      v11 = *(_QWORD *)(a1 + 3);
      if ( *(_DWORD **)(v11 + 4) != a1 + 3 || *(_DWORD **)HIDWORD(v11) != a1 + 3 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v11) = v11;
      *(_DWORD *)(v11 + 4) = HIDWORD(v11);
      ViDeadlockUpdateChildrenCount(*a1, -1);
    }
    else
    {
      v13 = (_QWORD *)a1[1];
      v14 = a1 + 1;
      if ( v13 != (_QWORD *)(a1 + 1) )
      {
        do
        {
          v15 = (_DWORD *)v13 - 3;
          v16 = v13;
          v17 = *v13;
          v13 = *(_QWORD **)v13;
          if ( *(_QWORD **)(v17 + 4) != v16 || *(_QWORD **)HIDWORD(v17) != v16 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v17) = v17;
          *(_DWORD *)(v17 + 4) = HIDWORD(v17);
          a1[10] = a1[10] - v15[10] - 1;
          *v15 = 0;
          v15[3] = 0;
          v15[4] = 0;
        }
        while ( v13 != v14 );
      }
    }
    LODWORD(v4) = a1 + 5;
    *(_WORD *)(a1[7] + 4) = *(_DWORD *)(a1[7] + 4) - 1;
    *(__int64 *)((char *)&v4 + 4) = *(_QWORD *)(a1 + 5);
    if ( *(_DWORD **)(HIDWORD(v4) + 4) != a1 + 5 || *v12 != (_DWORD)v4 )
      __fastfail(3u);
    *v12 = HIDWORD(v4);
    *(_DWORD *)(HIDWORD(v4) + 4) = v12;
  }
  return v4;
}
