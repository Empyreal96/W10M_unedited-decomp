// MiFreeCloneDescriptor 
 
unsigned int __fastcall MiFreeCloneDescriptor(int a1, unsigned int a2)
{
  unsigned int v3; // r5
  unsigned int v4; // r8
  unsigned int v5; // r4
  unsigned int i; // r7

  v3 = *(_DWORD *)(a2 + 32);
  v4 = *(_DWORD *)(a2 + 28);
  v5 = 0;
  for ( i = *(_DWORD *)(v4 + 8); v5 < v3; v5 += 4096 )
    MiUnlockPagedAddress(v5 + i);
  PsReturnProcessNonPagedPoolQuota(a1, v3);
  ExFreePoolWithTag(v4);
  ExFreePoolWithTag(i);
  return ExFreePoolWithTag(a2);
}
