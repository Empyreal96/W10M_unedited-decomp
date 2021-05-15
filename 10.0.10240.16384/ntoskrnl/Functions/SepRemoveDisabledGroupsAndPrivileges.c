// SepRemoveDisabledGroupsAndPrivileges 
 
int __fastcall SepRemoveDisabledGroupsAndPrivileges(_DWORD *a1, char a2, int a3, int a4, int a5, int *a6)
{
  int v7; // lr
  unsigned int v8; // r6
  int v9; // r10
  int v11; // r7
  _DWORD *v12; // r0
  int v13; // r8
  unsigned int v14; // r7
  unsigned int v15; // r0
  int *v16; // r2
  int v17; // r8
  _BYTE *v18; // r4
  unsigned int v19; // r3
  unsigned int v21; // r1
  int *v22; // r0
  int v23; // r2
  int v24; // t1
  int i; // r0
  int v27; // r2
  int v28; // r3
  int v29; // r1
  int v30; // r3
  unsigned int v31; // r6
  unsigned int v32; // r4
  int v33; // r3
  unsigned int v34; // r2
  int v35; // r3
  int v36; // r3
  unsigned __int64 v37; // r2
  int v38; // r2
  int v39; // r3
  int v40; // r3
  int v41; // r3
  unsigned int v42; // [sp+0h] [bp-30h]
  int v43; // [sp+4h] [bp-2Ch]
  int v45; // [sp+Ch] [bp-24h]

  v7 = a4;
  v45 = a3;
  v8 = 0;
  v42 = 0;
  v43 = 0;
  v9 = 0;
  if ( a1[31] )
  {
    while ( 1 )
    {
      v11 = 0;
      v12 = (_DWORD *)(a1[37] + 8 * v8);
      if ( (v12[1] & 0x30) == 0 )
      {
        v11 = SepSidInSidAndAttributes(v7, a3, a3, *v12);
        if ( v11 )
          goto LABEL_8;
      }
      if ( (a2 & 4) != 0 )
      {
        v16 = (int *)(a1[37] + 8 * v8);
        if ( (v16[1] & 0x30) == 0 )
        {
          v17 = *v16;
          v18 = (_BYTE *)RtlSubAuthorityCountSid(*v16);
          if ( *v18 )
          {
            v19 = *(_DWORD *)RtlSubAuthoritySid(v17, 0);
            if ( v19 < 0x50 || v19 > 0x6F )
            {
              if ( !*v18 )
                return sub_7DBA48();
              v21 = *(_DWORD *)RtlSubAuthoritySid(v17, (unsigned __int8)*v18 - 1);
              if ( v21 <= 0x239 )
                break;
            }
          }
        }
      }
LABEL_5:
      ++v8;
      v7 = a4;
      a3 = v45;
      if ( v8 >= a1[31] )
        goto LABEL_6;
    }
    v22 = &SepLUARids;
    v23 = 0;
    while ( !v11 )
    {
      v24 = *v22++;
      if ( v21 == v24 )
      {
        v43 = 1;
        v11 = 1;
      }
      if ( (unsigned int)++v23 >= 0x13 )
      {
        if ( !v11 )
          goto LABEL_5;
        break;
      }
    }
LABEL_8:
    v9 = 1;
    *(_DWORD *)(a1[37] + 8 * v8 + 4) &= 0xFFFFFFF0;
    *(_DWORD *)(a1[37] + 8 * v8 + 4) |= 0x10u;
    a1[44] |= 0x800u;
    if ( v8 == a1[36] )
      a1[36] = 0;
    goto LABEL_5;
  }
LABEL_6:
  v13 = a1[44];
  if ( (v13 & 0x800) == 0 )
  {
    v14 = 0;
    v15 = 0;
    do
    {
      if ( (1 << (v15 - 32)) & a1[17] | (1 << v15) & a1[16] )
        ++v14;
      ++v15;
    }
    while ( v15 <= 0x23 );
    v42 = v14;
  }
  if ( (a2 & 1) != 0 )
  {
    a1[18] &= 0x800000u;
    a1[19] = 0;
    v41 = a1[20];
    a1[21] = 0;
    a1[17] = 0;
    a1[20] = v41 & 0x800000;
    v9 = 1;
    a1[16] &= 0x800000u;
  }
  else if ( (a2 & 4) != 0 )
  {
    v9 = 1;
    v33 = a1[18];
    if ( v43 )
    {
      v38 = v33 & 0x2880000;
      v39 = a1[19];
      a1[18] = v38;
      a1[19] = v39 & 6;
      v40 = a1[21];
      a1[20] &= 0x2880000u;
      a1[21] = v40 & 6;
      v37 = *((_QWORD *)a1 + 8) & 0x602880000i64;
    }
    else
    {
      v34 = v33 & 0xDFE9F97B;
      v35 = a1[19];
      a1[18] = v34;
      a1[19] = v35 & 0xFFFFFFFE;
      v36 = a1[21];
      a1[20] &= 0xDFE9F97B;
      a1[21] = v36 & 0xFFFFFFFE;
      v37 = *((_QWORD *)a1 + 8) & 0xFFFFFFFEDFE9F97Bui64;
    }
    *((_QWORD *)a1 + 8) = v37;
  }
  else
  {
    for ( i = a5; i; --i )
    {
      v27 = *a6;
      if ( (unsigned int)(*a6 - 2) <= 0x21 )
      {
        v28 = a1[19];
        a1[18] &= ~(1 << v27);
        a1[19] = v28 & ~(1 << (v27 - 32));
        v29 = 1 << (*a6 - 32);
        v30 = a1[17];
        a1[16] &= ~(1 << *a6);
        a1[17] = v30 & ~v29;
      }
      a6 += 3;
    }
  }
  if ( (v13 & 0x800) == 0 )
  {
    v31 = 0;
    v32 = 0;
    do
    {
      if ( (1 << (v32 - 32)) & a1[17] | (1 << v32) & a1[16] )
        ++v31;
      ++v32;
    }
    while ( v32 <= 0x23 );
    if ( v31 < v42 )
      a1[44] = v13 | 0x800;
  }
  return v9;
}
