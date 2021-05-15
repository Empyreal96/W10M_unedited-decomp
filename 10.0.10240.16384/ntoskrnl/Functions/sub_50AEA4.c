// sub_50AEA4 
 
int sub_50AEA4()
{
  unsigned int *v1; // r4
  int v2; // r0
  int (__fastcall *v3)(int); // [sp-4h] [bp-4h]

  v2 = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v1);
  return v3(v2);
}
