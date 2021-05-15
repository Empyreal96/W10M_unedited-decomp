// PopDisconnectedStandbyEnabled 
 
int __fastcall PopDisconnectedStandbyEnabled(int *a1)
{
  int v1; // r5
  BOOL v2; // r4
  int v5; // r0

  v1 = 0;
  v2 = 0;
  if ( PopEnforceDisconnectedStandby )
    return sub_7F2CA8();
  v5 = PopConnectedStandbyComplianceChecks(a1);
  if ( v5 )
  {
    if ( PopConnectedStandbyCompliantNic(v5) )
    {
      if ( dword_64171C != 1 && dword_641724 != 1 )
      {
        v2 = dword_61EC58 == 0;
        if ( !dword_61EC58 )
          v1 = 2;
      }
    }
    else
    {
      v2 = 1;
      v1 = 1;
    }
  }
  else
  {
    v2 = 1;
    v1 = 4;
  }
  if ( a1 )
    *a1 = v1;
  return v2;
}
