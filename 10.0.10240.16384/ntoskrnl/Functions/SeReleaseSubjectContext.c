// SeReleaseSubjectContext 
 
int __fastcall SeReleaseSubjectContext(int a1)
{
  int result; // r0

  ObFastDereferenceObject(
    (_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244),
    *(_DWORD *)(a1 + 8));
  result = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 8) = 0;
  if ( result )
    result = ObfDereferenceObject(result);
  *(_DWORD *)a1 = 0;
  return result;
}
