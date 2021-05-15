// PiDqSerializationWrite 
 
int __fastcall PiDqSerializationWrite(int result, int a2, unsigned int a3, int a4)
{
  int v5; // r4
  int v6; // r2
  int varg_r0; // [sp+18h] [bp+8h]
  unsigned int varg_r2; // [sp+20h] [bp+10h]

  varg_r2 = a3;
  v5 = result;
  varg_r0 = result;
  v6 = *(_DWORD *)(result + 8);
  if ( *(_DWORD *)(result + 4) - v6 < a3 )
  {
    *(_BYTE *)(result + 20) = 1;
  }
  else
  {
    result = memmove(*(_DWORD *)result + v6, a2, a3);
    *(_DWORD *)(v5 + 8) += a3;
  }
  return result;
}
