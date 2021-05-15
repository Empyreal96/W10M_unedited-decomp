// sub_546CD4 
 
void __fastcall sub_546CD4(int a1, char a2)
{
  unsigned int *v2; // r5

  if ( (a2 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  JUMPOUT(0x4C2E38);
}
