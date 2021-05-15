// KiSignalThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiSignalThread(int a1, int a2, int a3, int a4)
{
  int v5; // r1
  int result; // r0
  _BYTE *v9; // r2
  int v10; // r3
  unsigned int *v11; // r5
  unsigned int v12; // r2
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r1

  v5 = *(_BYTE *)(a2 + 72) & 7;
  result = 0;
  if ( v5 == 1 || v5 == 4 )
  {
    v9 = *(_BYTE **)(a2 + 152);
    if ( v9 )
    {
      if ( (*v9 & 0x7F) == 21 )
      {
        v17 = *(unsigned __int8 *)(a2 + 332);
        *(_DWORD *)(a2 + 332) = v17;
        __dmb(0xBu);
        v18 = (unsigned int *)&v9[4 * v17 + 272];
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 + 1, v18) );
      }
      else
      {
        __dmb(0xBu);
        v15 = (unsigned int *)(v9 + 24);
        do
          v16 = __ldrex(v15);
        while ( __strex(v16 + 1, v15) );
      }
      __dmb(0xBu);
    }
    v10 = *(_DWORD *)(a2 + 436);
    if ( v10 )
    {
      v11 = (unsigned int *)(v10 + 1928);
      while ( 1 )
      {
        do
          v12 = __ldrex(v11);
        while ( __strex(1u, v11) );
        __dmb(0xBu);
        if ( !v12 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v11 );
      }
      if ( *(_DWORD *)(a2 + 436) )
      {
        *(_QWORD *)&v13 = *(_QWORD *)(a2 + 144);
        if ( *(_DWORD *)(v13 + 4) != a2 + 144 || *v14 != a2 + 144 )
          __fastfail(3u);
        *v14 = v13;
        *(_DWORD *)(v13 + 4) = v14;
        *(_DWORD *)(a2 + 436) = 0;
      }
      __dmb(0xBu);
      *v11 = 0;
    }
    *(_BYTE *)(a2 + 132) = 7;
    result = 1;
    *(_DWORD *)(a2 + 144) = *(_DWORD *)(a1 + 1540);
    *(_DWORD *)(a1 + 1540) = a2 + 144;
    *(_DWORD *)(a2 + 136) = a3;
  }
  else if ( a4 )
  {
    result = sub_50A43C(0);
  }
  return result;
}
