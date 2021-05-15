// RtlCreateUserProcess 
 
int __fastcall RtlCreateUserProcess(int a1, int a2, int a3)
{
  if ( !a1 || !a3 )
    return -1073741811;
  if ( (*(_DWORD *)(a3 + 8) & 1) == 0 )
    return sub_96C60C();
  *(_DWORD *)(a3 + 44) = 0;
  return RtlpCreateUserProcess();
}
