// NtOpenProcess 
 
int NtOpenProcess()
{
  __mrc(15, 0, 13, 0, 3);
  return PsOpenProcess();
}
