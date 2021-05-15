// VfGetPristineDispatchRoutine 
 
int __fastcall VfGetPristineDispatchRoutine(int a1, unsigned int a2)
{
  int result; // r0
  int v5; // r3

  if ( a2 > 0x1B )
    return 0;
  if ( !MmIsDriverVerifying(a1)
    || (v5 = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 32)) == 0
    || (result = *(_DWORD *)(v5 + 4 * a2 + 16)) == 0 )
  {
    result = *(_DWORD *)(a1 + 4 * (a2 + 14));
  }
  return result;
}
