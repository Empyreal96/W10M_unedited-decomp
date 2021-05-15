// SmProcessResizeRequest 
 
int __fastcall SmProcessResizeRequest(int a1, int a2, int a3, char a4)
{
  int result; // r0
  char v7; // r2
  unsigned int v8; // r1
  int v9; // [sp+8h] [bp-40h]
  char v10[16]; // [sp+10h] [bp-38h] BYREF
  int v11[8]; // [sp+20h] [bp-28h] BYREF

  if ( a3 != 16 )
    return -1073741306;
  if ( a4 )
    return -1073741811;
  if ( *(_BYTE *)a2 != 6 )
    return -1073741735;
  KeInitializeEvent((int)v10, 0, 0);
  memset(v11, 0, sizeof(v11));
  v7 = 4;
  v8 = *(_DWORD *)(a2 + 4);
  v11[0] = v11[0] & 0xFFFFFFF8 | 4;
  if ( (*(_DWORD *)a2 & 0x100) == 0 )
    v7 = 5;
  v11[1] = v11[1] & 0xFFFFFFF8 | v7 & 7;
  v11[3] = *(_DWORD *)(a2 + 8);
  v11[2] = *(_DWORD *)(a2 + 12);
  SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequest(a1, v8);
  KeWaitForSingleObject((unsigned int)v10, 0, 0, 0, 0);
  result = v9;
  *(_DWORD *)(a2 + 8) = v11[3];
  return result;
}
