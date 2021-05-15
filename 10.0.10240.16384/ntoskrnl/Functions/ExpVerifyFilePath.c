// ExpVerifyFilePath 
 
int __fastcall ExpVerifyFilePath(_DWORD *a1, unsigned int a2)
{
  _BYTE *v2; // r4
  unsigned int v3; // r3
  char *v4; // r2
  unsigned int v5; // r3
  char *v7; // r2
  int v8; // r6
  int v9; // r7
  unsigned int v10; // r3
  char *v11; // r5
  int v12; // r3
  int v13; // r0
  int v14; // r1
  char *v15; // r0
  int v16; // r3

  if ( (unsigned int)a1 <= a2 )
  {
    v2 = a1 + 3;
    if ( (unsigned int)(a1 + 3) <= a2 )
    {
      v3 = a1[1];
      if ( v3 >= 0xC )
      {
        v4 = (char *)a1 + v3;
        if ( (_DWORD *)((char *)a1 + v3) >= a1 && (unsigned int)v4 <= a2 )
        {
          if ( *a1 )
          {
            if ( *a1 <= 1u )
            {
              v5 = a1[2];
              if ( v5 )
              {
                if ( v5 <= 5 )
                {
                  if ( (unsigned int)v4 < a2 )
                    a2 = (unsigned int)v4;
                  if ( v5 <= 2 )
                    return sub_815180();
                  if ( v5 == 3 )
                  {
                    v13 = ExpSafeWcslen(a1 + 3, a2);
                    if ( v13 != -1 && ExpSafeWcslen(&v2[2 * v13 + 2], v14) != -1 )
                      return 0;
                  }
                  else if ( v5 == 4 )
                  {
                    while ( 1 )
                    {
                      v7 = v2 + 4;
                      if ( (unsigned int)(v2 + 4) > a2 )
                        break;
                      v8 = (unsigned __int8)v2[3];
                      v9 = (unsigned __int8)v2[2];
                      v10 = v9 | (v8 << 8);
                      if ( v10 < 4 )
                        break;
                      v11 = &v2[v10];
                      if ( (unsigned int)&v2[v10] > a2 )
                        break;
                      v12 = *v2 & 0x7F;
                      if ( v12 == 127 )
                        return 0;
                      if ( v12 == 4 && v2[1] == 4 )
                      {
                        v15 = v2 + 4;
                        if ( v7 >= v11 )
                          goto LABEL_33;
                        do
                        {
                          if ( !*(_WORD *)v15 )
                            break;
                          v15 += 2;
                        }
                        while ( v15 < v11 );
                        if ( v15 >= v11 )
LABEL_33:
                          v16 = -1;
                        else
                          v16 = (v15 - v7) >> 1;
                        if ( v16 == -1 )
                          break;
                      }
                      v2 += v9 | (v8 << 8);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -1073741811;
}
