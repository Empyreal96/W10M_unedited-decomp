// NormBuffer__IsBlocked 
 
int __fastcall NormBuffer__IsBlocked(int a1, unsigned int a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  int v4; // r4
  int v5; // r3
  int v6; // r2
  unsigned __int16 *v8; // r5
  int v9; // r7
  int v10; // r0
  unsigned __int16 *v11; // r3
  int result; // r0
  unsigned __int16 *v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v4 = a1;
  v5 = *(_DWORD *)(a1 + 20);
  v6 = *(_DWORD *)(a1 + 44);
  *(_DWORD *)(a1 + 64) = v5;
  if ( v5 == v6 )
    goto LABEL_6;
  v8 = (unsigned __int16 *)(v6 - 2);
  v13[0] = (unsigned __int16 *)(v5 - 2);
  if ( v5 - 2 == v6 - 2 )
    goto LABEL_6;
  v9 = *(_DWORD *)(a1 + 68);
  while ( 1 )
  {
    v10 = NormBuffer__GetCurrentOutputChar(a1, v13);
    Normalization__PageLookup(v9, v10);
    a1 = Normalization__TableLookup(v9);
    if ( (a1 & 0x3Fu) <= a2 )
      break;
    v11 = v13[0];
    *(unsigned __int16 **)(v4 + 64) = v13[0];
    v13[0] = v11 - 1;
    if ( v11 - 1 == v8 )
      goto LABEL_6;
  }
  if ( (a1 & 0x3F) != a2 )
LABEL_6:
    result = 0;
  else
    result = 1;
  return result;
}
