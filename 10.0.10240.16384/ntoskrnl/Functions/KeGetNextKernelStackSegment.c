// KeGetNextKernelStackSegment 
 
int __fastcall KeGetNextKernelStackSegment(_DWORD *a1, _DWORD *a2, int a3)
{
  _DWORD *v5; // r2
  _DWORD *v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3

  if ( a3 )
  {
    *a2 = a1[10];
    a2[1] = a1[9];
    a2[2] = a1[16];
    a2[3] = a1[8];
    return 1;
  }
  v5 = (_DWORD *)a2[3];
  if ( v5[2] )
  {
    v6 = v5 + 2;
    v7 = v5[2];
    v8 = v5[3];
    v9 = v5[4];
    v10 = v6[3];
    *a2 = v7;
    a2[1] = v8;
    a2[2] = v9;
    a2[3] = v10;
    return 1;
  }
  return 0;
}
