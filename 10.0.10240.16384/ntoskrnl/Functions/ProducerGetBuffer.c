// ProducerGetBuffer 
 
int __fastcall ProducerGetBuffer(int a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int *v7; // r6
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int result; // r0
  unsigned __int64 v24; // r4
  __int64 v25; // r0
  int v26; // r2
  int varg_r0; // [sp+28h] [bp+8h]
  unsigned int varg_r1; // [sp+2Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+30h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v7 = (unsigned int *)(a1 + 16);
  __dmb(0xBu);
  do
    v8 = __ldrex(v7);
  while ( !v8 && __strex(1u, v7) );
  __dmb(0xBu);
  if ( v8 )
  {
    do
    {
      do
      {
        v9 = KePollFreezeExecution();
        PopHiberCheckForDebugBreak(v9, v10, v11, v12);
      }
      while ( *v7 );
      __dmb(0xBu);
      do
        v13 = __ldrex(v7);
      while ( !v13 && __strex(1u, v7) );
      __dmb(0xBu);
    }
    while ( v13 );
  }
  while ( a2 > *(_DWORD *)(a1 + 4) + *(_DWORD *)(a1 + 48) - *(_DWORD *)(a1 + 24) )
  {
    if ( (a4 & 1) != 0 )
    {
      result = 0;
      goto LABEL_28;
    }
    __dmb(0xBu);
    *v7 = 0;
    do
    {
      v14 = KePollFreezeExecution();
      PopHiberCheckForDebugBreak(v14, v15, v16, v17);
    }
    while ( a2 > *(_DWORD *)(a1 + 4) + *(_DWORD *)(a1 + 48) - *(_DWORD *)(a1 + 24) );
    __dmb(0xBu);
    do
      v18 = __ldrex(v7);
    while ( !v18 && __strex(1u, v7) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !v18 )
        break;
      do
      {
        v19 = KePollFreezeExecution();
        PopHiberCheckForDebugBreak(v19, v20, v21, v22);
      }
      while ( *v7 );
      __dmb(0xBu);
      do
        v18 = __ldrex(v7);
      while ( !v18 && __strex(1u, v7) );
    }
  }
  v24 = *(_QWORD *)(a1 + 24);
  v25 = *(unsigned int *)(a1 + 4);
  if ( !(_DWORD)v25 )
    __brkdiv0();
  _rt_udiv64((unsigned int)v25, v24);
  result = v26 + *(_DWORD *)a1;
  *(_QWORD *)(a1 + 24) = v24 + a2;
  *(_QWORD *)(a1 + 8) -= a3;
LABEL_28:
  __dmb(0xBu);
  *v7 = 0;
  return result;
}
