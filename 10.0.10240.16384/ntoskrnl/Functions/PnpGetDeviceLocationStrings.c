// PnpGetDeviceLocationStrings 
 
int __fastcall PnpGetDeviceLocationStrings(int a1, unsigned int *a2, int *a3)
{
  int v3; // r6
  unsigned int v4; // r9
  int v5; // r0
  int v7; // r10
  int v8; // r3
  _BYTE *v9; // r0
  unsigned int v10; // r7
  _BYTE *v11; // r0
  unsigned int v12; // r7
  unsigned int v13; // r4
  unsigned __int16 **v14; // r8
  int v15; // r5
  int v16; // r7
  unsigned __int16 *v17; // r4
  int v18; // r9
  unsigned int v19; // r8
  unsigned int v20; // r10
  unsigned int v21; // r0
  int v22; // r7
  int v23; // r0
  unsigned __int16 *v24; // r4
  unsigned int v25; // r6
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r4
  _BYTE *v30; // r0
  unsigned int v31; // r2
  _WORD *v32; // r8
  unsigned int v33; // r0
  int v34; // r5
  unsigned int v35; // r1
  unsigned int *v36; // r10
  int v37; // r9
  int v38; // r6
  int v39; // r7
  unsigned int v40; // r4
  unsigned int v41; // r4
  unsigned __int16 *i; // r10
  int v43; // r3
  int j; // r1
  int v45; // r2
  int v46; // t1
  int v47; // r2
  int v48; // r4
  unsigned int v49; // r0
  _WORD *v50; // r7
  unsigned int v51; // r0
  int *v52; // r2
  unsigned int *v53; // r4
  unsigned int v54; // r0
  unsigned int v55; // t1
  int v56; // [sp+8h] [bp-78h]
  unsigned int v57; // [sp+8h] [bp-78h]
  int v58; // [sp+8h] [bp-78h]
  unsigned int v59; // [sp+Ch] [bp-74h]
  int v60; // [sp+Ch] [bp-74h]
  int v61; // [sp+10h] [bp-70h]
  unsigned int v62; // [sp+10h] [bp-70h]
  _BYTE *v63; // [sp+14h] [bp-6Ch]
  unsigned int *v64; // [sp+14h] [bp-6Ch]
  unsigned int v65; // [sp+18h] [bp-68h]
  unsigned __int16 *v66; // [sp+1Ch] [bp-64h] BYREF
  unsigned int v67; // [sp+20h] [bp-60h]
  unsigned int v68; // [sp+24h] [bp-5Ch]
  unsigned int v69; // [sp+28h] [bp-58h]
  _BYTE *v70; // [sp+2Ch] [bp-54h]
  unsigned int v71; // [sp+30h] [bp-50h]
  int v72; // [sp+34h] [bp-4Ch]
  int v73; // [sp+38h] [bp-48h]
  int v74; // [sp+3Ch] [bp-44h]
  unsigned int *v75; // [sp+40h] [bp-40h]
  int *v76; // [sp+44h] [bp-3Ch]
  _BYTE *v77; // [sp+48h] [bp-38h]
  char v78[4]; // [sp+50h] [bp-30h] BYREF
  int v79; // [sp+54h] [bp-2Ch]
  void (__fastcall *v80)(int); // [sp+5Ch] [bp-24h]
  int (__fastcall *v81)(int, unsigned __int16 **); // [sp+60h] [bp-20h]

  v72 = 0;
  v71 = -1;
  v3 = a1;
  v67 = -1;
  v75 = a2;
  v76 = a3;
  v61 = a1;
  v4 = 0;
  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  *a2 = 0;
  v5 = IopRootDeviceNode;
  *a3 = 0;
  if ( v3 == v5 )
    return sub_7C9A10();
  v7 = 0;
  v8 = v3;
  do
  {
    v8 = *(_DWORD *)(v8 + 8);
    ++v7;
  }
  while ( v8 != v5 );
  v73 = v7;
  v9 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v7, 1970499664);
  v10 = (unsigned int)v9;
  v65 = (unsigned int)v9;
  if ( !v9 )
    return -1073741670;
  memset(v9, 0, 4 * v7);
  v11 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v7, 1970499664);
  v70 = v11;
  if ( v11 )
  {
    memset(v11, 0, 4 * v7);
    v69 = 1;
    v12 = 0;
    v13 = 0;
    v56 = 0;
    v59 = 0;
    if ( v3 != IopRootDeviceNode )
    {
      v14 = (unsigned __int16 **)v65;
      v68 = v65;
      v63 = &v70[-v65];
      do
      {
        v15 = PnpQueryInterface(*(_DWORD *)(v3 + 16), &GUID_PNP_LOCATION_INTERFACE, 1, 20, 0, v78);
        if ( v15 < 0 )
        {
LABEL_92:
          v4 = 0;
          goto LABEL_80;
        }
        if ( !v81 )
        {
          v15 = -1073741823;
          goto LABEL_41;
        }
        v66 = 0;
        v15 = v81(v79, &v66);
        if ( v15 < 0 )
          goto LABEL_99;
        if ( !v66 )
          v15 = -1073741637;
        if ( v15 < 0 )
        {
LABEL_99:
          if ( v66 )
            goto LABEL_40;
          goto LABEL_41;
        }
        v16 = 0;
        *(unsigned __int16 **)((char *)v14 + (_DWORD)v63) = 0;
        v17 = v66;
        v18 = 0;
        v19 = 0;
        if ( *v66 )
        {
          v20 = v68;
          do
          {
            *(_DWORD *)&v63[v20] = ++v18;
            v16 += wcslen(v17) + 1;
            v21 = wcslen(v17);
            if ( v21 > v19 )
              v19 = v21;
            v17 += wcslen(v17) + 1;
          }
          while ( *v17 );
          v3 = v61;
          v7 = v73;
        }
        v22 = v16 + 1;
        v13 = v56 + v19;
        v69 *= v18;
        v57 = v56 + v19;
        v23 = ExAllocatePoolWithTag(1, 2 * v22, 1970499664);
        v14 = (unsigned __int16 **)v68;
        *(_DWORD *)v68 = v23;
        if ( !v23 )
        {
          v15 = -1073741670;
          v12 = v59;
          goto LABEL_40;
        }
        memmove(v23, (int)v66, 2 * v22);
        v24 = *v14;
        if ( !**v14 )
          goto LABEL_39;
        v25 = v71;
        do
        {
          v26 = 0;
          v27 = 0;
          while ( 1 )
          {
            v28 = *v24;
            if ( v28 == 33 )
            {
              v26 = 1;
              goto LABEL_30;
            }
            if ( v28 != 64 )
              break;
            v27 = 1;
LABEL_30:
            ++v24;
          }
          if ( v27 )
            v72 = 1;
          if ( v26 && v25 == -1 )
            v25 = v59;
          v24 += wcslen(v24) + 1;
        }
        while ( *v24 );
        v71 = v25;
        v3 = v61;
LABEL_39:
        v13 = v57;
        v68 = (unsigned int)++v14;
        v12 = ++v59;
LABEL_40:
        ExFreePoolWithTag((unsigned int)v66);
        v66 = 0;
LABEL_41:
        if ( v80 )
          v80(v79);
        if ( v15 < 0 )
          goto LABEL_92;
        if ( v15 == 288 || v12 == v7 )
        {
          ++v13;
          break;
        }
        v3 = *(_DWORD *)(v3 + 8);
        v56 = ++v13;
        v61 = v3;
      }
      while ( v3 != IopRootDeviceNode );
    }
    v15 = 0;
    v29 = v13 * v69 + 1;
    v74 = 0;
    v30 = (_BYTE *)ExAllocatePoolWithTag(1, 2 * v29, 1970499664);
    v4 = (unsigned int)v30;
    v77 = v30;
    if ( v30 )
    {
      memset(v30, 0, 2 * v29);
      v31 = v69;
      v62 = 0;
      v32 = (_WORD *)v4;
      if ( v69 )
      {
        v33 = (unsigned int)v70;
        v34 = v12 - 1;
        do
        {
          v35 = v31;
          v36 = (unsigned int *)(v33 + 4 * v34);
          v58 = 0;
          v60 = 0;
          v37 = 0;
          v38 = v34;
          v39 = (int)v32;
          v64 = v36;
          while ( 1 )
          {
            v40 = *v36;
            v68 = v35;
            if ( !v40 )
              __brkdiv0();
            if ( !(v35 / v40) )
              __brkdiv0();
            v41 = v62 / (v35 / v40) % v40;
            for ( i = *(unsigned __int16 **)((char *)v36 + v65 - (_DWORD)v70); v41; --v41 )
              i += wcslen(i) + 1;
            v43 = 0;
            for ( j = 0; ; j = 1 )
            {
              while ( 1 )
              {
                v46 = *i++;
                v45 = v46;
                if ( v46 != 33 )
                  break;
                v43 = 1;
              }
              if ( v45 != 64 )
                break;
            }
            if ( v38 == v34 )
            {
              v48 = v43;
              v47 = v43;
              v58 = v43;
              v60 = v43;
              v37 = v43;
              v67 = v43 ? v38 : -1;
            }
            else
            {
              v48 = v58;
              v47 = v60;
            }
            if ( v43 )
            {
              if ( !v37 && !v72 )
                goto LABEL_77;
              v48 = 1;
              v58 = 1;
              v67 = v38;
              if ( !v47 )
                v37 = 0;
            }
            else
            {
              v60 = 0;
            }
            if ( j )
            {
              v48 = v43;
              v58 = v43;
              v60 = v43;
              v39 = (int)v32;
              v37 = v43;
              if ( v43 )
                v67 = v38;
              else
                v67 = -1;
            }
            v49 = wcslen(i - 1);
            memmove(v39, (int)(i - 1), 2 * v49);
            v50 = (_WORD *)(v39 + 2 * wcslen(i - 1));
            if ( !v38 )
              break;
            *v50 = 35;
            v39 = (int)(v50 + 1);
            v36 = v64 - 1;
            v51 = *v64--;
            if ( !v51 )
              __brkdiv0();
            v35 = v68 / v51;
            --v38;
          }
          if ( !v48 || v37 && v67 <= v71 )
          {
            *v50 = 0;
            v32 = v50 + 1;
          }
LABEL_77:
          v31 = v69;
          v33 = (unsigned int)v70;
          ++v62;
        }
        while ( v62 < v69 );
        v7 = v73;
        v15 = v74;
        v4 = (unsigned int)v77;
      }
      *v32 = 0;
      v52 = v76;
      *v75 = v4;
      *v52 = (int)((int)v32 - v4 + 2) >> 1;
    }
    else
    {
      v15 = -1073741670;
    }
LABEL_80:
    v10 = v65;
  }
  else
  {
    v15 = -1073741670;
  }
  if ( v7 )
  {
    v53 = (unsigned int *)v10;
    do
    {
      v55 = *v53++;
      v54 = v55;
      if ( v55 )
        ExFreePoolWithTag(v54);
      --v7;
    }
    while ( v7 );
  }
  ExFreePoolWithTag(v10);
  if ( v70 )
    ExFreePoolWithTag((unsigned int)v70);
  if ( v15 < 0 && v4 )
    ExFreePoolWithTag(v4);
  return v15;
}
