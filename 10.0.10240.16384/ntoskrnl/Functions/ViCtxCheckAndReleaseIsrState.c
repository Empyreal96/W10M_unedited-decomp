// ViCtxCheckAndReleaseIsrState 
 
int __fastcall ViCtxCheckAndReleaseIsrState(int a1, int a2)
{
  int result; // r0
  int v5; // r2
  unsigned int v6; // r2

  result = KeGetCurrentIrql(a1);
  v5 = *(unsigned __int8 *)(a1 + 8);
  *(_BYTE *)(a1 + 9) = result;
  if ( v5 != result )
  {
    VfUtilDbgPrint((int)"Interrupt Service Routine %p has changed IRQL.\n"
                        "IRQL before executing ISR: %d. IRQL after executing ISR: %d.\n");
    VfErrorStoreTriageInformation(196, 273, a2, *(unsigned __int8 *)(a1 + 8), *(unsigned __int8 *)(a1 + 9));
    __assertfail();
    JUMPOUT(0x8F9470);
  }
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)a1);
  while ( __strex(0, (unsigned int *)a1) );
  __dmb(0xBu);
  return result;
}
