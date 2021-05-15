// PopUpdateOverThrottledCount 
 
int __fastcall PopUpdateOverThrottledCount(int a1, int a2)
{
  PopDiagTraceThermalOverthrottleState(*(_DWORD *)(a1 + 24));
  PopAcquirePolicyLock();
  if ( a2 )
  {
    if ( ++dword_61E4B8 == 1 )
      goto LABEL_5;
  }
  else if ( !--dword_61E4B8 )
  {
LABEL_5:
    ZwUpdateWnfStateData();
    return PopReleasePolicyLock();
  }
  return PopReleasePolicyLock();
}
