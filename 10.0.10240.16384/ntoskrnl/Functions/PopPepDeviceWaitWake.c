// PopPepDeviceWaitWake 
 
void __fastcall PopPepDeviceWaitWake(int result, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4
  unsigned int v4; // r4

  __dmb(0xBu);
  v2 = (unsigned int *)(result + 80);
  if ( a2 )
  {
    sub_50FF70(result, a2, v2);
  }
  else
  {
    do
    {
      v3 = __ldrex(v2);
      v4 = v3 + 1;
    }
    while ( __strex(v4, v2) );
    __dmb(0xBu);
    if ( v4 == 1 )
      PopPepUpdateConstraints(result, 5, a2);
  }
}
