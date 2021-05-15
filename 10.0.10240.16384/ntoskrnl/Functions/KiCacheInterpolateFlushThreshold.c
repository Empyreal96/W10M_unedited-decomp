// KiCacheInterpolateFlushThreshold 
 
void __fastcall __noreturn KiCacheInterpolateFlushThreshold(int a1, int a2, _BYTE *a3, unsigned int a4, unsigned __int8 a5)
{
  unsigned int v7; // r6
  unsigned int v8; // r5
  int v9; // r3

  v7 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x7C);
  v8 = a4 >> 1;
  IoBuildPartialMdl(a1, a2, (unsigned int)a3, a4 >> 1);
  v9 = v7;
  if ( v7 >= v8 )
    v9 = a4 >> 1;
  KiCacheFlushTrial(a2, a3, a5, v9);
}
