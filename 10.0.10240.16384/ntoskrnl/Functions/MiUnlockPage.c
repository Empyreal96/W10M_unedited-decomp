// MiUnlockPage 
 
int __fastcall MiUnlockPage(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 12);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & 0x7FFFFFFF, v2) );
  return KfLowerIrql(a2);
}
