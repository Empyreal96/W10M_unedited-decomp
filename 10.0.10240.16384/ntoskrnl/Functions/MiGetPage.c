// MiGetPage 
 
int __fastcall MiGetPage(int a1, unsigned int a2, int a3)
{
  int v3; // r6
  unsigned int i; // r10
  int v7; // r4
  int v8; // r7
  int v9; // r6
  int v11; // r0
  unsigned int v12; // r2
  int v13; // [sp+0h] [bp-28h]

  v3 = a2;
  v13 = 0;
  for ( i = a2 >> byte_6337F5;
        ;
        v3 = (*(unsigned __int16 *)(dword_6337E4 + 2 * (v11 + (unsigned __int16)KeNumberNodes * i)) << byte_6337F5) | dword_633814 & v3 )
  {
    v7 = MiGetFreeOrZeroPage(a1, v3, a3);
    if ( v7 != -1 )
      break;
    v11 = v13 + 1;
    v13 = v11;
    if ( v11 == (unsigned __int16)KeNumberNodes )
    {
      if ( (a3 & 1) != 0 )
        return -1;
      if ( (a3 & 4) == 0 )
      {
        v12 = *(_DWORD *)(a1 + 3712);
        if ( v12 < 0x80
          && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v12 < 2)
          && ((__int16 *)a1 == MiSystemPartition || v12 < 2) )
        {
          return -1;
        }
      }
      if ( (a3 & 0x10) != 0 )
        return -1;
      v7 = MiRemoveLowestPriorityStandbyPage(a1, 8);
      if ( v7 == -1 )
        return -1;
      break;
    }
  }
  v8 = MmPfnDatabase + 24 * v7;
  if ( (a3 & 0x80) != 0 )
  {
    v9 = 1;
  }
  else if ( (a3 & 0x100) != 0 )
  {
    v9 = 0;
  }
  else if ( (a3 & 0x200) != 0 )
  {
    v9 = 2;
  }
  else
  {
    v9 = 3;
  }
  if ( (a3 & 0x40) != 0 && *(_DWORD *)(v8 + 8) )
  {
    MiZeroPhysicalPage(v7, 1, v9);
    *(_DWORD *)(v8 + 8) = 0;
  }
  if ( v9 != 3 && *(unsigned __int8 *)(v8 + 18) >> 6 != v9 )
    MiChangePageAttribute(v8, v9, 2);
  return v7;
}
