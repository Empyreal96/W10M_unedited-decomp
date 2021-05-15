// PfpMemoryRangesQuery 
 
int __fastcall PfpMemoryRangesQuery(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r8
  int v6; // r0
  int v7; // r5
  int i; // r2
  unsigned int v9; // r9
  unsigned __int64 v10; // kr00_8
  unsigned int v11; // r1
  int v12; // r4
  _DWORD *v13; // r10
  unsigned int j; // lr
  _QWORD *v15; // r0
  _DWORD *v16; // r4
  int v18; // [sp+8h] [bp-30h]
  int varg_r0; // [sp+40h] [bp+8h]

  varg_r0 = a1;
  v4 = a3;
  v18 = (char)a2;
  v6 = MmGetPhysicalMemoryRanges();
  v7 = v6;
  if ( !v6 )
    goto LABEL_16;
  for ( i = v6; *(__int64 *)(i + 8) > 0; i += 16 )
    ;
  v9 = (i - v6) >> 4;
  v10 = 8 * v9 + __PAIR64__(v9 >> 29, 8);
  if ( HIDWORD(v10) )
  {
LABEL_16:
    v12 = -1073741670;
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 16);
    if ( v11 >= (unsigned int)v10 )
    {
      v13 = *(_DWORD **)(a1 + 12);
      if ( v18 )
        ProbeForWrite(*(_DWORD *)(a1 + 12), v11, 4);
      if ( *v13 == 1 )
      {
        v13[1] = v9;
        for ( j = 0; j < v9; ++j )
        {
          v15 = (_QWORD *)(v7 + 16 * j);
          v16 = &v13[2 * j];
          v16[2] = *v15 / 4096i64;
          v16[3] = v15[1] / 4096i64;
        }
        *v4 = v10;
        v12 = 0;
      }
      else
      {
        v12 = -1073741811;
      }
    }
    else
    {
      v12 = -1073741789;
      *v4 = v10;
    }
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v12;
}
