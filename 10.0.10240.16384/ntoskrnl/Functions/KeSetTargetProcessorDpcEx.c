// KeSetTargetProcessorDpcEx 
 
int __fastcall KeSetTargetProcessorDpcEx(int a1, int a2)
{
  unsigned int v2; // r2

  if ( *(_BYTE *)(a2 + 3) )
    return -1073741811;
  if ( *(_WORD *)a2 || (v2 = *(unsigned __int8 *)(a2 + 2), v2 >= KeNumberProcessors_0) )
    v2 = -1;
  if ( v2 == -1 )
    return -1073741811;
  *(_WORD *)(a1 + 2) = v2 + 32;
  return 0;
}
