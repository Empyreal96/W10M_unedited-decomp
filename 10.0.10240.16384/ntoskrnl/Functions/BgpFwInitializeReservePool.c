// BgpFwInitializeReservePool 
 
// local variable allocation has failed, the output may be wrong!
int *__fastcall BgpFwInitializeReservePool(int a1, int a2, int a3)
{
  int *result; // r0

  dword_6416C8 = 0;
  dword_6416B8 = a1;
  result = &dword_6416BC;
  *(_QWORD *)&dword_6416BC = *(_QWORD *)&a2;
  dword_6416CC = a2;
  if ( a3 )
    result = (int *)RtlClearAllBits((int)&dword_6416BC);
  return result;
}
