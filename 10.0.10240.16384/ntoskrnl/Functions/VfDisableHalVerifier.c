// VfDisableHalVerifier 
 
int *VfDisableHalVerifier()
{
  int *result; // r0
  int *i; // r2
  int v2; // r1

  if ( ViVerifyDma )
  {
    result = &ViAdapterList;
    ViVerifyDma = 0;
    for ( i = (int *)ViAdapterList; &ViAdapterList != i; i = (int *)*i )
    {
      v2 = i[2];
      if ( v2 )
        *(_DWORD *)(v2 + 4) = i[7];
    }
  }
  return result;
}
