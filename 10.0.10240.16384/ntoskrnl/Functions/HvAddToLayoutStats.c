// HvAddToLayoutStats 
 
int __fastcall HvAddToLayoutStats(int result, int a2)
{
  *(_DWORD *)(result + 8) += a2;
  ++*(_DWORD *)(result + 12);
  return result;
}
