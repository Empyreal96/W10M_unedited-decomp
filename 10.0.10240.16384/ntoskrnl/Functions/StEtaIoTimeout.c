// StEtaIoTimeout 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall StEtaIoTimeout(int a1, int a2, int a3, int a4, unsigned __int64 a5)
{
  int v6; // r0
  unsigned __int64 v7; // r0
  int *v8; // r2
  int v9; // r3 OVERLAPPED
  int v10; // r4 OVERLAPPED
  int v11; // t1
  __int64 v13; // [sp+0h] [bp-18h] BYREF
  char v14[16]; // [sp+8h] [bp-10h] BYREF

  KeQueryPerformanceCounter(v14, &v13);
  v6 = _rt_udiv64(10i64, a5);
  LODWORD(v7) = _rt_sdiv64(1000000i64, v13 * (unsigned int)v6);
  v8 = *(int **)(a1 + 16);
  do
  {
    *(_QWORD *)&v9 = *((_QWORD *)v8 + 1);
    if ( v7 > *(_QWORD *)&v9 )
    {
      v10 = HIDWORD(v7);
      v9 = v7;
    }
    *((_QWORD *)v8 + 1) = *(_QWORD *)&v9;
    v11 = *v8;
    v8 += 8;
  }
  while ( v11 != -1 );
  return v7;
}
