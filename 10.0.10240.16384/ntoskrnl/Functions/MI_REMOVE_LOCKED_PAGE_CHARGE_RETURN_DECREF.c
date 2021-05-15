// MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF 
 
int __fastcall MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(int a1)
{
  int v1; // r4
  int v2; // r3
  int v3; // r2
  int v4; // r5
  unsigned int v5; // r6
  unsigned int v6; // r2
  unsigned int v7; // r7
  int v8; // lr
  unsigned int v9; // r3
  unsigned int *v10; // r0
  int v11; // r1
  unsigned int v12; // r4
  unsigned int v13; // r4
  unsigned int v15; // r2
  unsigned int v16; // r4

  if ( !*(_WORD *)(a1 + 16) )
    sub_50E680();
  v1 = *(_DWORD *)(a1 + 12);
  v2 = (unsigned __int16)(*(_WORD *)(a1 + 16) - 1);
  *(_WORD *)(a1 + 16) = v2;
  v3 = v1 & 0x3FFFFFFF;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      if ( v3 || (*(_BYTE *)(a1 + 18) & 8) != 0 )
      {
LABEL_6:
        v4 = 0;
        goto LABEL_7;
      }
    }
    else if ( v2 == 2 && v3 && (*(_BYTE *)(a1 + 18) & 8) != 0 )
    {
      goto LABEL_6;
    }
    return 0;
  }
  v4 = 1;
LABEL_7:
  v5 = (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000;
  v6 = *(_DWORD *)(a1 + 4) | 0x80000000;
  if ( v6 > v5 || v6 < 0xC0000000 )
  {
    v7 = *(unsigned __int8 *)(a1 + 19);
    if ( ((v7 >> 5) & 1) != 0 )
    {
      *(_BYTE *)(a1 + 19) = v7 & 0xDF;
      return v4;
    }
  }
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 && (*(_DWORD *)(a1 + 8) & 0x400) != 0
    || v6 <= v5 && v6 >= 0xC0000000 && ((*(unsigned __int8 *)(a1 + 19) >> 5) & 1) != 0
    || v4 == 1 && (v1 & 0x40000000) != 0 )
  {
    MiReturnCommit(MiSystemPartition, 1);
  }
  v8 = 1;
  v9 = (unsigned int)KeGetPcr();
  v10 = (unsigned int *)((v9 & 0xFFFFF000) + 4992);
  v11 = *(_DWORD *)((v9 & 0xFFFFF000) + 0x1380);
  if ( v11 != -1 )
  {
    if ( (unsigned int)(v11 + 1) <= 0x100 )
    {
      do
      {
        do
          v12 = __ldrex(v10);
        while ( v12 == v11 && __strex(v11 + 1, v10) );
        if ( v12 == v11 )
          goto LABEL_17;
        v11 = v12;
      }
      while ( v12 != -1 && v12 + 1 <= 0x100 );
    }
    if ( v11 > 192 )
    {
      do
        v15 = __ldrex(v10);
      while ( v15 == v11 && __strex(0xC0u, v10) );
      if ( v15 == v11 )
        v8 = v11 - 191;
    }
  }
  do
    v16 = __ldrex((unsigned int *)&dword_640600);
  while ( __strex(v16 + v8, (unsigned int *)&dword_640600) );
  do
LABEL_17:
    v13 = __ldrex(&dword_634A2C[117]);
  while ( __strex(v13 + 1, &dword_634A2C[117]) );
  return v4;
}
