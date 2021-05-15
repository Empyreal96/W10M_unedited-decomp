// ExFastReplenishHandleTableEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExFastReplenishHandleTableEntry(unsigned __int64 *a1, unsigned int *a2, int a3)
{
  unsigned int v3; // lr
  unsigned int v5; // r7
  int result; // r0
  int v7; // r4
  int v8; // r9
  unsigned int v9; // r3 OVERLAPPED
  unsigned int v10; // r4 OVERLAPPED
  unsigned __int64 v11; // kr08_8

  v3 = *a2;
  do
  {
    v5 = *a2;
    result = 0;
    v7 = a3 + (a2[1] >> 27);
    if ( v7 > 31 )
      return sub_51DBFC(0);
    v8 = a2[1] & 0x7FFFFFF | (v7 << 27);
    *(_QWORD *)&v9 = *(_QWORD *)a2;
    do
      v11 = __ldrexd(a1);
    while ( v11 == __PAIR64__(v10, v9) && __strexd(__PAIR64__(v8, v5), a1) );
    if ( v11 == *(_QWORD *)a2 )
      return result;
    *(_QWORD *)a2 = v11;
  }
  while ( (unsigned int)v11 >> 3 == v3 >> 3 && (v11 & 1) != 0 );
  *a2 = v5;
  a2[1] = v8;
  return a3;
}
