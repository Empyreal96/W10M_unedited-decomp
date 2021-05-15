// PfVerifyTraceBuffer 
 
int __fastcall PfVerifyTraceBuffer(_DWORD *a1, unsigned int a2, int *a3)
{
  int v4; // r4
  int v5; // r9
  int v8; // r3
  unsigned int v9; // r8
  unsigned int v10; // r7
  unsigned int v11; // r3
  char *v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r1
  int v15; // r6
  _DWORD *v16; // r0
  int v17; // r3
  unsigned int v18; // r3
  unsigned int v19; // r3

  v4 = 0;
  v5 = 0;
  if ( a2 < 0xD0 )
  {
    v4 = 10;
  }
  else if ( ((unsigned __int8)a1 & 7) != 0 )
  {
    v4 = 15;
  }
  else
  {
    if ( *a1 != 30 || a1[1] != 1128485697 )
    {
      v4 = 20;
      goto LABEL_27;
    }
    if ( a2 > 0x10000000 )
    {
      v4 = 23;
    }
    else
    {
      v8 = a1[19];
      if ( v8 < 0 || v8 >= 2 )
      {
        v4 = 25;
        goto LABEL_27;
      }
      v9 = a1[25];
      if ( v9 > 0x84000 || (v10 = a1[21], v10 > 0x100000) )
      {
        v4 = 30;
        goto LABEL_27;
      }
      if ( a1[2] == a2 )
      {
        if ( PfVerifyScenarioId(a1 + 3) )
        {
          v11 = (unsigned int)a1 + a1[20];
          if ( (v11 & 3) != 0 )
          {
            v4 = 38;
          }
          else
          {
            if ( v11 < (unsigned int)a1 || (v12 = (char *)a1 + a2, v11 >= (unsigned int)a1 + a2) )
            {
              v4 = 40;
              goto LABEL_27;
            }
            v13 = v11 + 8 * v10 - 1;
            if ( v13 < (unsigned int)a1 || v13 >= (unsigned int)v12 )
            {
              v4 = 50;
              goto LABEL_27;
            }
            v14 = 0;
            v15 = 10;
            v16 = a1;
            do
            {
              v17 = v16[28];
              ++v16;
              v14 += v17;
              --v15;
            }
            while ( v15 );
            if ( v14 < a1[22] )
            {
              v4 = 120;
            }
            else
            {
              if ( v9 )
              {
                v18 = (unsigned int)a1 + a1[24];
                if ( (v18 & 3) != 0 )
                {
                  v4 = 65;
                  goto LABEL_27;
                }
                if ( v18 < (unsigned int)a1 || v18 >= (unsigned int)v12 )
                {
                  v4 = 80;
                  goto LABEL_27;
                }
                v19 = v18 + 16 * v9 - 1;
                if ( v19 < (unsigned int)a1 || v19 >= (unsigned int)v12 )
                {
                  v4 = 90;
                  goto LABEL_27;
                }
              }
              v5 = 1;
            }
          }
        }
        else
        {
          v4 = 37;
        }
      }
      else
      {
        v4 = 35;
      }
    }
  }
LABEL_27:
  *a3 = v4;
  return v5;
}
