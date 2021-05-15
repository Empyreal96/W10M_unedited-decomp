// RtlUpcaseUnicodeStringToOemString 
 
int __fastcall RtlUpcaseUnicodeStringToOemString(unsigned __int16 *a1, unsigned __int16 **a2, int a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r3
  int v9; // r0
  int v10; // r5
  int v11; // r4
  int v13; // [sp+8h] [bp-18h]
  unsigned int v14[5]; // [sp+Ch] [bp-14h] BYREF
  unsigned __int16 *varg_r0; // [sp+28h] [bp+8h]
  unsigned __int16 **varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v14[0] = a4;
  LOBYTE(varg_r2) = a3;
  varg_r0 = a1;
  if ( NlsMbOemCodePageTag )
    v7 = RtlxUnicodeStringToOemSize(a2);
  else
    v7 = ((unsigned int)*(unsigned __int16 *)a2 + 2) >> 1;
  if ( v7 > 0xFFFF )
  {
    v8 = -1073741584;
LABEL_6:
    v14[0] = v8;
    return v14[0];
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
  v10 = RtlUpcaseUnicodeToOemN(*((_BYTE **)a1 + 1), *a1, v14, a2[1], *(unsigned __int16 *)a2);
  v13 = v10;
  if ( v10 >= 0 )
  {
    if ( !RtlpDidUnicodeToOemWork(a1, (int)a2) )
    {
      v10 = -1073741470;
      v13 = -1073741470;
    }
    if ( v10 >= 0 )
    {
      *(_BYTE *)(*((_DWORD *)a1 + 1) + v14[0]) = 0;
      v13 = 0;
    }
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
