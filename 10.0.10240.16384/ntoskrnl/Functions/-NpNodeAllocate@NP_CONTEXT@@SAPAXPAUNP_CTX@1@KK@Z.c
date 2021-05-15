// -NpNodeAllocate@NP_CONTEXT@@SAPAXPAUNP_CTX@1@KK@Z 
 
void *__fastcall NP_CONTEXT::NpNodeAllocate(struct NP_CONTEXT::NP_CTX *a1, unsigned int a2, unsigned int a3)
{
  char v3; // r6
  unsigned int *v5; // r4
  int v6; // r0
  void *v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r3

  v3 = a3;
  v5 = *(unsigned int **)a1;
  v6 = ExAllocatePoolWithTag(512, 4096);
  v7 = (void *)v6;
  if ( (v6 || (v3 & 2) != 0)
    && (v3 & 1) != 0
    && (v6 || (v7 = NP_CONTEXT::NpiGetReservedBuffer((struct NP_CONTEXT *)v5, a1)) != 0) )
  {
    v8 = v5[6] + 1;
    v9 = *v5;
    v5[6] = v8;
    if ( v8 > v9 )
      NP_CONTEXT::NpiPerformPageOut((struct NP_CONTEXT *)v5, a1);
  }
  return v7;
}
