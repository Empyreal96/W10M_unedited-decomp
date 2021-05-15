// PopFxUnregisterDevice 
 
int __fastcall PopFxUnregisterDevice(unsigned int *a1)
{
  unsigned int v1; // r3
  unsigned int *v2; // r4
  unsigned int v3; // r5
  unsigned int i; // r5
  int v5; // r5
  unsigned int j; // r1
  int v7; // r3
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r3
  int result; // r0
  unsigned int v12; // r3

  v1 = a1[96];
  v2 = a1;
  __dmb(0xBu);
  if ( (v1 & 1) == 0 )
  {
    v3 = 0;
    if ( a1[97] )
    {
      do
        a1 = PoFxActivateComponent(v2, v3++, 2);
      while ( v3 < v2[97] );
    }
    for ( i = 0; i < v2[97]; ++i )
      a1 = (unsigned int *)KeWaitForSingleObject(*(_DWORD *)(v2[98] + 4 * i) + 64, 0, 0, 0, 0);
  }
  v5 = v2[7];
  if ( v5 )
  {
    PopFxRemoveDevice((int)a1, (int)v2);
    PopDiagTraceFxDeviceUnregistration(v5);
    PopFxAssignDeviceToDevNode(v5, 0);
  }
  for ( j = 0; j < v2[97]; ++j )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(v2[98] + 4 * j) + 60);
    __dmb(0xBu);
    if ( v7 > 0 )
    {
      do
        v8 = __ldrex((unsigned int *)&PopFxResidentComponentCount);
      while ( __strex(v8 - 1, (unsigned int *)&PopFxResidentComponentCount) );
    }
  }
  IoReleaseRemoveLockAndWaitEx((int)(v2 + 27), 0, 24);
  PopPepUnregisterDevice(v2[8]);
  result = v2[9];
  if ( result )
    result = PopPluginUnregisterDevice(result, v2[10], v9, v10);
  if ( v5 )
    result = KeSetEvent(v5 + 48, 0, 0);
  v12 = v2[96];
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    result = PopFxDestroyDeviceDpm(v5, v2);
  return result;
}
