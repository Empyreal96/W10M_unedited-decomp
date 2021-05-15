// PsWaitForAllProcesses 
 
int PsWaitForAllProcesses()
{
  __int64 v0; // r6
  unsigned int v1; // r8
  int *v2; // r0
  unsigned int v3; // r5
  int v5; // r4
  __int64 v6[4]; // [sp+8h] [bp-20h] BYREF

  v0 = -100000i64;
  v6[0] = -100000i64;
  v1 = 0;
  while ( 1 )
  {
    v2 = 0;
    do
    {
      v2 = PsGetNextProcess((int)v2);
      v3 = (unsigned int)v2;
      if ( !v2 )
        return 1;
    }
    while ( v2 == (int *)PsInitialSystemProcess || v2 == (int *)PsIdleProcess || (v2[48] & 4) == 0 || !v2[84] );
    ObfReferenceObject((int)v2);
    ObfDereferenceObjectWithTag(v3);
    v5 = KeWaitForSingleObject(v3, 0, 0, 0, (int *)v6);
    ObfDereferenceObject(v3);
    if ( v5 == 258 )
    {
      ++v1;
      v0 *= 2i64;
      v6[0] = v0;
      if ( v1 > 0xD )
        break;
    }
  }
  return 0;
}
