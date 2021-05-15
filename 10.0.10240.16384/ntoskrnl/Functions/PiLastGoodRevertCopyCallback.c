// PiLastGoodRevertCopyCallback 
 
int __fastcall PiLastGoodRevertCopyCallback(unsigned __int16 *a1, int a2, int a3, _WORD *a4)
{
  unsigned int v5; // r6
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r4
  int v10; // [sp+0h] [bp-18h] BYREF
  unsigned int v11; // [sp+4h] [bp-14h]
  _WORD *v12; // [sp+8h] [bp-10h]

  v10 = a2;
  v11 = a3;
  v12 = a4;
  v5 = (unsigned __int16)(*a4 + 2);
  v6 = ExAllocatePoolWithTag(1, *a1, 1733062736);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memmove(v6, *((_DWORD *)a1 + 1), 0x18u);
  memmove(v7 + 24, *((_DWORD *)a1 + 1) + 2 * (v5 >> 1), *a1 - v5);
  LOWORD(v10) = *a1 - v5 + 24;
  HIWORD(v10) = v10;
  v11 = v7;
  v8 = IopFileUtilRename((int)a1, (unsigned __int16 *)&v10, 1);
  ExFreePoolWithTag(v7);
  return v8;
}
