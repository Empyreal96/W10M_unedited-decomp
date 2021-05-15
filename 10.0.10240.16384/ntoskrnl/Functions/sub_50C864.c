// sub_50C864 
 
void __fastcall sub_50C864(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  BOOL v7; // r2

  v7 = *(_BYTE *)(a1 + 132) == 2
    && *(_DWORD *)(a1 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  EtwTraceEnqueueWork(a1, a7, v7);
  JUMPOUT(0x47F23E);
}
