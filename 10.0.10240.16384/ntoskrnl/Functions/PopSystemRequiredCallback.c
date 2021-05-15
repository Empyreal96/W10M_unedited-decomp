// PopSystemRequiredCallback 
 
int __fastcall PopSystemRequiredCallback(int a1, int a2)
{
  int v4; // r0
  int v5; // r0

  v4 = PopAcquirePolicyLock(a1, a2);
  if ( a1 )
  {
    dword_61E824 |= a2;
  }
  else
  {
    dword_61E824 &= ~a2;
    if ( !dword_61E824 )
      dword_61E838 = dword_61E808;
  }
  v5 = PopCheckResiliencyScenarios(v4);
  PopReleasePolicyLock(v5);
  return 0;
}
