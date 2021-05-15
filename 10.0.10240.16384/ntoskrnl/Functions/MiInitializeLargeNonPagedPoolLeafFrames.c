// MiInitializeLargeNonPagedPoolLeafFrames 
 
int __fastcall MiInitializeLargeNonPagedPoolLeafFrames(unsigned int a1, int a2)
{
  unsigned int v2; // r7
  __int16 v3; // r5
  int v4; // r6
  unsigned int v5; // r8
  int v6; // r5
  unsigned int *v7; // r4
  unsigned __int8 *v8; // r1
  unsigned int v9; // r2
  int v11; // r3
  unsigned int v12; // r1
  int v13; // [sp+0h] [bp-20h]

  v2 = a1;
  v3 = a2;
  v4 = MmPfnDatabase + 24 * a2;
  v5 = *(_DWORD *)((((((a1 >> 10) & 0x3FFFFC) - 1073741821) >> 10) & 0x3FFFFC) - 0x40000000);
  v13 = KfRaiseIrql(2);
  v6 = 1024 - (v3 & 0x3FF);
  do
  {
    v7 = (unsigned int *)(v4 + 12);
    v8 = (unsigned __int8 *)(v4 + 15);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      return sub_50EF18(1);
    v11 = *(_DWORD *)(v4 + 12);
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = v2;
    *(_WORD *)(v4 + 16) = 1;
    *(_DWORD *)(v4 + 12) = v11 & 0xC0000000 | 1;
    *(_BYTE *)(v4 + 18) = *(_BYTE *)(v4 + 18) & 0xF8 | 6;
    *(_DWORD *)(v4 + 20) = *(_DWORD *)(v4 + 20) & 0xF8F00000 | (v5 >> 12);
    __dmb(0xBu);
    do
      v12 = __ldrex(v7);
    while ( __strex(v12 & 0x7FFFFFFF, v7) );
    v4 += 24;
    v2 += 4;
    --v6;
  }
  while ( v6 );
  return KfLowerIrql(v13);
}
