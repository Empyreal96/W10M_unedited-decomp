// RtlPcToFileHeader 
 
int __fastcall RtlPcToFileHeader(unsigned int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  unsigned int v6; // [sp+0h] [bp-20h] BYREF
  _DWORD *v7; // [sp+4h] [bp-1Ch]
  int v8; // [sp+8h] [bp-18h]
  int v9; // [sp+Ch] [bp-14h]

  v6 = a1;
  v7 = a2;
  v8 = a3;
  v9 = a4;
  if ( a1 >= dword_616494 && a1 < dword_616498 + dword_616494 )
    return sub_554BA8();
  RtlpxLookupFunctionTable(a1, (int *)&v6);
  result = (int)v7;
  *a2 = v7;
  return result;
}
