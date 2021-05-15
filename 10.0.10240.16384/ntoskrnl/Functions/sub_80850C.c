// sub_80850C 
 
void __fastcall sub_80850C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, char a25)
{
  int v25; // r5
  int v26; // r0
  int v27; // r2
  int v28; // r3
  int v29; // r7

  v26 = MmGetSessionById(*(_DWORD *)(v25 + 28), a2, a3, a4);
  v29 = v26;
  if ( v26 )
  {
    if ( MmAttachSession(v26, (int)&a25, v27, v28) >= 0 )
      JUMPOUT(0x75AFEC);
    ObfDereferenceObject(v29);
  }
  JUMPOUT(0x75AFCC);
}
