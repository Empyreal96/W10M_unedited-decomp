// MiCommitmentAvailable 
 
unsigned int __fastcall MiCommitmentAvailable(int a1)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int result; // r0

  v1 = *(_DWORD *)(a1 + 4116);
  v2 = *(_DWORD *)(a1 + 3844);
  if ( v2 > v1 )
    result = 0;
  else
    result = v1 - v2;
  return result;
}
