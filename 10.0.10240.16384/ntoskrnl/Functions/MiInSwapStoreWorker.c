// MiInSwapStoreWorker 
 
unsigned int __fastcall MiInSwapStoreWorker(unsigned int a1)
{
  int v2; // r5
  _BYTE v4[40]; // [sp-4h] [bp-28h] BYREF

  KiStackAttachProcess(*(_DWORD *)(a1 + 16), 0, (int)v4);
  v2 = SmSwapStore(2);
  KeSetEvent(a1 + 20, 0, 0);
  if ( v2 < 0 )
    EtwTraceWorkingSetInSwapStoreFail(*(_DWORD *)(a1 + 16), v2);
  KiUnstackDetachProcess((unsigned int)v4, 0);
  ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 16));
  return MiInSwapStoreContextDereference(a1);
}
