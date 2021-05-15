// KeGetCurrentProcessorNumberEx 
 
int __fastcall KeGetCurrentProcessorNumberEx(int a1)
{
  unsigned int v1; // r2

  v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( a1 )
  {
    *(_WORD *)a1 = *(unsigned __int8 *)(v1 + 2460);
    *(_BYTE *)(a1 + 2) = *(_BYTE *)(v1 + 2461);
    *(_BYTE *)(a1 + 3) = 0;
  }
  return *(_DWORD *)(v1 + 1428);
}
