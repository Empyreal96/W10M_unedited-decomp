// PoFxSetComponentResidency 
 
int __fastcall PoFxSetComponentResidency(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( PopDiagHandleRegistered && EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_RESIDENCY) )
    result = sub_55431C();
  else
    result = PopPepComponentSetResidency(*(_DWORD *)(a1 + 32), a2, a3, a4);
  return result;
}
