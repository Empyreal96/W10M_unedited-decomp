// LdrpGetResourceFileName 
 
int __fastcall LdrpGetResourceFileName(int a1, int a2, int a3, unsigned __int16 *a4)
{
  unsigned int v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r6
  int v10; // r0
  unsigned int v11; // r2
  int result; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r2
  int v20; // r3
  _BYTE v21[544]; // [sp-4h] [bp-220h] BYREF

  if ( !a1 || !a4 || !a3 )
    return -1073741811;
  v7 = *(unsigned __int16 *)(a1 + 44);
  v8 = *(unsigned __int16 *)(a1 + 36);
  v9 = v8 - v7;
  if ( v8 - v7 >= 0x208 || v8 <= v7 )
    return -1073020927;
  v10 = memmove((int)v21, *(_DWORD *)(a1 + 40), v9);
  v11 = 2 * (v9 >> 1);
  if ( v11 >= 0x208 )
    sub_54DD24(v10);
  *(_WORD *)&v21[v11] = 0;
  result = RtlAppendUnicodeToString(a4, (int)v21, v11, (int)v21);
  if ( result >= 0 )
  {
    RtlAppendUnicodeToString(a4, a3, v13, v14);
    RtlAppendUnicodeToString(a4, (int)L"\\", v15, v16);
    result = RtlAppendUnicodeToString(a4, *(_DWORD *)(a1 + 48), v17, v18);
    if ( result >= 0 )
      result = RtlAppendUnicodeToString(a4, (int)L".mui", v19, v20);
  }
  return result;
}
