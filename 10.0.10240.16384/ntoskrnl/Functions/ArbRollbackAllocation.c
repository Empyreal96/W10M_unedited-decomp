// ArbRollbackAllocation 
 
int __fastcall ArbRollbackAllocation(int a1)
{
  RtlFreeRangeList(*(_DWORD **)(a1 + 24));
  return 0;
}
