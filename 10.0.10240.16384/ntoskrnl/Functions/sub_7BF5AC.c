// sub_7BF5AC 
 
void __fastcall sub_7BF5AC(int a1, int a2, int a3, int a4, __int16 a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
  int v17; // r7
  _BYTE *v18; // r0
  _BYTE *v19; // r6

  v18 = (_BYTE *)SmAlloc(24, 1397779827);
  v19 = v18;
  if ( v18 )
  {
    memset(v18, 0, 24);
    *((_DWORD *)v19 + 1) = a17;
    *((_WORD *)v19 + 4) = a5;
    SmpKeyedStoreEntryGet(v17, (int)(v19 + 4), 1, 0);
    JUMPOUT(0x6A41F6);
  }
  JUMPOUT(0x6A41F4);
}
