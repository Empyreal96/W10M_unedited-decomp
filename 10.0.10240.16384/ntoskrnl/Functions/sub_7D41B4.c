// sub_7D41B4 
 
void __fastcall sub_7D41B4(int a1, char a2)
{
  unsigned int *v2; // r5

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x6D4F52);
}
