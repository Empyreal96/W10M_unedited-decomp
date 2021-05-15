// sub_520AF4 
 
void sub_520AF4()
{
  int v0; // r5
  int v1; // r7
  int v2; // r0
  unsigned int v3; // r1
  int v4; // r0
  unsigned int v5; // r1

  v2 = MmIsFileObjectAPagingFile(v1);
  __dmb(0xBu);
  if ( v2 )
  {
    do
      v3 = __ldrex(&IoSynchronousPageWriteIrpAllocationFailure);
    while ( __strex(v3 + 1, &IoSynchronousPageWriteIrpAllocationFailure) );
    __dmb(0xBu);
    v4 = IopAllocateReserveIrp();
  }
  else
  {
    do
      v5 = __ldrex(&IoSynchronousPageWriteNonPagefileIrpAllocationFailure);
    while ( __strex(v5 + 1, &IoSynchronousPageWriteNonPagefileIrpAllocationFailure) );
    __dmb(0xBu);
    v4 = IopAllocateBackpocketIrp(v0, *(char *)(v0 + 48), 0);
  }
  if ( v4 )
    JUMPOUT(0x45342E);
  JUMPOUT(0x4534D6);
}
