// RtlUnicodeStringToOemString 
 
int __fastcall RtlUnicodeStringToOemString(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r3
  int v9; // r0
  int v10; // r4
  int v12; // [sp+8h] [bp-18h]
  unsigned int v13[5]; // [sp+Ch] [bp-14h] BYREF
  unsigned __int16 *varg_r0; // [sp+28h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v13[0] = a4;
  LOBYTE(varg_r2) = a3;
  varg_r0 = a1;
  if ( NlsMbOemCodePageTag )
    v7 = RtlxUnicodeStringToOemSize(a2);
  else
    v7 = ((unsigned int)*a2 + 2) >> 1;
  if ( v7 > 0xFFFF )
  {
    v8 = -1073741584;
LABEL_6:
    v13[0] = v8;
    return v13[0];
  }
  *a1 = v7 - 1;
  if ( a3 )
  {
    a1[1] = v7;
    v9 = ExpAllocateStringRoutine(v7);
    *((_DWORD *)a1 + 1) = v9;
    if ( !v9 )
    {
      v8 = -1073741801;
      goto LABEL_6;
    }
  }
  else if ( (unsigned __int16)(v7 - 1) >= (unsigned int)a1[1] )
  {
    v8 = -2147483643;
    goto LABEL_6;
  }
  v12 = RtlUnicodeToOemN(*((_DWORD *)a1 + 1), *a1, v13, *((_DWORD *)a2 + 1), *a2);
  if ( v12 >= 0 )
  {
    *(_BYTE *)(*((_DWORD *)a1 + 1) + v13[0]) = 0;
    v12 = 0;
  }
  if ( v12 < 0 && (_BYTE)varg_r2 )
  {
    v10 = (int)varg_r0;
    ExFreePool(*((_DWORD *)varg_r0 + 1));
    *(_DWORD *)(v10 + 4) = 0;
  }
  v13[0] = v12;
  return v13[0];
}
