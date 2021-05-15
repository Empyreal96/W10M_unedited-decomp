// sub_50B420 
 
void sub_50B420()
{
  int v0; // r5
  int v1; // r6
  BOOL v2; // r2

  v2 = *(_BYTE *)(v0 + 132) == 2
    && *(_DWORD *)(v0 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  EtwTraceEnqueueWork(v0, v1, v2);
  JUMPOUT(0x45F88A);
}
