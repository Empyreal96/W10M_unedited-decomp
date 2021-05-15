// sub_538ACC 
 
void sub_538ACC()
{
  int v0; // r4
  int v1; // r5
  unsigned int v2; // r6
  int v3; // r8
  _DWORD *v4; // r9

  MiRemoveLockedPageFromWorkingSet(v1, v2, v0, *v4 + 24 * (*(_DWORD *)((v3 & (v2 >> 10)) - 0x40000000) >> 12));
  JUMPOUT(0x496CE8);
}
