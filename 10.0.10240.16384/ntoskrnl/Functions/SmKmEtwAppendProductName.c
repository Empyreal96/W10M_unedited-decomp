// SmKmEtwAppendProductName 
 
int __fastcall SmKmEtwAppendProductName(int *a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r6
  unsigned __int16 *v7; // r4
  int v8; // r5
  int v9; // r0
  unsigned int v10; // r0
  unsigned __int16 *v11; // r8
  unsigned int v12; // r5
  int result; // r0
  __int64 v14; // kr00_8
  __int16 v15; // r3
  unsigned int v16; // r5
  _DWORD *v17; // r3
  int v18; // r10
  int v19; // r4
  int *v20; // r3
  int v21; // [sp+0h] [bp-28h] BYREF
  int v22; // [sp+4h] [bp-24h] BYREF
  unsigned int v23; // [sp+8h] [bp-20h]

  v21 = a2;
  v22 = a3;
  v23 = a4;
  v5 = *(_DWORD *)(a2 + 12);
  v6 = 0;
  v21 = 0;
  v22 = v5;
  if ( !v5 )
  {
    SmKmStoreFileOpenVolume(*(_DWORD *)(a2 + 4), &v21, &v22);
    v6 = v21;
    v5 = v22;
  }
  v7 = (unsigned __int16 *)((a1[4] + a1[1] + 1) & 0xFFFFFFFE);
  v8 = a1[5] - (_DWORD)v7 + a1[1];
  if ( v5 )
    v9 = SmKmVolumeQueryUniqueId();
  else
    v9 = -1073741275;
  if ( v9 < 0 )
    *v7 = 0;
  v10 = wcslen(v7);
  v11 = &v7[v10];
  if ( SmUniqueIdParseProductName((char *)v7, (int)(v11 + 1), v8 - 2 * v10 - 2) < 0 )
    v12 = 0;
  else
    v12 = wcslen(v11 + 1);
  result = a1[4];
  v14 = *(_QWORD *)(a1 + 1);
  v23 = v12;
  v15 = v12;
  v16 = 2 * v12;
  *(_WORD *)(v14 + result) = v15;
  v22 = *a1;
  v17 = (_DWORD *)(v22 + 16 * HIDWORD(v14));
  *v17 = v14 + result;
  v17[1] = 0;
  v17[2] = 2;
  v17[3] = 0;
  v18 = result + 2;
  a1[4] = result + 2;
  v19 = v14 + result + 2;
  a1[2] = HIDWORD(v14) + 1;
  if ( v11 != (unsigned __int16 *)-2 )
    result = memmove(v19, (int)(v11 + 1), v16);
  v20 = (int *)(v22 + 16 * (HIDWORD(v14) + 1));
  *v20 = v19;
  v20[1] = 0;
  v20[2] = v16;
  v20[3] = 0;
  a1[2] = HIDWORD(v14) + 2;
  a1[4] = v18 + v16;
  if ( v6 )
    result = ObfDereferenceObjectWithTag(v6);
  return result;
}
