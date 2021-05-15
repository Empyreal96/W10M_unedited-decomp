// IopAllocateBootResources 
 
int __fastcall IopAllocateBootResources(int a1, int a2, int a3)
{
  unsigned int v6; // r4
  int v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  int result; // r0

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
  v7 = IopAllocateBootResourcesInternal(a1, a2, a3);
  v8 = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( v10 || *(_DWORD *)(v9 + 100) == v9 + 100 )
    result = v7;
  else
    result = sub_80DD30(v8);
  return result;
}
