// NtFlushBuffersFile 
 
int __fastcall NtFlushBuffersFile(int a1)
{
  return NtFlushBuffersFileEx(a1, 0, 0, 0);
}
