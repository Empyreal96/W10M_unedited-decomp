// MiMapImageInSystemProcess 
 
int __fastcall MiMapImageInSystemProcess(int *a1, char a2, unsigned int *a3, int *a4)
{
  int v4; // r4
  unsigned __int64 *v6; // r6
  unsigned __int64 v7; // kr00_8
  unsigned __int64 v8; // r4
  _DWORD *v9; // r1
  int v11; // [sp+20h] [bp-48h] BYREF
  int v12; // [sp+24h] [bp-44h]
  _DWORD v13[16]; // [sp+28h] [bp-40h] BYREF

  v4 = *a1;
  __dmb(0xBu);
  v6 = (unsigned __int64 *)(v4 + 16);
  do
    v7 = __ldrexd(v6);
  while ( __PAIR64__(v7, HIDWORD(v7)) == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v6) );
  v12 = HIDWORD(v7);
  __dmb(0xBu);
  *a4 = v7;
  __dmb(0xBu);
  do
    v8 = __ldrexd(v6);
  while ( v8 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v6) );
  __dmb(0xBu);
  if ( HIDWORD(v8) > 1 || HIDWORD(v8) || MmHighestUserAddress - 0x10000 < (unsigned int)*a4 )
    return -1073741793;
  *a3 = 0;
  v11 = 0;
  v12 = 0;
  v9 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v13[8] = 0x80000;
  v13[5] = 0;
  return MiMapViewOfImageSection(a1, (int)v9, v9, a3, &v11, a4, v13, 2, 1, 0, 0, a2);
}
