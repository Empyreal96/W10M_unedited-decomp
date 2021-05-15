// MiAddLockedPageCharge 
 
int __fastcall MiAddLockedPageCharge(int a1, char a2)
{
  int v3; // r1
  int v4; // r2
  int v5; // r5
  int v6; // r3
  int v7; // r6
  char v8; // r1
  int v9; // r7
  int result; // r0
  unsigned int *v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r5
  unsigned int v14; // r0

  v3 = a2 & 1;
  if ( !v3 && *(unsigned __int16 *)(a1 + 16) >= 0x7FFFu )
    return 0;
  v4 = *(unsigned __int16 *)(a1 + 16);
  v5 = 1;
  v6 = *(_DWORD *)(a1 + 12) & 0x3FFFFFFF;
  if ( *(_WORD *)(a1 + 16) )
  {
    if ( v4 == 1 )
    {
      if ( !v6 && (*(_BYTE *)(a1 + 18) & 8) == 0 )
        goto LABEL_18;
    }
    else if ( v4 != 2 || !v6 || (*(_BYTE *)(a1 + 18) & 8) == 0 )
    {
      goto LABEL_18;
    }
  }
  if ( v3 )
  {
    v7 = -1;
    v8 = 4;
  }
  else
  {
    v7 = 0;
    v8 = 8;
  }
  v9 = 0;
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) == 0 || (*(_DWORD *)(a1 + 8) & 0x400) == 0 )
  {
    if ( (*(_DWORD *)(a1 + 4) | 0x80000000) <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 )
      return sub_543ED4();
LABEL_10:
    v11 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4992);
    v12 = *v11;
    if ( *v11 )
    {
      while ( v12 != -1 )
      {
        do
          v13 = __ldrex(v11);
        while ( v13 == v12 && __strex(v12 - 1, v11) );
        if ( v13 == v12 )
        {
          v5 = 1;
          goto LABEL_16;
        }
        v12 = v13;
        if ( !v13 )
          break;
      }
    }
    v5 = MiChargePartitionResidentAvailable((int)MiSystemPartition, 1u, v7);
    if ( v5 )
    {
      do
LABEL_16:
        v14 = __ldrex(&dword_634A2C[85]);
      while ( __strex(v14 + 1, &dword_634A2C[85]) );
    }
    else if ( v9 )
    {
      MiReturnCommit((int)MiSystemPartition, 1);
    }
    if ( !v5 )
      return 0;
LABEL_18:
    result = v5;
    ++*(_WORD *)(a1 + 16);
    return result;
  }
  v9 = 1;
  if ( MiChargeCommit((int)MiSystemPartition, 1u, v8) )
    goto LABEL_10;
  return 0;
}
