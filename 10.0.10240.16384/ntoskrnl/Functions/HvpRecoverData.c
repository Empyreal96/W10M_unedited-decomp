// HvpRecoverData 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall HvpRecoverData(int a1, unsigned int a2, int a3, int a4, _DWORD *a5, int *a6)
{
  unsigned int v7; // r4
  int v9; // r6
  _BYTE *v10; // r7
  _BYTE *v11; // r0
  unsigned int v12; // r8
  int v13; // r4
  int v14; // r1
  int v15; // r0
  int v16; // r9
  int v17; // r10
  unsigned int v18; // r3
  _BYTE *v19; // r4 OVERLAPPED
  unsigned int v20; // r3
  unsigned int v21; // r4
  unsigned int v24; // [sp+10h] [bp-40h]
  int v25; // [sp+14h] [bp-3Ch]
  int v26; // [sp+18h] [bp-38h]
  unsigned int v27; // [sp+20h] [bp-30h] BYREF
  _BYTE *v28; // [sp+24h] [bp-2Ch]
  unsigned int v29[10]; // [sp+28h] [bp-28h] BYREF

  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
  v29[2] = a2;
  v9 = ((v7 >> 12) + 3) & 0xFFFFFFFC;
  v10 = 0;
  v29[0] = 0;
  v29[1] = 0;
  v11 = (_BYTE *)ExAllocatePoolWithTag(1, v9, 942886211);
  v12 = (unsigned int)v11;
  if ( !v11 )
  {
    v13 = 2;
    goto LABEL_21;
  }
  memset(v11, 0, ((v7 >> 12) + 3) & 0xFFFFFFFC);
  v27 = v7 >> 9;
  v28 = (_BYTE *)v12;
  RtlMergeBitMaps(&v27, (unsigned int *)(a1 + 36));
  if ( a4 )
  {
    v17 = 0;
    v16 = 1;
    v15 = HvApplyLegacyLogFile(a1, v14, v29, &v27);
  }
  else
  {
    v15 = HvApplyLogFile(a1, a3);
    v16 = v25;
    v17 = v26;
  }
  if ( v15 == -1073741801 )
    goto LABEL_7;
  if ( v15 < 0 )
  {
    v13 = 1;
    goto LABEL_20;
  }
  RtlMergeBitMaps((unsigned int *)(a1 + 36), &v27);
  v18 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
  if ( v7 >= v18 )
  {
    if ( v7 > v18 )
    {
      v21 = v18 >> 9;
      RtlClearBits((_BYTE *)(a1 + 36), v18 >> 9, *(_DWORD *)(a1 + 36) - (v18 >> 9));
      *(_DWORD *)(a1 + 36) = v21;
      *(_DWORD *)(a1 + 52) = v21;
    }
    goto LABEL_17;
  }
  v24 = v18 >> 9;
  v9 = ((v18 >> 12) + 3) & 0xFFFFFFFC;
  v10 = (_BYTE *)(*(int (__fastcall **)(int, int, int))(a1 + 12))(v9, 1, 909331779);
  if ( v10 )
  {
    v19 = (_BYTE *)(*(int (__fastcall **)(int, int, int))(a1 + 12))(v9, 1, 909331779);
    if ( !v19 )
    {
      v13 = 2;
      goto LABEL_18;
    }
    memset(v10, 0, v9);
    memset(v19, 0, v9);
    v27 = v24;
    v28 = v10;
    RtlMergeBitMaps(&v27, (unsigned int *)(a1 + 36));
    RtlSetBits(&v27, *(_DWORD *)(a1 + 36), v24 - *(_DWORD *)(a1 + 36));
    (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 40), *(_DWORD *)(a1 + 48));
    (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 48));
    v20 = v24;
    *(_DWORD *)(a1 + 36) = v24;
    *(_DWORD *)(a1 + 40) = v10;
    *(_QWORD *)(a1 + 52) = *(_QWORD *)(&v19 - 1);
    *(_DWORD *)(a1 + 48) = v9;
    v10 = 0;
LABEL_17:
    *(_DWORD *)(a1 + 44) = RtlNumberOfSetBits((unsigned int *)(a1 + 36));
    v13 = 3;
    *a5 = v17;
    *a6 = v16;
LABEL_18:
    if ( v10 )
      (*(void (__fastcall **)(_BYTE *, int))(a1 + 16))(v10, v9);
    goto LABEL_20;
  }
LABEL_7:
  v13 = 2;
LABEL_20:
  ExFreePoolWithTag(v12);
LABEL_21:
  if ( v29[0] )
    ExFreePoolWithTag(v29[0]);
  return v13;
}
