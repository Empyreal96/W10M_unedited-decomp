// MiWaitForAsynchronousFlushes 
 
int __fastcall MiWaitForAsynchronousFlushes(int a1)
{
  int *v1; // r4
  int *v2; // r5
  unsigned int *v3; // r6
  int v4; // r0
  int result; // r0

  v1 = (int *)a1;
  v2 = (int *)a1;
  v3 = (unsigned int *)(a1 + 1120);
  v4 = KfRaiseIrql(1);
  do
  {
    if ( !v2[2] || v2[7] == 1 )
    {
      v2 += 35;
    }
    else
    {
      KfLowerIrql(v4);
      KeWaitForMultipleObjects(8u, v3, 1, 19, 0, 0, 0, v1 + 288);
      v2 = v1;
      v4 = KfRaiseIrql(1);
    }
  }
  while ( v2 < (int *)v3 );
  KfLowerIrql(v4);
  result = 0;
  while ( *v1 >= 0 )
  {
    v1 += 35;
    if ( v1 >= (int *)v3 )
      return result;
  }
  return *v1;
}
