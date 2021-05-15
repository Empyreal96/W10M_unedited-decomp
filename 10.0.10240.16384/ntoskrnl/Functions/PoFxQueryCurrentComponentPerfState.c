// PoFxQueryCurrentComponentPerfState 
 
int __fastcall PoFxQueryCurrentComponentPerfState(int a1, int a2, unsigned int a3)
{
  if ( a2 || a3 >= *(_DWORD *)(a1 + 388) || !*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a3) + 184) )
    return -1073741811;
  PopFxQueryCurrentComponentPerfState();
  return 0;
}
