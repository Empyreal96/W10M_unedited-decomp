// sub_8AB028 
 
int __fastcall sub_8AB028(unsigned __int16 *a1, int *a2, int a3)
{
  int v3; // r8
  unsigned int v4; // r7
  char v8; // r3
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r5
  int v17; // r0
  int v18; // r4
  int v20[16]; // [sp-4h] [bp-40h] BYREF

  v3 = *(unsigned __int8 *)(a3 + 12);
  v4 = 0;
  if ( !*(_BYTE *)(a3 + 12) )
  {
    memset(v20, 0, 32);
    if ( a2 )
      v8 = 2;
    else
      v8 = 1;
    LOBYTE(v20[1]) = v8;
    HIWORD(v20[1]) = a1[14];
    BYTE1(v20[1]) = *((_BYTE *)a1 + 30);
    v20[2] = *((_DWORD *)a1 + 8);
    if ( a2 )
    {
      v12 = a2[1];
      v13 = a2[2];
      v14 = a2[3];
      v20[3] = *a2;
      v20[4] = v12;
      v20[5] = v13;
      v20[6] = v14;
    }
    else
    {
      v9 = *((_DWORD *)a1 + 4);
      v10 = *((_DWORD *)a1 + 5);
      v11 = *((_DWORD *)a1 + 6);
      v20[3] = *((_DWORD *)a1 + 3);
      v20[4] = v9;
      v20[5] = v10;
      v20[6] = v11;
    }
  }
  v15 = a1[24];
  v16 = *a1;
  if ( !v3 )
  {
    v17 = ExAllocatePoolWithTag(1, v15 + v16, 542329939);
    v4 = v17;
    if ( !v17 )
      return -1073741670;
    memmove(v17, *((_DWORD *)a1 + 2), *a1);
    if ( a1[24] )
      memmove(v4 + 2 * (*a1 >> 1), *((_DWORD *)a1 + 14), a1[24]);
  }
  v18 = sub_8AA490((__int64 *)a3, (int)v20, v4, v15 + v16);
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v18;
}
