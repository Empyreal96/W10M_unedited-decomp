// AslpFileMakeStringVersionAttributes 
 
int __fastcall AslpFileMakeStringVersionAttributes(_DWORD *a1, int a2)
{
  int v4; // r3
  int v5; // r4
  int v6; // r0
  unsigned __int16 *v7; // r6
  int *v8; // r9
  unsigned int v9; // r8
  unsigned int v10; // r2
  int v11; // r0
  unsigned __int16 *v12; // r0
  _DWORD *v13; // r4
  unsigned int v14; // r0
  unsigned __int16 *v15; // r2
  unsigned __int16 *v17; // [sp+8h] [bp-28h] BYREF
  unsigned int i; // [sp+Ch] [bp-24h] BYREF
  unsigned int v19[8]; // [sp+10h] [bp-20h] BYREF

  v17 = 0;
  i = 0;
  v19[0] = 0;
  if ( a2 )
  {
    v6 = AslpFileVerQueryValue(a2, L"\\VarFileInfo\\Translation", &i, v19);
    v5 = v6;
    if ( v6 == -1073741275 )
    {
      v7 = 0;
    }
    else
    {
      if ( v6 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslpFileMakeStringVersionAttributes", 1482, "AslpFileVerQueryValue failed [%x]", v6);
        return v5;
      }
      v7 = (unsigned __int16 *)i;
    }
    v8 = &dword_41D970;
    v9 = 0;
    v10 = v19[0] >> 2;
    for ( i = v19[0] >> 2; ; v10 = i )
    {
      v19[0] = *v8;
      v11 = AslpFileQueryVersionString(&v17, a2, v7, v10, v8[1]);
      v5 = v11;
      if ( v11 < 0 )
      {
        if ( v11 != -1073741275 )
        {
          AslLogCallPrintf(
            1,
            (int)"AslpFileMakeStringVersionAttributes",
            1522,
            "AslpFileQueryVersionString failed [%x]",
            v11);
          return v5;
        }
        a1[6 * v19[0] + 4] |= 2u;
      }
      else
      {
        v5 = AslStringXmlSanitize(v17);
        if ( v5 < 0 )
        {
          AslLogCallPrintf(1, (int)"AslpFileMakeStringVersionAttributes", 1509, "AslStringXmlSanitize failed [%x]", v5);
          return v5;
        }
        v12 = v17;
        v13 = &a1[6 * v19[0]];
        *v13 = 4;
        v14 = wcslen(v12);
        v15 = v17;
        v13[1] = v14;
        *((_QWORD *)v13 + 1) = (int)v15;
        v13[4] |= 1u;
      }
      ++v9;
      v8 += 2;
      if ( v9 >= 8 )
        break;
    }
    if ( v7 && i == 1 )
    {
      a1[144] = 2;
      a1[145] = 4;
      a1[146] = *v7;
      a1[147] = 0;
      v4 = a1[148] | 1;
    }
    else
    {
      v4 = a1[148] | 2;
    }
  }
  else
  {
    a1[34] |= 2u;
    a1[40] |= 2u;
    a1[46] |= 2u;
    a1[52] |= 2u;
    a1[58] |= 2u;
    a1[64] |= 2u;
    a1[70] |= 2u;
    a1[76] |= 2u;
    v4 = a1[148] | 2;
  }
  a1[148] = v4;
  return 0;
}
