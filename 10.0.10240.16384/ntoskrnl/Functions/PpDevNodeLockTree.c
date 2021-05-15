// PpDevNodeLockTree 
 
int __fastcall PpDevNodeLockTree(int a1, int a2)
{
  int v2; // r6
  int v3; // r2
  int v4; // r3
  int v6; // r4
  int v7; // r5
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r1
  int v11; // r3

  v2 = 1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  switch ( a1 )
  {
    case 0:
      goto LABEL_2;
    case 1:
      ExAcquireResourceExclusiveLite((int)&PiEngineLock, 1, v3, v4);
LABEL_2:
      ExAcquireResourceSharedLite((int)&IopDeviceTreeLock, 1);
      return v2;
    case 2:
      if ( !ExAcquireResourceExclusiveLite((int)&PiEngineLock, 0, v3, v4) )
      {
        v2 = 0;
        v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v11 = (__int16)(*(_WORD *)(v10 + 0x134) + 1);
        *(_WORD *)(v10 + 308) = v11;
        if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
          KiCheckForKernelApcDelivery(0);
        return v2;
      }
      goto LABEL_2;
  }
  if ( a1 != 3 )
  {
    if ( a1 == 4 )
    {
      v6 = ExIsResourceAcquiredSharedLite((int)&IopDeviceTreeLock, a2, v3, v4);
      v7 = v6;
      if ( v6 )
      {
        do
        {
          ExReleaseResourceLite((int)&IopDeviceTreeLock);
          --v7;
        }
        while ( v7 );
        do
        {
          ExAcquireResourceExclusiveLite((int)&IopDeviceTreeLock, 1, v8, v9);
          --v6;
        }
        while ( v6 );
      }
    }
    return v2;
  }
  return sub_7BDAB4();
}
