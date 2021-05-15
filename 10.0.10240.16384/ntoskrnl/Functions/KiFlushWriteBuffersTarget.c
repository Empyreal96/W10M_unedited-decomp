// KiFlushWriteBuffersTarget 
 
void KiFlushWriteBuffersTarget()
{
  __dmb(0xFu);
}
