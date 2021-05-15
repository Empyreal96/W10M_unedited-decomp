// sub_96B520 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall sub_96B520(int a1, int a2, int a3, int a4, int a5)
{
  _BYTE *v5; // r4
  int v6; // r5
  int v7; // r6
  unsigned int v8; // r0
  int v9; // r1 OVERLAPPED
  int (__fastcall *v11)(int); // [sp+24h] [bp-4h]

  while ( 1 )
  {
    v8 = a5;
    if ( (int *)a5 == &a5 )
      break;
    *(_QWORD *)&v9 = *(_QWORD *)a5;
    if ( *(int **)(a5 + 4) != &a5 || *(_DWORD *)(v9 + 4) != a5 )
      __fastfail(3u);
    a5 = v9;
    *(_DWORD *)(v9 + 4) = &a5;
    *(_DWORD *)(v7 + 8) = *(_DWORD *)(v8 + 8);
    v7 += 8;
    *(_DWORD *)(v7 + 4) = *(_DWORD *)(v8 + 12);
    *v5 = *(_BYTE *)(v8 + 16);
    v5[1] = *(_BYTE *)(v8 + 17);
    v5 += 2;
    ExFreePoolWithTag(v8);
  }
  return v11(v6);
}
