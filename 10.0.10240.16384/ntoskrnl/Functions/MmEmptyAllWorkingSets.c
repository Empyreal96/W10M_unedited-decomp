// MmEmptyAllWorkingSets 
 
__int16 *MmEmptyAllWorkingSets()
{
  __int16 *result; // r0

  result = MiSystemPartition;
  if ( byte_634C8C )
  {
    ++*(_DWORD *)(dword_6404B8 + 20);
    result = (__int16 *)MiQueueWorkingSetRequest((int)MiSystemPartition, 4);
  }
  return result;
}
