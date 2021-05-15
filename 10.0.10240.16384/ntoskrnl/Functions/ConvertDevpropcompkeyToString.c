// ConvertDevpropcompkeyToString 
 
int __fastcall ConvertDevpropcompkeyToString(_DWORD *a1, _WORD *a2, unsigned int a3, unsigned int *a4)
{
  int v7; // r4
  int v8; // r6
  const __int16 *v9; // r7
  int v10; // r4
  __int16 *v11; // r0
  unsigned int v12; // r0
  const __int16 *v13; // r5
  int v14; // r4
  unsigned __int16 *v15; // r0
  unsigned int v16; // r3
  unsigned __int16 v19; // [sp+20h] [bp-28h] BYREF
  _BYTE v20[6]; // [sp+22h] [bp-26h]

  v19 = 0;
  *(_DWORD *)v20 = 0;
  *(_WORD *)&v20[4] = 0;
  if ( a3 >= 2 )
    *a2 = 0;
  v7 = RtlStringFromGUIDEx((int)a1, (int)&v19, 1);
  if ( v7 >= 0 )
  {
    v8 = a1[5];
    v9 = L"System";
    v10 = v19 + 18;
    if ( v8 )
    {
      if ( v8 != 1 )
      {
        v7 = -1073741811;
        goto LABEL_21;
      }
      v11 = L"User";
    }
    else
    {
      v11 = L"System";
    }
    v12 = wcslen((unsigned __int16 *)v11);
    v13 = (const __int16 *)a1[6];
    v14 = v10 + 2 * v12 + 2;
    if ( v13 )
      v15 = (unsigned __int16 *)a1[6];
    else
      v15 = L"(NULL)";
    v16 = v14 + 2 * wcslen(v15) + 2;
    if ( a4 )
      *a4 = v16;
    if ( v16 > a3 )
    {
      v7 = -1073741789;
    }
    else
    {
      if ( !v13 )
        v13 = L"(NULL)";
      if ( v8 )
        v9 = L"User";
      v7 = RtlStringCbPrintfExW(a2, a3, 0, 0, 2048, L"[(%s %3d) %s %s]", *(_DWORD *)&v20[2], a1[4], v9, v13);
    }
  }
LABEL_21:
  RtlFreeAnsiString(&v19);
  return v7;
}
