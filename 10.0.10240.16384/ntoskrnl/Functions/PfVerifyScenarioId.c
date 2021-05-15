// PfVerifyScenarioId 
 
int __fastcall PfVerifyScenarioId(int a1)
{
  int result; // r0

  if ( *(_WORD *)(a1 + 58) )
    result = sub_808F14(a1, a1 + 56, 29);
  else
    result = 1;
  return result;
}
