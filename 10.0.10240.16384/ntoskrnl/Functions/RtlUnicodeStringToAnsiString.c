// RtlUnicodeStringToAnsiString 
 
int __fastcall RtlUnicodeStringToAnsiString(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r3
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r5
  int v12; // r4
  int v14; // [sp+8h] [bp-20h]
  int v16; // [sp+Ch] [bp-1Ch]
  _DWORD _10[7]; // [sp+10h] [bp-18h] BYREF
  unsigned __int16 *varg_r0; // [sp+30h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  _10[0] = a3;
  _10[1] = a4;
  LOBYTE(varg_r2) = a3;
  varg_r0 = a1;
  v14 = 0;
  if ( NlsMbCodePageTag )
    v7 = RtlxUnicodeStringToOemSize(a2);
  else
    v7 = ((unsigned int)*a2 + 2) >> 1;
  if ( v7 > 0xFFFF )
    return -1073741584;
  v8 = (unsigned __int16)(v7 - 1);
  *a1 = v8;
  if ( a3 )
  {
    a1[1] = v7;
    v9 = ExpAllocateStringRoutine(v7);
    *((_DWORD *)a1 + 1) = v9;
    if ( !v9 )
      return -1073741801;
  }
  else
  {
    v10 = a1[1];
    if ( v8 >= v10 )
    {
      if ( !a1[1] )
        return -2147483643;
      v14 = -2147483643;
      *a1 = v10 - 1;
    }
  }
  v16 = RtlUnicodeToMultiByteN(*((_DWORD *)a1 + 1), *a1, _10, *((_DWORD *)a2 + 1));
  if ( v16 >= 0 )
    *(_BYTE *)(*((_DWORD *)a1 + 1) + _10[0]) = 0;
  v11 = v16;
  if ( v16 >= 0 )
    return v14;
  if ( (_BYTE)varg_r2 )
  {
    v12 = (int)varg_r0;
    ExFreePool(*((_DWORD *)varg_r0 + 1));
    *(_DWORD *)(v12 + 4) = 0;
  }
  return v11;
}
