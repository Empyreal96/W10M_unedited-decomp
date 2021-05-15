// sub_50EE28 
 
void __fastcall sub_50EE28(int a1)
{
  char v1; // r3
  char v2; // r3

  v1 = PspDebugFlags;
  __dmb(0xBu);
  if ( (v1 & 0x10) != 0 && *(int *)(*(_DWORD *)(a1 + 144) + 56) < 1 || *(int *)(*(_DWORD *)(a1 + 144) + 56) >= 3 )
  {
    v2 = PspDebugFlags;
    __dmb(0xBu);
    if ( (v2 & 0x20) != 0 )
      __debugbreak();
  }
  JUMPOUT(0x4D6F90);
}
