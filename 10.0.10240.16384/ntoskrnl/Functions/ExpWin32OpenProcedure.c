// ExpWin32OpenProcedure 
 
int __fastcall ExpWin32OpenProcedure(int a1, int a2, int a3, int *a4, int *a5, int a6)
{
  int v6; // r1
  int v7; // r1
  int v8; // r7
  int v9; // r0
  int v11; // [sp+0h] [bp-30h] BYREF
  int v12[10]; // [sp+8h] [bp-28h] BYREF

  v11 = *a4;
  v12[1] = a3;
  v12[2] = (int)a4;
  v6 = *((unsigned __int8 *)a4 - 12);
  v12[3] = *a5;
  v7 = ObTypeIndexTable[v6 ^ (unsigned __int8)((unsigned __int16)((_WORD)a4 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v12[4] = a6;
  v8 = -1073741823;
  v12[0] = a1;
  if ( v7 == ExRawInputManagerObjectType )
  {
    v9 = 27;
    return PsInvokeWin32Callout(v9, v12, 1, &v11);
  }
  if ( v7 == ExCompositionObjectType )
  {
    v9 = 18;
    return PsInvokeWin32Callout(v9, v12, 1, &v11);
  }
  if ( v7 != ExDesktopObjectType )
  {
    if ( v7 != ExWindowStationObjectType )
      return v8;
    v9 = 16;
    return PsInvokeWin32Callout(v9, v12, 1, &v11);
  }
  return sub_803074();
}
