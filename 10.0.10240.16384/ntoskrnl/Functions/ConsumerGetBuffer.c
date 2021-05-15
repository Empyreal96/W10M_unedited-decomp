// ConsumerGetBuffer 
 
int __fastcall ConsumerGetBuffer(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int *v6; // r7
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r3
  int v12; // r0
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r3
  unsigned int v16; // r2
  int v17; // r0
  int result; // r0
  unsigned int v19; // r8
  unsigned __int64 v20; // r4
  __int64 v21; // r0
  int v22; // r2
  int varg_r0; // [sp+20h] [bp+8h]
  unsigned int *varg_r1; // [sp+24h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v6 = (unsigned int *)(a1 + 16);
  __dmb(0xBu);
  do
    v7 = __ldrex(v6);
  while ( !v7 && __strex(1u, v6) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !v7 )
      break;
    do
    {
      v8 = KePollFreezeExecution();
      PopHiberCheckForDebugBreak(v8);
    }
    while ( *v6 );
    __dmb(0xBu);
    do
      v7 = __ldrex(v6);
    while ( !v7 && __strex(1u, v6) );
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(a1 + 40);
    v10 = *(_DWORD *)(a1 + 32) - v9;
    if ( !*(_QWORD *)(a1 + 8) )
    {
      v11 = *a2;
      if ( *a2 >= *(_DWORD *)(a1 + 24) - v9 )
        v11 = *(_DWORD *)(a1 + 24) - v9;
      *a2 = v11;
    }
    if ( *a2 <= v10 )
      break;
    if ( (a3 & 1) != 0 )
      goto LABEL_32;
    __dmb(0xBu);
    *v6 = 0;
    do
    {
      v12 = KePollFreezeExecution();
      PopHiberCheckForDebugBreak(v12);
      v13 = *(_DWORD *)(a1 + 40);
      v14 = *(_DWORD *)(a1 + 32) - v13;
      if ( !*(_QWORD *)(a1 + 8) )
      {
        v15 = *a2;
        if ( *a2 >= *(_DWORD *)(a1 + 24) - v13 )
          v15 = *(_DWORD *)(a1 + 24) - v13;
        *a2 = v15;
      }
    }
    while ( *a2 > v14 );
    __dmb(0xBu);
    do
      v16 = __ldrex(v6);
    while ( !v16 && __strex(1u, v6) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !v16 )
        break;
      do
      {
        v17 = KePollFreezeExecution();
        PopHiberCheckForDebugBreak(v17);
      }
      while ( *v6 );
      __dmb(0xBu);
      do
        v16 = __ldrex(v6);
      while ( !v16 && __strex(1u, v6) );
    }
  }
  v19 = *a2;
  if ( !*a2 )
  {
LABEL_32:
    result = 0;
    goto LABEL_37;
  }
  v20 = *(_QWORD *)(a1 + 40);
  v21 = *(unsigned int *)(a1 + 4);
  if ( !(_DWORD)v21 )
    __brkdiv0();
  _rt_udiv64((unsigned int)v21, v20);
  result = v22 + *(_DWORD *)a1;
  *(_QWORD *)(a1 + 40) = v20 + v19;
LABEL_37:
  __dmb(0xBu);
  *v6 = 0;
  return result;
}
