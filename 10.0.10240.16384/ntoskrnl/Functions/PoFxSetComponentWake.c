// PoFxSetComponentWake 
 
int __fastcall PoFxSetComponentWake(int a1, int a2, int a3)
{
  int result; // r0

  if ( PopDiagHandleRegistered && EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_COMPONENT_WAKE) )
    result = sub_5245D4();
  else
    result = PopPepComponentSetWakeHint(*(_DWORD *)(a1 + 32), a2, a3);
  return result;
}
