// ExFlushTb 
 
void __fastcall ExFlushTb(int a1, int a2, int a3)
{
  int v3; // r3
  void (__cdecl *v4)(); // r3

  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( a3 == 1 )
  {
    if ( !*(_DWORD *)(v3 + 744) )
      return;
    v4 = (void (__cdecl *)())HalIommuDispatch[9];
  }
  else
  {
    v4 = (void (__cdecl *)())HalIommuDispatch[10];
  }
  v4();
}
