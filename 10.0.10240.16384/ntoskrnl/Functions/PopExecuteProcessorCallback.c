// PopExecuteProcessorCallback 
 
int __fastcall PopExecuteProcessorCallback(int a1, int a2)
{
  int result; // r0

  if ( (*(int (__fastcall **)(unsigned int, _DWORD, _DWORD))a2)(
         ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408,
         *(_DWORD *)(a2 + 4),
         *(_DWORD *)(a2 + 8)) >= 0 )
    result = PopQueueTargetDpc(a1, a2);
  else
    result = sub_529558();
  return result;
}
