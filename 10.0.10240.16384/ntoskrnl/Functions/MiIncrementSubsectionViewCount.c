// MiIncrementSubsectionViewCount 
 
int __fastcall MiIncrementSubsectionViewCount(int a1)
{
  ++*(_DWORD *)(a1 + 60);
  return 1;
}
