// AuthzBasepMemAlloc 
 
int __fastcall AuthzBasepMemAlloc(int a1, int a2, int a3)
{
  int v5; // r4

  v5 = 1;
  if ( (unsigned int)KeGetCurrentIrql() >= 2 )
    v5 = 512;
  return ExAllocatePoolWithTag(v5, a1, a3);
}
