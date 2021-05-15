// sub_7D1D70 
 
void sub_7D1D70()
{
  _DWORD *v0; // r4
  unsigned int *v1; // r7
  unsigned int v2; // r2
  unsigned int v3; // r2

  __dmb(0xBu);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 + 1;
  }
  while ( __strex(v3, v1) );
  __dmb(0xBu);
  v0[(((_BYTE)v3 - 1) & 0x7F) + 832] = 23;
  CmpUnlockRegistry();
  UNLOCK_HIVE_LOAD();
  CmpDereferenceHive(v0);
  JUMPOUT(0x6D0CEA);
}
