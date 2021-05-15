// MiStoreEvictThread 
 
int __fastcall MiStoreEvictThread(int a1)
{
  int v2; // r4
  int result; // r0

  KeWaitForSingleObject(a1 + 4, 26, 0);
  v2 = *(_DWORD *)(a1 + 20);
  result = ExFreePoolWithTag(a1, 0);
  if ( !v2 )
    sub_526F5C(result);
  return result;
}
