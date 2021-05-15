// IoAllocateGenericErrorLogEntry 
 
int __fastcall IoAllocateGenericErrorLogEntry(unsigned int a1)
{
  return IopAllocateErrorLogEntry(0, 0, a1);
}
