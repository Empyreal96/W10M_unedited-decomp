// MmQueryCommitReleaseState 
 
int __fastcall MmQueryCommitReleaseState(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r3
  int result; // r0
  unsigned int v5; // r3

  v3 = *(_DWORD *)(a1 + 604);
  result = *(_DWORD *)(a1 + 608);
  v5 = HIBYTE(v3) >> 6;
  if ( v5 < 2 )
    result = 0;
  *a2 = v5 != 0;
  *a3 = result;
  return result;
}
