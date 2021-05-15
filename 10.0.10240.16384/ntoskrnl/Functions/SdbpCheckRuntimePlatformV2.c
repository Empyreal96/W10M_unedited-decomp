// SdbpCheckRuntimePlatformV2 
 
int __fastcall SdbpCheckRuntimePlatformV2(BOOL *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r7
  int v6; // r5
  BOOL v7; // r4
  unsigned int v9; // r0
  int v10; // r2
  int v11; // r3
  bool v12; // zf

  v6 = *(_DWORD *)(a2 + 404);
  v7 = 0;
  if ( (v6 & 2) != 0 )
    v5 = 1;
  if ( (v6 & 2) == 0 )
    v5 = 0;
  v9 = SdbReadDWORDTag(a3, a5, 31);
  if ( v9 != -1073741824 )
  {
    v10 = 0;
    while ( 1 )
    {
      if ( v7 )
        goto LABEL_26;
      if ( ((v9 >> v10) & 0x40) == 0 )
        goto LABEL_25;
      v11 = (v9 >> v10) & 0x3F;
      if ( v11 )
      {
        if ( v11 == 5 )
        {
          v12 = (v6 & 8) == 0;
        }
        else if ( v11 == 9 )
        {
          v12 = (v6 & 2) == 0;
        }
        else
        {
          if ( v11 != 11 )
          {
            if ( v11 == 12 )
            {
              v7 = (v6 & 4) != 0;
            }
            else
            {
              if ( v11 != 13 )
                goto LABEL_24;
              v7 = v5;
            }
            goto LABEL_25;
          }
          v12 = (v6 & 4) == 0;
        }
      }
      else
      {
        v12 = (v6 & 1) == 0;
      }
      if ( v12 )
      {
LABEL_24:
        v7 = 0;
        goto LABEL_25;
      }
      v7 = 1;
LABEL_25:
      v10 += 8;
      if ( v10 >= 24 )
        goto LABEL_26;
    }
  }
  v7 = 1;
LABEL_26:
  *a1 = v7;
  return 1;
}
