// PopHiberReadChecksums 
 
char *__fastcall PopHiberReadChecksums(char *result)
{
  int v1; // r4
  int v2; // r0
  unsigned int *v3; // r9
  int v4; // r10
  int v5; // r1
  unsigned __int64 v6; // r2
  unsigned int v7; // r8
  unsigned int v8; // r6
  unsigned int v9; // r5
  int v10; // r1
  int v11; // r3
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r9
  int v15; // r7
  _DWORD *v16; // r8
  int v17; // r7
  unsigned int v18; // r0
  bool v19; // cf
  unsigned int v20; // r2
  int v21; // r1
  unsigned int v22; // [sp+8h] [bp-60h]
  unsigned int v23; // [sp+Ch] [bp-5Ch]
  int v24; // [sp+10h] [bp-58h]
  unsigned int *v25; // [sp+18h] [bp-50h]
  unsigned int v26; // [sp+1Ch] [bp-4Ch]
  int v27; // [sp+20h] [bp-48h]
  int v28[2]; // [sp+28h] [bp-40h] BYREF
  __int64 v29; // [sp+30h] [bp-38h] BYREF
  int v30[2]; // [sp+38h] [bp-30h] BYREF
  unsigned int v31[10]; // [sp+40h] [bp-28h] BYREF

  v1 = (int)result;
  if ( *((_DWORD *)result + 74) )
  {
    v2 = ReadTimeStampCounter();
    v3 = *(unsigned int **)(v1 + 128);
    v24 = *(_DWORD *)(v1 + 296);
    v4 = *(_DWORD *)(v1 + 200);
    v26 = v2;
    v27 = v5;
    v7 = (unsigned __int64)v3[22] >> 20;
    LODWORD(v6) = v3[22] << 12;
    v25 = v3;
    v8 = (2 * v3[24] + 4095) & 0xFFFFF000;
    while ( 1 )
    {
      v22 = v6;
      v23 = v7;
      if ( !v8 )
        break;
      HIDWORD(v6) = v7;
      PopGetIoLocation(v28, *(_DWORD **)(v1 + 104), v6, v31);
      v9 = v31[0];
      v10 = *(_DWORD *)(v1 + 96);
      v30[0] = v28[0];
      if ( v8 < v31[0] )
        v9 = v8;
      v30[1] = v28[1];
      v11 = *(_DWORD *)(v1 + 100);
      v12 = v10 & 0xFFF;
      if ( v9 >= v11 << 12 )
        v9 = v11 << 12;
      v13 = *(_DWORD *)(v1 + 272);
      *(_DWORD *)v4 = 0;
      if ( v9 >= v13 << 12 )
        v9 = v13 << 12;
      *(_WORD *)(v4 + 4) = 4 * (((v12 + v9 + 4095) >> 12) + 7);
      *(_WORD *)(v4 + 6) = 0;
      *(_DWORD *)(v4 + 16) = v10 & 0xFFFFF000;
      *(_DWORD *)(v4 + 20) = v9;
      *(_DWORD *)(v4 + 24) = v12;
      *(_DWORD *)(v4 + 12) = *(_DWORD *)(v1 + 96);
      *(_WORD *)(v4 + 6) = 1;
      if ( ((v10 & 0xFFF) + v9 + 4095) >> 12 )
      {
        v14 = ((v10 & 0xFFF) + v9 + 4095) >> 12;
        v15 = 0;
        v16 = (_DWORD *)(v4 + 28);
        do
        {
          MmGetPhysicalAddress((int)&v29, v15 + *(_DWORD *)(v1 + 96), v12, *(_DWORD *)(v1 + 96));
          v12 = v29;
          v15 += 4096;
          *v16++ = v29 >> 12;
          --v14;
        }
        while ( v14 );
        v3 = v25;
        v7 = v23;
      }
      v17 = (*(int (__fastcall **)(_DWORD, int *, int))(*(_DWORD *)(v1 + 108) + 108))(0, v30, v4);
      if ( v17 < 0 )
      {
        PopInternalAddToDumpFile(*(_DWORD *)(v1 + 108), 256, 0);
        KeBugCheckEx(160, 266, 10, v1, v17);
      }
      memmove(v24, *(_DWORD *)(v1 + 96), v9);
      v8 -= v9;
      v7 = (__PAIR64__(v7, v22) + v9) >> 32;
      LODWORD(v6) = v22 + v9;
      v24 += v9;
    }
    *(_DWORD *)(v1 + 280) = v3[24];
    *(_DWORD *)(v1 + 284) = v3[25];
    v18 = ReadTimeStampCounter();
    v19 = v18 >= v26;
    v20 = v18 - v26;
    result = &PopSleepStats;
    qword_61F100 += __PAIR64__(v21 - (v27 + (unsigned int)!v19), v20);
  }
  return result;
}
