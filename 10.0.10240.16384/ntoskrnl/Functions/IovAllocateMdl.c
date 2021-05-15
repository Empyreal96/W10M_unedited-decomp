// IovAllocateMdl 
 
int __fastcall IovAllocateMdl(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r6
  unsigned int v8; // r8
  int result; // r0
  int *i; // r2

  v6 = a1 & 0xFFF;
  v8 = 4 * (((unsigned int)(v6 + a2 + 4095) >> 12) + 7);
  result = VeAllocatePoolWithTagPriority(640, v8, 1818512726, 32, a6);
  if ( result )
  {
    *(_DWORD *)result = 0;
    *(_WORD *)(result + 6) = 0;
    *(_WORD *)(result + 4) = v8;
    *(_DWORD *)(result + 16) = a1 & 0xFFFFF000;
    *(_DWORD *)(result + 20) = a2;
    *(_DWORD *)(result + 24) = v6;
    if ( a5 )
    {
      if ( a3 )
      {
        for ( i = *(int **)(a5 + 4); *i; i = (int *)*i )
          ;
        *i = result;
      }
      else
      {
        *(_DWORD *)(a5 + 4) = result;
      }
    }
  }
  return result;
}
