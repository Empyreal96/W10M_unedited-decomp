// sub_54AB04 
 
void sub_54AB04()
{
  int v0; // r4
  int v1; // r5
  int v2; // r3
  BOOL v3; // r3

  v2 = *(unsigned __int8 *)(v0 + 64);
  v3 = v2 == 2 || v2 == 4;
  CcPerfLogWorkItemEnqueue(v1, v0, 0, v3);
  JUMPOUT(0x4D100A);
}
