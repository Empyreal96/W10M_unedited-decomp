// MiGetReadyInPageBlock 
 
unsigned int __fastcall MiGetReadyInPageBlock(int a1)
{
  _DWORD *v1; // r6
  unsigned int v2; // r4
  int v3; // r5

  v1 = MiLocateVadEvent(a1, 8);
  v2 = v1[2];
  while ( *(_DWORD *)(v2 + 100) != 1 )
  {
    v3 = MiGetInPageSupportBlock(0);
    if ( v3 )
    {
      MiFreeInPageSupportBlock(v2);
      v1[2] = v3;
      v2 = v3;
      break;
    }
    KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
  }
  MiInitializeInPageSupport(v2, 0);
  return v2;
}
