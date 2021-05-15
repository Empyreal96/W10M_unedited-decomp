// KiEndThreadAccountingPeriod 
 
int __fastcall KiEndThreadAccountingPeriod(int result, int a2, unsigned int a3, unsigned int a4)
{
  char v4; // r10
  unsigned int v5; // r6
  unsigned int v6; // r7
  int v7; // r4
  int v8; // r5
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned __int64 *v13; // r4
  unsigned __int64 v14; // kr08_8
  unsigned __int64 v15; // kr10_8
  int v16; // r1
  int i; // r1
  int v18; // r9

  v4 = *(_BYTE *)(a2 + 2);
  v5 = a4;
  v6 = a3;
  v7 = a2;
  if ( (v4 & 0x10) != 0 )
  {
    v18 = result + 8 * *(unsigned __int8 *)(a2 + 84);
    v5 = a4;
    v6 = a3;
    *(_QWORD *)(v18 + 2392) = *(_QWORD *)(v18 + 2392) - *(_QWORD *)(result + 2384) + *(_QWORD *)(result + 2376);
    v7 = a2;
    *(_DWORD *)(result + 2384) = 0;
    *(_DWORD *)(result + 2388) = 0;
    v4 &= 0xEFu;
  }
  if ( (v4 & 0x3E) != 0 )
  {
    if ( (v4 & 0x20) != 0 )
    {
      v8 = *(_DWORD *)(v7 + 1084);
      if ( v8 )
      {
        v9 = *(_DWORD *)(result + 3200);
        v10 = *(_DWORD *)(result + 3204);
        if ( v9 && v10 )
        {
          v11 = *(_DWORD *)(v10 + 44);
          if ( v11 >= *(_DWORD *)(v9 + 148) )
            v11 = *(_DWORD *)(v9 + 148);
        }
        else
        {
          v11 = 100;
        }
        v12 = v11 / 0x19;
        if ( v11 / 0x19 >= 3 )
          v12 = 3;
        v13 = (unsigned __int64 *)(v8 + 8 * (*(unsigned __int8 *)(result + 2986) + 2 * v12));
        v14 = *v13 + __PAIR64__(v5, v6);
        __dmb(0xBu);
        do
          v15 = __ldrexd(v13);
        while ( __strexd(v14, v13) );
        __dmb(0xBu);
        v7 = a2;
      }
      v4 &= 0xDFu;
    }
    if ( (v4 & 0x3E) != 0 )
    {
      v16 = *(_DWORD *)(v7 + 68);
      if ( v16 )
      {
        for ( i = v16 + *(_DWORD *)(result + 2352); i; i = *(_DWORD *)(i + 236) )
          *(_QWORD *)i += __PAIR64__(v5, v6);
      }
      if ( (*(_BYTE *)(v7 + 2) & 8) != 0
        && (*(_DWORD *)(*(_DWORD *)(result + 2360) + 260) & *(_DWORD *)(v7 + 356)) != *(_DWORD *)(*(_DWORD *)(result + 2360)
                                                                                                + 260) )
      {
        *(_QWORD *)(result + 2368) += __PAIR64__(v5, v6);
      }
      if ( *(_DWORD *)(v7 + 236) )
        result = sub_50AA54();
    }
  }
  return result;
}
