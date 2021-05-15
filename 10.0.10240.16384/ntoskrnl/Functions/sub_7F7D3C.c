// sub_7F7D3C 
 
void __fastcall sub_7F7D3C(int a1, char a2)
{
  unsigned int *v2; // r4

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x7215C6);
}
