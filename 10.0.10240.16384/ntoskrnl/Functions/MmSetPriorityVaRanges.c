// MmSetPriorityVaRanges 
 
_DWORD *__fastcall MmSetPriorityVaRanges(int a1, unsigned int *a2, int a3)
{
  return MiSetPriorityVaRanges((_DWORD *)1, a2, a3);
}
