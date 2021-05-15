// ExpSaInitialize 
 
int ExpSaInitialize()
{
  _BYTE *v0; // r0
  int v1; // r1
  int v2; // r0
  int result; // r0

  ExSaPageGroupDescriptorArray = 0;
  ExSaPageArrays = 0;
  ExSaNonPagedSlotAllocator = 0;
  ExSaPagedSlotAllocator = 0;
  ExSaPageGroupDescriptorArrayLock = 0;
  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 64, 1632860229);
  ExSaPageGroupDescriptorArray = (int)v0;
  if ( v0
    && (memset(v0, 0, 64),
        v2 = KeQueryMaximumProcessorCountEx(0xFFFFu, v1),
        (ExSaPageArrays = ExAllocatePoolWithTag(512, 4 * v2, 1632860229)) != 0) )
  {
    result = sub_50A71C();
  }
  else
  {
    result = 0;
  }
  return result;
}
