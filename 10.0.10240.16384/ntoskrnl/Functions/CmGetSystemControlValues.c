// CmGetSystemControlValues 
 
int __fastcall CmGetSystemControlValues(_DWORD *a1)
{
  __int16 **v2; // r6
  _DWORD *v3; // r0
  int v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r4
  int v8; // r3
  int v9; // r9
  unsigned int v10; // r4
  int v11; // r0
  int v12; // r7
  int v13; // r3
  int v14; // r8
  unsigned int *v15; // r3
  __int16 *v16; // t1
  int v17; // r0
  __int16 v18; // r2
  unsigned int *v19; // r3
  unsigned int v20; // r7
  int v21; // r8
  __int16 *v22; // r2
  char v23[4]; // [sp+20h] [bp-160h] BYREF
  int v24; // [sp+24h] [bp-15Ch] BYREF
  _DWORD v25[2]; // [sp+28h] [bp-158h] BYREF
  char v26[8]; // [sp+30h] [bp-150h] BYREF
  int v27; // [sp+38h] [bp-148h] BYREF
  int *v28; // [sp+40h] [bp-140h] BYREF
  char v29[284]; // [sp+44h] [bp-13Ch] BYREF

  v2 = CmControlVector;
  v24 = -1;
  v25[0] = -1;
  memset(v29, 0, sizeof(v29));
  memset(&CmControlHive, 0, 3872);
  v3 = CmpInitSecurityCache(&CmControlHive);
  dword_982394 = (int)&v28;
  v28 = &CmControlHive;
  if ( HvInitializeHive((int)v3, 4u, 1, 0, a1, 0, 1u, 0, 0, 0, v23, 0) < 0 )
    sub_968368();
  dword_982394 = 0;
  v4 = a1[9];
  RtlInitUnicodeString((unsigned int)v26, L"current");
  v5 = CmpFindControlSet((int)&CmControlHive, v4, (int)v26, v23);
  if ( v5 == -1 )
    KeBugCheckEx(116, 1, 2, (int)&CmControlHive, (int)v26);
  result = off_98237C(&CmControlHive, v5, &v24);
  v7 = result;
  if ( result )
  {
    RtlInitUnicodeString((unsigned int)v26, L"control");
    v9 = CmpFindSubKeyByName((int)&CmControlHive, v7, (int)v26, v8);
    if ( v9 == -1 )
      KeBugCheckEx(116, 1, 3, v7, (int)v26);
    off_982380(&CmControlHive, &v24);
    if ( L"Session Manager" )
    {
      do
      {
        v10 = -1;
        v11 = CmpWalkPath((int)&CmControlHive, v9, (unsigned __int16 *)*v2);
        if ( v11 != -1 )
        {
          result = off_98237C(&CmControlHive, v11, &v24);
          v12 = result;
          if ( !result )
            return result;
          RtlInitUnicodeString((unsigned int)v26, (unsigned __int16 *)v2[1]);
          v14 = CmpFindValueByName((int)&CmControlHive, v12, (int)v26, v13);
          off_982380(&CmControlHive, &v24);
          if ( v14 != -1 )
          {
            v19 = (unsigned int *)v2[3];
            if ( v19 )
              v20 = *v19;
            else
              v20 = 4;
            result = off_98237C(&CmControlHive, v14, v25);
            v21 = result;
            if ( !result )
              return result;
            v10 = *(_DWORD *)(result + 4);
            if ( v10 >= 0x80000000 )
              v10 += 0x80000000;
            if ( v20 < v10 )
              v10 = v20;
            if ( v10 && !CmpGetBootValueData() )
              return off_982380(&CmControlHive, v25);
            v22 = v2[4];
            if ( v22 )
              *(_DWORD *)v22 = *(_DWORD *)(v21 + 12);
            off_982380(&CmControlHive, v25);
          }
        }
        v15 = (unsigned int *)v2[3];
        if ( v15 )
          *v15 = v10;
        v16 = v2[5];
        v2 += 5;
      }
      while ( v16 );
    }
    if ( CmDefaultLanguageIdType == 1 )
      PsDefaultSystemLocaleId = CmpConvertLangId(CmDefaultLanguageId, CmDefaultLanguageIdLength);
    else
      PsDefaultSystemLocaleId = 1033;
    if ( CmInstallUILanguageIdType == 1 )
    {
      v17 = CmpConvertLangId(CmInstallUILanguageId, CmInstallUILanguageIdLength);
      PsInstallUILanguageId = v17;
    }
    else
    {
      v17 = (unsigned __int16)PsInstallUILanguageId;
    }
    result = CmSelectQualifiedInstallLanguage(v17, v9, &v27, v17);
    if ( result )
    {
      if ( !psMUITest )
        KeBugCheckEx(298, 1, result, 0, 0);
      v18 = PsDefaultSystemLocaleId;
    }
    else
    {
      v18 = PsInstallUILanguageId;
      if ( (unsigned __int16)PsInstallUILanguageId == v27 )
        goto LABEL_19;
      v18 = v27;
      result = 1;
      CmInstallUILanguageFallbackToOOBm = 1;
    }
    PsInstallUILanguageId = v18;
LABEL_19:
    PsDefaultThreadLocaleId = PsDefaultSystemLocaleId;
    PsDefaultUILanguageId = v18;
    if ( !PsMachineUILanguageId )
      PsMachineUILanguageId = v18;
  }
  return result;
}
