// PopWiFiInStandbyCallback 
 
int __fastcall PopWiFiInStandbyCallback(int a1, int *a2, int a3)
{
  int v4; // r4
  int v5; // r0

  if ( a3 != 4 || (unsigned int)*a2 > 1 )
    return -1073741811;
  v4 = 0;
  v5 = PopAcquirePolicyLock();
  dword_61EC58 = *a2;
  PopSnapStandbyNetworkingState(v5);
  PopReleasePolicyLock();
  return v4;
}
