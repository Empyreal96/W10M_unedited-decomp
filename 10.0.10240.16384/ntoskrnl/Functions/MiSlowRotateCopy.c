// MiSlowRotateCopy 
 
void __fastcall __spoils<R2,R3,R12> MiSlowRotateCopy(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int *v4; // r7
  int v5; // r6
  int v6; // r8
  int v7; // r3
  int v8; // r2
  int v9; // r9
  unsigned int v10; // r5
  unsigned int v11; // r4
  _DWORD v12[3]; // [sp+0h] [bp-28h] BYREF
  unsigned int v13; // [sp+Ch] [bp-1Ch]

  v12[2] = a3;
  v13 = a4;
  v4 = (unsigned int *)(a2 + 28);
  v5 = 1;
  v6 = *(_DWORD *)(a2 + 20) >> 12;
  v7 = *(_DWORD *)(a3 + 28);
  v8 = (unsigned __int8)v7 >> 6;
  if ( v8 == 3 && (v7 & 0x38) != 0 )
  {
    v5 = 2;
  }
  else if ( v8 == 1 )
  {
    v5 = 0;
  }
  if ( v6 )
  {
    v9 = a1 - a2;
    do
    {
      MiGetPteMappingPair(1, (int)v12);
      v10 = v13;
      v11 = v13 + 4;
      MiInitializeSlowPte(v13, *v4, v5);
      MiInitializeSlowPte(v11, *(unsigned int *)((char *)v4 + v9), v5);
      memmove(v11 << 10, v10 << 10, 0x1000u);
      MiReturnPteMappingPair((int)v12);
      ++v4;
      --v6;
    }
    while ( v6 );
  }
}
