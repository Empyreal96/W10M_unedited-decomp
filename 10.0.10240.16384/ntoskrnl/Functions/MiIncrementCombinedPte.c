// MiIncrementCombinedPte 
 
unsigned int __fastcall MiIncrementCombinedPte(int a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)(a1 - 8);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  do
    result = __ldrex((unsigned int *)&dword_6404B0);
  while ( __strex(result + 1, (unsigned int *)&dword_6404B0) );
  return result;
}
