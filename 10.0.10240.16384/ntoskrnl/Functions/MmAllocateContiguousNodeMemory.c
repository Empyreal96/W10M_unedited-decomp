// MmAllocateContiguousNodeMemory 
 
int __fastcall MmAllocateContiguousNodeMemory(int a1, __int64 a2, __int64 a3, __int16 a4, int a5, int a6)
{
  unsigned int v7; // r4
  unsigned int v9; // r0
  __int16 v10; // r1
  unsigned int v11; // r2
  int varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = a1;
  v7 = a2 >> 12;
  if ( (a2 & 0xFFF) != 0 )
    ++v7;
  if ( (a4 & 0xFFF) == 0 )
  {
    v9 = MiMakeProtectionMask(a6);
    if ( (v10 & 0x100) == 0 && v9 != -1 && (v9 & 1) == 0 && (v9 & 4) != 0 )
    {
      if ( (v9 & 2) == 0 )
      {
LABEL_9:
        v11 = a3 >> 12;
        if ( v11 > dword_633850 )
          v11 = dword_633850;
        if ( v7 <= v11 )
          return MiAllocateContiguousMemory(a1, v7);
        return 0;
      }
      if ( v9 >> 3 != 1 )
      {
        if ( v9 >> 3 == 3 )
          return sub_512578();
        goto LABEL_9;
      }
    }
  }
  return 0;
}
