// sub_519440 
 
void __fastcall sub_519440(char a1)
{
  int v1; // r5
  int v2; // r6

  if ( (a1 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v1 + v2));
  JUMPOUT(0x4DAEE0);
}
