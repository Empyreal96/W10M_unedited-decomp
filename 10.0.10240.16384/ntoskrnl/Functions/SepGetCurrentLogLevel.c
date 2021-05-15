// SepGetCurrentLogLevel 
 
int __fastcall SepGetCurrentLogLevel(int a1)
{
  int v1; // r4
  int result; // r0

  v1 = __mrc(15, 0, 13, 0, 3);
  if ( KeGetCurrentIrql(a1) )
    result = 2;
  else
    result = (*(_BYTE *)((v1 & 0xFFFFFFC0) + 0x78) & 1) != 0;
  return result;
}
