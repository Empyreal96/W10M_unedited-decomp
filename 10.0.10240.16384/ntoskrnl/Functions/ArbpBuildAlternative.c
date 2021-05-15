// ArbpBuildAlternative 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ArbpBuildAlternative(int a1, int a2, int a3)
{
  int result; // r0
  unsigned __int64 v6; // kr08_8
  unsigned int v7; // r7 OVERLAPPED
  unsigned int v8; // r8 OVERLAPPED
  __int64 v9; // r0
  __int64 v10; // r2
  int v11; // r3

  *(_DWORD *)(a3 + 40) = a2;
  result = (*(int (__fastcall **)(int, int, int, int))(a1 + 60))(a2, a3, a3 + 8, a3 + 16);
  if ( result >= 0 )
  {
    *(_DWORD *)(a3 + 36) = 0;
    if ( *(_BYTE *)(a2 + 2) == 3 )
    {
      result = sub_80E4CC();
    }
    else
    {
      v6 = *(_QWORD *)(a3 + 8);
      *(_QWORD *)&v7 = *(_QWORD *)a3;
      LODWORD(v9) = *(_DWORD *)(a3 + 20);
      HIDWORD(v10) = *(_DWORD *)(a3 + 16);
      LODWORD(v10) = (v6 - *(_QWORD *)a3 + 1) >> 32;
      HIDWORD(v9) = v6 - *(_DWORD *)a3 + 1;
      if ( v9 == v10 )
        *(_DWORD *)(a3 + 36) |= 2u;
      v11 = *(unsigned __int8 *)(a2 + 1);
      if ( (v11 == 3 || v11 == 7) && (*(_WORD *)(a2 + 4) & 0x100) != 0 )
        *(_DWORD *)(a3 + 36) |= 8u;
      if ( v6 < __PAIR64__(v8, v7) )
        *(_DWORD *)(a3 + 36) |= 4u;
      result = 0;
    }
  }
  return result;
}
