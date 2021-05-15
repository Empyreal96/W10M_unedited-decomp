// FstubReadPartitionTableEFI 
 
int __fastcall FstubReadPartitionTableEFI(_DWORD *a1, int a2, int *a3)
{
  int v5; // r7
  _DWORD *v6; // r4
  unsigned int v7; // r9
  int v8; // r8
  _BYTE *v9; // r0
  int v10; // r5
  __int64 v11; // r0
  __int64 v12; // r2
  int v13; // r10
  unsigned int v14; // r1
  unsigned int v15; // r3
  bool v16; // cf
  unsigned int v17; // r3
  unsigned int v18; // r1
  unsigned __int64 v19; // kr30_8
  unsigned int v20; // r4
  int v21; // r9
  int v22; // r5
  __int64 v23; // kr40_8
  unsigned int v24; // r0
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // [sp+8h] [bp-38h] BYREF
  int v28; // [sp+Ch] [bp-34h] BYREF
  int v29; // [sp+10h] [bp-30h]
  _BYTE *v30; // [sp+14h] [bp-2Ch]
  int v31; // [sp+18h] [bp-28h]
  int *v32; // [sp+1Ch] [bp-24h]

  v32 = a3;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  *a3 = 0;
  if ( a2 )
    return sub_810528(-1);
  v5 = FstubReadHeaderEFI(a1, &v28, 1, 0, &v28);
  if ( v5 >= 0 )
  {
    v6 = (_DWORD *)v28;
    v5 = FstubReadTableEFI(a1, (_DWORD *)v28, (int *)&v27);
    v7 = v27;
    v31 = v5;
    if ( v5 >= 0 )
    {
      v8 = v6[20];
      v28 = 144 * v8;
      v9 = (_BYTE *)ExAllocatePoolWithTag(512, 144 * v8 + 48, 1114927942);
      v10 = (int)v9;
      v30 = v9;
      if ( v9 )
      {
        memset(v9, 0, v28 + 48);
        LODWORD(v11) = v6[9];
        HIDWORD(v12) = v6[8];
        LODWORD(v12) = (unsigned __int64)(*((_QWORD *)a1 + 6) - 1i64) >> 32;
        HIDWORD(v11) = a1[12] - 1;
        if ( v12 == v11 )
        {
          v13 = 0;
        }
        else
        {
          v25 = a1[1];
          if ( !v25 )
            __brkdiv0();
          v26 = (v8 << 7) / v25;
          *((_QWORD *)v6 + 5) = (unsigned int)v26 + 2i64;
          *((_QWORD *)v6 + 6) = *((_QWORD *)a1 + 6) - (unsigned int)v26 - 2i64;
          v13 = 1;
        }
        *(_DWORD *)v10 = 1;
        *(_QWORD *)(v10 + 24) = *((_QWORD *)v6 + 5) * (unsigned int)a1[1];
        v14 = v6[12];
        v15 = v6[10];
        v16 = v14 >= v15;
        v17 = v14 - v15;
        v18 = a1[1];
        v19 = __PAIR64__(v6[13] - (v6[11] + (unsigned int)!v16), v17) + 1;
        *(_DWORD *)(v10 + 40) = v8;
        *(_QWORD *)(v10 + 32) = v19 * v18;
        *(_DWORD *)(v10 + 8) = v6[14];
        *(_DWORD *)(v10 + 12) = v6[15];
        *(_DWORD *)(v10 + 16) = v6[16];
        *(_DWORD *)(v10 + 20) = v6[17];
        if ( v8 )
        {
          v20 = v7;
          v21 = v10 + 48;
          v22 = 0;
          do
          {
            if ( *(_DWORD *)v20
              || *(_WORD *)(v20 + 4)
              || *(_WORD *)(v20 + 6)
              || *(_BYTE *)(v20 + 8)
              || *(_BYTE *)(v20 + 9)
              || *(_BYTE *)(v20 + 10)
              || *(_BYTE *)(v20 + 11)
              || *(_BYTE *)(v20 + 12)
              || *(_BYTE *)(v20 + 13)
              || *(_BYTE *)(v20 + 14)
              || *(_BYTE *)(v20 + 15) )
            {
              *(_DWORD *)(v21 + 8) = *(_DWORD *)(v20 + 32);
              *(_DWORD *)(v21 + 12) = *(_DWORD *)(v20 + 36);
              *(_QWORD *)(v21 + 8) *= (unsigned int)a1[1];
              v23 = *(_QWORD *)(v20 + 40) - *(_QWORD *)(v20 + 32) + 1i64;
              *(_QWORD *)(v21 + 16) = v23;
              v24 = a1[1];
              *(_DWORD *)v21 = 1;
              *(_QWORD *)(v21 + 16) = v23 * v24;
              *(_DWORD *)(v21 + 32) = *(_DWORD *)v20;
              *(_DWORD *)(v21 + 36) = *(_DWORD *)(v20 + 4);
              *(_DWORD *)(v21 + 40) = *(_DWORD *)(v20 + 8);
              *(_DWORD *)(v21 + 44) = *(_DWORD *)(v20 + 12);
              *(_DWORD *)(v21 + 48) = *(_DWORD *)(v20 + 16);
              *(_DWORD *)(v21 + 52) = *(_DWORD *)(v20 + 20);
              *(_DWORD *)(v21 + 56) = *(_DWORD *)(v20 + 24);
              *(_DWORD *)(v21 + 60) = *(_DWORD *)(v20 + 28);
              *(_DWORD *)(v21 + 64) = *(_DWORD *)(v20 + 48);
              *(_DWORD *)(v21 + 68) = *(_DWORD *)(v20 + 52);
              memmove(v21 + 72, v20 + 56, 0x48u);
              *(_BYTE *)(v21 + 28) = 0;
              *(_DWORD *)(v21 + 24) = -1;
              v21 += 144;
              ++v22;
            }
            v20 += 128;
            --v8;
          }
          while ( v8 );
          v5 = v31;
          v7 = v27;
          v29 = v22;
          v10 = (int)v30;
        }
        *(_DWORD *)(v10 + 4) = v29;
        if ( v13 )
          IoWritePartitionTableEx(*a1, v10);
        *v32 = v10;
      }
      else
      {
        v5 = -1073741670;
      }
    }
    if ( v7 )
      ExFreePoolWithTag(v7);
  }
  return v5;
}
