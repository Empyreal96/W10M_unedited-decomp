// IopQueryConflictList 
 
int __fastcall IopQueryConflictList(int a1, int a2)
{
  unsigned int v4; // r4
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r1
  __int16 v8; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
  v5 = IopQueryConflictListInternal(a1, a2);
  v6 = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v6);
  return v5;
}
