// ViThunkApplyThunksCurrentSession 
 
int __fastcall ViThunkApplyThunksCurrentSession(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r4
  int v7; // r0
  int v8; // r5
  int v9; // r9
  unsigned int v10; // r7
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v4 = *(_DWORD *)(a1 + 24);
  v6 = 0;
  v7 = VfTargetDriversGetNode(v4, a2, a3, a4);
  v8 = v7;
  if ( v7 )
  {
    if ( (*(_DWORD *)(v7 + 8) & 1) == 0 )
    {
      v9 = RtlImageDirectoryEntryToData(v4, 1, 12, (int)v15);
      if ( v9 )
      {
        v10 = v15[0];
        if ( v15[0] )
        {
          if ( a2 )
          {
            __dmb(0xBu);
            do
              v11 = __ldrex((unsigned int *)&ViLookasideAlreadyLoadedDrivers);
            while ( __strex(1u, (unsigned int *)&ViLookasideAlreadyLoadedDrivers) );
            __dmb(0xBu);
            do
              v12 = __ldrex((unsigned int *)&ViResourcesAlreadyLoadedDrivers);
            while ( __strex(1u, (unsigned int *)&ViResourcesAlreadyLoadedDrivers) );
            __dmb(0xBu);
          }
          v13 = ViIsDriverSuspectForVerifier();
          v6 = ViThunkReplaceAllThunkedImports(v9, v10 >> 2, a2, v13);
          if ( v6 )
            ViThunkReplaceAllSharedExports(v8, a2);
        }
      }
    }
  }
  return v6;
}
