// EtwpLogMemInfoDpc 
 
int EtwpLogMemInfoDpc()
{
  int result; // r0
  int v1[6]; // [sp+0h] [bp-18h] BYREF

  result = MmQuerySystemMemoryInformation(v1);
  if ( (dword_682604 & 0x80000) != 0 )
    return sub_521970(result);
  if ( (dword_682604 & 0x800000) != 0 )
    result = EtwpQueuePerfMemInfoWorkItem(v1[0]);
  return result;
}
