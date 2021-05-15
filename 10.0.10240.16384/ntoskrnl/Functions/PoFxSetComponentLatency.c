// PoFxSetComponentLatency 
 
int __fastcall PoFxSetComponentLatency(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( PopDiagHandleRegistered && EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_LATENCY) )
    result = sub_54B18C();
  else
    result = PopPepComponentSetLatency(*(_DWORD *)(a1 + 32), a2, a3, a4);
  return result;
}
