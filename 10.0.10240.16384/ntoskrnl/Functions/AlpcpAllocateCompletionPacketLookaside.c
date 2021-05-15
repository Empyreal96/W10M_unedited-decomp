// AlpcpAllocateCompletionPacketLookaside 
 
int __fastcall AlpcpAllocateCompletionPacketLookaside(int a1)
{
  int result; // r0

  if ( ExAllocatePoolWithTag(512, 12 * (a1 + 3), 1850305601) )
    result = sub_7F78E8();
  else
    result = 0;
  return result;
}
