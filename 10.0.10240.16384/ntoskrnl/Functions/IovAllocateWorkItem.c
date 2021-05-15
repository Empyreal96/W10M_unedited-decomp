// IovAllocateWorkItem 
 
_DWORD *__fastcall IovAllocateWorkItem(int a1, int a2)
{
  _DWORD *result; // r0

  result = (_DWORD *)VeAllocatePoolWithTagPriority(640, 52, 1769432662, 32, a2);
  if ( result )
  {
    result[8] = 1;
    result[5] = a1;
    result[7] = 0;
    result[2] = IopProcessWorkItem;
    result[3] = result;
    *result = 0;
  }
  return result;
}
