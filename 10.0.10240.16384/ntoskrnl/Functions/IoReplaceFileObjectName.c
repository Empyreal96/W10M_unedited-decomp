// IoReplaceFileObjectName 
 
int __fastcall IoReplaceFileObjectName(int a1, int a2, unsigned int a3)
{
  int v7; // r3
  __int16 v8; // r6
  int v9; // r7
  unsigned int v10; // r0
  int v11; // r2
  _BYTE *v12; // r0

  if ( a3 <= *(unsigned __int16 *)(a1 + 50) )
  {
LABEL_10:
    v11 = *(unsigned __int16 *)(a1 + 50);
    v12 = *(_BYTE **)(a1 + 52);
    *(_WORD *)(a1 + 48) = a3;
    memset(v12, 0, v11);
    memmove(*(_DWORD *)(a1 + 52), a2, a3);
    return 0;
  }
  if ( a3 < 0x38 )
  {
    v7 = 56;
  }
  else
  {
    if ( a3 >= 0x78 )
      return sub_7EAD14();
    v7 = 120;
  }
  v8 = v7;
  v9 = ExAllocatePoolWithTag(1, v7, 1833856841);
  if ( v9 )
  {
    v10 = *(_DWORD *)(a1 + 52);
    if ( v10 )
      ExFreePoolWithTag(v10);
    *(_DWORD *)(a1 + 52) = v9;
    *(_WORD *)(a1 + 50) = v8;
    goto LABEL_10;
  }
  return -1073741670;
}
