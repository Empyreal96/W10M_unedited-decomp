// SeSetVirtualizationToken 
 
int __fastcall SeSetVirtualizationToken(int *a1, int a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r3
  unsigned int v7; // r3
  int result; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  ExAcquireResourceExclusiveLite(a1[12], 1, v4, v5);
  __dmb(0xFu);
  v6 = a1[44];
  if ( !a2 )
  {
    v7 = v6 & 0xFFFFFBFF;
    goto LABEL_5;
  }
  if ( (v6 & 0x200) != 0 )
  {
    v7 = v6 | 0x400;
LABEL_5:
    a1[44] = v7;
  }
  ExAllocateLocallyUniqueId(a1 + 13);
  __dmb(0xFu);
  result = ExReleaseResourceLite(a1[12]);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
