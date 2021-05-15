// ExQueryFastCacheAppOrigin 
 
int __fastcall ExQueryFastCacheAppOrigin(unsigned __int16 *a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r6
  unsigned int v6; // r5
  int v7; // r3
  int v9; // [sp+10h] [bp-68h] BYREF
  char v10[4]; // [sp+14h] [bp-64h] BYREF
  char v11[4]; // [sp+18h] [bp-60h] BYREF
  int v12; // [sp+1Ch] [bp-5Ch]
  char v13[88]; // [sp+20h] [bp-58h] BYREF

  if ( !a1 || !*a1 || !a2 )
    return -1073741811;
  v5 = ExAllocatePoolWithTag(1, *a1 + 2, 542329939);
  if ( !v5 )
    return -1073741801;
  v6 = 0;
  if ( (*a1 & 0xFFFE) != 0 )
  {
    do
    {
      v7 = *((_DWORD *)a1 + 1);
      if ( !*(_WORD *)(v7 + 2 * v6) )
        break;
      *(_WORD *)(v5 + 2 * v6) = towlower(*(unsigned __int16 *)(v7 + 2 * v6));
      ++v6;
    }
    while ( v6 < *a1 >> 1 );
  }
  *(_WORD *)(v5 + 2 * v6) = 0;
  if ( dword_61D898 )
  {
    v4 = dword_61D898(32780, v5, 2 * v6, v13, v10);
    if ( v4 >= 0 )
    {
      v4 = sub_6E331C(0, (int)v13, v5, 0, 8u, (int)v11, &v9);
      if ( v4 >= 0 )
      {
        if ( v9 == 8 )
          *a2 = v12;
        else
          v4 = -1073700221;
      }
    }
  }
  else
  {
    v4 = -1073741822;
  }
  ExFreePoolWithTag(v5);
  return v4;
}
