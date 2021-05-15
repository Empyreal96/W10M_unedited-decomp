// PfSnAddProcessTrace 
 
int __fastcall PfSnAddProcessTrace(int a1, int a2)
{
  int v4; // r3

  if ( (*(_DWORD *)(a1 + 420) & 0xFFFFFFF8) != 0 )
    return -1073741791;
  if ( !ExAcquireRundownProtectionEx((int *)(a2 + 268), 8) )
    return -1073741431;
  if ( a2 )
    v4 = a2 + 7;
  else
    v4 = 0;
  *(_DWORD *)(a1 + 420) = v4;
  return 0;
}
