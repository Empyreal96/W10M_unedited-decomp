// PopHiberCheckForDebugBreak 
 
int __fastcall PopHiberCheckForDebugBreak(int result, int a2, int a3, int a4)
{
  _DWORD v4[2]; // [sp+0h] [bp-8h] BYREF

  v4[0] = a3;
  v4[1] = a4;
  if ( !*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) && (++PopDebugCount & 0x3F) == 0 )
  {
    KdCheckForDebugBreak(result, a2);
    result = KeQueryPerformanceCounter(v4, 0);
  }
  return result;
}
