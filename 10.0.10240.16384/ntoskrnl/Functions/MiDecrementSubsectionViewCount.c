// MiDecrementSubsectionViewCount 
 
int __fastcall MiDecrementSubsectionViewCount(int a1)
{
  --*(_DWORD *)(a1 + 60);
  return 0;
}
