// sub_815F1C 
 
void sub_815F1C()
{
  _DWORD *v0; // r4
  int v1; // r5
  int v2; // r0
  unsigned int v3; // r1
  __int16 v4; // r3

  if ( !*v0 )
  {
    v2 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v1);
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = *(_WORD *)(v3 + 0x134) + 1;
    *(_WORD *)(v3 + 308) = v4;
    if ( !v4 && *(_DWORD *)(v3 + 100) != v3 + 100 && !*(_WORD *)(v3 + 310) )
      KiCheckForKernelApcDelivery(v2);
    JUMPOUT(0x7ACBB0);
  }
  JUMPOUT(0x7ACB0A);
}
