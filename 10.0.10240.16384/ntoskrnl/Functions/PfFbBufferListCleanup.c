// PfFbBufferListCleanup 
 
int __fastcall PfFbBufferListCleanup(int a1)
{
  int i; // r0
  int v3; // r0
  int result; // r0

  for ( i = RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 16));
        i;
        i = RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 16)) )
  {
    if ( (*(_DWORD *)(i + 20) & 1) != 0 )
    {
      *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 64) - *(_DWORD *)(i + 12) + i;
      ExFreePoolWithTag(i);
    }
  }
  while ( 1 )
  {
    v3 = RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 8));
    if ( !v3 )
      break;
    if ( (*(_DWORD *)(v3 + 20) & 1) != 0 )
    {
      *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 64) - *(_DWORD *)(v3 + 12) + v3;
      ExFreePoolWithTag(v3);
    }
  }
  while ( 1 )
  {
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 24));
    if ( !result )
      break;
    *(_DWORD *)(a1 + 64) -= *(_DWORD *)(result + 12);
    ExFreePoolWithTag(result);
  }
  return result;
}
