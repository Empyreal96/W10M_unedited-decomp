// PopPdcUpdateDeviceCompliance 
 
int PopPdcUpdateDeviceCompliance()
{
  int v0; // r4
  int v1; // r5
  int i; // r2
  int v3; // r0
  int *v4; // r3
  unsigned int j; // r2

  v0 = 0;
  v1 = 0;
  for ( i = PopPdcDeviceList; (int *)i != &PopPdcDeviceList; i = *(_DWORD *)i )
  {
    v3 = 1 << *(_DWORD *)(i + 12);
    v1 |= v3;
    if ( *(_BYTE *)(i + 20) )
      v0 |= v3;
  }
  PopAcquirePolicyLock();
  v4 = &PopCsDeviceCompliance;
  for ( j = 0; j < 5; ++j )
  {
    if ( ((1 << j) & v0) != 0 )
    {
      *v4 = 1;
    }
    else
    {
      if ( ((1 << j) & v1) != 0 )
        return sub_7F10B0(1);
      *v4 = 0;
    }
    ++v4;
  }
  return PopReleasePolicyLock();
}
