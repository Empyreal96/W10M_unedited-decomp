// KeFreeCalloutStack 
 
unsigned int __fastcall KeFreeCalloutStack(unsigned int a1)
{
  unsigned int v1; // r4
  int v2; // r5
  unsigned int v3; // r7
  unsigned int v4; // r6

  v1 = a1;
  v2 = *(_BYTE *)(a1 + 4) != 0;
  v3 = 0;
  if ( *(_BYTE *)(a1 + 5) )
  {
    v4 = a1;
    do
    {
      MmDeleteKernelStack(*(_DWORD *)(v4 + 40), v2);
      ++v3;
      *(_DWORD *)(v4 + 40) = MmBadPointer + 4096;
      v4 += 4;
    }
    while ( v3 < *(unsigned __int8 *)(v1 + 5) );
  }
  return ExFreePoolWithTag(v1);
}
