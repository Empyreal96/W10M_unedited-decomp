// ArbStartArbiter 
 
int __fastcall ArbStartArbiter(int a1, int a2)
{
  RtlFreeRangeList(*(_DWORD **)(a1 + 20));
  return (*(int (__fastcall **)(int, _DWORD, int, _DWORD))(a1 + 140))(
           a1,
           *(_DWORD *)(a2 + 16),
           a2 + 20,
           *(_DWORD *)(a1 + 20));
}
