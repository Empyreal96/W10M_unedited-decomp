// WmipPrepareForWnodeAD 
 
int __fastcall WmipPrepareForWnodeAD(int a1, _DWORD *a2, int *a3, int *a4, _BYTE *a5)
{
  _DWORD *v5; // r8
  int v8; // r4
  int v9; // r5
  int v10; // r6
  int v11; // r4
  int v12; // r7
  int v13; // r6
  _DWORD *v14; // r5
  _DWORD *v15; // r8
  _DWORD *v16; // t1
  int v18; // [sp+8h] [bp-28h] BYREF
  int v19; // [sp+Ch] [bp-24h] BYREF
  int v20[8]; // [sp+10h] [bp-20h] BYREF

  v5 = *(_DWORD **)(a1 + 40);
  if ( !v5 || !v5[5] )
    return -1073741055;
  v8 = v5[11];
  v9 = v5[12];
  v10 = v5[13];
  *a2 = v5[10];
  a2[1] = v8;
  a2[2] = v9;
  a2[3] = v10;
  v11 = 0;
  if ( (v5[2] & 1) != 0 )
  {
    *a5 = 1;
    return v11;
  }
  *a5 = 0;
  v12 = *a4;
  v20[0] = *a3;
  v13 = 0;
  v18 = v12;
  v19 = 0;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v16 = (_DWORD *)v5[8];
  v15 = v5 + 8;
  v14 = v16;
  if ( v16 != v15 )
  {
    do
    {
      if ( v11 < 0 )
        break;
      if ( (v14[2] & 0x89000) == 0 )
      {
        WmipReferenceEntry(v14);
        v11 = WmipAddProviderIdToPIList(&v18, &v19, v20, v12, v14);
      }
      v14 = (_DWORD *)*v14;
    }
    while ( v14 != v15 );
    v12 = v18;
    v13 = v19;
  }
  KeReleaseMutex((int)&WmipSMMutex);
  if ( !v13 )
    return -1073741055;
  *a3 = v13;
  *a4 = v12;
  return v11;
}
