// KeInterlockedClearProcessorAffinityEx 
 
BOOL __fastcall KeInterlockedClearProcessorAffinityEx(int a1, char a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 8);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & ~(1 << a2), v2) );
  __dmb(0xBu);
  return ((1 << a2) & v3) != 0;
}
