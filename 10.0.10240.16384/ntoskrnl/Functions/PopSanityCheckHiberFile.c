// PopSanityCheckHiberFile 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopSanityCheckHiberFile(int a1, int a2, _QWORD *a3, int **a4, _DWORD *a5)
{
  int result; // r0
  unsigned int v9; // r7
  int v10; // r2
  unsigned int v11; // r5 OVERLAPPED
  unsigned int v12; // r6 OVERLAPPED
  unsigned int v13; // lr
  int *v14; // r4
  int *v15; // [sp+18h] [bp-28h]
  int v16; // [sp+20h] [bp-20h]

  result = ZwFsControlFile();
  if ( result == 259 )
  {
    KeWaitForSingleObject(a2 + 92, 0, 0, 0, 0);
    result = v16;
  }
  if ( result >= 0 )
  {
    v9 = 0;
    v10 = 0;
    *(_QWORD *)&v11 = *(_QWORD *)v15;
    v13 = 0;
    if ( *(_QWORD *)v15 )
    {
      v14 = v15;
      do
      {
        v13 = (__PAIR64__(v13, v9) + __PAIR64__(v12, v11)) >> 32;
        v9 += v11;
        if ( v14[3] < 0 )
          return -1073741823;
        v10 += 2;
        v14 = &v15[2 * v10];
        *(_QWORD *)&v11 = *(_QWORD *)v14;
      }
      while ( *(_QWORD *)v14 );
    }
    if ( __SPAIR64__(v13, v9) < *a3 )
      return -1073741823;
    *a4 = v15;
    *a5 = 8 * (v10 + 2);
  }
  return result;
}
