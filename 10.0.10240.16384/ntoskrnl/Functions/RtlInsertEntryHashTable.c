// RtlInsertEntryHashTable 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlInsertEntryHashTable(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v6; // r5
  int *v7; // r2 OVERLAPPED
  int v8; // r1 OVERLAPPED
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  *(_DWORD *)(a2 + 8) = a3;
  v6 = a4;
  ++*(_DWORD *)(a1 + 20);
  if ( a4 )
  {
    if ( !*a4 )
      return sub_52AF9C();
  }
  else
  {
    RtlpPopulateContext(a1, v10, a3, 0);
    v6 = v10;
  }
  if ( *(_DWORD *)*v6 == *v6 )
    ++*(_DWORD *)(a1 + 24);
  v7 = (int *)v6[1];
  v8 = *v7;
  *(_QWORD *)a2 = *(_QWORD *)&v8;
  if ( *(int **)(v8 + 4) != v7 )
    __fastfail(3u);
  *(_DWORD *)(v8 + 4) = a2;
  *v7 = a2;
  return 1;
}
