// RtlAppendUnicodeToString 
 
int __fastcall RtlAppendUnicodeToString(unsigned __int16 *a1, int a2, int a3, int a4)
{
  unsigned int v6; // r1
  unsigned int v7; // r6
  int v8; // r7
  int v9; // r3
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  if ( a2 )
  {
    if ( RtlInitUnicodeStringEx(v11) < 0 )
      return -1073741789;
    v6 = *a1;
    v7 = LOWORD(v11[0]);
    if ( (int)(v6 + LOWORD(v11[0])) > a1[1] )
      return -1073741789;
    v8 = *((_DWORD *)a1 + 1) + 2 * (v6 >> 1);
    memmove(v8, a2, LOWORD(v11[0]));
    v9 = (unsigned __int16)(*a1 + v7);
    *a1 = v9;
    if ( v9 + 1 < a1[1] )
      *(_WORD *)(v8 + 2 * (v7 >> 1)) = 0;
  }
  return 0;
}
