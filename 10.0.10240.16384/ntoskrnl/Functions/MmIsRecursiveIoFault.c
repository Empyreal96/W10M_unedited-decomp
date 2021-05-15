// MmIsRecursiveIoFault 
 
BOOL MmIsRecursiveIoFault()
{
  int v0; // r3

  v0 = __mrc(15, 0, 13, 0, 3);
  return *(_BYTE *)((v0 & 0xFFFFFFC0) + 0x3CD) || *(_BYTE *)((v0 & 0xFFFFFFC0) + 0x3CC) == 1;
}
