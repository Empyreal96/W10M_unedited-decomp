// SmpPageWrite 
 
int __fastcall SmpPageWrite(unsigned int *a1, _DWORD *a2, unsigned int a3, int a4, int a5, int *a6, int a7)
{
  unsigned int v7; // r4
  int v10; // r6
  int v11; // r0
  int v12; // r5
  _DWORD *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1

  v7 = a3;
  v10 = -1;
  if ( (a3 & 0x3F) == 32 && (a2[1] & 3) == 0 )
  {
    v11 = SmpKeyedStoreReference((unsigned int *)&unk_636CC4, (int)SmGlobals, *a2);
    v10 = v11;
    if ( v11 != -1 )
      v7 = v11 & 0x1F | v7 & 0xFFFFFFC0;
  }
  if ( (v7 & 0x3F) == 32 && dword_636CDC == -1 )
    v12 = -1073741285;
  else
    v12 = SMKM_STORE_MGR<SM_TRAITS>::SmPageWrite((int)SmGlobals, a1, v7, a4, a5 & 0x7FFFFFFF, a6, a7);
  if ( v10 != -1 )
  {
    v13 = &SmGlobals[24 * (v10 & 0x1F) + 1];
    __pld(v13);
    v14 = *v13 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( v15 == v14 && __strex(v14 - 2, v13) );
    if ( v15 != v14 )
      ExfReleaseRundownProtection((unsigned __int8 *)v13);
  }
  return v12;
}
