// EtwpDeleteRealTimeConnectionObject 
 
int __fastcall EtwpDeleteRealTimeConnectionObject(int a1)
{
  ZwClose();
  ObfDereferenceObject(*(_DWORD *)(a1 + 24));
  return ObfDereferenceObject(*(_DWORD *)(a1 + 28));
}
