// VfNotifyOfHibernate 
 
int __fastcall VfNotifyOfHibernate(int result)
{
  int v1; // r5
  int *v2; // r2
  int v3; // r0

  v1 = result;
  if ( result )
  {
    if ( ViVerifyDma )
    {
      ViEnableAfterHibernate = 1;
      VfDisableHalVerifier();
    }
  }
  else
  {
    if ( !ViEnableAfterHibernate )
      return result;
    ViVerifyDma = 1;
    v2 = (int *)ViAdapterList;
    ViEnableAfterHibernate = 0;
    while ( &ViAdapterList != v2 )
    {
      v3 = v2[2];
      if ( v3 )
        *(_DWORD *)(v3 + 4) = &ViDmaOperations;
      v2 = (int *)*v2;
    }
  }
  result = VfIsVerifierExtensionEnabled();
  if ( result == 1 )
  {
    if ( ViFnExtensionHiberFunc )
      result = ViFnExtensionHiberFunc(v1);
  }
  return result;
}
