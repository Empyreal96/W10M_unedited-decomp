// PspSubtractAccountingValues 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspSubtractAccountingValues(int result, _QWORD *a2)
{
  unsigned int v2; // r3 OVERLAPPED
  unsigned int v3; // r4 OVERLAPPED
  unsigned int v4; // r3 OVERLAPPED
  unsigned int v5; // r4 OVERLAPPED
  unsigned __int64 v6; // kr08_8
  unsigned int v7; // r3 OVERLAPPED
  unsigned int v8; // r4 OVERLAPPED
  unsigned __int64 v9; // kr10_8
  unsigned int v10; // r3 OVERLAPPED
  unsigned int v11; // r4 OVERLAPPED
  __int64 v12; // kr18_8
  unsigned int v13; // r3 OVERLAPPED
  unsigned int v14; // r4 OVERLAPPED
  __int64 v15; // kr20_8
  unsigned int v16; // r3 OVERLAPPED
  unsigned int v17; // r4 OVERLAPPED
  __int64 v18; // kr28_8
  unsigned int v19; // r3 OVERLAPPED
  unsigned int v20; // r4 OVERLAPPED
  __int64 v21; // kr30_8
  unsigned int v22; // r3 OVERLAPPED
  unsigned int v23; // r4 OVERLAPPED
  __int64 v24; // kr38_8
  __int64 v25; // kr40_8
  __int64 v26; // kr48_8

  *(_QWORD *)&v2 = *a2;
  if ( *a2 > *(_QWORD *)result )
  {
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 4) = 0;
  }
  else
  {
    *(_QWORD *)result -= __PAIR64__(v3, v2);
  }
  *(_QWORD *)&v4 = a2[1];
  v6 = *(_QWORD *)(result + 8);
  if ( *(_QWORD *)&v4 > v6 )
  {
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 0;
  }
  else
  {
    *(_QWORD *)(result + 8) = v6 - __PAIR64__(v5, v4);
  }
  *(_QWORD *)&v7 = a2[2];
  v9 = *(_QWORD *)(result + 16);
  if ( *(_QWORD *)&v7 > v9 )
  {
    *(_DWORD *)(result + 16) = 0;
    *(_DWORD *)(result + 20) = 0;
  }
  else
  {
    *(_QWORD *)(result + 16) = v9 - __PAIR64__(v8, v7);
  }
  *(_QWORD *)&v10 = a2[4];
  v12 = *(_QWORD *)(result + 32);
  if ( *(__int64 *)&v10 > v12 )
  {
    *(_DWORD *)(result + 32) = 0;
    *(_DWORD *)(result + 36) = 0;
  }
  else
  {
    *(_QWORD *)(result + 32) = v12 - __PAIR64__(v11, v10);
  }
  *(_QWORD *)&v13 = a2[5];
  v15 = *(_QWORD *)(result + 40);
  if ( *(__int64 *)&v13 > v15 )
  {
    *(_DWORD *)(result + 40) = 0;
    *(_DWORD *)(result + 44) = 0;
  }
  else
  {
    *(_QWORD *)(result + 40) = v15 - __PAIR64__(v14, v13);
  }
  *(_QWORD *)&v16 = a2[6];
  v18 = *(_QWORD *)(result + 48);
  if ( *(__int64 *)&v16 > v18 )
  {
    *(_DWORD *)(result + 48) = 0;
    *(_DWORD *)(result + 52) = 0;
  }
  else
  {
    *(_QWORD *)(result + 48) = v18 - __PAIR64__(v17, v16);
  }
  *(_QWORD *)&v19 = a2[7];
  v21 = *(_QWORD *)(result + 56);
  if ( *(__int64 *)&v19 > v21 )
  {
    *(_DWORD *)(result + 56) = 0;
    *(_DWORD *)(result + 60) = 0;
  }
  else
  {
    *(_QWORD *)(result + 56) = v21 - __PAIR64__(v20, v19);
  }
  *(_QWORD *)&v22 = a2[8];
  v24 = *(_QWORD *)(result + 64);
  if ( *(__int64 *)&v22 > v24 )
  {
    *(_DWORD *)(result + 64) = 0;
    *(_DWORD *)(result + 68) = 0;
  }
  else
  {
    *(_QWORD *)(result + 64) = v24 - __PAIR64__(v23, v22);
  }
  v25 = a2[9];
  v26 = *(_QWORD *)(result + 72);
  if ( v25 > v26 )
  {
    *(_DWORD *)(result + 72) = 0;
    *(_DWORD *)(result + 76) = 0;
  }
  else
  {
    *(_QWORD *)(result + 72) = v26 - v25;
  }
  return result;
}
