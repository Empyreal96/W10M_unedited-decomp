// PfCalculateProcessHash 
 
int __fastcall PfCalculateProcessHash(int a1, unsigned __int16 **a2)
{
  int v5; // r5
  unsigned __int16 *v6; // r4
  unsigned int v7; // r5
  unsigned __int8 *v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // lr
  int v11; // r2
  int v12; // r3
  int v13; // t1
  int v14; // t1
  int v15; // t1
  int v16; // t1
  int v17; // t1
  unsigned __int16 *v18; // [sp+0h] [bp-18h] BYREF

  v18 = 0;
  if ( ((unsigned __int8)a2 & 1) != 0 )
    return sub_8088AC();
  if ( *(_DWORD *)(a1 + 292) )
  {
    v5 = PsGetAllocatedFullProcessImageName(a1, &v18);
    v6 = v18;
    if ( v5 >= 0 )
    {
      if ( *v18 )
      {
        RtlUpcaseUnicodeString(v18, v18, 0, *v18);
        if ( *(_DWORD *)(a1 + 408) )
        {
LABEL_8:
          if ( a2 )
          {
            *a2 = v6;
            v6 = 0;
          }
          v5 = 0;
          goto LABEL_11;
        }
        v7 = *v6;
        v8 = (unsigned __int8 *)*((_DWORD *)v6 + 1);
        v9 = 314159;
        if ( v7 >= 8 )
        {
          v10 = v7 >> 3;
          v7 -= 8 * (v7 >> 3);
          do
          {
            v11 = 37 * (37 * (37 * (37 * (37 * (37 * v8[1] + v8[2]) + v8[3]) + v8[4]) + v8[5]) + v8[6])
                - 803794207 * v9
                + 442596621 * *v8;
            v12 = v8[7];
            v8 += 8;
            v9 = v11 + v12;
            --v10;
          }
          while ( v10 );
        }
        if ( v7 != 1 )
        {
          if ( v7 != 2 )
          {
            if ( v7 != 3 )
            {
              if ( v7 != 4 )
              {
                if ( v7 != 5 )
                {
                  if ( v7 != 6 )
                  {
                    if ( v7 != 7 )
                    {
LABEL_35:
                      if ( v9 <= 1 )
                        v9 = 1;
                      *(_DWORD *)(a1 + 408) = v9;
                      goto LABEL_8;
                    }
                    v9 = 37 * v9 + *v8++;
                  }
                  v13 = *v8++;
                  v9 = 37 * v9 + v13;
                }
                v14 = *v8++;
                v9 = 37 * v9 + v14;
              }
              v15 = *v8++;
              v9 = 37 * v9 + v15;
            }
            v16 = *v8++;
            v9 = 37 * v9 + v16;
          }
          v17 = *v8++;
          v9 = 37 * v9 + v17;
        }
        v9 = 37 * v9 + *v8;
        goto LABEL_35;
      }
      v5 = -1073741198;
    }
LABEL_11:
    if ( v6 )
      ExFreePoolWithTag((unsigned int)v6);
    goto LABEL_13;
  }
  v5 = -1073741275;
LABEL_13:
  if ( !a2 )
    v5 = 0;
  return v5;
}
