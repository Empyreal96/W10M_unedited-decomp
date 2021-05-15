// MiComputeFaultCluster 
 
int __fastcall MiComputeFaultCluster(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  __int64 v6; // kr00_8
  unsigned int v8; // lr
  unsigned int v9; // r10
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r9
  int v13; // r5
  unsigned int v14; // r4
  int v16; // r5
  int v17; // r7
  unsigned int v18; // r3
  unsigned int v19; // [sp+0h] [bp-38h]
  int v21; // [sp+8h] [bp-30h]
  int v23; // [sp+18h] [bp-20h]

  v6 = *(_QWORD *)(a2 + 8);
  v5 = HIDWORD(v6);
  v19 = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 8 * HIDWORD(v6)) + (*(_DWORD *)(a2 + 16) << 12);
  v23 = *(_DWORD *)(a2 + 16);
  v8 = *(_DWORD *)(MiAdvanceFaultList(a2) + 12);
  v9 = 1;
  if ( v8 < (unsigned int)v6 )
  {
    v10 = v19;
    v11 = 0;
    v12 = ((v19 >> 10) & 0x3FFFFC) - 1073741820;
    v13 = a1;
    v14 = 256;
    v21 = 0;
    if ( a4 )
      return sub_52116C();
    if ( a3 )
    {
      if ( *(_DWORD *)(a3 + 16) - (v19 >> 12) + 1 < 0x100 )
        v14 = *(_DWORD *)(a3 + 16) - (v19 >> 12) + 1;
      if ( (*(_DWORD *)(a3 + 32) & 0x7FFFFFFF) != 0 )
      {
        v11 = 1;
        v21 = 1;
        a3 = 0;
      }
    }
    if ( v14 > 1 )
    {
      while ( 1 )
      {
        if ( !a3 )
        {
          if ( (v12 & 0xFFF) == 0 || (v18 = *(_DWORD *)v12, (*(_DWORD *)v12 & 2) != 0) )
          {
LABEL_15:
            v5 = HIDWORD(v6);
            break;
          }
          if ( v11 )
          {
            if ( (v18 & 0x400) == 0 )
              goto LABEL_15;
          }
          else
          {
            if ( (v18 & 0xC00) != 0 || (v18 & 0x10) == 0 || ((v18 >> 2) & 1) == *(_DWORD *)(v13 + 668) )
              goto LABEL_15;
            v10 = v19;
          }
          v12 += 4;
        }
        v16 = *(_DWORD *)(a2 + 16);
        v17 = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 8 * v8);
        if ( ((v17 + (v16 << 12)) & 0xFFFFF000) - 4096 == (v10 & 0xFFFFF000) )
        {
          ++v9;
          MiAdvanceFaultList(a2);
          v8 = *(_DWORD *)(a2 + 12);
          if ( v8 != (_DWORD)v6 )
          {
            v10 = v17 + (v16 << 12);
            v11 = v21;
            v13 = a1;
            v19 = v10;
            if ( v9 < v14 )
              continue;
          }
        }
        goto LABEL_15;
      }
    }
  }
  *(_DWORD *)(a2 + 12) = v5;
  *(_DWORD *)(a2 + 16) = v23;
  return v9;
}
