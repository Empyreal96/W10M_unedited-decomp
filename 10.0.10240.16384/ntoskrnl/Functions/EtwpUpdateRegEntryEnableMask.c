// EtwpUpdateRegEntryEnableMask 
 
int __fastcall EtwpUpdateRegEntryEnableMask(int result, char a2, int a3, int a4)
{
  int v5; // r5
  _BYTE *v6; // r4
  char v7; // r3
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a4;
  v5 = result;
  if ( a3 )
    v6 = (_BYTE *)(result + 52);
  else
    v6 = (_BYTE *)(result + 51);
  if ( a4 == 1 )
  {
    LOBYTE(v8[0]) = a2;
    result = EtwpApplyScopeFilters(result, 1, a3, v8, v8[0], v8[1], v8[2]);
    if ( (*(_BYTE *)(v5 + 50) & 8) != 0 )
    {
      *(_BYTE *)(v5 + 51) = v8[0];
      return result;
    }
    v7 = LOBYTE(v8[0]) | *v6 & ~a2;
    goto LABEL_6;
  }
  if ( !a4 && (*(_BYTE *)(result + 50) & 8) == 0 )
  {
    v7 = *v6 & ~a2;
LABEL_6:
    *v6 = v7;
  }
  return result;
}
