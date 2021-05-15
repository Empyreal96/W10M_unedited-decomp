// RtlMakeSelfRelativeSD 
 
int __fastcall RtlMakeSelfRelativeSD(_DWORD *a1, int a2, unsigned int *a3)
{
  unsigned int v6; // r6
  unsigned int v7; // r9
  unsigned int v8; // r7
  unsigned int v9; // r8
  unsigned int v10; // r2
  int v11; // r5
  int result; // r0
  unsigned int v13; // [sp+18h] [bp-40h] BYREF
  unsigned int v14; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v15; // [sp+20h] [bp-38h] BYREF
  unsigned int v16; // [sp+24h] [bp-34h] BYREF
  int v17; // [sp+28h] [bp-30h] BYREF
  int v18; // [sp+2Ch] [bp-2Ch] BYREF
  int v19; // [sp+30h] [bp-28h] BYREF
  int v20[9]; // [sp+34h] [bp-24h] BYREF

  RtlpQuerySecurityDescriptor(a1, &v19, &v13, v20, &v14, &v18, &v15, &v17, &v16);
  v6 = v13;
  v7 = v14;
  v8 = v15;
  v9 = v16;
  v10 = v13 + v14 + v15 + v16 + 20;
  if ( v10 > *a3 )
  {
    result = -1073741789;
    *a3 = v10;
  }
  else if ( a2 )
  {
    memset((_BYTE *)a2, 0, v10);
    v11 = a2 + 20;
    *(_DWORD *)a2 = *a1;
    if ( v9 )
    {
      memmove(a2 + 20, v17, v9);
      *(_DWORD *)(a2 + 12) = 20;
      v11 += v9;
    }
    else
    {
      *(_DWORD *)(a2 + 12) = 0;
    }
    if ( v8 )
    {
      memmove(v11, v18, v8);
      *(_DWORD *)(a2 + 16) = v11 - a2;
      v11 += v8;
    }
    else
    {
      *(_DWORD *)(a2 + 16) = 0;
    }
    if ( v6 )
    {
      memmove(v11, v19, v6);
      *(_DWORD *)(a2 + 4) = v11 - a2;
      v11 += v6;
    }
    if ( v7 )
    {
      memmove(v11, v20[0], v7);
      *(_DWORD *)(a2 + 8) = v11 - a2;
    }
    result = 0;
    *(_WORD *)(a2 + 2) |= 0x8000u;
  }
  else
  {
    result = -1073741811;
  }
  return result;
}
