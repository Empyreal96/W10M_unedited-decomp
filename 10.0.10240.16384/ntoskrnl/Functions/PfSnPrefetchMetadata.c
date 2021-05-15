// PfSnPrefetchMetadata 
 
int __fastcall PfSnPrefetchMetadata(int a1, int a2)
{
  int v3; // r6
  int v4; // r4
  int v5; // r3
  unsigned int v6; // r4
  int v7; // r10
  int v8; // r3
  _DWORD *v9; // r8
  int *v10; // r0
  unsigned int v12; // r3
  int v13[3]; // [sp+8h] [bp-78h] BYREF
  unsigned int v14; // [sp+14h] [bp-6Ch]
  _DWORD *v15; // [sp+18h] [bp-68h]
  int v16; // [sp+20h] [bp-60h]
  int v17; // [sp+24h] [bp-5Ch]
  int v18; // [sp+28h] [bp-58h]
  int v19[14]; // [sp+48h] [bp-38h] BYREF

  v3 = *(_DWORD *)a1;
  v16 = a2;
  v17 = v3;
  v13[0] = 0;
  PfSnLogPrefetchMetadata(v3);
  if ( !v3 )
  {
    v4 = -1073741811;
    goto LABEL_10;
  }
  v19[0] = 24;
  v19[1] = 0;
  v19[3] = 512;
  v19[2] = 0;
  v19[4] = 0;
  v19[5] = 0;
  v4 = NtCreateEvent((unsigned int)v13, 2031619, (int)v19, 0, 0);
  if ( v4 < 0 )
  {
LABEL_10:
    if ( v13[0] )
      NtClose();
    PfSnLogPrefetchMetadata(v3);
    return v4;
  }
  v5 = *(_DWORD *)(v3 + 108);
  v6 = 0;
  v14 = 0;
  v7 = v5 + v3;
  v8 = *(_DWORD *)(v3 + 112);
  v18 = v7;
  if ( !v8 )
  {
LABEL_9:
    v4 = 0;
    goto LABEL_10;
  }
  v9 = (_DWORD *)v7;
  v15 = (_DWORD *)v7;
  while ( 1 )
  {
    v10 = PfSnFindPrefetchVolumeInfoInList((_WORD *)(*v9 + v7), (int **)(a1 + 96), 1);
    if ( v10 )
    {
      if ( (v10[16] & 1) != 0 )
        return sub_8091D8();
    }
    v12 = *(_DWORD *)(v3 + 112);
    ++v6;
    v9 += 24;
    v14 = v6;
    v15 = v9;
    if ( v6 >= v12 )
      goto LABEL_9;
  }
}
