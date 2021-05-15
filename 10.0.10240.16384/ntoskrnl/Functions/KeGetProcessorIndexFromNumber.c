// KeGetProcessorIndexFromNumber 
 
unsigned int __fastcall KeGetProcessorIndexFromNumber(int a1)
{
  unsigned int result; // r0

  if ( *(_BYTE *)(a1 + 3) )
    return -1;
  if ( *(_WORD *)a1 || (result = *(unsigned __int8 *)(a1 + 2), result >= KeNumberProcessors_0) )
    result = -1;
  return result;
}
