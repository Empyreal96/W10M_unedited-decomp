// sub_52641C 
 
void __fastcall sub_52641C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // r7
  int v13; // r9
  int *v14; // r10
  unsigned int *v15; // r2
  unsigned int v16; // r8
  int v17; // r2
  int v18; // r3
  int v19; // r4
  int v20; // r3

  SmKmStoreHelperCommandProcess(v12, v13, v14);
  __dmb(0xBu);
  v15 = (unsigned int *)(v12 + 36);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 | 1, v15) );
  __dmb(0xBu);
  if ( (v16 & 2) != 0 )
  {
    v17 = v14[1];
    v18 = v14[2];
    v19 = v14[3];
    a7 = *v14;
    a8 = v17;
    a9 = v18;
    a10 = v19;
    v20 = v14[5];
    a11 = v14[4];
    a12 = v20;
    if ( v13 == 4 )
    {
      SmKmStoreHelperCommandCleanup(v12, 4, &a7);
      LOBYTE(v16) = v16 & 0xFD;
    }
  }
  KeSetEvent(v12 + 20, 0, 0);
  if ( (v16 & 2) != 0 )
  {
    SmKmStoreHelperCommandCleanup(v12, v13, &a7);
    JUMPOUT(0x4616F6);
  }
  JUMPOUT(0x4616F8);
}
