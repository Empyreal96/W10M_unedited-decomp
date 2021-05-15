// MmTrimFilePagesFromWorkingSets 
 
int MmTrimFilePagesFromWorkingSets()
{
  int result; // r0

  if ( byte_634C8C )
    result = MiQueueWorkingSetRequest((int)MiSystemPartition, 256);
  return result;
}
