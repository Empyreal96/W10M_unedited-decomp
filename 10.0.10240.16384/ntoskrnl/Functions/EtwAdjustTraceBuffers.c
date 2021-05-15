// EtwAdjustTraceBuffers 
 
int EtwAdjustTraceBuffers()
{
  int result; // r0
  unsigned int v1; // r1

  if ( EtwpInitialized )
  {
    if ( !--EtwpBufferAdjustmentCount )
    {
      EtwpBufferAdjustmentCount = 8;
      __dmb(0xBu);
      result = 1;
      do
        v1 = __ldrex(&EtwpBufferAdjustmentActive);
      while ( !v1 && __strex(1u, &EtwpBufferAdjustmentActive) );
      __dmb(0xBu);
      if ( !v1 )
        result = ExQueueWorkItem(&EtwpAdjustBuffersWorkItem, 1);
    }
  }
  return result;
}
