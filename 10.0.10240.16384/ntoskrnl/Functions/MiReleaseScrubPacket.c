// MiReleaseScrubPacket 
 
int __fastcall MiReleaseScrubPacket(int a1)
{
  unsigned int v2; // r0
  int result; // r0

  MiReleasePteCopyList(a1);
  v2 = *(_DWORD *)(a1 + 16);
  if ( v2 )
    ExFreePoolWithTag(v2);
  result = *(_DWORD *)(a1 + 28);
  if ( result )
    result = MiDereferencePageRuns(result);
  return result;
}
