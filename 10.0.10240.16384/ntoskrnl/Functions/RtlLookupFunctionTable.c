// RtlLookupFunctionTable 
 
int __fastcall RtlLookupFunctionTable(unsigned int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int result; // r0
  unsigned int v7; // [sp+0h] [bp-28h] BYREF
  _DWORD *v8; // [sp+4h] [bp-24h]
  _DWORD *v9; // [sp+8h] [bp-20h]
  int v10; // [sp+Ch] [bp-1Ch]

  v7 = a1;
  v8 = a2;
  v9 = a3;
  v10 = a4;
  if ( a1 < dword_616494 || a1 >= dword_616498 + dword_616494 )
  {
    result = RtlpxLookupFunctionTable(a1, (int *)&v7);
  }
  else
  {
    result = dword_616490[0];
    v7 = dword_616490[0];
    v8 = (_DWORD *)dword_616494;
    v9 = (_DWORD *)dword_616498;
    v10 = *(_DWORD *)algn_61649C;
  }
  if ( result )
  {
    *a2 = v8;
    *a3 = v10;
  }
  return result;
}
