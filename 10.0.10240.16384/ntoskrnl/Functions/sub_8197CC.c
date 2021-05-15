// sub_8197CC 
 
int __fastcall sub_8197CC(int a1, int a2)
{
  int v3; // r7
  int v4; // r2
  int v5; // r0
  int (__fastcall *v6)(int); // [sp-4h] [bp-4h]

  if ( *(_DWORD *)(a2 + 100) != a2 + 100 && !*(_WORD *)(a2 + 310) )
    KiCheckForKernelApcDelivery(a1);
  if ( v3 && (v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v4 == PsInitialSystemProcess) )
  {
    v5 = PnpDelayedRemoveWorker(0, a2, v4, PsInitialSystemProcess);
  }
  else
  {
    dword_630BC8 = (int)PnpDelayedRemoveWorker;
    dword_630BCC = 0;
    PnpDelayedRemoveWorkItem = 0;
    v5 = ExQueueWorkItem(&PnpDelayedRemoveWorkItem, 1);
  }
  return v6(v5);
}
