// PfSnLogPageFaultCommon 
 
int __fastcall PfSnLogPageFaultCommon(int a1, int a2, int *a3, unsigned int *a4, __int64 a5, char a6)
{
  int v8; // r0
  int result; // r0
  int v10; // r7
  int v11; // r4
  int v12; // r5
  int v13; // r3
  unsigned int *v14; // r5
  unsigned int *v15; // r1
  unsigned int v16; // r0
  int *v17; // r2
  unsigned int *v18; // r2
  int *v19; // [sp+0h] [bp-20h] BYREF
  unsigned int *v20; // [sp+4h] [bp-1Ch] BYREF

  v19 = a3;
  v20 = a4;
  v8 = PfSnGetFileInformation();
  if ( (*(_WORD *)(a1 + 344) & 1) == 0 && *(_BYTE *)(*(_DWORD *)(a1 + 264) + 606) == 2 )
    return sub_5376A8(v8);
  if ( HIDWORD(a5) >= 0x40 )
    return -1073739516;
  v10 = a5 >> 9;
  if ( (a6 & 1) != 0 )
  {
    v11 = 1;
  }
  else if ( (a6 & 2) != 0 )
  {
    v11 = 3;
  }
  else
  {
    v11 = 0;
  }
  v12 = dword_643B68;
  v13 = *(_DWORD *)(a1 + 292);
  __dmb(0xBu);
  if ( v12 != v13 && PfSnTraceGetLogEntry(a1, 1, &v20) >= 0 )
  {
    v18 = v20;
    *v20 = *v20 & 0xFFFFFFF8 | 2;
    v18[1] = v12;
    __dmb(0xBu);
    *(_DWORD *)(a1 + 292) = v12;
    __dmb(0xBu);
    *(_DWORD *)(a1 + 296) = a1 + 300;
  }
  if ( v11 || (v17 = *(int **)(a1 + 296), v19 = v17, __dmb(0xBu), (unsigned int)*v17 >> 3 != v10) || (int *)v17[1] != a3 )
  {
    result = PfSnTraceGetLogEntry(a1, 1, &v19);
    if ( result < 0 )
      return result;
    v14 = (unsigned int *)v19;
    *v19 = *v19 & 7 | (8 * v10);
    v14[1] = (unsigned int)a3;
    v15 = (unsigned int *)(a1 + 248);
    *v14 = *v14 & 0xFFFFFFF8 | v11 & 7;
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 + 1, v15) );
    if ( !v11 )
    {
      __dmb(0xBu);
      *(_DWORD *)(a1 + 296) = v14;
    }
  }
  return 0;
}
