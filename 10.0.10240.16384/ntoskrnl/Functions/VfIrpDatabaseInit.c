// VfIrpDatabaseInit 
 
int VfIrpDatabaseInit()
{
  int result; // r0
  int v1; // r3
  unsigned int v2; // r1

  __dmb(0xBu);
  ViIrpDatabaseLock = 0;
  result = ExAllocatePoolWithTag(512, 4096, 1951690569);
  ViIrpDatabase = result;
  if ( result )
  {
    v1 = 256;
    do
    {
      *(_DWORD *)result = result;
      *(_DWORD *)(result + 4) = result;
      result += 8;
      --v1;
    }
    while ( v1 );
    ViIrpDatabaseAddressRanges = result;
    memset((_BYTE *)result, 0, 2048);
    __dmb(0xBu);
    result = 1;
    do
      v2 = __ldrex((unsigned int *)&VfIrpDatabaseInitialized);
    while ( __strex(1u, (unsigned int *)&VfIrpDatabaseInitialized) );
    __dmb(0xBu);
  }
  return result;
}
