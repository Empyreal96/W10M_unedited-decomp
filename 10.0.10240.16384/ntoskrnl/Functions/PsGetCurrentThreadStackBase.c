// PsGetCurrentThreadStackBase 
 
int PsGetCurrentThreadStackBase()
{
  return *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x28);
}
