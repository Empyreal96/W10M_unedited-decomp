// MmReleaseLoadLock 
 
int __fastcall MmReleaseLoadLock(int a1)
{
  int result; // r0
  __int16 v3; // r3

  result = KeReleaseMutant((unsigned int)&unk_632F0C, 1, 0, 0);
  v3 = *(_WORD *)(a1 + 308) + 1;
  *(_WORD *)(a1 + 308) = v3;
  if ( !v3 && *(_DWORD *)(a1 + 100) != a1 + 100 && !*(_WORD *)(a1 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
