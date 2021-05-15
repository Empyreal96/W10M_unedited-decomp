// FstubReadHeaderEFI 
 
int __fastcall FstubReadHeaderEFI(int *a1, __int64 a2, _DWORD *a3)
{
  int v5; // r1
  int v6; // r7
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r8
  int result; // r0
  _DWORD *v11; // r5
  unsigned int v12; // r3
  int v13; // r4
  int v14; // r0
  int v15; // [sp+4h] [bp-1Ch]

  v5 = a1[10];
  v6 = HIDWORD(a2);
  v7 = *a1;
  v15 = v5;
  v8 = a1[1];
  v9 = a2;
  *a3 = 0;
  result = FstubReadSectors(v7, v8, a2, 1, v15);
  if ( result >= 0 )
  {
    v11 = (_DWORD *)a1[10];
    if ( *v11 == 541673029
      && v11[1] == 1414676816
      && v11[2] == 0x10000
      && v11[3] == 92
      && v11[21] == 128
      && (v12 = v11[20]) != 0
      && v12 <= 0x400
      && v11[6] == v9
      && v11[7] == v6
      && (v13 = v11[4], v11[4] = 0, v14 = RtlComputeCrc32(0, (int)v11, 0x5Cu), v11[4] = v13, v14 == v13) )
    {
      *a3 = v11;
      result = 0;
    }
    else
    {
      result = -1073741774;
    }
  }
  return result;
}
