// NtFlushProcessWriteBuffers 
 
int NtFlushProcessWriteBuffers()
{
  KeFlushProcessWriteBuffers(0);
  return 0;
}
