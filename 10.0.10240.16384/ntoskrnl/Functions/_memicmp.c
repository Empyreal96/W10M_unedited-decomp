// _memicmp 
 
int __fastcall memicmp(int a1, unsigned __int8 *a2, int a3)
{
  return _ascii_memicmp(a1, a2, a3);
}
