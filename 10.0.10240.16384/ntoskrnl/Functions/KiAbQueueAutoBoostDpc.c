// KiAbQueueAutoBoostDpc 
 
int __fastcall KiAbQueueAutoBoostDpc(int result)
{
  int v1; // r4

  v1 = result;
  if ( !*(_DWORD *)(result + 17432) )
  {
    result = KiInsertQueueDpc(result + 17416);
    *(_DWORD *)(v1 + 17432) = 1;
  }
  return result;
}
