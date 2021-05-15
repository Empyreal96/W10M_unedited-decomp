// MiMapProcessExecutable 
 
int __fastcall MiMapProcessExecutable(_DWORD *a1, int a2, unsigned int *a3, int a4)
{
  int v4; // r4
  int v9; // r9
  int v10; // r0
  __int64 v11; // kr00_8
  unsigned int v12; // r4
  unsigned int v13; // r8
  _BYTE *v14; // r1
  __int16 *v15; // r2
  int v16; // t1
  _BYTE *v17; // r3
  unsigned int v18; // r0
  unsigned int v19; // r4
  __int16 v20; // t1
  int v21; // r5
  int v22; // r2
  int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r0
  int v27; // r0
  int v28; // r3
  int v29; // r2
  int *v30; // r4
  int *v31; // t1
  int v32; // r3
  int v33; // r8
  int v34; // r7
  _DWORD *v35; // r3
  _DWORD *v36; // r4
  _DWORD *v37; // r3
  _DWORD *v38; // r2
  int v39; // r0
  unsigned int v40; // [sp+20h] [bp-40h] BYREF
  int v41; // [sp+24h] [bp-3Ch] BYREF
  int v42; // [sp+28h] [bp-38h] BYREF
  _DWORD v43[2]; // [sp+30h] [bp-30h] BYREF
  int v44[10]; // [sp+38h] [bp-28h] BYREF

  v4 = *(_DWORD *)(a2 + 32);
  v42 = a4;
  if ( (v4 & 0x20) == 0 )
    return sub_7F56B8();
  v9 = MiSectionControlArea(a2);
  v10 = MI_REFERENCE_CONTROL_AREA_FILE(v9);
  v11 = *(_QWORD *)(v10 + 48);
  v12 = 0;
  v13 = v10;
  v44[0] = *(_DWORD *)(v10 + 48);
  v14 = a1 + 90;
  v15 = (__int16 *)(LOWORD(v44[0]) + HIDWORD(v11));
  if ( HIDWORD(v11) )
  {
    if ( (unsigned int)v15 > HIDWORD(v11) )
    {
      while ( 1 )
      {
        v16 = (unsigned __int16)*--v15;
        if ( v16 == 92 )
          break;
        ++v12;
        if ( (unsigned int)v15 <= HIDWORD(v11) )
          goto LABEL_9;
      }
      ++v15;
LABEL_9:
      if ( v12 >= 0xF )
        v12 = 14;
    }
    v17 = &v14[v12];
    v18 = v12;
    v19 = 0;
    if ( v14 > v17 )
      v18 = 0;
    if ( v18 )
    {
      do
      {
        v20 = *v15++;
        ++v19;
        *v14++ = v20;
      }
      while ( v19 < v18 );
    }
  }
  *v14 = 0;
  v21 = PsInitializeFullProcessImageName(a1);
  if ( v21 < 0 )
  {
    MI_DEREFERENCE_CONTROL_AREA_FILE(v9, v13);
  }
  else
  {
    MI_DEREFERENCE_CONTROL_AREA_FILE(v9, v13);
    if ( (*a3 & 0x80) != 0 )
    {
      v21 = MiSessionCreate(&v41);
      if ( v21 < 0 )
        return v21;
    }
    v22 = 0;
    if ( (*a3 & 0x10) != 0 )
      v22 = 0x20000000;
    v40 = 0;
    v41 = 0;
    v43[0] = 0;
    v43[1] = 0;
    v23 = MmMapViewOfSection(a2, a1, &v40, 0, 0, v43, &v41, 1, v22, 4);
    v24 = v40;
    v21 = v23;
    a1[74] = v40;
    if ( v23 < 0 )
      return v21;
    v25 = *a3;
    v26 = 0;
    if ( (*a3 & 0x10) != 0 )
    {
      v28 = ((v24 >> 20) & 0xFFC) - 1070596096;
      v29 = 1;
      v41 = v28;
      v30 = &v42;
      while ( 1 )
      {
        v31 = (int *)*--v30;
        --v29;
        v32 = *v31;
        if ( (*v31 & 2) == 0 )
          break;
        if ( !v29 )
        {
          if ( (v32 & 0x400) != 0 )
            goto LABEL_35;
          break;
        }
      }
      *a3 = v25 & 0xFFFFFFEF;
LABEL_35:
      if ( (*a3 & 0x30) == 48 )
        v26 = 1;
    }
    v27 = PsMapSystemDlls(a1, v26);
    if ( v27 < 0 )
      v21 = v27;
    if ( v21 < 0 )
      return v21;
    if ( (a1[48] & 0x10) == 0 )
      goto LABEL_25;
    v44[0] = 0;
    v44[1] = 0;
    v40 = 0;
    v41 = 50331648;
    v33 = MiMapViewOfSection(dword_632EE8, a1, &v40, 0, 0, v44, &v41, 1, 0, 1, -2147483647, v43);
    if ( v33 >= 0 )
    {
      v34 = __mrc(15, 0, 13, 0, 3);
      MiReferenceCfgVad(v34 & 0xFFFFFFC0, v40);
      LOCK_ADDRESS_SPACE_SHARED(v34 & 0xFFFFFFC0, (int)a1);
      v35 = (_DWORD *)a1[159];
      v36 = 0;
      while ( v35 )
      {
        v36 = v35;
        v35 = (_DWORD *)*v35;
      }
      while ( v36 )
      {
        if ( (v36[7] & 7) == 2 )
        {
          MiReferenceVad((int)v36);
          UNLOCK_ADDRESS_SPACE_SHARED(v34 & 0xFFFFFFC0, (int)a1);
          MiLockVad(v34 & 0xFFFFFFC0, (int)v36);
          v33 = MiCommitVadCfgBits((int)v36, 0, 0);
          MiUnlockAndDereferenceVad((int)v36);
          if ( v33 < 0 )
            goto LABEL_54;
          LOCK_ADDRESS_SPACE_SHARED(v34 & 0xFFFFFFC0, (int)a1);
        }
        v37 = (_DWORD *)v36[1];
        v38 = v36;
        if ( v37 )
        {
          do
          {
            v36 = v37;
            v37 = (_DWORD *)*v37;
          }
          while ( v37 );
        }
        else
        {
          while ( 1 )
          {
            v36 = (_DWORD *)(v36[2] & 0xFFFFFFFC);
            if ( !v36 || (_DWORD *)*v36 == v38 )
              break;
            v38 = v36;
          }
        }
      }
      UNLOCK_ADDRESS_SPACE_SHARED(v34 & 0xFFFFFFC0, (int)a1);
LABEL_25:
      if ( v42 )
      {
        v39 = MiInitializeUserNoAccess(a1, v42);
        if ( v39 < 0 )
          v21 = v39;
      }
      return v21;
    }
LABEL_54:
    v21 = v33;
  }
  return v21;
}
