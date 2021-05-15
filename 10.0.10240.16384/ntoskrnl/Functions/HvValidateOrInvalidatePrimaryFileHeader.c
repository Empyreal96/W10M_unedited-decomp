// HvValidateOrInvalidatePrimaryFileHeader 
 
int __fastcall HvValidateOrInvalidatePrimaryFileHeader(int a1, int a2, int a3, char a4)
{
  char v5; // r8
  int *v8; // r5
  int v9; // r3
  int v10; // r3
  int v11; // r4
  BOOL v12; // r9
  int v13; // [sp+8h] [bp-30h] BYREF
  _DWORD v14[10]; // [sp+10h] [bp-28h] BYREF

  v5 = a2;
  if ( !*(_DWORD *)(a1 + 1776) )
    return 0;
  v12 = (a4 & 1) != 0;
  if ( !a3 )
    return sub_7F3D9C();
  v8 = *(int **)(a1 + 1924);
  v9 = *(_DWORD *)(a1 + 100);
  if ( a2 )
  {
    v8[2] = v9;
  }
  else
  {
    v10 = v9 - 1;
    v8[2] = v10;
    v9 = v10 + 1;
  }
  v8[1] = v9;
  v8[127] = HvpHeaderCheckSum(v8);
  v13 = 0;
  v14[0] = 0;
  v14[1] = v8;
  v14[2] = 4096;
  if ( (*(int (__fastcall **)(int, _DWORD, _DWORD *, int, int *, BOOL))(a1 + 20))(a1, 0, v14, 1, &v13, v12)
    && CmpFileFlushAndPurge(a1, 0) )
  {
    *(_BYTE *)(a1 + 122) = v5;
    v11 = 0;
    *(_DWORD *)(a1 + 112) = v8[2];
  }
  else
  {
    v11 = -1073741491;
  }
  if ( !a3 )
    ExFreePoolWithTag((unsigned int)v8);
  return v11;
}
