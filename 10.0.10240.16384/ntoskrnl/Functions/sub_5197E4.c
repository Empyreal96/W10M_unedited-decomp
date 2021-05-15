// sub_5197E4 
 
void __fastcall sub_5197E4(int a1, int a2)
{
  _DWORD *v2; // r5
  int v3; // r7

  while ( (*v2 & v3) != a2 )
  {
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xBu);
  JUMPOUT(0x4DFE82);
}
