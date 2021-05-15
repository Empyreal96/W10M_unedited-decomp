// EtwpGetSchematizedFilterSize 
 
int __fastcall EtwpGetSchematizedFilterSize(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r6
  unsigned int v5; // r2
  int i; // r4

  v2 = *(_DWORD *)(a1 + 344);
  result = 0;
  if ( v2 )
  {
    v4 = 0;
    v5 = 0;
    for ( i = a1; !*(_DWORD *)(i + 88) || !*(_DWORD *)(*(_DWORD *)(a1 + 344) + v5 + 32); i += 32 )
    {
      v5 += 36;
      ++v4;
      if ( v5 >= 0x120 )
        return result;
    }
    result = sub_7C5088(0);
  }
  return result;
}
