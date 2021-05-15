// MmGetAvailablePagesBelowPriority 
 
int __fastcall MmGetAvailablePagesBelowPriority(int a1)
{
  return MiGetAvailablePagesBelowPriority(MiSystemPartition, a1);
}
