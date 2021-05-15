// ProducerConsumerCopyFromContextBuffer 
 
int __fastcall ProducerConsumerCopyFromContextBuffer(int a1, unsigned int a2, int *a3, int a4)
{
  __int64 v4; // kr00_8
  unsigned int v6; // r7
  unsigned int v7; // r1
  int result; // r0

  v4 = *(_QWORD *)a3;
  v6 = 0;
  v7 = a4 - *a3;
  if ( v7 >= a3[1] )
  {
    v7 -= HIDWORD(v4);
    a4 -= HIDWORD(v4);
  }
  if ( v7 + a2 > HIDWORD(v4) )
  {
    v6 = v7 - HIDWORD(v4) + a2;
    a2 = HIDWORD(v4) - v7;
  }
  result = memmove(a1, a4, a2);
  if ( v6 )
    result = memmove(a1 + a2, *a3, v6);
  return result;
}
