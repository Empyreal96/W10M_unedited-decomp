// MiStoreLogFullPagefile 
 
void MiStoreLogFullPagefile()
{
  _DWORD *v0; // r4
  int v1; // r2
  int v2[10]; // [sp+8h] [bp-28h] BYREF

  v0 = (_DWORD *)dword_634CA0;
  if ( dword_634CA0 && *(_DWORD *)dword_634CA0 > 5u )
  {
    if ( TlgKeywordOn(dword_634CA0, 2i64) )
      MmTlgWrite(v0, (unsigned __int8 *)dword_414188, v1, (int)&byte_414187, 2, v2);
  }
}
