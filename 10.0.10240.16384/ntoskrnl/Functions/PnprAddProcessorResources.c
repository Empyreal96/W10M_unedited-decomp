// PnprAddProcessorResources 
 
int __fastcall PnprAddProcessorResources(int a1, unsigned int a2, int a3, int a4)
{
  _DWORD *v5; // r4
  __int64 v7; // r0
  int v9; // r7
  int v10; // r0
  _DWORD *v11; // r6
  int v12; // r3
  int v13; // r2
  int v14; // r2
  int result; // r0
  int v16; // r0
  char v17; // r3
  unsigned int v18; // r2

  v5 = *(_DWORD **)a4;
  v7 = *(_QWORD *)(*(_DWORD *)a4 + 8);
  if ( HIDWORD(v7) == (_DWORD)v7 )
  {
    v9 = HIDWORD(v7) + 4;
    v10 = ExAllocatePoolWithTag(512, 4 * (HIDWORD(v7) + 8), 1366322768);
    v11 = (_DWORD *)v10;
    if ( !v10 )
    {
      v12 = PnprContext;
      v13 = *(_DWORD *)(PnprContext + 608);
      if ( !v13 )
        v13 = 820;
      *(_DWORD *)(PnprContext + 608) = v13;
      v14 = *(_DWORD *)(v12 + 612);
      if ( !v14 )
        v14 = 10;
      result = -1073741670;
      *(_DWORD *)(v12 + 612) = v14;
      return result;
    }
    memmove(v10, (int)v5, 4 * v9);
    ExFreePoolWithTag((unsigned int)v5);
    v5 = v11;
    v11[2] = v9;
  }
  if ( a2 != -1 )
  {
    if ( a2 )
    {
      if ( a2 < 0x20 && (v18 = KiProcessorIndexToNumberMappingTable[a2]) != 0 )
      {
        v16 = (unsigned __int16)(v18 >> 6);
        v17 = v18 & 0x3F;
      }
      else
      {
        v17 = 0;
        v16 = 0;
      }
    }
    else
    {
      v16 = 0;
      v17 = 0;
    }
    *(_DWORD *)(*v5 + 4 * v16) |= 1 << v17;
  }
  v5[v5[3]++ + 4] = a3;
  *(_DWORD *)a4 = v5;
  return 0;
}
