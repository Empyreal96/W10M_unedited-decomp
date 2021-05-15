// sub_519508 
 
void __fastcall sub_519508(int a1)
{
  _DWORD *v1; // r5
  unsigned int v2; // r3
  _DWORD *v3; // r4
  int v4; // r2
  int v5; // r3

  v2 = *(unsigned __int8 *)(a1 + 3576);
  if ( v2 < 6 )
  {
    v3 = (_DWORD *)(a1 + 12 * v2 + 3504);
    v4 = v1[1];
    v5 = v1[2];
    *v3 = *v1;
    v3[1] = v4;
    v3[2] = v5;
    ++*(_BYTE *)(a1 + 3576);
  }
  KiSetCacheInformation();
  JUMPOUT(0x4DF798);
}
