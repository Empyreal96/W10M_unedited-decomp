// IopConnectMessageBasedInterrupt 
 
int __fastcall IopConnectMessageBasedInterrupt(int a1, _DWORD *a2, unsigned int a3, unsigned int a4, int a5, unsigned __int8 a6)
{
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r0
  int *v11; // r2
  int v12; // r3
  unsigned int v14[6]; // [sp+18h] [bp-B8h] BYREF
  int v15[20]; // [sp+60h] [bp-70h] BYREF

  v14[3] = a3;
  v14[4] = a4;
  *a2 = 0;
  v14[2] = (unsigned int)a2;
  v14[0] = 0;
  memset(v15, 0, sizeof(v15));
  if ( !a1 )
    return -1073741811;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v8 || (*(_DWORD *)(v8 + 268) & 0x20000) != 0 || !a3 )
    return -1073741811;
  v9 = IopGetInterruptConnectionData(a1, v14);
  if ( v9 < 0 )
  {
LABEL_14:
    if ( v14[0] )
      ExFreePoolWithTag(v14[0]);
    return v9;
  }
  v10 = 0;
  if ( !*(_DWORD *)v14[0] )
  {
LABEL_13:
    v9 = -1073741811;
    goto LABEL_14;
  }
  v11 = (int *)(v14[0] + 8);
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 == 1 || v12 == 2 || v12 == 3 )
      return sub_81B368(v10, a6);
    ++v10;
    v11 += 18;
    if ( v10 >= *(_DWORD *)v14[0] )
      goto LABEL_13;
  }
}
