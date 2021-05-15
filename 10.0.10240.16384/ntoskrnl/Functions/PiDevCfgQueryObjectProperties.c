// PiDevCfgQueryObjectProperties 
 
int __fastcall PiDevCfgQueryObjectProperties(int a1, int a2, int a3, int a4, int *a5, unsigned int a6)
{
  int v7; // r0
  int v8; // r4
  int v9; // r8
  int v11; // r3
  _BYTE *v12; // r7
  int v13; // r10
  unsigned int v14; // r6
  int v15; // r4
  int v16; // r0
  unsigned int v18; // r0
  int v19; // r0
  int v20; // r1
  _BYTE *v21; // r2
  int v22; // r3
  int v23; // r3
  unsigned int v24; // [sp+20h] [bp-40h] BYREF
  int v25; // [sp+24h] [bp-3Ch] BYREF
  int v26; // [sp+28h] [bp-38h] BYREF
  int v27; // [sp+2Ch] [bp-34h]
  int v28; // [sp+30h] [bp-30h]
  int v29; // [sp+34h] [bp-2Ch]
  int v30; // [sp+38h] [bp-28h]
  int v31; // [sp+3Ch] [bp-24h]
  int v32; // [sp+40h] [bp-20h]

  v26 = 1;
  v7 = 0;
  v8 = 0;
  v24 = 0;
  v25 = 0;
  v9 = 0;
  v27 = 0;
  v29 = a4;
  v30 = a3;
  v31 = a2;
  v32 = a1;
  if ( !a4 )
  {
    v8 = PnpOpenObjectRegKey(a1, a2, a3, 33554433, 0, (int)&v25, 0, 0);
    if ( v8 < 0 )
      goto LABEL_21;
    v7 = v25;
  }
  v28 = 0;
  if ( a6 )
  {
    while ( 1 )
    {
      v11 = a5[4];
      if ( (v11 & 4) != 0 )
      {
        v14 = a5[2];
        v12 = *(_BYTE **)(v14 + 4);
        v13 = *(unsigned __int16 *)(v14 + 2);
      }
      else
      {
        v13 = a5[3];
        v12 = (_BYTE *)a5[2];
        v14 = 0;
      }
      if ( (v11 & 2) != 0 )
      {
        if ( v9 )
        {
          v15 = v27;
        }
        else
        {
          v15 = 260;
          v27 = 260;
          v9 = ExAllocatePoolWithTag(1, 260, 1667526736);
          v7 = v25;
          if ( !v9 )
          {
            v8 = -1073741670;
            goto LABEL_22;
          }
        }
        v13 = v15;
        v12 = (_BYTE *)v9;
      }
      if ( v29 )
        v7 = v29;
      v16 = PnpGetObjectProperty(v32, v31, v30, v7, 0, *a5, (int)&v26, (int)v12, v13, (int)&v24, 0);
      v8 = v16;
      if ( v16 == -1073741789 )
        return sub_7E3474();
      if ( v16 == -1073741670 )
      {
LABEL_19:
        if ( v9 )
          ExFreePoolWithTag(v9);
LABEL_21:
        v7 = v25;
        goto LABEL_22;
      }
      if ( v16 >= 0 )
        break;
LABEL_15:
      a5[5] = v8;
      if ( v8 < 0 )
      {
        if ( (a5[4] & 8) != 0 )
        {
          if ( v14 )
          {
            RtlInitUnicodeString(v14, 0);
          }
          else if ( v12 )
          {
            memset(v12, 0, v13);
          }
        }
        if ( (a5[4] & 1) != 0 )
          goto LABEL_19;
        v8 = 0;
      }
      a5 += 6;
      if ( ++v28 >= a6 )
        goto LABEL_19;
      v7 = v25;
    }
    v18 = v24;
    if ( !v26 )
    {
      a5[1] = 0;
      goto LABEL_31;
    }
    if ( v26 != a5[1] )
    {
      v8 = -1073741823;
      goto LABEL_15;
    }
    if ( v26 == 18 || v26 == 20 || v26 == 25 )
    {
      if ( v24 < 2 )
        goto LABEL_69;
      v22 = *(unsigned __int16 *)&v12[2 * (v24 >> 1) - 2];
    }
    else
    {
      if ( v26 != 8210 )
        goto LABEL_31;
      if ( v24 >= 4 )
      {
        v21 = &v12[2 * (v24 >> 1)];
        if ( !*((_WORD *)v21 - 1) && !*((_WORD *)v21 - 2) )
          goto LABEL_68;
      }
      if ( v24 != 2 )
      {
LABEL_69:
        v23 = 0;
LABEL_70:
        if ( !v23 )
          v8 = -1073741823;
LABEL_31:
        if ( v8 >= 0 )
        {
          if ( v14 && v18 > 0xFFFE )
            v8 = -2147483643;
          if ( v8 >= 0 )
          {
            if ( (a5[4] & 2) != 0 )
            {
              if ( v14 )
              {
                v19 = ExpAllocateStringRoutine(v18);
                *(_DWORD *)(v14 + 4) = v19;
                if ( !v19 )
                  goto LABEL_57;
                *(_WORD *)(v14 + 2) = v24;
              }
              else
              {
                v19 = ExAllocatePoolWithTag(1, v18, 1667526736);
                v12 = (_BYTE *)v19;
                if ( !v19 )
                {
LABEL_57:
                  v8 = -1073741670;
                  goto LABEL_19;
                }
              }
              memmove(v19, v9, v24);
              v18 = v24;
            }
            if ( v14 )
            {
              *(_WORD *)v14 = v18;
              if ( v26 != 8210 )
              {
                v20 = *(_DWORD *)(v14 + 4);
                if ( v20 )
                {
                  if ( (unsigned __int16)v18 >= 2u && !*(_WORD *)(v20 + 2 * ((unsigned __int16)v18 >> 1) - 2) )
                    *(_WORD *)v14 = v18 - 2;
                }
              }
            }
            else
            {
              if ( (a5[4] & 2) != 0 )
              {
                *(_DWORD *)a5[2] = v12;
                v18 = v24;
              }
              a5[3] = v18;
            }
          }
        }
        goto LABEL_15;
      }
      v22 = *(unsigned __int16 *)v12;
    }
    if ( !v22 )
    {
LABEL_68:
      v23 = 1;
      goto LABEL_70;
    }
    goto LABEL_69;
  }
LABEL_22:
  if ( v7 )
    ZwClose();
  return v8;
}
