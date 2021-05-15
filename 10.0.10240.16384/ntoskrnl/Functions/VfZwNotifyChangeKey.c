// VfZwNotifyChangeKey 
 
int __fastcall VfZwNotifyChangeKey(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, unsigned __int8 a10)
{
  int vars4; // [sp+34h] [bp+4h]

  if ( ViZwShouldCheck(a1, a2) )
  {
    if ( a3 )
    {
      ViZwCheckVirtualAddress(a3);
      if ( (a4 < 0 || a4 >= 7) && (unsigned int)(a4 - 32) > 0x1F )
        VerifierBugCheckIfAppropriate(196, 252, vars4, a4, 0);
    }
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a8);
  }
  return pXdvZwNotifyChangeKey(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
