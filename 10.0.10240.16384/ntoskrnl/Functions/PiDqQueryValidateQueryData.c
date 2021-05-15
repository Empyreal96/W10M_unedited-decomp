// PiDqQueryValidateQueryData 
 
int __fastcall PiDqQueryValidateQueryData(int *a1)
{
  int v2; // r7
  int v4; // r3
  int v5; // r2
  int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r0
  int v9; // r1
  int v10; // r1
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r5
  int v14; // r6

  v2 = -1073741811;
  if ( !a1 || !PiDqGetPnpObjectType(a1[4]) )
    return v2;
  if ( (a1[8] & 2) != 0 )
    return sub_7C7578();
  v4 = a1[5];
  if ( v4 == 1 )
  {
    if ( !a1[6] )
      return v2;
  }
  else if ( v4 == 2 && PnpValidateMultiSz(a1[7], a1[6]) < 0 )
  {
    return v2;
  }
  v5 = a1[8];
  if ( (v5 & 0xFFFFFFF8) == 0 )
  {
    if ( (v5 & 4) != 0 )
    {
      if ( PnpValidateMultiSz(a1[10], a1[9]) >= 0 )
      {
LABEL_11:
        v6 = a1[12];
        if ( v6 || !a1[11] )
        {
          v7 = a1[11];
          if ( v7 || !v6 )
          {
            v8 = 0;
            if ( v7 )
            {
              v9 = a1[12];
              while ( !*(_DWORD *)(v9 + 24) )
              {
                ++v8;
                v9 += 28;
                if ( v8 >= v7 )
                  goto LABEL_17;
              }
            }
            else
            {
LABEL_17:
              v10 = a1[14];
              if ( (v10 || !a1[13]) && (a1[13] || !v10) && (!v10 || ValidFilter()) )
              {
                v11 = a1[16];
                if ( v11 || !a1[15] )
                {
                  v12 = a1[15];
                  if ( !v11 || v12 )
                  {
                    v13 = 0;
                    if ( v12 )
                    {
                      v14 = 0;
                      while ( PnpValidatePropertyData(
                                *(_DWORD *)(a1[16] + v14 + 28),
                                *(_DWORD *)(a1[16] + v14 + 24),
                                *(_DWORD *)(a1[16] + v14 + 20),
                                a1[16] + v14) >= 0 )
                      {
                        ++v13;
                        v14 += 32;
                        if ( v13 >= a1[15] )
                          goto LABEL_25;
                      }
                    }
                    else
                    {
LABEL_25:
                      v2 = 0;
                    }
                  }
                }
              }
            }
          }
        }
        return v2;
      }
    }
    else if ( !a1[10] && !a1[9] )
    {
      goto LABEL_11;
    }
  }
  return v2;
}
