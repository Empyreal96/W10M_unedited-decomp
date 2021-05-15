// sub_7D2E98 
 
void sub_7D2E98()
{
  _DWORD *v0; // r6
  unsigned int v1; // r1
  __int16 v2; // r3

  if ( !ExfAcquireRundownProtection(v0) )
  {
    v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v2 = *(_WORD *)(v1 + 0x134) + 1;
    *(_WORD *)(v1 + 308) = v2;
    if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
      KiCheckForKernelApcDelivery(0);
    JUMPOUT(0x6D318A);
  }
  JUMPOUT(0x6D3104);
}
