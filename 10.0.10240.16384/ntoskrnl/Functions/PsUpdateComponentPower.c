// PsUpdateComponentPower 
 
int __fastcall PsUpdateComponentPower(int result, int a2, __int64 a3)
{
  int v3; // r5
  __int64 v4; // r6
  int v5; // r4
  unsigned __int64 *v6; // r3
  unsigned __int64 v7; // kr10_8
  unsigned __int64 *v8; // r2
  unsigned __int64 v9; // kr18_8
  unsigned __int64 *v10; // r2
  unsigned __int64 v11; // kr20_8
  int v12; // r3
  int v13; // r6
  __int64 v14; // kr38_8
  int v15; // r3
  int v16; // r5
  __int64 v17; // kr48_8
  unsigned int v18; // r1
  __int64 v19; // kr50_8
  __int64 v20; // kr58_8
  unsigned int v21; // r2
  __int64 v22[3]; // [sp+0h] [bp-18h] BYREF

  v22[0] = a3;
  v3 = result;
  v4 = a3;
  if ( !result )
    v3 = PsInitialSystemProcess;
  v5 = *(_DWORD *)(v3 + 796);
  if ( v5 )
  {
    if ( a2 == 1 )
    {
      if ( a3 )
      {
        __dmb(0xBu);
        v6 = (unsigned __int64 *)(v5 + 64);
        do
          v7 = __ldrexd(v6);
        while ( __strexd(v7 + v4, v6) );
        __dmb(0xBu);
      }
    }
    else
    {
      result = a2 - 2;
      switch ( a2 )
      {
        case 2:
          if ( a3 )
          {
            __dmb(0xBu);
            v8 = (unsigned __int64 *)(v5 + 72);
            do
              v9 = __ldrexd(v8);
            while ( __strexd(v9 + HIDWORD(v4), v8) );
            __dmb(0xBu);
            v10 = (unsigned __int64 *)(v5 + 88);
            do
            {
              v11 = __ldrexd(v10);
              result = v11 + v4;
            }
            while ( __strexd(v11 + (unsigned int)v4, v10) );
            __dmb(0xBu);
          }
          break;
        case 3:
          if ( a3 )
            result = sub_51F5D4();
          break;
        case 4:
          if ( v3 != PsInitialSystemProcess )
          {
            HIDWORD(a3) = *(_DWORD *)(v5 + 104);
            if ( (_DWORD)a3 )
            {
              if ( (v12 & 1) == 0 )
              {
                *(_DWORD *)(v5 + 104) = v12 | 1;
                result = KeQuerySystemTime(v22);
                *(_QWORD *)(v5 + 128) = v22[0];
              }
            }
            else if ( (v12 & 1) != 0 )
            {
              KeQuerySystemTime(v22);
              v13 = HIDWORD(v22[0]);
              result = v22[0];
              v14 = v22[0] - *(_QWORD *)(v5 + 128);
              if ( v14 > 0 )
                *(_QWORD *)(v5 + 136) += v14;
              v15 = *(_DWORD *)(v5 + 104);
              *(_DWORD *)(v5 + 128) = result;
              *(_DWORD *)(v5 + 132) = v13;
              *(_DWORD *)(v5 + 104) = v15 & 0xFFFFFFFE;
            }
          }
          break;
        case 5:
          if ( v3 != PsInitialSystemProcess )
          {
            if ( (_DWORD)a3 )
            {
              KeQuerySystemTime(v22);
              result = *(_DWORD *)(v5 + 108);
              v16 = HIDWORD(v22[0]);
              HIDWORD(v4) = v22[0];
              if ( result )
              {
                v17 = v22[0] - *(_QWORD *)(v5 + 112);
                if ( v17 > 0 )
                {
                  v18 = result * v17;
                  result = (v17 * (unsigned __int64)(unsigned int)result) >> 32;
                  *(_QWORD *)(v5 + 120) += __PAIR64__(result, v18);
                }
              }
              *(_QWORD *)(v5 + 108) = v4;
              *(_DWORD *)(v5 + 116) = v16;
            }
            else if ( *(_DWORD *)(v5 + 108) )
            {
              KeQuerySystemTime(v22);
              v19 = v22[0];
              v20 = v22[0] - *(_QWORD *)(v5 + 112);
              result = HIDWORD(v20);
              if ( v20 > 0 )
              {
                v21 = *(_DWORD *)(v5 + 108);
                result = (v20 * (unsigned __int64)v21) >> 32;
                *(_QWORD *)(v5 + 120) += v20 * v21;
              }
              *(_DWORD *)(v5 + 108) = 0;
              *(_QWORD *)(v5 + 112) = v19;
            }
          }
          break;
      }
    }
  }
  return result;
}
