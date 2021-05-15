// LdrpLoadResourceFromAlternativeModule 
 
int __fastcall LdrpLoadResourceFromAlternativeModule(int a1, int a2, int a3, char a4, int **a5)
{
  int result; // r0
  int v8; // r4
  int v9; // [sp+8h] [bp-18h] BYREF
  int v10[5]; // [sp+Ch] [bp-14h] BYREF

  v9 = 0;
  if ( a3 != 4 )
    return sub_54DCAC();
  v8 = (unsigned __int16)*(_DWORD *)(a2 + 8);
  v10[0] = 0;
  result = LdrLoadAlternateResourceModuleEx(a1, v8, &v9, v10, a4);
  if ( result >= 0 )
  {
    *(_DWORD *)(a2 + 8) = v8;
    result = LdrpSearchResourceSection_U(v9, a2, 3, 48, a5);
    if ( (a4 & 0x40) != 0 && result >= 0 )
    {
      result = LdrpFindMessageInAlternateModule(v9, *a5, 0, *(int **)(a2 + 12), 0);
      if ( result < 0 )
        *a5 = 0;
    }
  }
  else if ( result == -1073741772 || result == -1073741766 )
  {
    result = -1073020927;
  }
  return result;
}
