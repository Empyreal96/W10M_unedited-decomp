// RtlUnicodeStringToCountedOemString 
 
int __fastcall RtlUnicodeStringToCountedOemString(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r0
  int v9; // r3
  int v10; // r0
  int v11; // r5
  int v12; // r4
  int v14; // [sp+8h] [bp-18h]
  int v15[5]; // [sp+Ch] [bp-14h] BYREF
  unsigned __int16 *varg_r0; // [sp+28h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v15[0] = a4;
  LOBYTE(varg_r2) = a3;
  varg_r0 = a1;
  if ( NlsMbOemCodePageTag )
    v7 = RtlxUnicodeStringToOemSize(a2);
  else
    v7 = ((unsigned int)*a2 + 2) >> 1;
  v8 = v7 - 1;
  if ( !v8 )
  {
    v9 = 0;
    *a1 = 0;
    a1[1] = 0;
    *((_DWORD *)a1 + 1) = 0;
LABEL_6:
    v15[0] = v9;
    return v15[0];
  }
  if ( v8 > 0xFFFF )
  {
    v9 = -1073741584;
    goto LABEL_6;
  }
  *a1 = v8;
  if ( a3 )
  {
    a1[1] = v8;
    v10 = ExpAllocateStringRoutine(v8);
    *((_DWORD *)a1 + 1) = v10;
    if ( !v10 )
    {
      v9 = -1073741801;
      goto LABEL_6;
    }
  }
  else if ( (unsigned __int16)v8 > (unsigned int)a1[1] )
  {
    v9 = -2147483643;
    goto LABEL_6;
  }
  v11 = ((int (__fastcall *)(_DWORD, _DWORD, int *, _DWORD, _DWORD))RtlUnicodeToOemN)(
          *((_DWORD *)a1 + 1),
          *a1,
          v15,
          *((_DWORD *)a2 + 1),
          *a2);
  v14 = v11;
  if ( v11 >= 0 )
  {
    if ( !RtlpDidUnicodeToOemWork(a1, a2) )
    {
      v11 = -1073741470;
      v14 = -1073741470;
    }
    if ( v11 >= 0 )
      v14 = 0;
  }
  if ( v14 < 0 && (_BYTE)varg_r2 )
  {
    v12 = (int)varg_r0;
    ExFreePool(*((_DWORD *)varg_r0 + 1));
    *(_DWORD *)(v12 + 4) = 0;
  }
  v15[0] = v14;
  return v15[0];
}
