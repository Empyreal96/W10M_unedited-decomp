// ExpProfileDelete 
 
int __fastcall ExpProfileDelete(int a1)
{
  int v2; // r2
  int result; // r0

  if ( *(_DWORD *)(a1 + 28) )
  {
    KeStopProfile(*(_DWORD *)(a1 + 24));
    MmUnmapLockedPages(*(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 32), v2);
    MmUnlockPages(*(_DWORD *)(a1 + 32));
    ExFreePoolWithTag(*(_DWORD *)(a1 + 24));
  }
  result = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 )
    result = ObfDereferenceObjectWithTag(result);
  return result;
}
