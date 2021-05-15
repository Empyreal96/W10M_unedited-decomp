// ExpWin32CloseProcedure 
 
int __fastcall ExpWin32CloseProcedure(int result, int *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r4
  int v6; // r0
  int v7; // [sp+0h] [bp-28h] BYREF
  _DWORD v8[8]; // [sp+8h] [bp-20h] BYREF

  v7 = *a2;
  v8[2] = a3;
  v8[3] = a4;
  v4 = *((unsigned __int8 *)a2 - 12);
  v8[0] = result;
  v8[1] = a2;
  v5 = ObTypeIndexTable[v4 ^ (unsigned __int8)((unsigned __int16)((_WORD)a2 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  if ( v5 == ExRawInputManagerObjectType )
  {
    v6 = 29;
    return PsInvokeWin32Callout(v6, v8, 1, &v7);
  }
  if ( v5 == ExCompositionObjectType )
  {
    v6 = 20;
    return PsInvokeWin32Callout(v6, v8, 1, &v7);
  }
  if ( v5 == ExDesktopObjectType )
    return sub_803044();
  if ( v5 == ExWindowStationObjectType )
  {
    v6 = 13;
    return PsInvokeWin32Callout(v6, v8, 1, &v7);
  }
  return result;
}
