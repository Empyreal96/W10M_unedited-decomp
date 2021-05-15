// PiGetDeviceRegProperty 
 
int __fastcall PiGetDeviceRegProperty(char *a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  char *v8; // r10
  int v9; // r0
  int v10; // r4
  int v12; // r0
  char *v13; // r7
  int v14; // r0
  char *v15; // r9
  unsigned int v16; // r8
  int v17; // r2
  int v18; // r0
  char *v19; // r0
  int v20; // r2
  _WORD *v21; // r0
  int *v22; // r2
  _WORD *v23; // r0
  unsigned int v24; // r3
  unsigned int v25; // [sp+18h] [bp-88h] BYREF
  unsigned int v26; // [sp+1Ch] [bp-84h] BYREF
  int v27; // [sp+20h] [bp-80h] BYREF
  char *v28; // [sp+24h] [bp-7Ch]
  char *v29; // [sp+28h] [bp-78h] BYREF
  int v30; // [sp+2Ch] [bp-74h]
  int v31[28]; // [sp+30h] [bp-70h] BYREF

  v28 = a1;
  v25 = *a6;
  v27 = 0;
  v8 = 0;
  v30 = a5;
  v9 = CmGetDeviceRegProp(PiPnpRtlCtx, (int)a1, 0, a4, (int)&v27, a5, (int)&v25);
  v10 = v9;
  if ( a3 == 1 )
  {
    if ( v9 < 0 )
    {
      if ( v9 != -1073741789 )
        return v10;
    }
    else if ( v27 != 1 )
    {
      return -1073741584;
    }
    v12 = ExAllocatePoolWithTag(1, v25, 1869181008);
    v13 = (char *)v12;
    if ( !v12 )
      return -1073741670;
    if ( v10 != -1073741789 )
    {
      memmove(v12, a5, v25);
      goto LABEL_14;
    }
    v18 = CmGetDeviceRegProp(PiPnpRtlCtx, (int)v28, 0, a4, (int)&v27, v12, (int)&v25);
    v10 = v18;
    if ( v18 < 0 )
    {
      if ( v18 == -1073741789 )
        *a6 = v25;
    }
    else
    {
      if ( v27 == 1 )
      {
LABEL_14:
        v26 = v25;
        v28 = v13;
        v29 = v13;
        v14 = PnpFindAlternateStringData(v13, v25, &v29, &v26);
        v15 = v29;
        v16 = v26;
        if ( !v14 )
          goto LABEL_15;
        v28 = v29;
        v19 = wcsstr(v29, (char *)L";(");
        v20 = (v16 >> 1) - 2;
        v8 = v19;
        if ( !v19 )
          goto LABEL_15;
        if ( *(_WORD *)&v15[2 * v20] == 41
          && (*(_WORD *)v19 = 0,
              *(_WORD *)&v15[2 * v20] = 0,
              v8 = v19 + 4,
              memset(v31, 0, 80),
              v26 = 1,
              v31[0] = (int)v8,
              (v21 = wcschr(v8, 44)) != 0) )
        {
          v22 = &v31[1];
          while ( 1 )
          {
            *v21 = 0;
            v23 = v21 + 1;
            v24 = v26;
            if ( v26 >= 0x13 )
              break;
            *v22 = (int)v23;
            v29 = (char *)(v22 + 1);
            v26 = v24 + 1;
            v21 = wcschr(v23, 44);
            v22 = (int *)v29;
            if ( !v21 )
              goto LABEL_15;
          }
          v17 = 1;
        }
        else
        {
LABEL_15:
          v17 = 0;
        }
        if ( *a6 < v16 )
        {
          v10 = -1073741789;
        }
        else if ( v8 )
        {
          if ( v17 )
            v10 = -1073741619;
          else
            v10 = RtlFormatMessage(v28, 0, 0, 0, 1, v31, v30, *a6, a6);
        }
        else
        {
          memmove(v30, (int)v15, v16);
        }
        *a6 = v16;
        goto LABEL_20;
      }
      v10 = -1073741584;
    }
LABEL_20:
    ExFreePoolWithTag((unsigned int)v13);
    return v10;
  }
  if ( v9 >= 0 )
  {
    if ( v27 != a3 )
      return sub_7E7CDC();
    goto LABEL_7;
  }
  if ( v9 == -1073741789 )
LABEL_7:
    *a6 = v25;
  return v10;
}
