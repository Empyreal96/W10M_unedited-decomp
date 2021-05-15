// RtlpGetNameFromLangInfoNode 
 
int __fastcall RtlpGetNameFromLangInfoNode(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r2
  unsigned int v8; // r1
  __int16 v9; // r6
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a2;
  v10[1] = a3;
  v10[2] = a4;
  v4 = 0;
  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  v6 = *(__int16 *)(a2 + 6);
  if ( v6 <= 0 )
    return sub_553898();
  RtlInitUnicodeString(
    (unsigned int)v10,
    (unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 16)
                       + 2 * *(__int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 24) + 12) + 2 * v6)));
  v8 = *(unsigned __int16 *)(a3 + 2);
  v9 = v10[0];
  if ( LOWORD(v10[0]) > v8 || RtlStringCbCopyW(*(_DWORD *)(a3 + 4), v8) < 0 )
    return -1073741595;
  *(_WORD *)a3 = v9;
  return v4;
}
