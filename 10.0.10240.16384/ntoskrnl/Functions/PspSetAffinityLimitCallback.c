// PspSetAffinityLimitCallback 
 
int __fastcall PspSetAffinityLimitCallback(int a1, _DWORD *a2)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 192) & 0x4000000) == 0 || (*(_DWORD *)(a1 + 188) & 1) != 0 )
    result = 0;
  else
    result = PspCheckJobAccessState(a2, a1);
  return result;
}
