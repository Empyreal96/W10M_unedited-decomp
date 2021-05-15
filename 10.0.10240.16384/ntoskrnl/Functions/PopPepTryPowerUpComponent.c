// PopPepTryPowerUpComponent 
 
int __fastcall PopPepTryPowerUpComponent(int result, int a2)
{
  int v2; // r3
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r1

  v2 = *(_DWORD *)(a2 + 4);
  if ( (v2 & 2) == 0 )
  {
    *(_DWORD *)(a2 + 4) = v2 | 2;
    __dmb(0xBu);
    v3 = (unsigned int *)(result + 92);
    do
    {
      v4 = __ldrex(v3);
      v5 = v4 + 1;
    }
    while ( __strex(v5, v3) );
    __dmb(0xBu);
    if ( v5 == 1 && !*(_BYTE *)(result + 88) && !**(_DWORD **)(result + 48) )
      result = PopPepTriggerActivity(result, 0, 0, 0);
  }
  return result;
}
