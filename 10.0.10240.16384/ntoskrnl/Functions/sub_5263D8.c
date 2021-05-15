// sub_5263D8 
 
void __fastcall sub_5263D8(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int *v5; // r5
  unsigned int v6; // r1
  unsigned int *v7; // r2
  unsigned int v8; // r1

  PopDiagTraceFxDevicePowerRequirement(*(_DWORD *)(v4 + 28), 0, 0, a4);
  (*(void (__fastcall **)(_DWORD))(v4 + 76))(*(_DWORD *)(v4 + 88));
  __dmb(0xBu);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x40, v5) );
  __dmb(0xBu);
  v7 = (unsigned int *)(v4 + 24);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 - 1, v7) );
  __dmb(0xBu);
  JUMPOUT(0x4616A0);
}
