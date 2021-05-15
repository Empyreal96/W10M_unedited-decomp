// ExpWin32DeleteProcedure 
 
int __fastcall ExpWin32DeleteProcedure(int *a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v6; // r0
  int v7; // [sp+0h] [bp-10h] BYREF
  _DWORD v8[3]; // [sp+4h] [bp-Ch] BYREF

  v7 = a2;
  v8[0] = a3;
  v8[1] = a4;
  v7 = *a1;
  v8[0] = a1;
  v4 = ObTypeIndexTable[*((unsigned __int8 *)a1 - 12) ^ (unsigned __int8)((unsigned __int16)((_WORD)a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  if ( v4 == ExRawInputManagerObjectType )
  {
    v6 = 30;
  }
  else
  {
    if ( v4 != ExCompositionObjectType )
      return sub_7E8BF4();
    v6 = 21;
  }
  return PsInvokeWin32Callout(v6, v8, 1, &v7);
}
