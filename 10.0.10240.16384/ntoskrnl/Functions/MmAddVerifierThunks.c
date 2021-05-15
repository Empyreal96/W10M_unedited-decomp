// MmAddVerifierThunks 
 
int __fastcall MmAddVerifierThunks(unsigned int *a1, unsigned int a2)
{
  unsigned int *v3; // r6
  int v4; // r4
  unsigned int *v5; // r4
  unsigned int v6; // r8
  int v7; // r5
  int *v8; // r0
  unsigned int v9; // lr
  unsigned int v10; // r2
  unsigned int v11; // r9
  int *v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r2

  v3 = a1;
  if ( (MiFlags & 1) == 0 )
    return -1073741637;
  v5 = a1;
  v6 = a2 >> 3;
  if ( !(a2 >> 3) )
    return -1073741585;
  v7 = MmAcquireLoadLock();
  v8 = MiLookupDataTableEntry(*v3, 1);
  if ( v8 )
  {
    v9 = v8[6];
    v10 = 0;
    v11 = v8[8] + v9;
    v12 = (int *)PsLoadedModuleList;
    do
    {
      if ( v12 == &PsLoadedModuleList )
        break;
      if ( v8 == v12 )
        goto LABEL_6;
      ++v10;
      v12 = (int *)*v12;
    }
    while ( v10 < 2 );
    v13 = 0;
    if ( v6 )
    {
      while ( *v5 >= v9 )
      {
        if ( *v5 >= v11 )
          break;
        v14 = v5[1];
        if ( v14 < v9 || v14 >= v11 )
          break;
        ++v13;
        v5 += 2;
        if ( v13 >= v6 )
          goto LABEL_17;
      }
      v4 = -1073741584;
    }
    else
    {
LABEL_17:
      v4 = VfThunkAddDriverThunks(v3, a2, v8, v13);
    }
    MmReleaseLoadLock(v7);
  }
  else
  {
LABEL_6:
    MmReleaseLoadLock(v7);
    v4 = -1073741584;
  }
  return v4;
}
