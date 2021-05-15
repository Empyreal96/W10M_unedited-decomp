// MiFlushCacheRange 
 
int __fastcall MiFlushCacheRange(int a1, unsigned int a2)
{
  int result; // r0
  int v5; // r4

  if ( a2 < dword_633828 )
  {
    v5 = KfRaiseIrql(2);
    MI_FLUSH_CACHE_DUE_TO_ATTRIBUTE_CHANGE(a1, a2, 3);
    KfLowerIrql(v5);
    result = 0;
  }
  else
  {
    KeInvalidateAllCaches(a1, a2, (int)MiState, ++dword_633820);
    result = 1;
  }
  return result;
}
