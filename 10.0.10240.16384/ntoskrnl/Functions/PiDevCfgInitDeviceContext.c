// PiDevCfgInitDeviceContext 
 
int __fastcall PiDevCfgInitDeviceContext(int a1, int a2, int a3)
{
  _BYTE *v6; // r0
  int (**v8)[5]; // r0
  char *v9; // r2
  int v10; // r5
  int v11; // r1
  int v12; // t1
  int v13; // r7
  char *v14; // r5
  unsigned int v15; // r4
  int v16; // r6
  char v17[96]; // [sp+10h] [bp-60h] BYREF

  v6 = memset((_BYTE *)a3, 0, 36);
  *(_DWORD *)(a3 + 4) = a1;
  if ( !a2 )
    return sub_7E252C(v6);
  *(_DWORD *)(a3 + 8) = a2;
  memset(v17, 0, 72);
  v8 = off_9200D0;
  v9 = v17;
  v10 = 3;
  v11 = a3 + 12;
  do
  {
    v12 = (int)*v8++;
    *(_DWORD *)v9 = v12;
    *((_DWORD *)v9 + 1) = 8210;
    *((_DWORD *)v9 + 2) = v11;
    *((_DWORD *)v9 + 4) = 6;
    v9 += 24;
    v11 += 8;
    --v10;
  }
  while ( v10 );
  v13 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, *(_DWORD *)(a3 + 4), 1, *(_DWORD *)(a3 + 8), v17, 3);
  if ( v13 < 0 )
    JUMPOUT(0x7E255C);
  v14 = v17;
  v15 = a3 + 12;
  v16 = 3;
  do
  {
    if ( *((int *)v14 + 5) < 0 )
      RtlInitUnicodeString(v15, 0);
    v14 += 24;
    v15 += 8;
    --v16;
  }
  while ( v16 );
  return v13;
}
