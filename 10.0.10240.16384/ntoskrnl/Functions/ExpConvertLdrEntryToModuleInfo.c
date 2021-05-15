// ExpConvertLdrEntryToModuleInfo 
 
int __fastcall ExpConvertLdrEntryToModuleInfo(int a1, int a2, int a3, int a4)
{
  __int16 v6; // r3
  int result; // r0
  _BYTE *v8; // r3
  int v9; // [sp+0h] [bp-18h] BYREF
  unsigned int v10; // [sp+4h] [bp-14h]
  int v11; // [sp+8h] [bp-10h]

  v9 = a2;
  v10 = a3;
  v11 = a4;
  *(_DWORD *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 12) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a3 + 20) = *(_DWORD *)(a1 + 52);
  v6 = *(_WORD *)(a1 + 56);
  *(_WORD *)(a3 + 24) = a2;
  *(_WORD *)(a3 + 28) = v6;
  v10 = a3 + 32;
  v9 = 0x1000000;
  *(_WORD *)(a3 + 26) = 0;
  result = RtlUnicodeStringToAnsiString((unsigned __int16 *)&v9, (unsigned __int16 *)(a1 + 36), 0, 256);
  v8 = (_BYTE *)((unsigned __int16)v9 + v10);
  while ( (unsigned int)v8 > v10 )
  {
    if ( *--v8 == 92 )
    {
      LOWORD(v8) = (_WORD)v8 + 1;
      break;
    }
    if ( !*v8 )
      break;
  }
  *(_WORD *)(a3 + 30) = (_WORD)v8 - v10;
  *(_DWORD *)(a3 + 288) = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(a3 + 292) = *(_DWORD *)(a1 + 88);
  *(_DWORD *)(a3 + 296) = 0;
  return result;
}
