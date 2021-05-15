// _CmDeleteCommonClassRegKey 
 
int __fastcall CmDeleteCommonClassRegKey(int a1, int a2, int a3, int a4, unsigned __int8 a5)
{
  int v9; // r5
  int (__fastcall *v10)(int, int, int, int, int, int *); // r7
  int v11; // r3
  int v12; // r0
  int v13; // r4
  int v14; // r0
  int v16; // [sp+8h] [bp-50h] BYREF
  _DWORD v17[10]; // [sp+Ch] [bp-4Ch] BYREF

  v16 = 0;
  memset(v17, 0, sizeof(v17));
  if ( (unsigned __int8)a3 == 32 )
  {
    v9 = 2;
  }
  else
  {
    if ( (unsigned __int8)a3 != 64 )
      return -1073741811;
    v9 = 4;
  }
  v10 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v11 = a5;
  LOBYTE(v17[3]) = a5;
  v17[1] = a3;
  v17[2] = a4;
  v17[4] = 0;
  if ( v10 )
  {
    v12 = v10(a1, a2, v9, 12, 1, &v16);
    if ( v12 == -1073741822 )
    {
      v10 = 0;
    }
    else
    {
      if ( v12 == -1073741536 )
        return v16;
      if ( v12 )
        return -1073741595;
    }
    a3 = v17[1];
    a4 = v17[2];
    v11 = LOBYTE(v17[3]);
  }
  v13 = CmDeleteCommonClassRegKeyWorker(a1, a2, a3, a4, v11);
  if ( !v10 )
    return v13;
  v16 = v13;
  v14 = v10(a1, a2, v9, 12, 2, &v16);
  if ( v14 == -1073741822 )
    return v13;
  if ( v14 == -1073741536 )
    return v16;
  if ( v14 )
    return -1073741595;
  return v13;
}
