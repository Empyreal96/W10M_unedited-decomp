// SmcProcessStoreCreateRequest 
 
int __fastcall SmcProcessStoreCreateRequest(int a1, unsigned int a2, int a3, char a4)
{
  int v4; // r6
  _BYTE *v7; // r0
  int v8; // r4
  int v11; // [sp+Ch] [bp-54h] BYREF
  int v12; // [sp+10h] [bp-50h]
  unsigned int v13; // [sp+14h] [bp-4Ch]
  int v14; // [sp+18h] [bp-48h]
  _DWORD v15[16]; // [sp+20h] [bp-40h] BYREF

  v4 = a4;
  v14 = a1;
  v13 = a2;
  v12 = 0;
  v11 = -1;
  v7 = memset(v15, 0, 32);
  if ( a3 != 32 )
    return -1073741306;
  if ( v4 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v7);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 28) = *(_BYTE *)(a2 + 28);
  }
  memmove((int)v15, a2, 0x20u);
  if ( LOBYTE(v15[0]) != 2 || (v15[0] & 0xFFFFFF00) != 0 )
    return -1073741811;
  if ( v15[6] >= 2 )
    return -1073741822;
  if ( (v15[1] & 0xFFFFE000) != 0 )
    return -1073741811;
  v8 = SmcStoreCreate(a1, v15[6], &v15[1], v15[5], &v11);
  if ( v8 >= 0 )
  {
    v12 = 1;
    v8 = 0;
    *(_DWORD *)(a2 + 28) = v11;
  }
  return v8;
}
