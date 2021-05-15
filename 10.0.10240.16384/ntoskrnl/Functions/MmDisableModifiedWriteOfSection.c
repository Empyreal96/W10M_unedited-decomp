// MmDisableModifiedWriteOfSection 
 
int __fastcall MmDisableModifiedWriteOfSection(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r0
  unsigned int v6; // r3
  int v8; // [sp+0h] [bp-8h] BYREF

  v8 = a4;
  v4 = 1;
  v5 = (_DWORD *)MiLockSectionControlArea(a1, 1, &v8);
  if ( !v5 )
    return 0;
  v6 = v5[7];
  if ( v5[5] )
    v4 = (v6 >> 3) & 1;
  else
    v5[7] = v6 | 8;
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_529D7C();
  __dmb(0xBu);
  v5[9] = 0;
  KfLowerIrql((unsigned __int8)v8);
  return v4;
}
