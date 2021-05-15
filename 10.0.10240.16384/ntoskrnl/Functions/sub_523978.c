// sub_523978 
 
void sub_523978()
{
  int v0; // r5
  int v1; // r6
  BOOL v2; // r2

  v2 = *(_BYTE *)(v1 + 132) == 2
    && *(_DWORD *)(v1 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  EtwTraceEnqueueWork(v1, v0, v2);
  JUMPOUT(0x45AC60);
}
