// ExpCreateOutputSIGNATURE 
 
int __fastcall ExpCreateOutputSIGNATURE(int a1, unsigned int *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, unsigned __int16 *a7, char a8)
{
  int v9; // r4
  unsigned int v11; // r9
  unsigned int v12; // r8
  int result; // r0
  int v14; // r6
  unsigned int v15; // r5
  unsigned int v16; // r5
  unsigned int v17; // r3
  unsigned __int16 v20; // [sp+18h] [bp-28h] BYREF
  char *v21; // [sp+1Ch] [bp-24h]

  if ( a8 == 1 )
    v9 = 93;
  else
    v9 = 63;
  if ( a7 )
  {
    v11 = wcslen(a7);
    v9 += v11;
  }
  else
  {
    v11 = 0;
  }
  v12 = 2 * (v9 + 6);
  if ( *a2 >= v12 )
  {
    *(_DWORD *)a1 = 1;
    *(_DWORD *)(a1 + 4) = v12;
    v14 = a1 + 12;
    *(_DWORD *)(a1 + 8) = 2;
    wcscpy_s((char *)(a1 + 12), v9, (char *)L"signature(");
    v15 = wcslen((unsigned __int16 *)(a1 + 12));
    if ( a8 == 1 )
    {
      result = RtlStringFromGUIDEx((int)a3, (int)&v20, 1);
      if ( result < 0 )
        return result;
      wcscat_s((_WORD *)(v14 + 2 * v15), v9 - v15, v21);
      v16 = v15 + (v20 >> 1);
      ExFreePoolWithTag((unsigned int)v21);
    }
    else
    {
      swprintf_s(v14 + 2 * v15, v9 - v15, (int)L"%08x", *a3);
      v16 = v15 + wcslen((unsigned __int16 *)(v14 + 2 * v15));
    }
    swprintf_s(v14 + 2 * v16, v9 - v16, (int)L"-%08x-%016I64x-%016I64x)", *a4, *a5, a5[1], *a6, a6[1]);
    v17 = wcslen((unsigned __int16 *)(v14 + 2 * v16)) + v16;
    if ( v11 )
      wcscpy_s((char *)(v14 + 2 * v17), v9 - v17, (char *)a7);
    result = 0;
  }
  else
  {
    result = -1073741789;
  }
  *a2 = v12;
  return result;
}
