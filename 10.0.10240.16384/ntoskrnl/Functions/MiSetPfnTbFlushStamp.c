// MiSetPfnTbFlushStamp 
 
int __fastcall MiSetPfnTbFlushStamp(int result, int a2, int a3)
{
  char v3; // r4
  unsigned int *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  unsigned int v7; // r4

  v3 = a2;
  if ( a3 == 1 )
  {
    *(_DWORD *)(result + 12) ^= (*(_DWORD *)(result + 12) ^ (a2 << 20)) & 0xF00000;
  }
  else
  {
    v4 = (unsigned int *)(result + 12);
    v5 = *(_DWORD *)(result + 12);
    v6 = v5 & 0xFF0FFFFF | ((v3 & 0xF) << 20);
    do
      v7 = __ldrex(v4);
    while ( v7 == v5 && __strex(v6, v4) );
    if ( v5 != v7 )
      result = sub_50DA38(result, v5, v6);
  }
  return result;
}
