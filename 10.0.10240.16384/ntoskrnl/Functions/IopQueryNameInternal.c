// IopQueryNameInternal 
 
int __fastcall IopQueryNameInternal(_DWORD *a1, int a2, int a3, int a4, unsigned int a5, unsigned int *a6, char a7)
{
  _DWORD *v8; // lr
  int *v9; // r4
  int v10; // r2
  int v11; // r10
  unsigned int v12; // r6
  int v13; // r0
  int v14; // r3
  unsigned __int16 *v16; // r8
  int v17; // r0
  int v18; // r0
  unsigned int v19; // r5
  int v20; // lr
  int v21; // r0
  unsigned int v22; // r2
  int v23; // r1
  int v24; // r3
  unsigned int v25; // r2
  int v26; // r10
  unsigned int *v27; // r9
  int v28; // r8
  _DWORD *v29; // r0
  int v30; // r0
  unsigned int v31; // r3
  int v32; // r3
  unsigned int v33; // r5
  _WORD *v34; // r10
  int v35; // r6
  __int16 v36; // r2
  unsigned int v38; // [sp+10h] [bp-50h] BYREF
  int v39; // [sp+14h] [bp-4Ch]
  int v40; // [sp+18h] [bp-48h]
  _DWORD *v41; // [sp+1Ch] [bp-44h]
  _WORD *v42; // [sp+20h] [bp-40h]
  _WORD *v43; // [sp+24h] [bp-3Ch]
  int v44; // [sp+28h] [bp-38h]
  int v45; // [sp+2Ch] [bp-34h]
  int v46; // [sp+30h] [bp-30h]
  _DWORD _38[16]; // [sp+38h] [bp-28h] BYREF

  _38[12] = a1;
  _38[13] = a2;
  _38[14] = a3;
  _38[15] = a4;
  v42 = (_WORD *)a4;
  v46 = a3;
  v8 = a1;
  v41 = a1;
  v9 = 0;
  v45 = 0;
  v10 = 0;
  v44 = 0;
  v40 = 0;
  v11 = 0;
  v12 = a5;
  if ( a5 < 8 )
  {
    v12 = 8;
    v10 = 1;
    v40 = 1;
  }
  if ( a7 == 1 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v14 = 40;
      else
        v14 = 32;
      v13 = ExAllocatePoolWithTagPriority(1, v12, 538996553, v14);
    }
    else
    {
      v13 = ExAllocatePoolWithTag(1, v12, 538996553);
    }
    v9 = (int *)v13;
    v45 = v13;
    if ( !v13 )
      return -1073741670;
    v16 = (unsigned __int16 *)v13;
    v8 = v41;
  }
  else if ( v10 )
  {
    v16 = (unsigned __int16 *)_38;
  }
  else
  {
    v16 = (unsigned __int16 *)a4;
  }
  v17 = v8[1];
  if ( !a3 )
    goto LABEL_24;
  if ( (*(_DWORD *)(v17 + 32) & 0x10) == 0 )
  {
    v18 = IoVolumeDeviceToDosName();
    v19 = *v16 + 10;
    v38 = v19;
    v8 = v41;
LABEL_21:
    v39 = v18;
    if ( v18 >= 0 )
    {
      v11 = 1;
      goto LABEL_25;
    }
    goto LABEL_22;
  }
  v38 = 12;
  if ( v12 >= 0xC )
  {
    v18 = 0;
    *v16 = 2;
    v16[1] = 2;
    v16[4] = 92;
    *((_DWORD *)v16 + 1) = v16 + 4;
    v19 = v38;
    goto LABEL_21;
  }
LABEL_22:
  v17 = v8[1];
LABEL_24:
  v18 = ObQueryNameStringMode(v17, v16, v12, &v38, 0);
  v19 = v38;
  v39 = v18;
