// HvFoldBackUnreconciledData 
 
unsigned int __fastcall HvFoldBackUnreconciledData(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r0
  int v5; // r3

  CmpLockRegistry();
  ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 1872), 1, v2, v3);
  RtlMergeBitMaps((unsigned int *)(a1 + 52), (unsigned int *)(a1 + 1904));
  v4 = RtlNumberOfSetBits((unsigned int *)(a1 + 52));
  v5 = *(unsigned __int8 *)(a1 + 1900);
  *(_DWORD *)(a1 + 60) = v4;
  if ( v5 )
    *(_BYTE *)(a1 + 123) = 1;
  ExReleaseResourceLite(*(_DWORD *)(a1 + 1872));
  CmpUnlockRegistry();
  return HvFreeUnreconciledData(a1);
}
