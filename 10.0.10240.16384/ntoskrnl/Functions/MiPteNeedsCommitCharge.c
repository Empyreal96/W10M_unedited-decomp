// MiPteNeedsCommitCharge 
 
int __fastcall MiPteNeedsCommitCharge(_DWORD *a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v5; // r2
  bool v6; // zf
  unsigned int *v8; // [sp+0h] [bp-8h] BYREF

  v8 = a4;
  v5 = a1[7];
  if ( (v5 & 7) == 2 && (v5 & 0xF8) != 8 && (MiGetProtoPteAddress(a1, (a2 >> 2) & 0xFFFFF, 1, &v8), v8) )
    v6 = (v8[4] & 0xA) == 10;
  else
    v6 = (a1[7] & 0x28) == 40;
  return !v6;
}
