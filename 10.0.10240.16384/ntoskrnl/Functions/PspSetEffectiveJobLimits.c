// PspSetEffectiveJobLimits 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspSetEffectiveJobLimits(int a1)
{
  int v1; // r6
  int result; // r0
  int v4; // r2
  int v5; // r2
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r2
  int v9; // r1 OVERLAPPED
  unsigned int v10; // r2 OVERLAPPED
  int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r3
  unsigned int v17; // r3
  __int64 v18; // kr10_8

  v1 = *(_DWORD *)(a1 + 572);
  if ( PspSetEffectiveLimit(16) )
  {
    if ( (*(_DWORD *)(a1 + 176) & 0x10) != 0 )
      return sub_7E9974();
    if ( v1 )
    {
      v5 = *(_DWORD *)(v1 + 352);
      v6 = *(_DWORD *)(v1 + 356);
      *(_DWORD *)(a1 + 348) = *(_DWORD *)(v1 + 348);
      *(_DWORD *)(a1 + 352) = v5;
      *(_DWORD *)(a1 + 356) = v6;
    }
    else
    {
      *(_DWORD *)(a1 + 352) = 0;
      *(_WORD *)(a1 + 348) = 1;
      *(_WORD *)(a1 + 350) = 1;
      *(_DWORD *)(a1 + 356) = 0;
    }
  }
  if ( PspSetEffectiveLimit(32) )
  {
    if ( v1 )
      v7 = *(unsigned __int8 *)(v1 + 424);
    else
      v7 = 0;
    if ( (*(_DWORD *)(a1 + 176) & 0x20) != 0
      && *((unsigned __int8 *)PspPriorityClassRank + v7) >= (unsigned int)*((unsigned __int8 *)PspPriorityClassRank
                                                                          + *(unsigned __int8 *)(a1 + 425)) )
    {
      LOBYTE(v7) = *(_BYTE *)(a1 + 425);
    }
    *(_BYTE *)(a1 + 424) = v7;
  }
  if ( PspSetEffectiveLimit(128) )
  {
    if ( v1 )
      v8 = *(_DWORD *)(v1 + 404);
    else
      v8 = 10;
    if ( (*(_DWORD *)(a1 + 176) & 0x80) != 0 && (v15 = *(_DWORD *)(a1 + 236), v15 < v8) )
      *(_DWORD *)(a1 + 404) = v15;
    else
      *(_DWORD *)(a1 + 404) = v8;
  }
  if ( PspSetEffectiveLimit(1) )
  {
    if ( v1 )
    {
      *(_QWORD *)&v9 = *(_QWORD *)(v1 + 368);
    }
    else
    {
      v9 = 0;
      v10 = 0;
    }
    if ( (*(_DWORD *)(a1 + 176) & 1) == 0 || (v16 = *(_DWORD *)(a1 + 172), v16 >= v10) && v10 )
    {
      *(_QWORD *)(a1 + 368) = *(_QWORD *)&v9;
    }
    else
    {
      *(_DWORD *)(a1 + 372) = v16;
      *(_DWORD *)(a1 + 368) = *(_DWORD *)(a1 + 168);
    }
  }
  if ( PspSetEffectiveLimit(256) )
  {
    if ( v1 )
    {
      v11 = *(_DWORD *)(v1 + 380);
      v12 = *(_DWORD *)(v1 + 376);
    }
    else
    {
      v12 = 0;
      v11 = 0;
    }
    if ( (*(_DWORD *)(a1 + 176) & 0x100) == 0 || (v17 = *(_DWORD *)(a1 + 328), v17 >= v12) && v12 )
    {
      *(_DWORD *)(a1 + 376) = v12;
      *(_DWORD *)(a1 + 380) = v11;
    }
    else
    {
      *(_DWORD *)(a1 + 376) = v17;
      *(_DWORD *)(a1 + 380) = a1;
    }
  }
  result = PspSetEffectiveLimit(2);
  if ( result )
  {
    if ( v1 )
    {
      v13 = *(_DWORD *)(v1 + 364);
      v14 = *(_DWORD *)(v1 + 360);
      result = *(_DWORD *)(v1 + 384);
    }
    else
    {
      v14 = 0;
      v13 = 0;
      result = 0;
    }
    if ( (*(_DWORD *)(a1 + 176) & 2) == 0 || (v18 = *(_QWORD *)(a1 + 152), v18 >= __SPAIR64__(v13, v14)) && v14 | v13 )
    {
      *(_DWORD *)(a1 + 360) = v14;
      *(_DWORD *)(a1 + 364) = v13;
      *(_DWORD *)(a1 + 384) = result;
    }
    else
    {
      *(_QWORD *)(a1 + 360) = v18;
      *(_DWORD *)(a1 + 384) = a1;
    }
  }
  v4 = *(_DWORD *)(a1 + 176);
  *(_DWORD *)(a1 + 400) = v4;
  if ( v1 )
    *(_DWORD *)(a1 + 400) = *(_DWORD *)(v1 + 400) | v4;
  return result;
}
