// RtlIsRangeAvailable 
 
int __fastcall RtlIsRangeAvailable(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, char a7, unsigned __int8 a8, int a9, int a10, _BYTE *a11)
{
  _DWORD *v11; // r1
  int result; // r0
  int v13[8]; // [sp+20h] [bp-20h] BYREF

  v13[3] = a1[4];
  v11 = (_DWORD *)*a1;
  v13[0] = (int)a1;
  if ( v11 == a1 )
  {
    result = 0;
    *a11 = 1;
  }
  else if ( (*((_WORD *)v11 - 1) & 1) != 0 )
  {
    result = sub_80E608();
  }
  else
  {
    v13[1] = 0;
    v13[2] = (int)(v11 - 7);
    *a11 = RtlpIsRangeAvailable(v13, a8, a3, a4, a5, a6, a8, a7 & 1, a7 & 2, 1, a9, a10);
    result = 0;
  }
  return result;
}
