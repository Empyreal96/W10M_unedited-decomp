// SepFilterToken 
 
int __fastcall SepFilterToken(_DWORD *a1, char a2, char a3, int a4, int a5, int a6, int a7, unsigned int a8, int *a9, int a10)
{
  int v11; // r4
  _DWORD *v12; // r0
  _DWORD *v13; // r8
  __int64 v14; // r4
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r3
  int v24; // r6
  int v25; // t1
  int v27; // [sp+20h] [bp-38h]
  int v28; // [sp+2Ch] [bp-2Ch]
  int v29; // [sp+30h] [bp-28h]

  v27 = a2;
  if ( (a3 & 8) == 0 || (a1[44] & 0x58) == 0 )
  {
    v11 = 0;
    if ( !a8 )
    {
LABEL_3:
      v12 = (_DWORD *)ExAllocatePoolWithTag(1, 24, 1950442835);
      v13 = v12;
      if ( v12 )
      {
        *v12 = 0;
        v12[1] = v12 + 1;
        v12[2] = v12 + 1;
        v12[3] = 0;
        v12[4] = v12 + 4;
        v12[5] = v12 + 4;
        v29 = ExAllocatePoolWithTag(512, 56, 1817470291);
        if ( v29 )
        {
          HIDWORD(v14) = a1[33] + a10;
          if ( ObCreateObjectEx(v27, SeTokenObjectType, 0, v27) >= 0 )
          {
            *(_DWORD *)(v28 + 48) = v29;
            ExInitializeResourceLite(v29);
            ExAllocateLocallyUniqueId((int *)(v28 + 52));
            ExAllocateLocallyUniqueId((int *)(v28 + 16));
            LODWORD(v14) = 0;
            *(_BYTE *)(v28 + 180) = 0;
            *(_DWORD *)(v28 + 24) = a1[6];
            *(_DWORD *)(v28 + 28) = a1[7];
            v15 = a1[1];
            v16 = a1[2];
            v17 = a1[3];
            *(_DWORD *)v28 = *a1;
            *(_DWORD *)(v28 + 4) = v15;
            *(_DWORD *)(v28 + 8) = v16;
            *(_DWORD *)(v28 + 12) = v17;
            *(_DWORD *)(v28 + 140) = 0;
            *(_QWORD *)(v28 + 128) = v14;
            *(_DWORD *)(v28 + 32) = a1[4];
            *(_DWORD *)(v28 + 36) = a1[5];
            *(_DWORD *)(v28 + 168) = a1[42];
            *(_DWORD *)(v28 + 172) = a1[43];
            *(_DWORD *)(v28 + 40) = a1[10];
            *(_DWORD *)(v28 + 44) = a1[11];
            *(_DWORD *)(v28 + 196) = a1[49];
            *(_DWORD *)(v28 + 200) = a1[50];
            *(_DWORD *)(v28 + 648) = 0;
            *(_DWORD *)(v28 + 652) = 0;
            *(_DWORD *)(v28 + 636) = 0;
            v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v18 + 308);
            ExAcquireResourceSharedLite(a1[12], 1);
            *(_DWORD *)(v28 + 136) = a1[34];
            *(_DWORD *)(v28 + 144) = a1[36];
            *(_DWORD *)(v28 + 120) = a1[30];
            *(_DWORD *)(v28 + 176) = a1[44] & 0xFFFFFBD7;
            memmove(v28 + 88, (int)(a1 + 22), 0x1Fu);
            *(_DWORD *)(v28 + 184) = a1[46];
            *(_DWORD *)(v28 + 188) = a1[47];
            v19 = a1[17];
            v20 = a1[18];
            v21 = a1[19];
            *(_DWORD *)(v28 + 64) = a1[16];
            *(_DWORD *)(v28 + 68) = v19;
            *(_DWORD *)(v28 + 72) = v20;
            *(_DWORD *)(v28 + 76) = v21;
            v22 = a1[21];
            *(_DWORD *)(v28 + 80) = a1[20];
            *(_DWORD *)(v28 + 84) = v22;
            *(_DWORD *)(v28 + 476) = v13;
            if ( *(_BYTE *)(v28 + 118) != 2 )
              JUMPOUT(0x7DB7B0);
            JUMPOUT(0x7DB7A6);
          }
          JUMPOUT(0x7DB794);
        }
        JUMPOUT(0x7DB790);
      }
      JUMPOUT(0x7DB78C);
    }
    while ( 1 )
    {
      v25 = *a9;
      a9 += 2;
      v24 = v25;
      if ( RtlIsPackageSid(v25) || RtlIsCapabilitySid(v24) )
        break;
      if ( ++v11 >= a8 )
        goto LABEL_3;
    }
  }
  return sub_7DB788();
}
