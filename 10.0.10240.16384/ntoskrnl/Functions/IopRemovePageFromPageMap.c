// IopRemovePageFromPageMap 
 
int __fastcall IopRemovePageFromPageMap(_BYTE *a1, _DWORD *a2, unsigned int a3, unsigned int a4, char a5)
{
  unsigned int v5; // r5
  unsigned int v9; // r2
  unsigned int v10; // r8
  __int64 v12; // kr00_8
  unsigned int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r5
  _DWORD *v16; // r5
  int i; // r3
  unsigned int v18; // r1

  v5 = a4;
  if ( a4 )
  {
    v9 = *(_DWORD *)a1;
    v10 = a3 + a4 - 1;
    if ( a3 < *(_DWORD *)a1 )
    {
      if ( v10 >= v9 )
      {
        if ( !a5 )
          return -1073741503;
        v10 = v9 - 1;
        v5 = v9 - a3;
      }
      if ( v5 )
      {
        if ( a2 )
        {
          do
          {
            v12 = *(_QWORD *)a1;
            if ( a3 < *(_DWORD *)a1 )
              v13 = a3;
            else
              v13 = 0;
            v14 = v12 - 1;
            while ( 1 )
            {
              if ( v14 - v13 == -1 )
                goto LABEL_16;
              v16 = (_DWORD *)(HIDWORD(v12) + 4 * (v13 >> 5));
              for ( i = ~*v16 | ((1 << (v13 & 0x1F)) - 1); i == -1; i = ~*v16 )
              {
                if ( (unsigned int)++v16 > HIDWORD(v12) + 4 * (v14 >> 5) )
                  goto LABEL_16;
              }
              v15 = __clz(__rbit(~i)) + 32 * (((int)v16 - HIDWORD(v12)) >> 2);
              if ( v15 > v14 )
              {
LABEL_16:
                v15 = -1;
              }
              else if ( v15 != -1 )
              {
                break;
              }
              if ( !v13 )
                break;
              v18 = a3 + 1;
              if ( a3 + 1 > (unsigned int)v12 )
                v18 = *(_DWORD *)a1;
              v14 = v18 - 1;
              v13 = 0;
            }
            if ( v15 < a3 )
              break;
            if ( v15 == -1 )
              break;
            RtlClearBits(a1, v15, 1u);
            a3 = v15 + 1;
            ++*a2;
          }
          while ( v15 + 1 <= v10 );
        }
        else
        {
          RtlClearBits(a1, a3, v5);
        }
      }
    }
    else if ( !a5 )
    {
      return -1073741503;
    }
  }
  return 0;
}
