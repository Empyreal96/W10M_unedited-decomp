// RawDeleteVcb 
 
int __fastcall RawDeleteVcb(int a1)
{
  ObfDereferenceObject(*(_DWORD *)(a1 + 136));
  return IoDeleteDevice((_DWORD *)(a1 - 184));
}
