// KiAbEntryGetCpuPriorityKey 
 
int __fastcall KiAbEntryGetCpuPriorityKey(_BYTE *a1)
{
  if ( (a1[15] & 1) == 0 )
    return (char)a1[24];
  if ( (a1[13] & 1) != 0 )
    return KiAbWaiterComputeCpuPriorityKey(a1);
  return KiAbOwnerComputeCpuPriorityKey(a1);
}
