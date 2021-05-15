// IopAddPageDumpRange 
 
int __fastcall IopAddPageDumpRange(_DWORD *a1, char *a2)
{
  int v4; // r3
  unsigned int v5; // r7
  int v6; // r5
  char v7; // r8
  int v8; // r2
  int v9; // r5
  int v10; // r10
  int v11; // r1
  int v12; // r2
  int v13; // r9
  unsigned int i; // r6
  __int64 v15; // r1
  int v17; // [sp+0h] [bp-40h]
  int v18; // [sp+8h] [bp-38h] BYREF
  int v19; // [sp+Ch] [bp-34h]
  _DWORD v20[2]; // [sp+10h] [bp-30h] BYREF
  int *v21; // [sp+18h] [bp-28h]
  int v22; // [sp+1Ch] [bp-24h]
  int v23; // [sp+20h] [bp-20h]

  v20[0] = 0;
  v20[1] = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  if ( a2 )
    *a2 = 0;
  v4 = a1[1];
  v5 = (unsigned __int8)v4 >> 4;
  a1[1] = v4 & 0xFFFFFF0F;
  if ( (v4 & 0x7FFFFF0C) != 0 )
    return -1073741582;
  if ( v4 >= 0 )
  {
    v7 = 0;
  }
  else
  {
    a1[1] = v4 & 0x7FFFFF0F;
    v7 = 1;
  }
  v8 = a1[1];
  if ( ((v8 - 1) & v8) != 0 )
    return -1073741811;
  v9 = a1[4];
  if ( !v9 )
    return 0;
  if ( (v8 & 1) != 0 )
    v10 = 0;
  else
    v10 = 2;
  v11 = a1[3];
  v12 = *(_DWORD *)(CrashdmpDumpBlock + 8);
  v17 = v12;
  v13 = v12 + 56;
  v18 = *(_DWORD *)(v12 + 48);
  v19 = v12 + 56;
  v21 = &v18;
  v6 = IoSetDumpRange(v20, v11, v9, v10);
  if ( v6 >= 0 && a2 )
    *a2 = v7;
  for ( i = (((unsigned int)(*(_DWORD *)(v17 + 48) + 7) >> 3) + 7) & 0xFFFFFFF8; v5; v5 >>= 1 )
  {
    v13 += i;
    if ( (v5 & 1) != 0 )
    {
      if ( i - v17 + v13 > (unsigned __int64)(*(_QWORD *)(v17 + 32) - 4096i64) )
        return v6;
      v15 = *(_QWORD *)(a1 + 3);
      v19 = v13;
      IoSetDumpRange(v20, v15, SHIDWORD(v15), v10);
    }
  }
  return v6;
}
