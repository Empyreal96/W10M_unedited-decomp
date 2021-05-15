// KeQuerySystemTime 
 
_DWORD *__fastcall KeQuerySystemTime(_DWORD *result)
{
  int v1; // r3
  int v2; // r3

  v1 = MEMORY[0xFFFF9018];
  __dmb(0xBu);
  result[1] = v1;
  v2 = MEMORY[0xFFFF9014];
  __dmb(0xBu);
  *result = v2;
  if ( result[1] != MEMORY[0xFFFF901C] )
    result = (_DWORD *)sub_50EC10();
  return result;
}
