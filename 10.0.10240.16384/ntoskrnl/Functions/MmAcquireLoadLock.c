// MmAcquireLoadLock 
 
unsigned int MmAcquireLoadLock()
{
  unsigned int v0; // r4

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  KeWaitForSingleObject((unsigned int)&unk_632F0C, 18, 0, 0, 0);
  return v0;
}
