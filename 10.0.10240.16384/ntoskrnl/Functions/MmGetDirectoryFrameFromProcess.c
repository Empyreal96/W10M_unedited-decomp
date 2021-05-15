// MmGetDirectoryFrameFromProcess 
 
int __fastcall MmGetDirectoryFrameFromProcess(int a1)
{
  return *(_DWORD *)(a1 + 24) >> 12;
}
