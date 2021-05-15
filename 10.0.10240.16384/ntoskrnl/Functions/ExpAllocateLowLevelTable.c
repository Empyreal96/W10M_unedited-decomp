// ExpAllocateLowLevelTable 
 
_DWORD *__fastcall ExpAllocateLowLevelTable(int a1, int a2)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExpAllocateTablePagedPoolNoZero(*(_DWORD *)(a1 + 12), 4096);
  if ( !result )
    return 0;
  result[1] = a2;
  *result = 0;
  return result;
}
