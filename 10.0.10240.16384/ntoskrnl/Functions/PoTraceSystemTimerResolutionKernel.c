// PoTraceSystemTimerResolutionKernel 
 
int __fastcall PoTraceSystemTimerResolutionKernel(int result, int a2)
{
  int _3C; // [sp+3Ch] [bp+8h]

  _3C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_KERNEL_STRS);
    if ( result )
      result = sub_50B3B4();
  }
  return result;
}
