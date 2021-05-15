// PiDqQueryMakeInconsistent 
 
int __fastcall PiDqQueryMakeInconsistent(int a1)
{
  *(_DWORD *)(a1 + 116) |= 1u;
  return PiDqQueryFreeActiveData(a1);
}
