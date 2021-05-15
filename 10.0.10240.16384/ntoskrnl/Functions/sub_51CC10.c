// sub_51CC10 
 
void sub_51CC10()
{
  int v0; // r8
  unsigned int v1; // r9
  int v2; // r10
  unsigned int *v3; // r2
  unsigned int v4; // r0

  __dmb(0xBu);
  v3 = (unsigned int *)(v0 + 12);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 & 0x7FFFFFFF, v3) );
  KfLowerIrql(v2);
  MmAccessFault(1, v1, 0, 0);
  JUMPOUT(0x449AB4);
}
