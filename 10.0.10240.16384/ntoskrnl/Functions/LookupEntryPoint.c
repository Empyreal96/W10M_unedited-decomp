// LookupEntryPoint 
 
int __fastcall LookupEntryPoint(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v7; // r0
  _DWORD *v8; // r5
  unsigned int v9; // r0
  int v11; // [sp+4h] [bp-1Ch]
  _DWORD v12[6]; // [sp+8h] [bp-18h] BYREF

  v11 = a2;
  v12[0] = a3;
  v12[1] = a4;
  v7 = (_DWORD *)RtlImageDirectoryEntryToData(a1, 1, 0, (int)v12);
  v8 = v7;
  if ( !v7 )
    return -1073741811;
  v9 = sub_4E086C(a2, a1, v7[6], v7[8] + a1, v7[9] + a1, v11);
  if ( v9 >= v8[5] )
    return -1073741702;
  *a3 = *(_DWORD *)(v8[7] + 4 * v9 + a1) + a1;
  return 0;
}
