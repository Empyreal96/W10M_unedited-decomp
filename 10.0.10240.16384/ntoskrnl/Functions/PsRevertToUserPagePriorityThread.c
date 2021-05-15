// PsRevertToUserPagePriorityThread 
 
int __fastcall PsRevertToUserPagePriorityThread(int result, int a2)
{
  unsigned int v2; // r3
  __int16 v3; // r3

  --*(_WORD *)(result + 310);
  if ( a2 == -1 )
    v2 = *(_DWORD *)(result + 968) & 0xFFFFF0FF;
  else
    v2 = *(_DWORD *)(result + 968) & 0xFFFFF1FF | (a2 << 9);
  *(_DWORD *)(result + 968) = v2;
  v3 = *(_WORD *)(result + 310) + 1;
  *(_WORD *)(result + 310) = v3;
  if ( !v3 && *(_DWORD *)(result + 100) != result + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
