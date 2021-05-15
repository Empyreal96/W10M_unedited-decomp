// KeIsAttachedProcess 
 
BOOL KeIsAttachedProcess()
{
  return *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1;
}
