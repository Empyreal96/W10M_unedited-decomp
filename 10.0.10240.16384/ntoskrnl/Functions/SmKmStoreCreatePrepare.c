// SmKmStoreCreatePrepare 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SmKmStoreCreatePrepare(_DWORD *a1, char a2, int *a3, int a4)
{
  _DWORD *v5; // r5 OVERLAPPED
  int v6; // r6 OVERLAPPED
  unsigned int v8; // r4
  int v9; // r3

  v5 = a1 + 1;
  v6 = 0;
  if ( (unsigned __int8)*a1 != 6 || (*a1 & 0xFFFFFC00) != 0 )
    return -1073741811;
  if ( a2 )
    return sub_7BFBC4();
  if ( !*(_BYTE *)v5 )
  {
    v8 = 0;
    v9 = 0;
LABEL_6:
    *(_QWORD *)a4 = *(_QWORD *)&v5;
    *(_DWORD *)(a4 + 8) = v8;
    *(_DWORD *)(a4 + 12) = v9;
    *a3 = v6;
    return 0;
  }
  v8 = a1[9];
  if ( !v8 || (v6 = SmAlloc(a1[9], 1262841203)) != 0 )
  {
    memmove(v6, v5[7], v8);
    v9 = v5[10];
    goto LABEL_6;
  }
  return -1073741670;
}
