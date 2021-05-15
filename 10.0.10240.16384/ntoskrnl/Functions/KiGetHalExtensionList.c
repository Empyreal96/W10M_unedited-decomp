// KiGetHalExtensionList 
 
int KiGetHalExtensionList()
{
  return *((_DWORD *)KeLoaderBlock_0 + 33) + 2136;
}
