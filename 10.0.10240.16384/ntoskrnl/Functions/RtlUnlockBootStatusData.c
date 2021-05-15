// RtlUnlockBootStatusData 
 
int RtlUnlockBootStatusData()
{
  ZwFsControlFile();
  ZwFlushBuffersFile();
  return ZwClose();
}
