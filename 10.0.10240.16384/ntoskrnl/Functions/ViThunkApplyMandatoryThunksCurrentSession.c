// ViThunkApplyMandatoryThunksCurrentSession 
 
int __fastcall ViThunkApplyMandatoryThunksCurrentSession(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // r2
  unsigned int i; // r4
  int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a4;
  v5 = RtlImageDirectoryEntryToData(*(_DWORD *)(a1 + 24), 1, 12, (int)v11);
  if ( v5 )
  {
    v6 = v11[0];
    if ( v11[0] )
    {
      if ( a2 )
      {
        __dmb(0xBu);
        do
          v7 = __ldrex((unsigned int *)&ViLookasideAlreadyLoadedDrivers);
        while ( __strex(1u, (unsigned int *)&ViLookasideAlreadyLoadedDrivers) );
        __dmb(0xBu);
        do
          v8 = __ldrex((unsigned int *)&ViResourcesAlreadyLoadedDrivers);
        while ( __strex(1u, (unsigned int *)&ViResourcesAlreadyLoadedDrivers) );
        __dmb(0xBu);
      }
      for ( i = v6 >> 2; i; --i )
      {
        ViThunkReplaceImportIfThunkedRegular(v5, &VfMandatoryThunks);
        v5 += 4;
      }
    }
  }
  return 1;
}
