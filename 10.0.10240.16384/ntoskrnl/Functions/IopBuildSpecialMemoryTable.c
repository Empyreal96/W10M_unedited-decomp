// IopBuildSpecialMemoryTable 
 
int __fastcall IopBuildSpecialMemoryTable(int result)
{
  unsigned int i; // r3
  _BYTE v2[48]; // [sp+0h] [bp-30h] BYREF

  if ( result )
  {
    for ( i = 0; i < 0x21; ++i )
      v2[i] = 0;
    v2[30] = 1;
    v2[31] = 1;
    v2[6] = 1;
    v2[32] = 1;
    result = MmInitializeMemoryLimits();
    SpecialMemoryRanges = result;
  }
  return result;
}
