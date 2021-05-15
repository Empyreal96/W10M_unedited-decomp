// sub_543E14 
 
void sub_543E14()
{
  int v0; // r5
  int v1; // lr
  unsigned int *v2; // r2
  unsigned int v3; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(v0 + 12);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & 0x7FFFFFFF, v2) );
  KfLowerIrql(v1);
  JUMPOUT(0x4B904E);
}
