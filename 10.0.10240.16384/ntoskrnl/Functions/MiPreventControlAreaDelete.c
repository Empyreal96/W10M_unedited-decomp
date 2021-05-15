// MiPreventControlAreaDelete 
 
unsigned int __fastcall MiPreventControlAreaDelete(int a1)
{
  unsigned __int64 *v1; // r3
  unsigned __int64 v2; // kr00_8

  v1 = (unsigned __int64 *)(a1 + 64);
  do
    v2 = __ldrexd(v1);
  while ( __strexd(v2 + 1, v1) );
  return ObFastReferenceObjectLocked((_DWORD *)(a1 + 32));
}
