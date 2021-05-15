// MxSwapPages 
 
int __fastcall MxSwapPages(int a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3

  result = MxGetPhase0Mapping();
  if ( result )
  {
    v3 = (unsigned __int16)(**(_WORD **)a1 + 1);
    v4 = *(unsigned __int16 *)(a1 + 4);
    **(_WORD **)a1 = v3;
    result = MiGetPage((int)MiSystemPartition, v3 & v4 | *(unsigned __int16 *)(a1 + 6), 8);
    if ( result != -1 )
      result = sub_96B050();
  }
  return result;
}
