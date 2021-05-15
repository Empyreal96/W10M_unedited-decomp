// RtlOemStringToCountedUnicodeString 
 
int __fastcall RtlOemStringToCountedUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  int v7; // r0
  unsigned int v8; // r0
  int v9; // r3
  int v10; // r0
  int v11; // r5
  int v12; // r4
  int v14; // [sp+8h] [bp-18h] BYREF
  int v15; // [sp+Ch] [bp-14h]
  unsigned __int16 *varg_r0; // [sp+28h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v14 = a3;
  v15 = a4;
  LOBYTE(varg_r2) = a3;
  varg_r0 = a1;
  if ( NlsMbOemCodePageTag )
    v7 = RtlxOemStringToUnicodeSize(a2);
  else
    v7 = 2 * (*a2 + 1);
  v8 = v7 - 2;
  if ( !v8 )
  {
    v9 = 0;
    *a1 = 0;
    a1[1] = 0;
    *((_DWORD *)a1 + 1) = 0;
    return v9;
  }
  if ( v8 > 0xFFFE )
    return -1073741584;
  *a1 = v8;
  if ( a3 )
  {
    a1[1] = v8;
    v10 = ExpAllocateStringRoutine(v8);
    *((_DWORD *)a1 + 1) = v10;
    if ( !v10 )
      return -1073741801;
  }
  else if ( (unsigned __int16)v8 > (unsigned int)a1[1] )
  {
    return -2147483643;
  }
  v15 = 0;
  v15 = RtlOemToUnicodeN(*((_DWORD *)a1 + 1), *a1, &v14, *((_DWORD *)a2 + 1), *a2);
  if ( v15 >= 0 )
    v15 = 0;
  v11 = v15;
  if ( v15 < 0 && (_BYTE)varg_r2 )
  {
    v12 = (int)varg_r0;
    ExFreePool(*((_DWORD *)varg_r0 + 1));
    *(_DWORD *)(v12 + 4) = 0;
  }
  return v11;
}
