// KeRestoreProcessorState 
 
void __fastcall __noreturn KeRestoreProcessorState(unsigned int *a1)
{
  __mcr(15, 0, a1[43], 1, 0, 0);
  __mcr(15, 0, a1[45], 1, 0, 2);
  __mcr(15, 0, a1[49], 3, 0, 0);
  __mcr(15, 0, a1[50], 5, 0, 0);
  __mcr(15, 0, a1[51], 5, 0, 1);
  __mcr(15, 0, a1[52], 6, 0, 0);
  __mcr(15, 0, a1[53], 6, 0, 2);
  __mcr(15, 0, a1[123], 10, 2, 0);
  __mcr(15, 0, a1[124], 10, 2, 1);
  __mcr(15, 0, a1[126], 13, 0, 1);
  __mcr(15, 0, a1[125], 12, 0, 0);
  __isb(0xFu);
  KiRestoreProcessorControlState(a1);
  RtlRestoreContext((int)(a1 + 128), 0);
}
