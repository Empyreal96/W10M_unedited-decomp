// sub_53DE34 
 
void sub_53DE34()
{
  int v0; // r7
  int v1; // r9
  unsigned int *v2; // r2
  unsigned int v3; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(v0 + 12);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & 0x7FFFFFFF, v2) );
  KfLowerIrql(v1);
  JUMPOUT(0x4A50EC);
}
