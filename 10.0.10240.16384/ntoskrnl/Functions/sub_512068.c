// sub_512068 
 
void __fastcall sub_512068(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r2
  int v6; // r3
  int v7; // r10

  v4 = MmGetSessionById(a1, a2, a3, a4);
  v7 = v4;
  if ( v4 )
  {
    if ( MmAttachSession(v4, (int)&STACK[0x100], v5, v6) >= 0 )
    {
      __mrc(15, 0, 13, 0, 3);
      JUMPOUT(0x42C14A);
    }
    MmQuitNextSession(v7);
  }
  JUMPOUT(0x42BD28);
}
