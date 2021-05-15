// ConsumerPeekAndConsumeBuffer 
 
int __fastcall ConsumerPeekAndConsumeBuffer(int a1, unsigned int *a2, int a3, int a4, int a5)
{
  unsigned int *v7; // r5
  unsigned int v8; // r2
  int v9; // r0
  unsigned __int64 v10; // kr08_8
  unsigned int v11; // r10
  unsigned int v12; // r3
  unsigned int v13; // r6
  BOOL v14; // r7
  __int64 v15; // r0
  int v16; // r2
  unsigned int v17; // r0
  int v18; // r0
  __int64 v19; // kr10_8
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r2
  int result; // r0
  int v24; // [sp+0h] [bp-28h]
  int v25; // [sp+4h] [bp-24h]
  int varg_r0; // [sp+30h] [bp+8h]
  unsigned int *varg_r1; // [sp+34h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v24 = 0;
  v7 = (unsigned int *)(a1 + 16);
  __dmb(0xBu);
  do
    v8 = __ldrex(v7);
  while ( !v8 && __strex(1u, v7) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !v8 )
      break;
    do
    {
      v9 = KePollFreezeExecution();
      PopHiberCheckForDebugBreak(v9);
    }
    while ( *v7 );
    __dmb(0xBu);
    do
      v8 = __ldrex(v7);
    while ( !v8 && __strex(1u, v7) );
  }
  while ( 1 )
  {
    v10 = *(_QWORD *)(a1 + 40);
    v25 = *(_DWORD *)(a1 + 44);
    v11 = *(_DWORD *)(a1 + 32) - v10;
    if ( !*(_QWORD *)(a1 + 8) )
    {
      v12 = *a2;
      if ( *a2 >= *(_DWORD *)(a1 + 24) - (int)v10 )
        v12 = *(_DWORD *)(a1 + 24) - v10;
      *a2 = v12;
    }
    v13 = *a2;
    v14 = *a2 <= v11;
    if ( *a2 <= v11 )
    {
      if ( v13 )
      {
        v15 = *(unsigned int *)(a1 + 4);
        if ( !(_DWORD)v15 )
          __brkdiv0();
        _rt_udiv64((unsigned int)v15, v10);
        v24 = *(_DWORD *)a1 + v16;
        v17 = PopHiberPeekRangeTable(v24, v13, a5);
        v13 = v17;
        if ( v17 > v11 )
          v14 = 0;
        else
          *a2 = v17;
      }
      if ( v14 )
        break;
    }
    if ( (a3 & 1) != 0 )
    {
      if ( !v14 )
        goto LABEL_43;
      break;
    }
    __dmb(0xBu);
    *v7 = 0;
    do
    {
      v18 = KePollFreezeExecution();
      PopHiberCheckForDebugBreak(v18);
      v19 = *(_QWORD *)(a1 + 40);
      if ( !*(_QWORD *)(a1 + 8) && v13 >= *(_DWORD *)(a1 + 24) - (int)v19 )
        v13 = *(_DWORD *)(a1 + 24) - v19;
    }
    while ( HIDWORD(v10) == (_DWORD)v10 && HIDWORD(v19) == v25 && v13 > *(_DWORD *)(a1 + 32) - (int)v19 );
    __dmb(0xBu);
    do
      v20 = __ldrex(v7);
    while ( !v20 && __strex(1u, v7) );
    __dmb(0xBu);
    if ( v20 )
    {
      do
      {
        do
        {
          v21 = KePollFreezeExecution();
          PopHiberCheckForDebugBreak(v21);
        }
        while ( *v7 );
        __dmb(0xBu);
        do
          v22 = __ldrex(v7);
        while ( !v22 && __strex(1u, v7) );
        __dmb(0xBu);
      }
      while ( v22 );
    }
  }
  if ( *a2 )
  {
    result = v24;
    *(_QWORD *)(a1 + 40) += *a2;
    goto LABEL_44;
  }
LABEL_43:
  result = 0;
LABEL_44:
  __dmb(0xBu);
  *v7 = 0;
  return result;
}
