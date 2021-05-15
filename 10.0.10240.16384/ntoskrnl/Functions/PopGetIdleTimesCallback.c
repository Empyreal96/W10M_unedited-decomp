// PopGetIdleTimesCallback 
 
int __fastcall PopGetIdleTimesCallback(int a1, int a2, _QWORD *a3)
{
  BOOL v5; // r10
  unsigned __int64 *v6; // r1
  unsigned int v7; // r8
  unsigned int v8; // r7
  __int64 *v9; // r6
  _DWORD *v10; // r9
  int v11; // r0
  unsigned int v12; // r9
  int v13; // r1
  _DWORD *i; // r8
  unsigned int v15; // r3
  int v16; // r0
  _DWORD *v17; // r1
  __int64 *v18; // r6
  unsigned int v19; // r1
  unsigned int v20; // lr
  __int64 v21; // kr18_8
  int v22; // r5
  __int64 v23; // r6
  int v24; // r2
  int v25; // r3
  unsigned __int64 v27; // kr10_8
  unsigned __int64 v28; // kr30_8
  unsigned __int64 v29; // kr38_8
  unsigned __int64 v30; // r0
  int v31; // r0
  __int64 v32; // [sp+0h] [bp-58h]
  int v33; // [sp+8h] [bp-50h]
  int v34; // [sp+Ch] [bp-4Ch]
  unsigned int v35; // [sp+10h] [bp-48h]
  unsigned int v36; // [sp+14h] [bp-44h]
  __int64 *v37; // [sp+18h] [bp-40h]
  _DWORD *v38; // [sp+1Ch] [bp-3Ch]
  _DWORD *v39; // [sp+20h] [bp-38h]
  unsigned __int64 *v40; // [sp+24h] [bp-34h]
  unsigned __int64 v42[5]; // [sp+30h] [bp-28h] BYREF

  v5 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408 != a1;
  v6 = (unsigned __int64 *)(a1 + 2968);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v39 = 0;
  v40 = (unsigned __int64 *)(a1 + 2968);
  v35 = 0;
  v36 = 0;
  v37 = 0;
  if ( v5 )
  {
    __dmb(0xBu);
    do
    {
      v28 = __ldrexd(v6);
      v8 = HIDWORD(v28);
      v7 = v28;
    }
    while ( __strexd(v28, v6) );
    v35 = HIDWORD(v28);
    v36 = v28;
    __dmb(0xBu);
    if ( !v28 )
      return -1073741823;
  }
  v10 = *(_DWORD **)(a1 + 2948);
  v33 = *(_DWORD *)(a1 + 2944);
  v38 = v10;
  KeQueryPerformanceCounter(v42, 0);
  LODWORD(v32) = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 404);
  HIDWORD(v32) = *(_DWORD *)(a1 + 2308);
  if ( a2 )
  {
    memset((_BYTE *)a2, 0, 48);
    if ( v10 )
    {
      v11 = v33;
      if ( v33 )
      {
        v12 = 0;
        v13 = v33 + 252;
        for ( i = v38; ; i += 246 )
        {
          v15 = *v38;
          v34 = v13;
          if ( *v38 >= *(_DWORD *)(v11 + 28) )
            v15 = *(_DWORD *)(v11 + 28);
          if ( v12 >= v15 )
          {
            v8 = v35;
            v7 = v36;
            v9 = v37;
            v10 = v38;
            *(_QWORD *)a2 = PpmConvertTimeTo(v38[6], v38[7], dword_989680, 0);
            goto LABEL_20;
          }
          v16 = PpmIdleGetCIndexForState(v13);
          if ( v16 == 3 )
          {
            v17 = (_DWORD *)(a2 + 40);
            v18 = (__int64 *)(a2 + 24);
          }
          else
          {
            if ( v16 != 1 )
              return sub_52959C();
            v17 = (_DWORD *)(a2 + 32);
            v18 = (__int64 *)(a2 + 8);
          }
          v11 = v33;
          if ( v12 == *(_DWORD *)(v33 + 16) )
          {
            v37 = v18;
            v39 = v17;
          }
          if ( v17 && v18 )
          {
            *v17 += i[13] + i[14];
            v19 = i[11];
            v20 = i[10];
            if ( *(_DWORD *)(v33 + 16) == v12 )
            {
              v27 = __PAIR64__(v19, v20) + *(_QWORD *)(a1 + 2952);
              v19 = HIDWORD(v27);
              v20 = v27;
            }
            v21 = *v18 + PpmConvertTimeTo(v20, v19, dword_989680, 0);
            v11 = v33;
            *v18 = v21;
          }
          ++v12;
          v13 = v34 + 64;
        }
      }
    }
  }
  if ( !v5 )
    goto LABEL_21;
LABEL_20:
  __dmb(0xBu);
  do
    v29 = __ldrexd(v40);
  while ( __strexd(v29, v40) );
  __dmb(0xBu);
  if ( __PAIR64__(v8, v7) != v29 )
    return -1073741823;
  if ( v42[0] > __PAIR64__(v8, v7) )
  {
    v30 = PpmConvertTimeTo(LODWORD(v42[0]) - v7, (v42[0] - __PAIR64__(v8, v7)) >> 32, dword_989680, 0);
    if ( v9 && v39 )
    {
      ++*v39;
      *v9 += v30;
    }
    v22 = KeMaximumIncrement;
    if ( v30 > (unsigned int)KeMaximumIncrement )
    {
      if ( !KeMaximumIncrement )
        __brkdiv0();
      v31 = _rt_udiv64((unsigned int)KeMaximumIncrement, v30);
      LODWORD(v23) = v32 + v31 - 1;
      HIDWORD(v23) = HIDWORD(v32) + v31 - 1;
      goto LABEL_23;
    }
  }
  else
  {
LABEL_21:
    v22 = KeMaximumIncrement;
  }
  v23 = v32;
LABEL_23:
  if ( a2 )
  {
    if ( v10 && v33 )
    {
      v24 = (*(_QWORD *)a2 + *(_QWORD *)(a2 + 24) + *(_QWORD *)(a2 + 16) + *(_QWORD *)(a2 + 8)) >> 32;
      v25 = *(_DWORD *)a2 + *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 16) + *(_DWORD *)(a2 + 8);
    }
    else
    {
      v24 = ((unsigned int)v22 * (unsigned __int64)(unsigned int)v23) >> 32;
      v25 = v22 * v23;
    }
    *(_DWORD *)a2 = v25;
    *(_DWORD *)(a2 + 4) = v24;
  }
  if ( a3 )
    *a3 = v23;
  return 0;
}
