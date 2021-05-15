// RtlpValidRelativeAttribute 
 
int __fastcall RtlpValidRelativeAttribute(unsigned int *a1, unsigned int a2, int a3, int a4)
{
  int *v4; // r4
  unsigned int v6; // r6
  unsigned int v7; // r3
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r0
  int *l; // r1
  unsigned int v12; // r2
  int v13; // r1
  int *k; // r2
  unsigned int v15; // r0
  int v16; // r7
  int v17; // r0
  int v18; // r0
  int *j; // r1
  unsigned int v20; // r2
  unsigned int v21; // r7
  int v22; // r8
  int *i; // r7
  unsigned int v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r3
  unsigned int v28; // [sp+0h] [bp-20h] BYREF
  _DWORD v29[7]; // [sp+4h] [bp-1Ch] BYREF

  v29[0] = a3;
  v29[1] = a4;
  v4 = (int *)a1;
  v28 = 0;
  if ( a1 )
  {
    if ( a2 >= 0x14 && !*((_WORD *)a1 + 3) && (a1[2] & 0xFFC0) == 0 )
    {
      v6 = a1[3];
      if ( v6 )
      {
        v7 = *a1;
        if ( a2 >= *a1 )
        {
          v8 = a2 - v7;
          if ( a2 - v7 >= 4
            && RtlStringCbLengthW((int)a1 + v7, v8, v29) >= 0
            && RtlULongLongToULong(4 * v6, (unsigned __int64)v6 >> 30, &v28) >= 0
            && a2 >= 0x10
            && a2 - 16 >= v28 )
          {
            v9 = *((unsigned __int16 *)v4 + 2);
            if ( *((_WORD *)v4 + 2) )
            {
              if ( *((unsigned __int16 *)v4 + 2) <= 2u )
              {
                v25 = 0;
                while ( 1 )
                {
                  v26 = v4[4];
                  if ( a2 < v26 || a2 - v26 < 8 )
                    break;
                  ++v25;
                  ++v4;
                  if ( v25 >= v6 )
                    return 1;
                }
              }
              else
              {
                switch ( v9 )
                {
                  case 3:
                    v22 = 0;
                    for ( i = v4; ; ++i )
                    {
                      v24 = i[4];
                      if ( a2 < v24 || a2 - v24 < 2 || RtlStringCbLengthW((int)v4 + v24, a2 - v24, v29) < 0 )
                        break;
                      if ( ++v22 >= v6 )
                        return 1;
                    }
                    break;
                  case 5:
                    v18 = 0;
                    for ( j = v4; ; ++j )
                    {
                      v20 = j[4];
                      if ( a2 < v20 )
                        break;
                      if ( a2 - v20 < 4 )
                        break;
                      v21 = *(int *)((char *)v4 + v20);
                      if ( !v21 || v20 + 4 < v20 || a2 - (v20 + 4) < v21 )
                        break;
                      if ( ++v18 >= v6 )
                        return 1;
                    }
                    break;
                  case 6:
                    v13 = 0;
                    for ( k = v4; ; ++k )
                    {
                      v15 = k[4];
                      if ( a2 < v15 )
                        break;
                      if ( a2 - v15 < 8 )
                        break;
                      v16 = *(int *)((char *)v4 + v15 + 4);
                      v17 = *(int *)((char *)v4 + v15);
                      if ( v17 | v16 )
                      {
                        if ( v17 != 1 || v16 )
                          break;
                      }
                      if ( ++v13 >= v6 )
                        return 1;
                    }
                    break;
                  case 16:
                    v10 = 0;
                    for ( l = v4; ; ++l )
                    {
                      v12 = l[4];
                      if ( a2 < v12 || a2 - v12 < 4 || v12 + 4 < v12 || a2 - (v12 + 4) < *(int *)((char *)v4 + v12) )
                        break;
                      if ( ++v10 >= v6 )
                        return 1;
                    }
                    break;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
