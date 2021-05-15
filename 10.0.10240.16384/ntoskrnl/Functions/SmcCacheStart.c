// SmcCacheStart 
 
int __fastcall SmcCacheStart(_DWORD *a1, int a2, int a3)
{
  int v4; // r1
  int v5; // r8
  int v8; // r4
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  unsigned int v13; // r5
  int v14; // r2
  int v15; // r0
  unsigned int v16; // r2
  char v17; // r3
  unsigned int v18; // r1
  unsigned int *v19; // r2
  int *v20; // r3
  int *v22; // [sp+20h] [bp-78h] BYREF
  int *v23; // [sp+24h] [bp-74h]
  int v24; // [sp+28h] [bp-70h] BYREF
  int v25; // [sp+2Ch] [bp-6Ch]
  __int64 v26; // [sp+30h] [bp-68h] BYREF
  int v27[2]; // [sp+38h] [bp-60h] BYREF
  int v28[2]; // [sp+40h] [bp-58h] BYREF
  _DWORD v29[20]; // [sp+48h] [bp-50h] BYREF

  v4 = *(_DWORD *)(a2 + 8);
  v5 = 0;
  v27[0] = 0;
  if ( !v4 || ((v4 - 1) & v4) != 0 )
  {
    v8 = -1073741811;
    goto LABEL_25;
  }
  if ( !*(_QWORD *)a2 )
    return -1073741811;
  if ( *(_QWORD *)a2 > 0x800000000ui64 )
    return -1073739516;
  v9 = *(_DWORD *)(a2 + 4);
  v10 = *(_DWORD *)(a2 + 8);
  v11 = *(_DWORD *)(a2 + 12);
  a1[4] = *(_DWORD *)a2;
  a1[5] = v9;
  a1[6] = v10;
  a1[7] = v11;
  v12 = *(_DWORD *)(a2 + 20);
  a1[8] = *(_DWORD *)(a2 + 16);
  a1[9] = v12;
  v13 = a3 & 0xFFFFFFFE;
  if ( (a3 & 1) == 0 )
    v13 = 0;
  v14 = a1[6];
  v22 = (int *)(*(_DWORD *)(a2 + 12) & 1);
  v26 = *(_QWORD *)a2;
  v8 = ((int (__fastcall *)(int, int, int, int, __int64 *))SmKmStoreFileCreate)(PnpDriverObject, a3, v14, v14, &v26);
  if ( v8 >= 0 )
  {
    if ( v13 && v26 != *(_QWORD *)a2 )
      return -1073741792;
    v16 = a1[7] & 0xFFFFFFFC | (2 * (v24 & 1));
    v17 = (char)v22;
    v22 = (int *)a1[13];
    v15 = (int)v22;
    a1[7] = v17 & 1 | v16;
    if ( v15 )
      goto LABEL_16;
    v8 = SmKmStoreFileOpenVolume(a1[11], v27, &v22);
    v5 = v27[0];
    if ( v8 >= 0 )
    {
      v15 = (int)v22;
LABEL_16:
      v8 = SmKmVolumeQueryUniqueId(v15, a1 + 95, 512);
      if ( v8 >= 0 )
      {
        v29[1] = 0;
        v29[2] = 4096;
        v29[3] = 0;
        v29[4] = 0x2000;
        v29[5] = 0;
        v29[6] = 0x4000;
        v29[7] = 0;
        v29[8] = 0x8000;
        v29[9] = 0;
        v29[10] = -1;
        v29[11] = 0;
        v18 = a1[6];
        v26 = 0x5F5E100FFFFFFFFi64;
        v27[0] = -1;
        v27[1] = 0;
        v28[1] = 0;
        v29[0] = 2048;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v25 = 0;
        v28[0] = -1;
        if ( v18 )
        {
          v19 = v29;
          if ( v18 > 0x800 )
          {
            do
              v19 += 2;
            while ( *v19 < v18 );
          }
          v22 = v29;
          v20 = (int *)&v26;
          *v19 = -1;
        }
        else
        {
          v22 = v27;
          v20 = v28;
        }
        v23 = v20;
        v24 = 983104;
        v25 = 0;
        v8 = StEtaStart((int)(a1 + 18), (int)&v22, &v24);
        if ( v8 >= 0 )
          v8 = 0;
      }
    }
LABEL_25:
    if ( v5 )
      ObfDereferenceObject(v5);
  }
  return v8;
}
