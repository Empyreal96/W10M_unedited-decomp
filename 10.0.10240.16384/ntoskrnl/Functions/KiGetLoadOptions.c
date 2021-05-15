// KiGetLoadOptions 
 
int KiGetLoadOptions()
{
  return *((_DWORD *)KeLoaderBlock_0 + 30);
}
