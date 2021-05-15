// KiWaitForProcessorResume 
 
int __fastcall KiWaitForProcessorResume(int result)
{
  int v1; // r5
  unsigned int v2; // r4

  v1 = result;
  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  while ( (*(_DWORD *)(v1 + 18240) & 1) != 0 )
    result = KiCheckStall(v2 + 1408, 0);
  return result;
}
