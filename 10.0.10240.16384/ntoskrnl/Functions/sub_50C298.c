// sub_50C298 
 
void sub_50C298()
{
  int v0; // r9
  int v1; // lr
  BOOL v2; // r2

  v2 = *(_BYTE *)(v1 + 132) == 2
    && *(_DWORD *)(v1 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  EtwTraceEnqueueWork(v1, v0, v2);
  JUMPOUT(0x4729CA);
}
