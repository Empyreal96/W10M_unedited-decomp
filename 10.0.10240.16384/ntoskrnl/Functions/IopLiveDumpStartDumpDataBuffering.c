// IopLiveDumpStartDumpDataBuffering 
 
int __fastcall IopLiveDumpStartDumpDataBuffering(unsigned int *a1)
{
  int *v1; // r5
  int result; // r0
  int v4; // r2
  int v5; // r1

  v1 = &KdDebuggerDataBlock;
  if ( KdpDataBlockEncoded )
  {
    KdCopyDataBlock((int)&KdDebuggerDataBlock);
    KdpDataBlockEncoded = 0;
  }
  IopLiveDumpTrace();
  IopLiveDumpInitiateCorralStateChange(a1, 4u);
  result = IopLiveDumpTrace();
  if ( KdpBootedNodebug )
  {
    KdpDataBlockEncoded = 1;
    v4 = 216;
    v5 = KiWaitNever;
    result = KiWaitAlways;
    do
    {
      *v1 = __ROR4__(bswap32(*v1 ^ result) ^ (unsigned int)&KdpDataBlockEncoded, v5) ^ v5;
      ++v1;
      --v4;
    }
    while ( v4 );
  }
  return result;
}
