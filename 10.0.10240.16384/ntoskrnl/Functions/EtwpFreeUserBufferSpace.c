// EtwpFreeUserBufferSpace 
 
unsigned int __fastcall EtwpFreeUserBufferSpace(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r4
  unsigned int result; // r0

  v4 = *(_DWORD *)(a1 + 60);
  if ( a3 < v4 || a3 >= *(_DWORD *)(a1 + 64) + v4 )
    result = ZwFreeVirtualMemory();
  else
    result = RtlInterlockedClearBitRun(a1 + 52, (int)(a3 - v4) / 4096, ((a2 + 4095) & 0xFFFFF000) >> 12);
  return result;
}
