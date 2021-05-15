// EtwpGetScsiPassThroughCdb 
 
int __fastcall EtwpGetScsiPassThroughCdb(int a1)
{
  int v2; // r6
  int v3; // r2
  int result; // r0
  int v5; // r3
  unsigned int v6; // r1

  v2 = *(_DWORD *)(a1 + 96);
  v3 = *(_DWORD *)(v2 + 16);
  result = 0;
  if ( v3 == 315396 || v3 == 315412 || v3 == 315460 || v3 == 315464 )
  {
    v5 = *(_DWORD *)(a1 + 12);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v2 + 12);
      if ( v3 == 315460 || v3 == 315464 )
      {
        if ( v6 >= 0x34 )
          result = v5 + 48;
      }
      else if ( v6 >= 0x2C )
      {
        result = v5 + 28;
      }
    }
  }
  return result;
}
