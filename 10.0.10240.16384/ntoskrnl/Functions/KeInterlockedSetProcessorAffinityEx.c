// KeInterlockedSetProcessorAffinityEx 
 
BOOL __fastcall KeInterlockedSetProcessorAffinityEx(int a1, char a2)
{
  int v2; // r4
  unsigned int *v3; // r2
  unsigned int v4; // r0

  __dmb(0xBu);
  v2 = 1 << a2;
  v3 = (unsigned int *)(a1 + 8);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | v2, v3) );
  __dmb(0xBu);
  return (v2 & v4) != 0;
}
