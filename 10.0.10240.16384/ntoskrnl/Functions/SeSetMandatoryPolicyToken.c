// SeSetMandatoryPolicyToken 
 
int __fastcall SeSetMandatoryPolicyToken(int *a1, int *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r0
  unsigned int v7; // r1
  __int16 v8; // r3
  int result; // r0

  if ( (*a2 & 0xFFFFFFFC) != 0 )
    return -1073741811;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  ExAcquireResourceExclusiveLite(a1[12], 1, v4, v5);
  __dmb(0xFu);
  a1[47] = *a2;
  ExAllocateLocallyUniqueId(a1 + 13);
  __dmb(0xFu);
  v6 = ExReleaseResourceLite(a1[12]);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( v8 || *(_DWORD *)(v7 + 100) == v7 + 100 )
    result = 0;
  else
    result = sub_7DC04C(v6);
  return result;
}
