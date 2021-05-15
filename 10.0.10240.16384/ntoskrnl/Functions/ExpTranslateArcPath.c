// ExpTranslateArcPath 
 
int __fastcall ExpTranslateArcPath(int a1, int a2, char *a3, unsigned int *a4)
{
  int result; // r0
  int v9; // r3
  char v10[4]; // [sp+8h] [bp-28h] BYREF
  int v11; // [sp+Ch] [bp-24h] BYREF
  char *v12; // [sp+10h] [bp-20h] BYREF
  char *v13; // [sp+14h] [bp-1Ch] BYREF

  result = ExpParseArcPathName((char *)(a1 + 12), &v13, &v12, &v11, v10);
  if ( result >= 0 )
  {
    v9 = *(_DWORD *)(a1 + 8);
    if ( v10[0] )
    {
      if ( v9 != 2 )
        return -1073741811;
      result = ExpConvertSignatureName(a2, (int)a3, a4, (int)v13, (unsigned __int16 *)v12, v11);
    }
    else
    {
      if ( v9 != 1 )
        return -1073741811;
      result = ExpConvertArcName(a2, a3, a4, v13, (unsigned __int16 *)v12, v11);
    }
  }
  return result;
}
