// KiProcessExpiredTimerList 
 
int *__fastcall KiProcessExpiredTimerList(_DWORD *a1, _DWORD *a2, unsigned int *a3, unsigned int a4)
{
  int *result; // r0
  int v7; // r2
  _DWORD *v8; // r8
  int v9; // r1
  BOOL v10; // r7
  unsigned int v11; // r5
  BOOL v12; // r10
  unsigned int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r2
  int v16; // r3
  int v17; // r8
  __int64 v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  _DWORD *v21; // r5
  void (__fastcall *v22)(int, _DWORD, _DWORD, _DWORD); // r4
  unsigned int v23; // r1
  int v24; // r2
  void (__fastcall *v26)(int, _DWORD, _DWORD, _DWORD); // [sp+10h] [bp-70h] BYREF
  unsigned int v27; // [sp+14h] [bp-6Ch]
  int v28; // [sp+18h] [bp-68h]
  int v29; // [sp+1Ch] [bp-64h]
  unsigned int v30; // [sp+20h] [bp-60h]
  int v31[4]; // [sp+28h] [bp-58h] BYREF
  int v32[4]; // [sp+38h] [bp-48h] BYREF
  char v33; // [sp+48h] [bp-38h]
  char v34[48]; // [sp+50h] [bp-30h] BYREF

  result = &KiWaitNever;
  v7 = a1[1];
  v30 = a4;
  v8 = a2;
  v9 = *(_DWORD *)(v7 + 308);
  v10 = (dword_682604 & 0x80) != 0;
  v11 = 0;
  v28 = v7;
  v29 = v9;
  v12 = (dword_682608 & 0x20000) != 0;
  do
  {
    __dmb(0xBu);
    do
      v13 = __ldrex(a3);
    while ( __strex(0, a3) );
    __dmb(0xBu);
    ++v11;
    ++a3;
    v27 = v11;
    if ( v13 )
    {
      do
        v14 = __ldrex((unsigned __int8 *)v13);
      while ( __strex(v14 | 0x80, (unsigned __int8 *)v13) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v14 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v13 & 0x80) != 0 );
        do
          v14 = __ldrex((unsigned __int8 *)v13);
        while ( __strex(v14 | 0x80, (unsigned __int8 *)v13) );
      }
      if ( v12 )
      {
        v32[0] = *(_DWORD *)(v13 + 16);
        v32[1] = *(_DWORD *)(v13 + 20);
        v15 = bswap32(__ROR4__(KiWaitNever ^ *(_DWORD *)(v13 + 32), -(char)KiWaitNever) ^ v13);
        if ( KiWaitAlways != v15 )
          v16 = *(_DWORD *)((KiWaitAlways ^ v15) + 0xC);
        else
          v16 = 0;
        v32[3] = v16;
      }
      v17 = KiTimerWaitTest((int)a1, v13, (int)(v8 + 2));
      if ( v12 )
      {
        v32[2] = v13;
        v33 = *(_BYTE *)(v13 + 1) >> 2;
        v31[0] = (int)v32;
        v31[1] = 0;
        v31[2] = 24;
        v31[3] = 0;
        EtwTraceKernelEvent(v31, 1, 0x40020000u, 3921, 1538);
      }
      if ( v17 )
      {
        if ( a1[385] )
          KiProcessThreadWaitList((int)a1, 1, 0);
        if ( v10 )
        {
          LODWORD(v18) = v34;
          HIDWORD(v18) = 536871040;
          EtwGetKernelTraceTimestamp(v18);
        }
        v20 = *a2;
        v26 = *(void (__fastcall **)(int, _DWORD, _DWORD, _DWORD))(v17 + 12);
        v19 = (unsigned int)v26;
        *a2 = v20 + 1;
        v21 = &a2[3 * (v20 & 0xF)];
        v21[4] = v19;
        v21[5] = KeTickCount;
        v22 = v26;
        a1[583] = 0;
        v22(v17, *(_DWORD *)(v17 + 16), a2[2], a2[3]);
        v23 = v29;
        v24 = v28;
        v21[6] = KeTickCount;
        if ( v23 != *(_DWORD *)(v24 + 308) )
          KeBugCheck2(199, 5, (unsigned int)v26, v23, *(_DWORD *)(v24 + 308), 0);
        if ( v10 )
          EtwTraceTimedEvent(3909, 0x20000080u, (int)&v26, 4, 4196866, (int)v34);
        v11 = v27;
      }
      result = &KiWaitNever;
      v8 = a2;
    }
  }
  while ( v11 < v30 );
  if ( a1[385] )
    result = (int *)KiProcessThreadWaitList((int)a1, 1, 0);
  return result;
}
