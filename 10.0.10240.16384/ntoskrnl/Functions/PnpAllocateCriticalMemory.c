// PnpAllocateCriticalMemory 
 
int __fastcall PnpAllocateCriticalMemory(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = ExAllocatePoolWithTag(a2, a3, a4);
  if ( !result )
    result = sub_7E050C();
  return result;
}
