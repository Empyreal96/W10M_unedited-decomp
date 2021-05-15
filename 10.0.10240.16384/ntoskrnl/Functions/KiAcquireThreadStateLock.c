// KiAcquireThreadStateLock 
 
int __fastcall KiAcquireThreadStateLock(int a1, _DWORD *a2, unsigned int **a3)
{
  _DWORD *v5; // r5
  int result; // r0
  int v7; // r3
  unsigned int *v8; // r10
  unsigned int v9; // r2
  unsigned int v10; // r3
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r10
  unsigned int *v14; // r6
  unsigned int v15; // r2
  unsigned int *v16; // r8
  unsigned int v17; // r2

  while ( 2 )
  {
    v5 = 0;
    result = *(unsigned __int8 *)(a1 + 132);
    switch ( *(_BYTE *)(a1 + 132) )
    {
      case 1:
        v13 = *(_DWORD *)(a1 + 328);
        if ( (v13 & 0x80000000) == 0 )
        {
          v5 = *(&KiProcessorBlock + v13);
          v16 = v5 + 6;
          while ( 1 )
          {
            do
              v17 = __ldrex(v16);
            while ( __strex(1u, v16) );
            __dmb(0xBu);
            if ( !v17 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v16 );
          }
          if ( *(_BYTE *)(a1 + 132) != 1 || *(_DWORD *)(a1 + 328) != v13 )
          {
            __dmb(0xBu);
            v5[6] = 0;
            continue;
          }
          goto LABEL_7;
        }
        v14 = (unsigned int *)*((_DWORD *)*(&KiProcessorBlock + v13) + 865);
        while ( 1 )
        {
          do
            v15 = __ldrex(v14);
          while ( __strex(1u, v14) );
          __dmb(0xBu);
          if ( !v15 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v14 );
        }
        if ( *(_BYTE *)(a1 + 132) != 1 || *(_DWORD *)(a1 + 328) != v13 )
        {
          __dmb(0xBu);
          *v14 = 0;
          continue;
        }
        *a2 = 0;
        *a3 = v14;
        return result;
      case 2:
        goto LABEL_2;
      case 3:
        v11 = *(_DWORD *)(a1 + 328);
        if ( (v11 & 0x80000000) != 0 )
          continue;
        v5 = *(&KiProcessorBlock + v11);
        v8 = v5 + 6;
        while ( 1 )
        {
          do
            v12 = __ldrex(v8);
          while ( __strex(1u, v8) );
          __dmb(0xBu);
          if ( !v12 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v8 );
        }
        if ( a1 == v5[2] )
          goto LABEL_7;
        if ( *(_BYTE *)(a1 + 132) == 3 && *(_DWORD *)(a1 + 328) == v11 )
          sub_50C478();
        goto LABEL_17;
      case 5:
        v10 = *(_BYTE *)(a1 + 72) & 7;
        if ( v10 == 1 || v10 >= 3 && v10 <= 6 )
          goto LABEL_7;
        result = 2;
LABEL_2:
        v7 = *(_DWORD *)(a1 + 328);
        if ( (v7 & 0x80000000) != 0 )
          continue;
        v5 = *(&KiProcessorBlock + v7);
        v8 = v5 + 6;
        while ( 1 )
        {
          do
            v9 = __ldrex(v8);
          while ( __strex(1u, v8) );
          __dmb(0xBu);
          if ( !v9 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v8 );
        }
        if ( a1 != v5[1] )
        {
LABEL_17:
          __dmb(0xBu);
          *v8 = 0;
          continue;
        }
LABEL_7:
        *a2 = v5;
        *a3 = 0;
        return result;
      default:
        goto LABEL_7;
    }
  }
}
