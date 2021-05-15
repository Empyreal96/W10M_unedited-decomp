// sub_806D8C 
 
void __fastcall sub_806D8C(int a1, char a2)
{
  unsigned int *v2; // r6

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x7579E8);
}
