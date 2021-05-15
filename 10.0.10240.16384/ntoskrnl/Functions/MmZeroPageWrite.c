// MmZeroPageWrite 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MmZeroPageWrite(int a1, int a2, int a3, int a4)
{
  int v4; // r5 OVERLAPPED
  int result; // r0

  *(_QWORD *)&v4 = *(_QWORD *)a3;
  result = 0;
  if ( *(_DWORD *)(a3 + 4) )
    return sub_52759C(0);
  if ( v4 )
    result = MiZeroPageWrite(a1, a2, v4, a4);
  return result;
}
