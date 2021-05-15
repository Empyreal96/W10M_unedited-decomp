// StLcInitialize 
 
int __fastcall StLcInitialize(unsigned int *a1, int a2, unsigned int a3)
{
  __int64 v5; // r0
  unsigned int *v6; // r7
  unsigned int v7; // r8
  unsigned int v8; // r9
  _DWORD v10[2]; // [sp+0h] [bp-30h] BYREF
  char v11[40]; // [sp+8h] [bp-28h] BYREF

  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  LODWORD(v5) = KeQueryPerformanceCounter(v11, v10);
  v6 = (unsigned int *)a3;
  if ( a3 < a3 + 128 )
  {
    v8 = v10[0];
    v7 = v10[1];
    do
    {
      LODWORD(v5) = _rt_sdiv64(1000000i64, __PAIR64__(v7, v8) * *v6);
      *(_QWORD *)v6 = v5;
      v6[2] = 0;
      v6 += 4;
    }
    while ( (unsigned int)v6 < a3 + 128 );
  }
  *(_DWORD *)(a3 + 112) = -1;
  *(_DWORD *)(a3 + 116) = -1;
  a1[1] = 8;
  a1[2] = a3;
  *a1 = a3;
  return v5;
}
