// PoStartDeviceBusy 
 
int __fastcall PoStartDeviceBusy(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int *v3; // r2
  unsigned int v4; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 4);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  __dmb(0xBu);
  v3 = (unsigned int *)(result + 8);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 + 1, v3) );
  __dmb(0xBu);
  return result;
}
