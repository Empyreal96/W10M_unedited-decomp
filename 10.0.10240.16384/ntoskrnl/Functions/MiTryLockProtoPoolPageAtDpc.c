// MiTryLockProtoPoolPageAtDpc 
 
int __fastcall MiTryLockProtoPoolPageAtDpc(unsigned int a1, int a2)
{
  unsigned int *v2; // r8
  unsigned int v3; // r3
  unsigned int v5; // r7
  int v6; // r4
  unsigned __int8 *v7; // r3
  unsigned int v9; // r1
  unsigned int v10; // r5
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0

  v2 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v3 = *v2;
  if ( (*v2 & 2) != 0 )
  {
    v5 = v3 >> 12;
    if ( MI_IS_PFN(v3 >> 12) )
    {
      v6 = MmPfnDatabase + 24 * v5;
      v7 = (unsigned __int8 *)(v6 + 15);
      if ( a2 == 1 )
        return sub_51EFE0();
      do
        v9 = __ldrex(v7);
      while ( __strex(v9 | 0x80, v7) );
      __dmb(0xBu);
      if ( !(v9 >> 7) )
      {
        if ( (*(_DWORD *)(v6 + 12) & 0x40000000) == 0 )
        {
          v10 = *v2;
          if ( (*v2 & 2) != 0 && (v10 & 0x100) == 0 && v5 == v10 >> 12 && (*(_BYTE *)(v6 + 18) & 0x20) == 0 )
          {
            MiAddLockedPageCharge(v6, 1);
            *(_BYTE *)(v6 + 18) |= 0x20u;
            if ( (v10 & 0x10) == 0 )
              MI_WRITE_VALID_PTE_VOLATILE(v2, 1);
            __dmb(0xBu);
            v11 = (unsigned int *)(v6 + 12);
            do
              v12 = __ldrex(v11);
            while ( __strex(v12 & 0x7FFFFFFF, v11) );
            return v6;
          }
        }
        __dmb(0xBu);
        v13 = (unsigned int *)(v6 + 12);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 & 0x7FFFFFFF, v13) );
      }
    }
  }
  return 0;
}
