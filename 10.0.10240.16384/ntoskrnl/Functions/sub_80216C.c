// sub_80216C 
 
void __fastcall sub_80216C(char a1)
{
  int v1; // r5
  int v2; // r7

  if ( (a1 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v1 + v2));
  JUMPOUT(0x7403D8);
}
