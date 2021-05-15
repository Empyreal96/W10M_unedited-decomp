// BgpFwAllocateMemory 
 
int __fastcall BgpFwAllocateMemory(unsigned int a1)
{
  int v2; // r5
  int v3; // r4
  BOOL v4; // r8
  int v5; // r10
  int v6; // r9
  unsigned int v7; // r6
  int v8; // r0
  int *v9; // r1
  int v10; // lr
  _DWORD *v11; // r0
  int v12; // r0

  if ( !a1 )
    return sub_50EE84();
  if ( (dword_619018 & 0x800) != 0 )
    return BgpFwReserveAllocate();
  v2 = 0;
  v3 = 0;
  v4 = (dword_619018 & 0x8000) != 0;
  if ( (dword_619018 & 0x8000) != 0 )
  {
    v5 = 1262634818;
    v6 = 32;
  }
  else
  {
    v5 = 1263093570;
    v6 = 16;
  }
  v7 = v6 + a1;
  if ( v6 + a1 >= a1 && v7 < 0xFFFFEFFF )
  {
    if ( v7 < 0x1000 )
    {
      v8 = ExAllocatePoolWithTag(512, v6 + a1);
LABEL_10:
      if ( !v8 )
        goto LABEL_23;
      v2 = v6 + v8;
      v9 = (int *)(v6 + v8 - 12);
      if ( v4 )
      {
        v10 = dword_61909C;
        v11 = (_DWORD *)(v6 + v8 - 20);
        *v11 = dword_61909C;
        v11[1] = &dword_61909C;
        if ( *(int **)(v10 + 4) != &dword_61909C )
          __fastfail(3u);
        *(_DWORD *)(v10 + 4) = v11;
        dword_61909C = (int)v11;
      }
      *v9 = v5;
      v9[1] = v7;
      v9[2] = v3;
      if ( !v2 )
      {
LABEL_23:
        if ( v3 )
        {
          MiFreePagesFromMdl(MiSystemPartition, v3, 0);
          ExFreePoolWithTag(v3, 0);
        }
      }
      return v2;
    }
    v7 = (v7 + 4095) & 0xFFFFF000;
    v12 = MmAllocatePagesForMdlEx(0, 0, -1, -1, 0, 0, v7, 1, 5);
    v3 = v12;
    if ( v12 )
    {
      if ( (*(_WORD *)(v12 + 6) & 5) != 0 )
        v8 = *(_DWORD *)(v12 + 12);
      else
        v8 = MmMapLockedPagesSpecifyCache(v12, 0, 1, 0, 0, 1073741840);
      goto LABEL_10;
    }
  }
  return v2;
}
