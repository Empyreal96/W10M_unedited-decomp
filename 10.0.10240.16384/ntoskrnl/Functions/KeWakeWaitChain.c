// KeWakeWaitChain 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeWakeWaitChain(_DWORD **a1, int a2, char a3)
{
  _DWORD *v3; // r6
  int v4; // r4
  unsigned int v6; // r0
  _DWORD *v7; // r4
  unsigned __int8 *v8; // r6
  unsigned int v9; // r2
  unsigned __int8 *v10; // r9
  int v11; // r4
  int v12; // r1 OVERLAPPED
  _DWORD *v13; // r2 OVERLAPPED
  int v15; // r3
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // [sp+8h] [bp-40h]
  int v19; // [sp+Ch] [bp-3Ch]
  int v20; // [sp+10h] [bp-38h]
  _DWORD *v21; // [sp+18h] [bp-30h]
  int v23; // [sp+20h] [bp-28h]

  v3 = *a1;
  v4 = 0;
  v19 = 0;
  v20 = 1;
  if ( *a1 )
  {
    v23 = KfRaiseIrql(2);
    v6 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v18 = v6;
    do
    {
      v7 = v3;
      v21 = (_DWORD *)*v3;
      v8 = (unsigned __int8 *)(v3 + 1);
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 | 0x80, v8) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v9 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v8 & 0x80) != 0 );
        do
          v9 = __ldrex(v8);
        while ( __strex(v9 | 0x80, v8) );
      }
      v7[2] = 1;
      v10 = (unsigned __int8 *)*((_DWORD *)v8 + 2);
      if ( v10 != v8 + 8 )
      {
        v11 = *((_DWORD *)v8 + 2);
        *(_QWORD *)&v12 = *(_QWORD *)v10;
        if ( *(_DWORD *)(*(_DWORD *)v10 + 4) != v11 || *v13 != v11 )
          __fastfail(3u);
        *v13 = v12;
        *(_DWORD *)(v12 + 4) = v13;
        if ( *(_BYTE *)(v11 + 8) != 1 )
          return sub_521234();
        if ( !KiTryUnwaitThread(v6, v11, *(unsigned __int16 *)(v11 + 10), 0)
          || (v15 = *((_DWORD *)v8 + 1) - 1, (*((_DWORD *)v8 + 1) = v15) != 0) )
        {
          JUMPOUT(0x521340);
        }
        v6 = v18;
      }
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)v8);
      while ( __strex(v16 & 0xFFFFFF7F, (unsigned int *)v8) );
      v3 = v21;
      v4 = ++v19;
    }
    while ( v21 );
    if ( (a3 & 1) != 0 )
    {
      v17 = KiRemoveBoostThread(v6, *(_DWORD *)(v6 + 4));
      if ( a2 )
      {
        v20 = 2;
        if ( v17 > (char)a2 )
          a2 = v17;
      }
    }
    KiExitDispatcher(v18, 0, v20, a2, v23);
    *a1 = 0;
  }
  return v4;
}
