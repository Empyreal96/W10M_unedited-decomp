// AlpcpCaptureAttributes 
 
int __fastcall AlpcpCaptureAttributes(int a1, int a2, unsigned int a3, int a4, int a5)
{
  int v5; // r5
  unsigned int v6; // r8
  int v7; // r4
  int *v8; // r2
  int v9; // r6
  unsigned int v10; // r1
  int v11; // r5
  int v12; // r2
  _DWORD *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v19; // [sp+8h] [bp-40h]
  int v20; // [sp+1Ch] [bp-2Ch]
  int v21; // [sp+24h] [bp-24h]

  v5 = a4;
  v20 = a4;
  v6 = a3;
  v21 = a2;
  v19 = a1;
  memset((_BYTE *)a5, 0, 32);
  *(_DWORD *)a5 = *(_DWORD *)(v5 + 56);
  *(_DWORD *)(a5 + 4) = *(_DWORD *)(v5 + 60);
  if ( !v6 )
    return 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v8 = (int *)v6;
    if ( v6 >= MmUserProbeAddress )
      v8 = (int *)MmUserProbeAddress;
    v9 = *v8;
    v10 = 8;
    if ( *v8 < 0 )
      v10 = 20;
    if ( (v9 & 0x40000000) != 0 )
      v10 += 16;
    if ( (v9 & 0x20000000) != 0 )
      v10 += 20;
    if ( (v9 & 0x10000000) != 0 )
      v10 += 16;
    if ( (v9 & 0x8000000) != 0 )
      v10 += 24;
    if ( (v9 & 0x4000000) != 0 )
      v10 += 4;
    if ( (v9 & 0xA0000000) != 0 )
    {
      if ( v10 )
      {
        if ( (v6 & 3) != 0 )
          ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
        if ( v6 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *(_BYTE *)v6 = *(_BYTE *)v6;
        if ( v10 > 4 )
          *(_BYTE *)(((v10 - 1) & 0xFFFFFFFC) + v6) = *(_BYTE *)(((v10 - 1) & 0xFFFFFFFC) + v6);
      }
      else
      {
        ProbeForWrite(v6, 0, 4);
      }
    }
    else if ( (v6 & 3) != 0 )
    {
      ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
    }
    v11 = *(_DWORD *)(v6 + 4);
    v12 = a5;
    v13 = (_DWORD *)v19;
  }
  else
  {
    v9 = *(_DWORD *)v6;
    v11 = *(_DWORD *)(v6 + 4);
    v12 = a5;
    v13 = (_DWORD *)v19;
  }
  if ( (v11 & ~v9) != 0 )
    return -1073741811;
  v7 = 0;
  if ( (v11 & 0x80000000) != 0 )
  {
    v7 = AlpcpCaptureSecurityAttribute(v13, (_DWORD *)(v6 + 8), v12);
    if ( v7 < 0 )
      goto LABEL_66;
  }
  if ( (v11 & 0x40000000) != 0 )
  {
    v14 = 8;
    if ( (v9 & 0x80000000) != 0 )
      v14 = 20;
    v7 = AlpcpCaptureViewAttribute(v19, (_DWORD *)(v14 + v6), v20, a5);
    if ( v7 < 0 )
      goto LABEL_66;
  }
  if ( (v11 & 0x20000000) != 0 )
  {
    v15 = 8;
    if ( (v9 & 0x80000000) != 0 )
      v15 = 20;
    if ( (v9 & 0x40000000) != 0 )
      v15 += 16;
    v7 = AlpcpCaptureContextAttribute(v19, v15 + v6, v20, a5);
    if ( v7 < 0 )
      goto LABEL_66;
  }
  if ( (v11 & 0x10000000) != 0 )
  {
    v16 = 8;
    if ( (v9 & 0x80000000) != 0 )
      v16 = 20;
    if ( (v9 & 0x40000000) != 0 )
      v16 += 16;
    if ( (v9 & 0x20000000) != 0 )
      v16 += 20;
    v7 = AlpcpCaptureHandleAttribute(v16 + v6, a5);
    if ( v7 < 0 )
      goto LABEL_66;
  }
  if ( (v11 & 0x4000000) != 0 )
  {
    v17 = 8;
    if ( (v9 & 0x80000000) != 0 )
      v17 = 20;
    if ( (v9 & 0x40000000) != 0 )
      v17 += 16;
    if ( (v9 & 0x20000000) != 0 )
      v17 += 20;
    if ( (v9 & 0x10000000) != 0 )
      v17 += 16;
    if ( (v9 & 0x8000000) != 0 )
      v17 += 24;
    v7 = AlpcpCaptureDirectAttribute((int *)(v17 + v6), 0x8000000, a5, v21, v11);
  }
  if ( v7 < 0 )
LABEL_66:
    AlpcpReleaseAttributes((_DWORD *)a5);
  return v7;
}
