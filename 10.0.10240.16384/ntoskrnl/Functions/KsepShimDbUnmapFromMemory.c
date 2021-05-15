// KsepShimDbUnmapFromMemory 
 
int __fastcall KsepShimDbUnmapFromMemory(unsigned int a1, int a2)
{
  int result; // r0

  if ( a1 )
    SdbReleaseDatabase(a1, a2);
  if ( KsepShimDbAddress )
  {
    MmUnmapViewInSystemSpace(KsepShimDbAddress);
    KsepShimDbAddress = 0;
  }
  if ( KsepShimDbSectionPointer )
  {
    ObfDereferenceObject(KsepShimDbSectionPointer);
    KsepShimDbSectionPointer = 0;
  }
  if ( KsepShimDbSectionHandle )
  {
    ZwClose();
    KsepShimDbSectionHandle = 0;
  }
  result = KsepShimDbFileHandle;
  if ( KsepShimDbFileHandle )
  {
    result = ZwClose();
    KsepShimDbFileHandle = 0;
  }
  return result;
}
