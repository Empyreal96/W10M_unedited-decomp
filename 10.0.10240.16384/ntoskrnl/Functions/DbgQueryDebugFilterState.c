// DbgQueryDebugFilterState 
 
int __fastcall DbgQueryDebugFilterState(unsigned int a1, unsigned int a2)
{
  return NtQueryDebugFilterState(a1, a2);
}
