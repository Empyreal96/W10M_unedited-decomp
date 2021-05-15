// NtFlushWriteBuffer 
 
int NtFlushWriteBuffer()
{
  KeFlushWriteBuffer();
  return 0;
}
