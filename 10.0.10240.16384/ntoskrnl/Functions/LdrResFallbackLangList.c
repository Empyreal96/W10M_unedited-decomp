// LdrResFallbackLangList 
 
int __fastcall LdrResFallbackLangList(int a1, int a2, int a3, int a4, unsigned __int16 *a5)
{
  char v5; // r5
  int v7; // r0
  int v8; // r8
  int v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r6
  unsigned __int16 *v12; // r5
  int v13; // r3
  int v14; // [sp+0h] [bp-28h] BYREF
  int v15; // [sp+4h] [bp-24h]
  int v16; // [sp+8h] [bp-20h]

  v14 = a2;
  v5 = a4;
  v15 = a3;
  v16 = a4;
  if ( !a5 )
    return sub_818D4C();
  v7 = (unsigned __int16)v14;
  *a5 = 0;
  *((_BYTE *)a5 + 516) = 0;
  v8 = 0;
  while ( 1 )
  {
    v13 = v8++;
    if ( !v13 )
    {
      v7 = a3;
      LOWORD(v14) = a3;
      v9 = 1;
      goto LABEL_8;
    }
    if ( v13 == 1 )
      break;
    switch ( v13 )
    {
      case 2:
        if ( PsMachineUILanguageId )
        {
          v7 = (unsigned __int16)PsMachineUILanguageId;
          LOWORD(v14) = PsMachineUILanguageId;
        }
        else
        {
          v7 = 61166;
          LOWORD(v14) = -4370;
        }
        v9 = 5;
        break;
      case 3:
        if ( PsInstallUILanguageId )
        {
          v7 = (unsigned __int16)PsInstallUILanguageId;
          LOWORD(v14) = PsInstallUILanguageId;
        }
        else
        {
          v7 = 61166;
          LOWORD(v14) = -4370;
        }
        v9 = 6;
        break;
      case 4:
        if ( PsDefaultSystemLocaleId )
        {
          v7 = (unsigned __int16)PsDefaultSystemLocaleId;
          LOWORD(v14) = PsDefaultSystemLocaleId;
        }
        else
        {
          v7 = 61166;
          LOWORD(v14) = -4370;
        }
        v9 = 7;
        break;
      case 5:
        v7 = 1033;
        LOWORD(v14) = 1033;
        v9 = 8;
        break;
      case 6:
        v7 = 4660;
        LOWORD(v14) = 4660;
        v9 = 9;
        break;
      default:
        return 0;
    }
LABEL_8:
    if ( v7 != 61166 )
    {
      v10 = *a5;
      v11 = 0;
      if ( *a5 )
      {
        v12 = a5;
        do
        {
          if ( v12[2] == v7 )
            break;
          ++v11;
          v12 += 4;
        }
        while ( v11 < v10 );
        v5 = v16;
      }
      if ( v11 >= v10 )
      {
        if ( v10 >= 0x40 )
          return 0;
        a5[4 * v10 + 2] = v7;
        *(_DWORD *)&a5[4 * (*a5)++ + 4] = v9;
      }
    }
    a3 = v15;
  }
  if ( (v5 & 4) == 0 )
  {
    if ( (a3 & 0x3FF) != 0 )
    {
      *((_BYTE *)a5 + 516) = 1;
      if ( LdrpGetParentLangId(v7, &v14) >= 0 )
      {
        v7 = (unsigned __int16)v14;
      }
      else
      {
        v7 = 0;
        LOWORD(v14) = 0;
      }
      if ( v7 )
        --v8;
      else
        v8 = -1;
    }
    else
    {
      v7 = 61166;
      LOWORD(v14) = -4370;
    }
    v9 = 2;
    goto LABEL_8;
  }
  *((_BYTE *)a5 + 516) = 1;
  return 0;
}
