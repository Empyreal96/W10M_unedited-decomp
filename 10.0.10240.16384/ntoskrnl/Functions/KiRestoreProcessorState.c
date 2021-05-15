// KiRestoreProcessorState 
 
int __fastcall KiRestoreProcessorState(int a1, int a2)
{
  unsigned int v2; // r4

  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  KeContextToKframes(a1, a2, *(_DWORD *)(v2 + 2712), **(_DWORD **)(v2 + 2712));
  return KiRestoreProcessorControlState(v2 + 1440);
}
