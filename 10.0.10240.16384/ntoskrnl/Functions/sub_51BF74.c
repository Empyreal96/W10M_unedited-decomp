// sub_51BF74 
 
void sub_51BF74()
{
  int v0; // r5
  int v1; // r0
  int v2; // r3
  unsigned int *v3; // r2
  unsigned int v4; // r4
  unsigned int v5; // r3

  v1 = *(_DWORD *)(v0 + 20);
  if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != v1 )
  {
    v2 = (int)*(&KiProcessorBlock + v1);
    __dmb(0xBu);
    v3 = (unsigned int *)(v2 + 1676);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 2, v3) );
    __dmb(0xBu);
    v5 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v5 & 0xFFFFF000) + 0x1414);
    HalSendSoftwareInterrupt(v1, 2);
  }
  JUMPOUT(0x445F86);
}
