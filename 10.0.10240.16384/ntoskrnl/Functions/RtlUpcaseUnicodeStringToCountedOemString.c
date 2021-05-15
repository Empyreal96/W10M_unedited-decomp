// RtlUpcaseUnicodeStringToCountedOemString 
 
int __fastcall RtlUpcaseUnicodeStringToCountedOemString(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v7; // r0
  unsigned int v8; // r0
  int v9; // r0
  int v10; // r3
  int v11; // r4
  int v13; // [sp+8h] [bp-18h]
  int v14[5]; // [sp+Ch] [bp-14h] BYREF
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
  if ( NlsMbOemCodePageTag )
    v7 = RtlxUnicodeStringToOemSize(a2);
  else
    v7 = ((unsigned int)*a2 + 2) >> 1;
  v8 = v7 - 1;
  if ( v8 )
  {
    if ( v8 <= 0xFFFF )
    {
      *a1 = v8;
      if ( a3 )
      {
        a1[1] = v8;
        v9 = ExpAllocateStringRoutine(v8);
        *((_DWORD *)a1 + 1) = v9;
        if ( !v9 )
        {
          v14[0] = -1073741801;
          return v14[0];
        }
      }
      else if ( (unsigned __int16)v8 > (unsigned int)a1[1] )
      {
        v14[0] = -2147483643;
        return v14[0];
      }
      v13 = ((int (__fastcall *)(_DWORD, _DWORD, int *, _DWORD, _DWORD))RtlUpcaseUnicodeToOemN)(
              *((_DWORD *)a1 + 1),
              *a1,
              v14,
              *((_DWORD *)a2 + 1),
              *a2);
      if ( v13 >= 0 )
      {
        if ( RtlpDidUnicodeToOemWork(a1, a2) )
          v10 = 0;
        else
          v10 = -1073741470;
        v13 = v10;
      }
      if ( v13 < 0 && (_BYTE)varg_r2 )
      {
        v11 = (int)varg_r0;
        ExFreePool(*((_DWORD *)varg_r0 + 1));
        *(_DWORD *)(v11 + 4) = 0;
      }
      v14[0] = v13;
    }
    else
    {
      v14[0] = -1073741584;
    }
  }
  else
  {
    *a1 = 0;
    a1[1] = 0;
    *((_DWORD *)a1 + 1) = 0;
    v14[0] = 0;
  }
  return v14[0];
}
