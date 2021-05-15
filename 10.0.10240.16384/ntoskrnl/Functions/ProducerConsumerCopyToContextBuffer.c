// ProducerConsumerCopyToContextBuffer 
 
int __fastcall ProducerConsumerCopyToContextBuffer(int a1, unsigned int a2, int *a3, unsigned int a4)
{
  unsigned int v5; // r1
  int v7; // r2
  unsigned int v9; // r7
  unsigned int v10; // r6
  int result; // r0

  v5 = a3[1];
  v7 = *a3;
  if ( a4 >= v7 + v5 )
    a4 -= v5;
  v9 = a4 - v7;
  v10 = 0;
  if ( a4 - v7 + a2 > v5 )
  {
    v10 = v9 - v5 + a2;
    a2 = v5 - v9;
  }
  result = memmove(a4, a1, a2);
  if ( v10 )
    result = memmove(*a3, a1 + a2, v10);
  return result;
}
