// sub_50A948 
 
void sub_50A948()
{
  int v0; // r4
  unsigned int v1; // r5
  unsigned int v2; // r6
  unsigned __int64 v3; // kr00_8

  *(_BYTE *)(v0 + 348) += 16 * (15 - *(_BYTE *)(v0 + 123));
  KiAbProcessThreadPriorityModification(v0, 15, 1);
  v3 = *(_QWORD *)(v0 + 24);
  *(_BYTE *)(v0 + 123) = 15;
  if ( __PAIR64__(v2, v1) > v3 || v3 - __PAIR64__(v2, v1) < (unsigned int)KiLockQuantumTarget )
    *(_QWORD *)(v0 + 24) = __PAIR64__(v2, KiLockQuantumTarget) + v1;
  JUMPOUT(0x446BCC);
}
