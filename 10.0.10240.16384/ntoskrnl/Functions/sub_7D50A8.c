// sub_7D50A8 
 
void __fastcall sub_7D50A8(int a1, int a2, int a3)
{
  int v3; // r4
  unsigned int v4; // r5
  int v5; // r0
  unsigned __int64 *v6; // r3
  unsigned __int64 v7; // kr00_8

  if ( *(_DWORD *)(a1 + 48) != -1 && (*(_DWORD *)(a1 + 28) & 0x10000000) == 0 )
  {
    v5 = dword_632EE8;
    __dmb(0xBu);
    v6 = (unsigned __int64 *)(a3 + 16);
    do
      v7 = __ldrexd(v6);
    while ( v7 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v6) );
    __dmb(0xBu);
    MiUpdateCfgSystemWideBitmapWorker(v5, v3, 2 * (v4 >> 4), 2 * ((unsigned int)v7 >> 4));
    JUMPOUT(0x6D7818);
  }
  JUMPOUT(0x6D7816);
}
