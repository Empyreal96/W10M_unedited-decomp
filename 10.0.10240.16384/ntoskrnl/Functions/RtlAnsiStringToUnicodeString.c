// RtlAnsiStringToUnicodeString 
 
int __fastcall RtlAnsiStringToUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r3
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int v13; // [sp+8h] [bp-18h]
  unsigned int v14[5]; // [sp+Ch] [bp-14h] BYREF
  unsigned __int16 *varg_r0; // [sp+28h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v14[0] = a4;
  LOBYTE(varg_r2) = a3;
  varg_r0 = a1;
  if ( NlsMbCodePageTag )
    v7 = RtlxOemStringToUnicodeSize(a2);
  else
    v7 = 2 * (*a2 + 1);
  if ( v7 > 0xFFFE )
  {
    v8 = -1073741584;
LABEL_18:
    v14[0] = v8;
    return v14[0];
  }
  v9 = (unsigned __int16)(v7 - 2);
  *a1 = v9;
  if ( a3 )
  {
    a1[1] = v7;
    v10 = ExpAllocateStringRoutine(v7);
    *((_DWORD *)a1 + 1) = v10;
    if ( !v10 )
    {
      v8 = -1073741801;
      goto LABEL_18;
    }
  }
  else if ( v9 + 2 > (unsigned int)a1[1] || (unsigned int)(v9 + 2) < 2 )
  {
    v8 = -2147483643;
    goto LABEL_18;
  }
  v13 = RtlMultiByteToUnicodeN(*((_DWORD *)a1 + 1), *a1, v14, *((_DWORD *)a2 + 1));
  if ( v13 >= 0 )
  {
    *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * (v14[0] >> 1)) = 0;
    v13 = 0;
  }
  if ( v13 < 0 && (_BYTE)varg_r2 )
  {
    v11 = (int)varg_r0;
    ExFreePool(*((_DWORD *)varg_r0 + 1));
    *(_DWORD *)(v11 + 4) = 0;
  }
  v14[0] = v13;
  return v14[0];
}
