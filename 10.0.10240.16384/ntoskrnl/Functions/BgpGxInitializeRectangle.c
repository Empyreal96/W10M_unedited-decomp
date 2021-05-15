// BgpGxInitializeRectangle 
 
int __fastcall BgpGxInitializeRectangle(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  __int64 v4; // r4
  unsigned int v5; // r6

  if ( !a1 || !a3 )
    return -1073741811;
  LODWORD(v4) = a1[1];
  HIDWORD(v4) = *a1;
  v5 = (unsigned int)(*a1 * v4 * a2 + 7) >> 3;
  if ( v5 + 64 > a4 )
    return -1073741670;
  *(_DWORD *)(a3 + 12) = v5;
  *(_DWORD *)(a3 + 16) = 8;
  *(_DWORD *)(a3 + 20) = a3 + 64;
  *(_QWORD *)a3 = v4;
  *(_DWORD *)(a3 + 8) = a2;
  return 0;
}
