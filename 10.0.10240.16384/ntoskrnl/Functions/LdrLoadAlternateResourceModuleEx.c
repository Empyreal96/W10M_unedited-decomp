// LdrLoadAlternateResourceModuleEx 
 
int __fastcall LdrLoadAlternateResourceModuleEx(unsigned int a1, int a2, int *a3, int *a4, __int16 a5)
{
  int v9; // r0
  int v10; // r5
  int v11; // r4
  int v12; // r4
  int v13; // r1
  int v14; // r5
  int v16; // [sp+18h] [bp-300h] BYREF
  int v17; // [sp+1Ch] [bp-2FCh] BYREF
  int v18; // [sp+20h] [bp-2F8h] BYREF
  int v19; // [sp+24h] [bp-2F4h]
  int v20; // [sp+28h] [bp-2F0h] BYREF
  _WORD v21[2]; // [sp+30h] [bp-2E8h] BYREF
  int *v22; // [sp+34h] [bp-2E4h]
  int v23; // [sp+38h] [bp-2E0h]
  __int16 v24; // [sp+40h] [bp-2D8h] BYREF
  _BYTE v25[168]; // [sp+42h] [bp-2D6h] BYREF
  int v26; // [sp+F0h] [bp-228h] BYREF

  v19 = a1;
  v20 = 0;
  v18 = 0;
  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v17 = 0;
  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  v9 = LdrpGetFromMUIMemCache(a1, a2);
  v10 = v9;
  v16 = v9;
  if ( v9 == -1 )
  {
    *a3 = 0;
    return -1073020922;
  }
  if ( v9 )
  {
    *a3 = v9;
    if ( a4 )
      *a4 = v17;
    v11 = 0;
    v23 = 0;
    return v11;
  }
  v12 = LdrpKrnGetDataTableEntry(a1);
  if ( v12 )
  {
    v22 = &v26;
    v21[0] = 0;
    v21[1] = 520;
    if ( DownLevelLangIDToLanguageName(a2, &v24, 85, 2) >= 0 )
    {
      v11 = LdrpGetResourceFileName(v12, v13, &v24, v21);
      if ( v11 >= 0 )
      {
        v11 = LdrpMapResourceFile(a1, v21, &v18, &v20, &v17);
        if ( v11 >= 0 )
        {
          v10 = v20 | 1;
          v16 = v20 | 1;
          if ( !LdrpVerifyAlternateResourceModule(v19, v20 | 1, (int)&v24, a5) )
          {
            MmUnmapViewInSystemSpace(v20);
            ZwClose();
            v18 = 0;
            v10 = 0;
            v16 = 0;
            v11 = -1073020926;
          }
        }
      }
      goto LABEL_18;
    }
    DbgPrintEx(85, 1, (int)"LDR: No Locale name for LangId %d \n", a2);
  }
  v11 = -1073020927;
LABEL_18:
  if ( !v10 )
    v16 = -1;
  v14 = v17;
  LdrpSetAlternateResourceModuleHandle(v19, &v16);
  if ( v16 == -1 )
  {
    *a3 = 0;
  }
  else
  {
    *a3 = v16;
    if ( a4 )
      *a4 = v14;
    v11 = 0;
  }
  return v11;
}
