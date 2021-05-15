// SmKmStoreDeleteWhenEmptyWorker 
 
int __fastcall SmKmStoreDeleteWhenEmptyWorker(int a1)
{
  return SmKmStoreDelete(a1 - 20 - 96 * (*(_DWORD *)(*(_DWORD *)(a1 - 20) + 3512) & 0x1F));
}
