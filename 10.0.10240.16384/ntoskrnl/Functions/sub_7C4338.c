// sub_7C4338 
 
void __fastcall sub_7C4338(int a1, char a2)
{
  unsigned int *v2; // r5

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x6B9AB2);
}
