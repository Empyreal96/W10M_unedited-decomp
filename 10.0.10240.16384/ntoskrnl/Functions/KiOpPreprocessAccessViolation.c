// KiOpPreprocessAccessViolation 
 
int __fastcall KiOpPreprocessAccessViolation(int a1, int a2)
{
  int (*v2)(); // r4
  int result; // r0

  if ( (*(_DWORD *)(a2 + 68) & 0x1F) == 16 )
    v2 = (int (*)())KeUserPopEntrySListFault;
  else
    v2 = ExpInterlockedPopEntrySListFault;
  if ( *(int (**)())(a2 + 64) == v2 )
    result = sub_51BC60();
  else
    result = 0;
  return result;
}
