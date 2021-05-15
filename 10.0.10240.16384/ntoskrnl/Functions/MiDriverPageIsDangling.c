// MiDriverPageIsDangling 
 
int __fastcall MiDriverPageIsDangling(int result)
{
  int v1; // r2

  v1 = dword_632F3C;
  if ( (*(_DWORD *)(result + 20) & 0x8000000) != 0 )
    --*(_DWORD *)(dword_632F3C + 116);
  --*(_DWORD *)(v1 + 120);
  return result;
}
