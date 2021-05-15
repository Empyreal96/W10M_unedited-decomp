// KiUpdateNumberProcessors 
 
int __fastcall KiUpdateNumberProcessors(int a1, int a2, int a3)
{
  int v3; // r3
  int v5[8]; // [sp+0h] [bp-20h] BYREF

  v5[0] = a1;
  v5[1] = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v3 = KeNumberProcessors_0 - 1;
  __dmb(0xBu);
  v5[2] = v3;
  __dmb(0xBu);
  v5[3] = v3;
  __dmb(0xBu);
  v5[4] = 0;
  return KeIpiGenericCall((int (__fastcall *)(int))KiUpdateNumberProcessorsIpi, (int)v5, a3, 0);
}
