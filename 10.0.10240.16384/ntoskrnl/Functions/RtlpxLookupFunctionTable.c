// RtlpxLookupFunctionTable 
 
int __fastcall RtlpxLookupFunctionTable(unsigned int a1, int *a2)
{
  int v3; // r9
  int result; // r0
  int v6; // r2
  int v7; // r6
  int v8; // r1
  int *v9; // r4
  unsigned int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3

  a2[1] = 0;
  a2[2] = 0;
  v3 = dword_616488;
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    goto LABEL_15;
  if ( PsInvertedFunctionTable == 1 )
    return sub_548000();
  v6 = PsInvertedFunctionTable - 1;
  v7 = 1;
  if ( PsInvertedFunctionTable - 1 < 1 )
    return sub_548000();
  while ( 1 )
  {
    v8 = (v6 + v7) >> 1;
    v9 = &dword_616490[4 * v8];
    v10 = v9[1];
    if ( a1 < v10 )
    {
      if ( !v8 )
        return sub_548000();
      v6 = v8 - 1;
      goto LABEL_8;
    }
    if ( a1 < v9[2] + v10 )
      break;
    v7 = v8 + 1;
LABEL_8:
    if ( v6 < v7 )
      return sub_548000();
  }
  if ( !v9 )
    return sub_548000();
  v11 = v9[1];
  v12 = v9[2];
  v13 = v9[3];
  *a2 = *v9;
  a2[1] = v11;
  a2[2] = v12;
  a2[3] = v13;
  result = *a2;
  __dmb(0xFu);
  if ( dword_616488 != v3 )
LABEL_15:
    JUMPOUT(0x548010);
  return result;
}
