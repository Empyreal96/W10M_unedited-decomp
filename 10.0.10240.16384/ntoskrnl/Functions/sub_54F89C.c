// sub_54F89C 
 
void __fastcall sub_54F89C(int a1, char a2)
{
  unsigned int *v2; // r5

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x4EA6D8);
}
