// sub_7F79D0 
 
void sub_7F79D0()
{
  const void *v0; // r5
  int v1; // r6
  int v2; // r4

  v2 = *(_DWORD *)(v1 + 192);
  __dmb(0xBu);
  if ( (v2 & 0x40000008) == 0 )
    PspCatchCriticalBreak("Terminating critical thread 0x%p (in %s)\n", v0, (const char *)(v1 + 360));
  JUMPOUT(0x71CA2E);
}
