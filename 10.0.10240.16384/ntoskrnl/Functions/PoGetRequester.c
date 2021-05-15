// PoGetRequester 
 
int __fastcall PoGetRequester(int result, int a2, int *a3, int a4)
{
  int v4; // r1
  int v5; // r3
  int v6; // r3
  int varg_r0; // [sp+10h] [bp+8h]

  varg_r0 = result;
  result = (char)result;
  if ( (_BYTE)result )
  {
    v4 = 0;
    if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
      || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    {
      v5 = 0;
    }
    else
    {
      v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
    }
    if ( v5 )
      v4 = *(_DWORD *)(v5 + 3936);
    if ( v4 )
      v6 = 2;
    else
      v6 = 1;
    *a3 = v6;
    a3[1] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    a3[2] = v4;
  }
  else
  {
    *a3 = 0;
    a3[1] = a2;
    if ( a2 )
      result = ObfReferenceObjectWithTag(a2, 1953261124);
  }
  return result;
}
