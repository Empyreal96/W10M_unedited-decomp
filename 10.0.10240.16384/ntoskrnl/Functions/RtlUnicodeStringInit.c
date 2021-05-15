// RtlUnicodeStringInit 
 
int __fastcall RtlUnicodeStringInit(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int result; // r0
  __int16 v7; // r3
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  result = 0;
  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 2) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  if ( a2 )
  {
    result = sub_455E68(a2, (int)a2, v8);
    if ( result >= 0 )
    {
      v7 = v8[0];
      *(_DWORD *)(a1 + 4) = a2;
      v7 *= 2;
      *(_WORD *)a1 = v7;
      *(_WORD *)(a1 + 2) = v7 + 2;
    }
  }
  return result;
}
