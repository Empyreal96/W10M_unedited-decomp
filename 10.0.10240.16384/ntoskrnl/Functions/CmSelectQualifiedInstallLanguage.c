// CmSelectQualifiedInstallLanguage 
 
int __fastcall CmSelectQualifiedInstallLanguage(int a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r10
  int v8; // r5
  int v10; // r0
  int v11; // r6
  int v12; // r3
  int v13; // r0
  int v14; // r6
  int v15; // r0
  int v16; // r1
  int v17; // r0
  _DWORD *v18; // r1
  unsigned int v19; // r8
  int v20; // r7
  int v21; // r8
  int v22; // r3
  int v23; // r0
  int v24; // r6
  int v25; // r0
  int v26; // r3
  __int16 v27; // r1
  unsigned int v28; // r6
  unsigned int v29; // r3
  int v30; // r0
  int v31; // r6
  _DWORD *v32; // [sp+8h] [bp-278h]
  unsigned int v33; // [sp+Ch] [bp-274h]
  int v34; // [sp+10h] [bp-270h] BYREF
  int v35; // [sp+14h] [bp-26Ch] BYREF
  int v36; // [sp+18h] [bp-268h]
  int v37; // [sp+1Ch] [bp-264h]
  int v38; // [sp+20h] [bp-260h]
  int v39; // [sp+24h] [bp-25Ch]
  int v40; // [sp+28h] [bp-258h] BYREF
  _DWORD *v41; // [sp+2Ch] [bp-254h]
  int v42; // [sp+30h] [bp-250h] BYREF
  int v43; // [sp+34h] [bp-24Ch] BYREF
  unsigned int v44; // [sp+38h] [bp-248h] BYREF
  int v45; // [sp+3Ch] [bp-244h] BYREF
  int v46; // [sp+40h] [bp-240h] BYREF
  char v47[8]; // [sp+48h] [bp-238h] BYREF
  unsigned __int16 v48; // [sp+50h] [bp-230h] BYREF
  char v49[168]; // [sp+52h] [bp-22Eh] BYREF
  __int16 v50; // [sp+100h] [bp-180h] BYREF
  char v51[168]; // [sp+102h] [bp-17Eh] BYREF
  unsigned __int16 v52; // [sp+1B0h] [bp-D0h] BYREF
  char v53[168]; // [sp+1B2h] [bp-CEh] BYREF

  v41 = a3;
  v34 = -1;
  v35 = -1;
  v39 = 0;
  v40 = -1;
  v42 = -1;
  v43 = -1;
  v45 = -1;
  v36 = 0;
  v37 = 0;
  v7 = 0;
  v38 = 0;
  v50 = 0;
  memset(v51, 0, sizeof(v51));
  v48 = 0;
  memset(v49, 0, sizeof(v49));
  v52 = 0;
  memset(v53, 0, sizeof(v53));
  if ( !a3 )
    return 1;
  *a3 = 0;
  if ( a4 )
  {
    v8 = 70;
    if ( !DownLevelLangIDToLanguageName((unsigned __int16)a4, &v52, 85, 0) )
      return sub_9680E8();
  }
  else
  {
    v8 = 38;
  }
  v10 = CmpWalkPath((int)&CmControlHive, a2, L"MUI\\Settings");
  if ( v10 != -1 )
  {
    v11 = off_98237C(&CmControlHive, v10, &v40);
    if ( v11 )
    {
      RtlInitUnicodeString((unsigned int)v47, L"PreferredUILanguages");
      v13 = CmpFindValueByName((int)&CmControlHive, v11, (int)v47, v12);
      v14 = v13;
      if ( v13 != -1 )
      {
        v15 = off_98237C(&CmControlHive, v13, &v35);
        if ( v15 )
        {
          if ( *(_DWORD *)(v15 + 12) == 7 )
          {
            v16 = CmpValueToData((int)&CmControlHive, v14, v15, &v44, (int)&v45);
            if ( v16 )
            {
              if ( v44 < 0xA8 )
              {
                memmove((int)&v50, v16, v44);
                PsMachineUILanguageId = DownLevelLanguageNameToLangID((int)&v50, 0);
              }
              off_982380(&CmControlHive, &v45);
            }
          }
          off_982380(&CmControlHive, &v35);
        }
      }
      off_982380(&CmControlHive, &v40);
    }
  }
  v17 = CmpWalkPath((int)&CmControlHive, a2, L"MUI\\UILanguages");
  if ( v17 == -1 )
    return v8;
  v18 = (_DWORD *)off_98237C(&CmControlHive, v17, &v43);
  v32 = v18;
  if ( !v18 )
    return v8;
  v8 &= 0xFFFFFFFD;
  v19 = 0;
  while ( 1 )
  {
    CmpFindSubKeyByNumber((int)&CmControlHive, v18, v19++, &v46);
    v33 = v19;
    if ( v46 == -1 )
      break;
    v20 = off_98237C(&CmControlHive, v46, &v34);
    v18 = v32;
    if ( v20 )
    {
      v21 = 0;
      RtlInitUnicodeString((unsigned int)v47, L"Type");
      v23 = CmpFindValueByName((int)&CmControlHive, v20, (int)v47, v22);
      v24 = v23;
      if ( v23 == -1 )
        goto LABEL_57;
      v25 = off_98237C(&CmControlHive, v23, &v35);
      if ( !v25 )
        goto LABEL_57;
      if ( *(_DWORD *)(v25 + 12) == 4 )
      {
        v26 = *(_DWORD *)CmpValueToData((int)&CmControlHive, v24, v25, &v44, (int)&v42);
        v38 = v26;
        if ( (v26 & 3) != 0 && (v26 & 0x10) != 0 )
          v21 = 1;
        off_982380(&CmControlHive, &v42);
      }
      off_982380(&CmControlHive, &v35);
      if ( !v21 )
      {
LABEL_57:
        off_982380(&CmControlHive, &v34);
        goto LABEL_45;
      }
      if ( (*(_WORD *)(v20 + 2) & 0x20) != 0 )
      {
        v27 = *(_WORD *)(v20 + 72);
        v28 = (unsigned __int16)(2 * v27);
        if ( v28 > 0xA8 )
          goto LABEL_57;
        CmpCopyCompressedName(&v48, (unsigned __int16)(2 * v27), v20 + 76, *(unsigned __int16 *)(v20 + 72));
      }
      else
      {
        v28 = *(unsigned __int16 *)(v20 + 72);
        if ( v28 > 0xA8 )
          goto LABEL_57;
        memmove((int)&v48, v20 + 76, *(unsigned __int16 *)(v20 + 72));
      }
      off_982380(&CmControlHive, &v34);
      v29 = 2 * (v28 >> 1);
      if ( v29 >= 0xAA )
        _report_rangecheckfailure();
      *(unsigned __int16 *)((char *)&v48 + v29) = 0;
      v30 = DownLevelLanguageNameToLangID((int)&v48, 0);
      v31 = v30;
      v18 = v32;
      v19 = v33;
      if ( v30 )
      {
        v18 = v32;
        v19 = v33;
        if ( v30 != 127 )
        {
          if ( a4 && !v37 && !wcsicmp((int)&v52, &v48) )
          {
            v37 = 1;
            v8 &= 0xFFFFFFBF;
          }
          v18 = v32;
          v19 = v33;
          if ( v36 )
          {
            if ( !v7 )
            {
              v18 = v32;
              v19 = v33;
              if ( (v38 & 2) != 0 )
              {
                v39 = v31;
LABEL_41:
                v7 = 1;
                goto LABEL_45;
              }
            }
          }
          else if ( !v7 )
          {
            v39 = v31;
            if ( (v38 & 2) != 0 )
              goto LABEL_41;
            v36 = 1;
LABEL_45:
            v18 = v32;
            v19 = v33;
          }
        }
      }
    }
  }
  off_982380(&CmControlHive, &v43);
  if ( v36 || v7 )
    v8 &= 0xFFFFFFFB;
  if ( v37 )
  {
    *v41 = a4;
    goto LABEL_50;
  }
  if ( v7 || v36 )
  {
    *v41 = v39;
LABEL_50:
    v8 = 0;
  }
  return v8;
}
