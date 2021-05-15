// EtwpIsProcessZombie 
 
int __fastcall EtwpIsProcessZombie(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 192) & 4) != 0 )
    result = sub_7D00AC();
  else
    result = 0;
  return result;
}
