// sub_80D93C 
 
void sub_80D93C()
{
  int *v0; // r4
  int v1; // r5
  int v2; // r9
  int v3; // r10
  int v4; // r7
  unsigned int v5; // r0

  v4 = PnpReleaseBootResourcesForFilteredRequirements(v0);
  PipClearDevNodeFlags(v1, 128);
  if ( v4 < 0 )
  {
    v5 = v0[7];
    v0[1] = v3;
    v0[9] = v4;
    ExFreePoolWithTag(v5);
    v0[7] = v2;
  }
  *(_DWORD *)(v1 + 284) = v2;
  JUMPOUT(0x79505A);
}
