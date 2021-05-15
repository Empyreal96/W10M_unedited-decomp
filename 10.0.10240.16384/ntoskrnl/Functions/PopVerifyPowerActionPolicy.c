// PopVerifyPowerActionPolicy 
 
int __fastcall PopVerifyPowerActionPolicy(int *a1)
{
  int v2; // r5
  int v3; // r2
  int v5; // r2
  BOOL v6; // r0
  int v7; // r6
  int v8; // r7
  int v9; // r1
  int v10; // r3
  _BYTE v11[22]; // [sp+0h] [bp-68h] BYREF
  char v12; // [sp+16h] [bp-52h]

  v2 = 0;
  if ( a1 )
  {
    v3 = a1[1];
    if ( (v3 & 0xFFFFFF0) == 0 )
    {
      if ( v3 < 0 )
        return sub_7BDC9C();
      PopFilterCapabilities(&PopCapabilities, v11);
      v5 = 0;
      v6 = 0;
      if ( v11[3] )
        v5 = 1;
      if ( v11[4] )
        ++v5;
      if ( v11[5] )
        ++v5;
      if ( v11[6] && v11[8] )
      {
        if ( v12 == 2 )
        {
          v6 = 1;
        }
        else if ( v12 == 1 )
        {
          v6 = (a1[1] & 8) != 0;
        }
      }
      v7 = v11[20];
      v8 = v11[7];
      while ( 1 )
      {
        v9 = *a1;
        if ( *a1 == 6 )
        {
          if ( !v8 )
          {
            v10 = 4;
LABEL_24:
            *a1 = v10;
            goto LABEL_18;
          }
        }
        else
        {
          if ( v9 != 2 )
          {
            if ( v9 != 1 )
            {
              if ( v9 != 3 )
              {
                if ( v9 != 8 || !v7 )
                  goto LABEL_18;
LABEL_36:
                *a1 = 2;
                goto LABEL_18;
              }
              if ( v6 )
                goto LABEL_18;
              if ( v5 )
                goto LABEL_36;
LABEL_27:
              *a1 = 0;
              v2 = 1;
              goto LABEL_18;
            }
            *a1 = 2;
          }
          if ( !v5 )
          {
            if ( !v6 )
              goto LABEL_27;
            v10 = 3;
            goto LABEL_24;
          }
        }
LABEL_18:
        if ( v9 == *a1 )
          return v2;
      }
    }
  }
  return 0;
}
