// VhdiGetDiskParameters 
 
int __fastcall VhdiGetDiskParameters(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r7
  unsigned int v9; // r1
  _DWORD *v10; // r4
  int v11; // r3

  v5 = -1073741811;
  if ( a1 )
  {
    if ( a2 )
    {
      if ( a3 )
      {
        if ( a4 )
        {
          if ( a1[1] == 6 && a1[9] == 6 )
          {
            v9 = a1[3];
            if ( v9 >= 0x5C && v9 >= a1[17] + 56 && !a1[15] && a1[19] == 5 && a1[22] == 5 )
            {
              v10 = a1 + 23;
              if ( a1[23] == 6 && !a1[31] )
              {
                memset((_BYTE *)a2, 0, 144);
                *(_DWORD *)(a2 + 24) = *a1;
                v11 = v10[9];
                if ( v11 == 1 )
                {
                  *(_DWORD *)a2 = 0;
                  *a3 = v10 + 10;
                  *(_DWORD *)(a2 + 8) = v10[4];
                  *(_DWORD *)(a2 + 12) = v10[5];
LABEL_18:
                  *a4 = (char *)v10 + v10[2];
                  return 0;
                }
                if ( !v11 )
                {
                  *(_DWORD *)a2 = 1;
                  *a3 = v10 + 10;
                  *(_DWORD *)(a2 + 48) = v10[4];
                  *(_DWORD *)(a2 + 52) = v10[5];
                  *(_DWORD *)(a2 + 56) = v10[6];
                  *(_DWORD *)(a2 + 60) = v10[7];
                  goto LABEL_18;
                }
              }
            }
          }
        }
      }
    }
  }
  return v5;
}
