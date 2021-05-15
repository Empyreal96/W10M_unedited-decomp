// SeUnlockSubjectContext 
 
int __fastcall SeUnlockSubjectContext(_DWORD *a1)
{
  int result; // r0
  __int16 v3; // r2
  unsigned int v4; // r1
  int v5; // r3

  ExReleaseResourceLite(*(_DWORD *)(a1[2] + 48));
  result = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(result + 0x134);
  *(_WORD *)(result + 308) = v3 + 1;
  if ( v3 == -1 && *(_DWORD *)(result + 100) != result + 100 && !*(_WORD *)(result + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( *a1 )
  {
    result = ExReleaseResourceLite(*(_DWORD *)(*a1 + 48));
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = (__int16)(*(_WORD *)(v4 + 0x134) + 1);
    *(_WORD *)(v4 + 308) = v5;
    if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
