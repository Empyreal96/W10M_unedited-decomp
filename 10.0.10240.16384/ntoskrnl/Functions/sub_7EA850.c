// sub_7EA850 
 
void sub_7EA850()
{
  int v0; // r4
  int v1; // r0
  unsigned int v2; // r1
  __int16 v3; // r3

  v1 = ExReleaseResourceLite(*(_DWORD *)(v0 + 48));
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(v2 + 0x134) + 1;
  *(_WORD *)(v2 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v1);
  JUMPOUT(0x706752);
}
