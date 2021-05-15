// PdcPoReportButton 
 
int __fastcall PdcPoReportButton(char a1, int a2)
{
  char v4; // r3
  char v5; // r3
  char v6; // r3

  PopAcquirePolicyLock();
  if ( (a1 & 1) != 0 )
  {
    if ( a2 )
    {
      if ( PopCapabilities == 1 )
        goto LABEL_8;
      v4 = 1;
    }
    else
    {
      if ( !PopCapabilities )
        goto LABEL_8;
      v4 = 0;
    }
    PopCapabilities = v4;
    PopResetCurrentPolicies();
  }
LABEL_8:
  if ( (a1 & 2) == 0 )
    goto LABEL_15;
  if ( a2 )
  {
    if ( byte_61EA41 == 1 )
      goto LABEL_15;
    v5 = 1;
  }
  else
  {
    if ( !byte_61EA41 )
      goto LABEL_15;
    v5 = 0;
  }
  byte_61EA41 = v5;
  PopResetCurrentPolicies();
LABEL_15:
  if ( (a1 & 4) != 0 )
  {
    if ( a2 )
    {
      if ( byte_61EA42 != 1 )
      {
        v6 = 1;
LABEL_21:
        byte_61EA42 = v6;
        PopResetCurrentPolicies();
        return PopReleasePolicyLock();
      }
    }
    else if ( byte_61EA42 )
    {
      v6 = 0;
      goto LABEL_21;
    }
  }
  return PopReleasePolicyLock();
}
