// EtwpIsStackWalkingEnabled 
 
int __fastcall EtwpIsStackWalkingEnabled(int a1)
{
  int v1; // r3
  int result; // r0

  v1 = *(_DWORD *)(a1 + 608);
  result = 0;
  if ( (v1 & 0x80) != 0 )
    result = sub_7D01DC(0);
  return result;
}
