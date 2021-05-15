// ExpWin32OkayToCloseProcedure 
 
int __fastcall ExpWin32OkayToCloseProcedure(int a1, int *a2, int a3, char a4)
{
  int v4; // r4
  int v5; // r4
  int v6; // r0
  int v8; // [sp+0h] [bp-28h] BYREF
  int v9[3]; // [sp+8h] [bp-20h] BYREF
  char v10; // [sp+14h] [bp-14h]

  v8 = *a2;
  v9[1] = (int)a2;
  v9[2] = a3;
  v4 = *((unsigned __int8 *)a2 - 12);
  v10 = a4;
  v5 = ObTypeIndexTable[v4 ^ (unsigned __int8)((unsigned __int16)((_WORD)a2 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v9[0] = a1;
  if ( v5 == ExRawInputManagerObjectType )
  {
    v6 = 28;
  }
  else if ( v5 == ExCompositionObjectType )
  {
    v6 = 19;
  }
  else
  {
    if ( v5 == ExDesktopObjectType )
      return sub_80305C();
    if ( v5 != ExWindowStationObjectType )
      return 0;
    v6 = 12;
  }
  return PsInvokeWin32Callout(v6, v9, 1, &v8) >= 0;
}
