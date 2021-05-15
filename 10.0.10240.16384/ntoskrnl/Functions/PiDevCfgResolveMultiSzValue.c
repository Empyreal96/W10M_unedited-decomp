// PiDevCfgResolveMultiSzValue 
 
int __fastcall PiDevCfgResolveMultiSzValue(unsigned int a1, unsigned int a2, unsigned __int16 *a3, int a4, int a5, unsigned __int16 *a6, unsigned int *a7, int *a8)
{
  unsigned __int16 *v9; // r9
  unsigned int v10; // r7
  unsigned __int16 *v13; // r2
  int v14; // r3
  int v15; // r3
  int v16; // r6
  int v17; // r0
  __int64 v18; // kr00_8
  _WORD *v19; // r1
  _WORD *v20; // r0
  unsigned int v23; // r5
  int v24; // r10
  int v25; // r0
  int v26; // r8
  unsigned int v27; // r10
  int v28; // r6
  unsigned int v29; // r4
  int v30; // r3
  unsigned __int16 *i; // r2
  unsigned __int16 *v32; // r2
  int j; // r3
  unsigned __int16 *v34; // r10
  int v35; // r6
  int v36; // r7
  int v37; // r3
  unsigned __int16 *v38; // r4
  unsigned int v39; // r4
  int v40; // r0
  int v42[2]; // [sp+0h] [bp-50h] BYREF
  int v43[2]; // [sp+8h] [bp-48h] BYREF
  int v44[2]; // [sp+10h] [bp-40h] BYREF
  int v45; // [sp+18h] [bp-38h] BYREF
  unsigned __int16 *v46; // [sp+1Ch] [bp-34h]
  int v47[2]; // [sp+20h] [bp-30h] BYREF
  unsigned __int16 v48[20]; // [sp+28h] [bp-28h] BYREF

  v9 = a3;
  *a7 = 0;
  v10 = 0;
  v43[0] = a4;
  *a8 = 0;
  v45 = a1;
  v42[0] = 0;
  if ( !a1 )
    goto LABEL_82;
  if ( a1 <= 2 )
  {
    if ( a2 < 2 )
      goto LABEL_11;
    v14 = a3[(a2 >> 1) - 1];
    goto LABEL_9;
  }
  if ( a1 != 7 )
  {
LABEL_82:
    v16 = -1073741823;
    goto LABEL_83;
  }
  if ( a2 >= 4 )
  {
    v13 = &a3[a2 >> 1];
    if ( !*(v13 - 1) && !*(v13 - 2) )
      goto LABEL_10;
  }
  if ( a2 == 2 )
  {
    v14 = *v9;
LABEL_9:
    if ( !v14 )
    {
LABEL_10:
      v15 = 1;
      goto LABEL_12;
    }
  }
LABEL_11:
  v15 = 0;
LABEL_12:
  if ( !v15 )
    return -1073741823;
  v17 = IopGetRegistryValue(a5, a6, 0, v42);
  v10 = v42[0];
  v16 = v17;
  v47[0] = v17;
  v44[0] = v42[0];
  if ( v17 >= 0 )
  {
    if ( *(_DWORD *)(v42[0] + 4) == 7 )
    {
      if ( (v18 = *(_QWORD *)(v42[0] + 8), v19 = (_WORD *)(v18 + v42[0]), HIDWORD(v18) >= 4)
        && (v20 = &v19[HIDWORD(v18) >> 1], !*(v20 - 1))
        && !*(v20 - 2)
        || HIDWORD(v18) == 2 && !*v19 )
      {
        if ( (a4 & 0x40000) != 0 )
        {
          v23 = *(_DWORD *)(v42[0] + 12);
          v24 = *(_DWORD *)(v42[0] + 8);
          v42[0] = v24;
          if ( !v23 )
            v23 = 2;
          v44[0] = v23 + a2;
          v25 = ExAllocatePoolWithTag(1, v23 + a2, 1667526736);
          v26 = v25;
          if ( !v25 )
            goto LABEL_33;
          if ( v23 <= 2 )
          {
            v27 = 0;
          }
          else
          {
            memmove(v25, v24 + v10, v23);
            v27 = v23 - 2;
          }
          if ( v45 == 7 )
          {
            if ( (v43[0] & 0x20000) != 0 )
            {
              memmove(v27 + v26, (int)v9, a2);
              v23 = v44[0] - 2;
            }
            else if ( *v9 )
            {
              v28 = v42[0];
              do
              {
                v29 = 2 * (wcslen(v9) + 1);
                RtlInitUnicodeString((unsigned int)v44, v9);
                v30 = *(unsigned __int16 *)(v28 + v10);
                for ( i = (unsigned __int16 *)(v28 + v10); ; v30 = *i )
                {
                  v42[0] = (int)i;
                  if ( !v30 )
                    break;
                  RtlInitUnicodeString((unsigned int)&v45, i);
                  if ( RtlEqualUnicodeString((unsigned __int16 *)v44, (unsigned __int16 *)&v45, 1) )
                    goto LABEL_47;
                  i = (unsigned __int16 *)(v42[0] + 2 * (((unsigned __int16)v45 >> 1) + 1));
                }
                memmove(v27 + v26, (int)v9, v29);
                v27 += v29;
                v23 += v29;
LABEL_47:
                v9 += v29 >> 1;
              }
              while ( *v9 );
              v16 = v47[0];
            }
          }
          else
          {
            if ( (v43[0] & 0x20000) == 0 && v23 != 2 )
            {
              RtlInitUnicodeString((unsigned int)&v45, v9);
              v32 = (unsigned __int16 *)(v42[0] + v10);
              for ( j = *(unsigned __int16 *)(v42[0] + v10); ; j = *v32 )
              {
                v43[0] = (int)v32;
                if ( !j )
                  break;
                RtlInitUnicodeString((unsigned int)v47, v32);
                if ( RtlEqualUnicodeString((unsigned __int16 *)&v45, (unsigned __int16 *)v47, 1) )
                  goto LABEL_79;
                v32 = (unsigned __int16 *)(v43[0] + 2 * ((LOWORD(v47[0]) >> 1) + 1));
              }
            }
            memmove(v27 + v26, (int)v9, a2);
            v23 = v44[0];
          }
          goto LABEL_79;
        }
        v26 = ExAllocatePoolWithTag(1, *(_DWORD *)(v42[0] + 12), 1667526736);
        if ( !v26 )
        {
LABEL_33:
          v16 = -1073741670;
          goto LABEL_83;
        }
        if ( a1 != 7 )
          RtlInitUnicodeString((unsigned int)v48, v9);
        v23 = 2;
        v34 = (unsigned __int16 *)(*(_DWORD *)(v10 + 8) + v10);
        if ( !*v34 )
        {
LABEL_79:
          if ( v26 )
            *(_WORD *)(v26 + 2 * (v23 >> 1) - 2) = 0;
          *a7 = v23;
          *a8 = v26;
          goto LABEL_83;
        }
        v35 = v45;
        v36 = 0;
        while ( 1 )
        {
          RtlInitUnicodeString((unsigned int)&v45, v34);
          if ( v35 == 7 )
            break;
          if ( !RtlEqualUnicodeString(v48, (unsigned __int16 *)&v45, 1) )
            goto LABEL_68;
LABEL_69:
          v34 += ((unsigned __int16)v45 >> 1) + 1;
          if ( !*v34 )
          {
            v16 = v47[0];
            v10 = v44[0];
            goto LABEL_79;
          }
        }
        RtlInitUnicodeString((unsigned int)v42, v46);
        v37 = *v9;
        v38 = v9;
        while ( v37 )
        {
          RtlInitUnicodeString((unsigned int)v43, v38);
          if ( RtlEqualUnicodeString((unsigned __int16 *)v42, (unsigned __int16 *)v43, 1) )
            goto LABEL_69;
          v38 += (LOWORD(v43[0]) >> 1) + 1;
          v37 = *v38;
        }
LABEL_68:
        v39 = (unsigned __int16)v45 + 2;
        memmove(v36 + v26, (int)v46, v39);
        v36 += v39;
        v23 += v39;
        goto LABEL_69;
      }
    }
    goto LABEL_82;
  }
  if ( v17 == -1073741772 )
  {
    v16 = 0;
    if ( (a4 & 0x40000) == 0 )
    {
      v23 = 0;
      v26 = 0;
      goto LABEL_79;
    }
    v23 = a2;
    if ( a1 != 7 )
      v23 = a2 + 2;
    v40 = ExAllocatePoolWithTag(1, v23, 1667526736);
    v26 = v40;
    if ( v40 )
    {
      memmove(v40, (int)v9, a2);
      goto LABEL_79;
    }
    v16 = -1073741670;
    v10 = v42[0];
  }
LABEL_83:
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v16;
}
