// EtwpSynchronizationDpc 
 
void __fastcall EtwpSynchronizationDpc(int a1, int a2, unsigned int *a3)
{
  unsigned int v3; // r1

  __dmb(0xBu);
  do
    v3 = __ldrex(a3);
  while ( __strex(v3 - 1, a3) );
  __dmb(0xBu);
}
