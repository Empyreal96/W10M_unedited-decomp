// CmpDumpKeyBodyList 
 
_DWORD *__fastcall CmpDumpKeyBodyList(_DWORD *result, _DWORD *a2, int a3)
{
  int v3; // r4
  int v4; // r6
  int v7; // r5
  unsigned int v8; // r7
  _DWORD *v9; // r6
  unsigned int *v10; // r5
  int v11; // r6
  unsigned int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r2

  v3 = (int)result;
  v4 = 1;
  if ( *result )
  {
    result = 0;
    v7 = v3;
    while ( !*(_DWORD *)(v7 + 72) )
    {
      result = (_DWORD *)((char *)result + 1);
      v7 += 4;
      if ( (unsigned int)result >= 4 )
        goto LABEL_7;
    }
    v4 = 0;
LABEL_7:
    if ( *(_DWORD *)(v3 + 64) != v3 + 64 || v4 != 1 )
    {
      result = (_DWORD *)CmpConstructName(v3);
      v8 = (unsigned int)result;
      if ( result )
      {
        v9 = *(_DWORD **)(v3 + 64);
        while ( v9 != (_DWORD *)(v3 + 64) )
        {
          CmpDumpOneKeyBody();
          v9 = (_DWORD *)*v9;
          ++*a2;
        }
        v10 = (unsigned int *)(v3 + 72);
        v11 = 4;
        do
        {
          v12 = *v10;
          __dmb(0xBu);
          if ( v12 && v12 != 1 && v12 != 2 )
          {
            __dmb(0xBu);
            do
              v13 = __ldrex(v10);
            while ( v13 == v12 && __strex(1u, v10) );
            __dmb(0xBu);
            if ( v13 == v12 )
            {
              CmpDumpOneKeyBody();
              ++*a2;
              __dmb(0xBu);
              do
                v14 = __ldrex(v10);
              while ( v14 == 1 && __strex(v12, v10) );
              __dmb(0xBu);
            }
          }
          ++v10;
          --v11;
        }
        while ( v11 );
        result = (_DWORD *)ExFreePoolWithTag(v8);
      }
      else if ( a3 )
      {
        *(_DWORD *)(a3 + 12) = -1073741670;
      }
    }
  }
  return result;
}
