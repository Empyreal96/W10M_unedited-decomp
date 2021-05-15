// sub_7C0260 
 
void __fastcall sub_7C0260(int a1, char a2)
{
  unsigned int *v2; // r4

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x6A637A);
}
