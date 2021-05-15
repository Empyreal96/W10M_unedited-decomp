// MiLocateKernelSections 
 
int __fastcall MiLocateKernelSections(int a1)
{
  int v1; // r7
  int result; // r0
  int v3; // r1
  int *v4; // r2
  unsigned int v5; // r5
  int v6; // r3
  int v7; // r4

  v1 = *(_DWORD *)(a1 + 24);
  result = RtlImageNtHeader(v1);
  v3 = *(unsigned __int16 *)(result + 6);
  v4 = (int *)(*(unsigned __int16 *)(result + 20) + result + 24);
  if ( *(_WORD *)(result + 6) )
  {
    result = MiFlags;
    do
    {
      v5 = v4[4];
      if ( v5 < v4[2] )
        v5 = v4[2];
      v6 = *v4;
      if ( *v4 == 1987011374 || v6 == 1953655086 )
      {
        result |= 0x400u;
        MiFlags = result;
      }
      else if ( v6 == 1280266064 )
      {
        v7 = v4[3] + v1;
        if ( v4[1] == 1162104643 )
        {
          ExPoolCodeStart = v4[3] + v1;
          ExPoolCodeEnd = ((v7 + v5 + 4095) & 0xFFFFF000) - 1;
        }
      }
      --v3;
      v4 += 10;
    }
    while ( v3 > 0 );
  }
  return result;
}
