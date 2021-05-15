// IopMemInitialize 
 
int __fastcall IopMemInitialize(int a1, int a2)
{
  int result; // r0

  dword_63057C = (int)IopGenericUnpackRequirement;
  dword_630580 = (int)IopGenericPackResource;
  dword_630584 = (int)IopGenericUnpackResource;
  dword_630588 = (int)IopGenericScoreRequirement;
  dword_6305BC = (int)IopMemFindSuitableRange;
  dword_6305A4 = (int)IopMemQueryConflict;
  result = ArbInitializeArbiterInstance((int)&IopRootMemArbiter, a2, 3, (int)L"RootMemory");
  if ( result >= 0 )
  {
    result = RtlAddRange(dword_630554, 0i64, 0xFFFui64, 0, 0, 0, 0);
    if ( result >= 0 )
    {
      result = ArbAddInaccessibleAllocationRange((int)&IopRootMemArbiter, dword_630554);
      if ( result >= 0 )
        result = ArbAddMmConfigRangeAsBootReserved((int)&IopRootMemArbiter, dword_630554);
    }
  }
  return result;
}
