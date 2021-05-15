// SymCryptSha256Append 
 
_BYTE *__fastcall SymCryptSha256Append(_BYTE *result, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  unsigned int *v4; // r6
  unsigned int v5; // r5
  int v6; // r8
  unsigned int v7; // r4
  unsigned int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a4;
  v4 = (unsigned int *)result;
  v5 = a3;
  v6 = (int)a2;
  *((_QWORD *)result + 1) += a3;
  v7 = *(_DWORD *)result;
  if ( *(_DWORD *)result )
    return (_BYTE *)sub_524AA4();
  if ( a3 >= 0x40 )
  {
    result = SymCryptSha256AppendBlocks_ul1((int *)result + 22, a2, a3, v8);
    v6 = v6 - v8[0] + v5;
    v5 = v8[0];
  }
  if ( v5 )
  {
    result = (_BYTE *)memmove((int)(v4 + 6), v6, v5);
    v7 = v5;
  }
  *v4 = v7;
  return result;
}