LABEL_25:
  if ( v18 >= 0 )
  {
    if ( !v11 && !*v16 )
      v44 = 1;
LABEL_31:
    v20 = (int)v42;
    v21 = (int)(v42 + 4);
    v43 = v42 + 4;
    if ( v46 && v11 )
    {
      if ( v12 >= v19 )
      {
        v22 = *v16;
      }
      else if ( v12 >= 8 )
      {
        v22 = v12 - 8;
      }
      else
      {
        v22 = 0;
      }
      memmove(v21, *((_DWORD *)v16 + 1), v22);
      if ( (*(_DWORD *)(v41[1] + 32) & 0x10) == 0 )
        ExFreePoolWithTag(*((_DWORD *)v16 + 1));
      v19 = v38;
    }
    else
    {
      v23 = a7;
      if ( a7 != 1 )
      {
LABEL_48:
        v24 = v40;
LABEL_49:
        if ( v44 )
        {
          v19 += 2;
          v38 = v19;
        }
        v26 = 0;
        if ( v24 || v19 > v12 )
        {
          v27 = a6;
          *a6 = v19;
          v26 = 1;
        }
        else
        {
          *(_DWORD *)(v20 + 4) = v21;
          v21 += *v16;
          v43 = (_WORD *)v21;
          v27 = a6;
          v24 = v40;
        }
        if ( v23 == 1 )
        {
          v28 = v44;
          if ( !v26 )
            v12 = v12 - v19 + 4;
        }
        else if ( v26 )
        {
          if ( v24 )
            v9 = _38;
          else
            v9 = (int *)v20;
          v28 = v44;
        }
        else
        {
          v9 = (int *)(v21 - 4);
          v28 = *(_DWORD *)(v21 - 4);
          v44 = v28;
          v12 = v20 - (v21 - 4) + v12 - 2;
        }
        if ( v23 == 1 && !v46 )
        {
          v29 = v41;
        }
        else
        {
          v29 = v41;
          if ( (v41[11] & 2) != 0 )
          {
            v30 = IopGetFileInformation(v41, v12, 9, (int)v9, &v38);
LABEL_71:
            v39 = v30;
            if ( (v30 & 0xC0000000) == -1073741824 )
            {
              if ( v30 != -1073741811 && v30 != -1073741808 && v30 != -1073741822 && v30 != -1073741821 )
                goto LABEL_92;
              v38 = 4;
              *v9 = 0;
              *((_WORD *)v9 + 2) = 92;
              v39 = 0;
              v31 = v38;
            }
            else
            {
              v31 = v38;
              if ( v38 < 4 )
              {
                v31 = 4;
                v38 = 4;
              }
            }
            if ( v26 )
            {
              *v27 += *v9;
              if ( v40 )
                v32 = -1073741820;
              else
                v32 = -2147483643;
            }
            else
            {
              v33 = v31 - 4;
              if ( v31 - 4 > *v9 )
                v33 = *v9;
              v34 = v42;
              v35 = (int)v43;
              v38 = (unsigned int)v43 + *v9 - (_DWORD)v42;
              if ( *((_WORD *)v9 + 2) == 92 )
              {
                if ( a7 == 1 )
                  memmove((int)v43, (int)(v9 + 1), v33);
                else
                  *v9 = v28;
                *(_WORD *)(v33 + v35) = 0;
                v38 += 2;
                *v27 = v38;
                v36 = v33 + v35 - (_WORD)v34;
                *v34 = v36 - 8;
                v34[1] = v36 - 6;
LABEL_92:
                if ( a7 == 1 )
                  ExFreePoolWithTag(v45);
                return v39;
              }
              v32 = -1073741767;
            }
            v39 = v32;
            goto LABEL_92;
          }
        }
        v30 = IopQueryXxxInformation(v29, 9, v12, v23, v9, &v38, 1);
        goto LABEL_71;
      }
      v24 = v40;
      if ( v40 )
        goto LABEL_49;
      if ( v19 <= v12 )
        v25 = v19;
      else
        v25 = v12;
      memmove((int)v42, (int)v16, v25);
    }
    v23 = a7;
    v20 = (int)v42;
    v21 = (int)v43;
    goto LABEL_48;
  }
  if ( v18 == -1073741820 )
    goto LABEL_31;
  return v18;
}
